#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "index.h"
#include "defines.h"

char loadSimilar(char letter, bool verbose=false, const std::string& binary="")
{
        std::string letterStr(1, letter);
        std::string path = std::string(binary) + std::string("/resources/") + SIMILARITIES_PATH + letterStr;
        if (verbose)
        {
                std::cout << "Loading similar letters from " << path << "\n";
        }
        std::ifstream file(path);
        std::vector<std::string> allSimilar;
        std::string line;
        while (std::getline(file, line))
        {
                allSimilar.push_back(line);
        }
        file.close();

        int index = generateRandomIndex(allSimilar.size());

        if (verbose)
        {
                std::cout << "Loaded similar letter " << allSimilar[index][0] << "\n";
        }
        return allSimilar[index][0];
}

std::string styleWord(const std::string& word, bool verbose=false, const std::string& binary="")
{
        if (verbose)
        {
                std::cout << "Styling word\n";
        }
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
                                styledLetter = loadSimilar(word[index], verbose, binary);
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

        if (verbose)
        {
                std::cout << "Styled word: " << styledWord << "\n";
        }

        return styledWord;
}

std::vector<std::string> styleWords(const std::vector<std::string>& words, bool verbose=false, const std::string& binary="")
{
        if (verbose)
        {
                std::cout << "Styling words\n";
        }
        std::vector<std::string> styledWords;
        styledWords.reserve(words.size());
        for (size_t i = 0; i < words.size(); i++)
        {
                styledWords.push_back(styleWord(words[i], verbose, binary));
        }

        if (verbose)
        {
                std::cout << "Styled words\n";
        }
        return styledWords;
}

std::string combineWords(const std::vector<std::string>& words, const std::string& separator, bool verbose=false)
{
        if (verbose)
        {
                std::cout << "Combining words\n";
        }
        std::string combined = "";
        for (size_t i = 0; i < words.size(); i++)
        {
                combined += words[i];
                if (i != words.size() - 1)
                {
                        combined += separator;
                }
        }

        if (verbose)
        {
                std::cout << "Combined words\n";
        }
        return combined;
}
