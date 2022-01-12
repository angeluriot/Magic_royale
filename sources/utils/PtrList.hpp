#ifndef PTRLIST_HPP
#define PTRLIST_HPP

#include <vector>
#include <memory>
#include <iterator>
#include <cstddef>

template<typename T>
class PtrList
{
private:

	std::vector<std::unique_ptr<T>> m_list;

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

		unsigned int m_index;
		PtrList& m_list;

	public:

		Iterator(unsigned int index, PtrList& list): m_index(index), m_list(list) {}

		reference operator*() const { return m_list[m_index]; }
		pointer operator->() { return &m_list[m_index]; }
		Iterator& operator++() { m_index++; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		bool operator==(const Iterator& other) { return m_index == other.m_index && &m_list == &other.m_list; }
		bool operator!=(const Iterator& other) { return !(*this == other); }
	};

	PtrList()
	{
		m_list.clear();
	}

	~PtrList() {}

	T& operator[](unsigned int index)
	{
		return *m_list[index];
	}

	const T& operator[](unsigned int index) const
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
		return Iterator(static_cast<unsigned int>(m_list.size()), *this);
	}

	template <typename U>
	void add(const U& element)
	{
		m_list.push_back(std::make_unique<U>(element));
	}

	void remove(const T& element)
	{
		for (auto it = m_list.begin(); it != m_list.end(); ++it)
			if (&(*(*it)) == &element)
			{
				m_list.erase(it);
				break;
			}
	}

	void remove(unsigned int index)
	{
		m_list.erase(m_list.begin() + index);
	}

	void clear()
	{
		m_list.clear();
	}

	bool empty() const
	{
		return m_list.empty();
	}

	bool contains(const T& element) const
	{
		for (int i = 0; i < size(); i++)
			if (&(*this)[i] == &element)
				return true;

		return false;
	}

	size_t size() const
	{
		return m_list.size();
	}
};

#endif
