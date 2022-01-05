#ifndef PTRLIST_HPP
#define PTRLIST_HPP

#include <vector>
#include <memory>

template<typename T>
class PtrList
{
private:

	std::vector<std::unique_ptr<T>> m_list;

public:

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
		return m_list.begin();
	}

	auto end()
	{
		return m_list.end();
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
