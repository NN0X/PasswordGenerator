#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "index.h"
#include "defines.h"

char loadSimilar(char letter)
{
	std::string letterStr(1, letter);
	std::string path = "resources/" SIMILARITIES_PATH + letterStr;
	std::ifstream file(path);
	std::vector<std::string> allSimilar;
	std::string line;
	while (std::getline(file, line))
	{
		allSimilar.push_back(line);
	}
	file.close();

	int index = generateRandomIndex(allSimilar.size());

	return allSimilar[index][0];
}

std::string styleWord(const std::string& word)
{
	int count = generateRandomIndex(word.size());
	std::vector<int> indexesChanged;
	indexesChanged.reserve(count);

	std::string styledWord = word;
	while (count > 0)
	{
		int index = generateRandomIndex(word.size());
		auto it = std::find(indexesChanged.begin(), indexesChanged.end(), index);
		if (it == indexesChanged.end())
		{
			char styledLetter;
			if (SIMILAR.find(word[index]) != std::string::npos)
			{
				styledLetter = loadSimilar(word[index]);
			}
			else
			{
				styledLetter = std::toupper(word[index]);
			}

			styledWord[index] = styledLetter;

			indexesChanged.push_back(index);
			count--;
		}
	}

	return styledWord;
}

std::vector<std::string> styleWords(const std::vector<std::string>& words)
{
	std::vector<std::string> styledWords;
	styledWords.reserve(words.size());
	for (size_t i = 0; i < words.size(); i++)
	{
		styledWords.push_back(styleWord(words[i]));
	}

	return styledWords;
}

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
