#ifndef PTRLIST_HPP
#define PTRLIST_HPP

#include <vector>
#include <iterator>
#include <cstddef>

/**
 * @brief Free the memory of a pointer.
 *
 * @tparam T the pointer type
 * @param ptr the pointer to free
 */
template <typename T>
void free_memory(T*& ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

/**
 * @brief Class to manage a list of pointers.
 *
 * @tparam T the pointer type
 */
template<typename T>
class PtrList
{
private:

	std::vector<T*> m_list;	// The list of pointers.

public:

	/**
	 * @brief A iterator for PtrList.
	 */
	class Iterator
	{
	public:

		using iterator_category	= std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type		= T;
		using pointer			= value_type*;
		using reference			= value_type&;

	private:

		size_t m_index;		// The current index.
		PtrList<T>& m_list;	// The list.

	public:

		/**
		 * @brief Construct a new Iterator object.
		 *
		 * @param index the current index
		 * @param list the list
		 */
		Iterator(size_t index, PtrList<T>& list): m_index(index), m_list(list) {}

		/**
		 * @brief Operator *.
		 *
		 * @return a reference to the current element
		 */
		reference operator*() const { return m_list[m_index]; }

		/**
		 * @brief Operator ->.
		 *
		 * @return a pointer to the current element
		 */
		pointer operator->() { return &(m_list[m_index]); }

		/**
		 * @brief Operator ++.
		 *
		 * @return a reference to the next element
		 */
		Iterator& operator++() { m_index++; return *this; }

		/**
		 * @brief Operator ++.
		 *
		 * @return a copy of the element before incrementing
		 */
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		/**
		 * @brief Operator ==.
		 *
		 * @param other the iterator to compare
		 * @return true if the iterators are equal
		 */
		bool operator==(const Iterator& other) { return m_index == other.m_index && &m_list == &other.m_list; }

		/**
		 * @brief Operator !=.
		 *
		 * @param other the iterator to compare
		 * @return true if the iterators are not equal
		 */
		bool operator!=(const Iterator& other) { return !(*this == other); }
	};

	/**
	 * @brief Construct a new PtrList object.
	 */
	PtrList()
	{
		clear();
	}

	/**
	 * @brief Construct a new PtrList object.
	 *
	 * @param ptrlist the list to copy
	 */
	PtrList(const PtrList<T>& ptrlist)
	{
		*this = ptrlist;
	}

	/**
	 * @brief Construct a new Ptr List object.
	 *
	 * @param ptrlist the list take the resources from
	 */
	PtrList(const PtrList<T>&& ptrlist)
	{
		*this = ptrlist;
	}

	/**
	 * @brief Destroy the Ptr List object.
	 */
	~PtrList()
	{
		clear();
	}

	/**
	 * @brief Operator =.
	 *
	 * @param ptrlist the list to copy
	 * @return a reference to the changed object
	 */
	PtrList<T>& operator=(const PtrList<T>& ptrlist)
	{
		clear();

		for (int i = 0; i < (int)ptrlist.size(); i++)
			add(ptrlist[i]);

		return *this;
	}

	/**
	 * @brief Operator =.
	 *
	 * @param ptrlist the list to take the resources from
	 * @return a reference to the changed object
	 */
	PtrList<T>& operator=(const PtrList<T>&& ptrlist)
	{
		clear();
		m_list = ptrlist.m_list;
		ptrlist.m_list.clear();
		return *this;
	}

	/**
	 * @brief Operator [].
	 *
	 * @param index the index of the element
	 * @return a reference to the element
	 */
	T& operator[](size_t index)
	{
		return *m_list[index];
	}

	/**
	 * @brief Operator [].
	 *
	 * @param index the index of the element
	 * @return a reference to the element
	 */
	const T& operator[](size_t index) const
	{
		return *m_list[index];
	}

	/**
	 * @brief Operator ==.
	 *
	 * @param other the list to compare
	 * @return true if the lists are equal
	 */
	bool operator==(const PtrList<T>& other)
	{
		return m_list == other.m_list;
	}

	/**
	 * @brief Operator !=.
	 *
	 * @param other the list to compare
	 * @return true if the lists are not equal
	 */
	bool operator!=(const PtrList<T>& other)
	{
		return m_list != other.m_list;
	}

	/**
	 * @brief Return an iterator to the first element.
	 *
	 * @return the iterator
	 */
	Iterator begin()
	{
		return Iterator(0, *this);
	}

	/**
	 * @brief Return an iterator after the last element.
	 *
	 * @return the last element
	 */
	Iterator end()
	{
		return Iterator(static_cast<size_t>(m_list.size()), *this);
	}

	/**
	 * @brief Add an element to the list.
	 *
	 * @tparam U the ype of the element
	 * @param element the element to add
	 */
	template <typename U>
	void add(const U& element)
	{
		m_list.push_back((T*)element.clone());
	}

	/**
	 * @brief Remove an element from the list.
	 *
	 * @param element the element to remove
	 */
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

	/**
	 * @brief Remove an element from the list.
	 *
	 * @param index the index of the element to remove
	 */
	void remove(size_t index)
	{
		free_memory(m_list[index]);
		m_list.erase(m_list.begin() + index);
	}

	/**
	 * @brief Swap two elements in the list.
	 *
	 * @param index_1 the index of the first element
	 * @param index_2 the index of the second element
	 */
	void swap(size_t index_1, size_t index_2)
	{
		if (index_1 != index_2)
			std::swap(m_list[index_1], m_list[index_2]);
	}

	/**
	 * @brief Clear the list.
	 */
	void clear()
	{
		for (auto& element : m_list)
			free_memory(element);

		m_list.clear();
	}

	/**
	 * @brief Check if the list is empty.
	 *
	 * @return true if the list is empty
	 */
	bool empty() const
	{
		return m_list.empty();
	}

	/**
	 * @brief Check if the list contains an element.
	 *
	 * @param element the element to check
	 * @return true if the list contains the element
	 */
	bool contains(const T& element) const
	{
		for (int i = 0; i < size(); i++)
			if (m_list[i] == &element)
				return true;

		return false;
	}

	/**
	 * @brief Return the size of the list.
	 *
	 * @return the size of the list
	 */
	size_t size() const
	{
		return m_list.size();
	}

	/**
	 * @brief Return the last element of the list.
	 *
	 * @return the last element of the list
	 */
	T& back()
	{
		return *m_list.back();
	}

	/**
	 * @brief Return the last element of the list.
	 *
	 * @return the last element of the list
	 */
	const T& back() const
	{
		return *m_list.back();
	}

	/**
	 * @brief Return the first element of the list.
	 *
	 * @return the first element of the list
	 */
	T& front()
	{
		return *m_list.front();
	}

	/**
	 * @brief Return the first element of the list.
	 *
	 * @return the first element of the list
	 */
	const T& front() const
	{
		return *m_list.front();
	}
};

#endif
