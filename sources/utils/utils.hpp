#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string remove_spaces(const std::string& str);

inline std::string to_str(const std::string_view& str)
{
	return std::string(str.data(), str.size());
}

template <typename T>
inline std::string to_str(const T& object)
{
	return std::to_string(object);
}

inline int random_int(int min, int max)
{
	return min + (rand() % (max - min));
}

#endif
