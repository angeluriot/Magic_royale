#ifndef PTRLIST_HPP
#define PTRLIST_HPP

#include <vector>
#include <iterator>
#include <cstddef>

template <typename T>
void free_memory(T* ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

template<typename T>
class PtrList
{
private:

	std::vector<T*> m_list;

public:

	class Iterator
	{
	public:

		using iterator_category	= std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type		= T;
		using pointer			= value_type*;
		using reference			= value_type&;

	private:

		size_t m_index;
		PtrList<T>& m_list;

	public:

		Iterator(size_t index, PtrList<T>& list): m_index(index), m_list(list) {}

		reference operator*() const { return m_list[m_index]; }
		pointer operator->() { return &(m_list[m_index]); }
		Iterator& operator++() { m_index++; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		bool operator==(const Iterator& other) { return m_index == other.m_index && &m_list == &other.m_list; }
		bool operator!=(const Iterator& other) { return !(*this == other); }
	};

	PtrList()
	{
		clear();
	}

	PtrList(const PtrList<T>& ptrlist)
	{
		*this = ptrlist;
	}

	PtrList(const PtrList<T>&& ptrlist)
	{
		*this = ptrlist;
	}

	~PtrList()
	{
		clear();
	}

	PtrList<T>& operator=(const PtrList<T>& ptrlist)
	{
		clear();

		for (int i = 0; i < (int)ptrlist.size(); i++)
			add(ptrlist[i]);

		return *this;
	}

	PtrList<T>& operator=(const PtrList<T>&& ptrlist)
	{
		clear();
		m_list = ptrlist.m_list;
		ptrlist.m_list.clear();
		return *this;
	}

	T& operator[](size_t index)
	{
		return *m_list[index];
	}

	const T& operator[](size_t index) const
	{
		return *m_list[index];
	}

	bool operator==(const PtrList<T>& other)
	{
		return m_list == other.m_list;
	}

	bool operator!=(const PtrList<T>& other)
	{
		return m_list != other.m_list;
	}

	auto begin()
	{
		return Iterator(0, *this);
	}

	auto end()
	{
		return Iterator(static_cast<size_t>(m_list.size()), *this);
	}

	template <typename U>
	void add(const U& element)
	{
		m_list.push_back((T*)element.clone());
	}

	void remove(const T& element)
	{
		for (auto it = m_list.begin(); it != m_list.end(); ++it)
			if (*it == &element)
			{
				free_memory(*it);
				m_list.erase(it);
				break;
			}
	}

	void remove(size_t index)
	{
		free_memory(m_list[index]);
		m_list.erase(m_list.begin() + index);
	}

	void swap(size_t index_1, size_t index_2)
	{
		if (index_1 != index_2)
			std::swap(m_list[index_1], m_list[index_2]);
	}

	void clear()
	{
		for (auto& element : m_list)
			free_memory(element);

		m_list.clear();
	}

	bool empty() const
	{
		return m_list.empty();
	}

	bool contains(const T& element) const
	{
		for (int i = 0; i < size(); i++)
			if (m_list[i] == &element)
				return true;

		return false;
	}

	size_t size() const
	{
		return m_list.size();
	}

	T& back()
	{
		return *m_list.back();
	}

	const T& back() const
	{
		return *m_list.back();
	}

	T& front()
	{
		return *m_list.front();
	}

	const T& front() const
	{
		return *m_list.front();
	}
};

#endif
