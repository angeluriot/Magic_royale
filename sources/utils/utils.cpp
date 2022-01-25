#include "utils/utils.hpp"

std::string remove_spaces(const std::string& str)
{
	int i = 0;

	while (i < (int)str.size() && (str[i] == ' ' || str[i] == '\t'))
		i++;

	int j = (int)str.size() - 1;

	while (j >= 0 && (str[j] == ' ' || str[j] == '\t'))
		j--;

	return str.substr(i, j - i + 1);
}
