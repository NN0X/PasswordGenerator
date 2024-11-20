#include <vector>
#include <string>

std::string combineWords(const std::vector<std::string>& words, const std::string& separator)
{
	std::string combined = "";
	for (size_t i = 0; i < words.size(); i++)
	{
		combined += words[i];
		if (i != words.size() - 1)
		{
			combined += separator;
		}
	}

	return combined;
}
