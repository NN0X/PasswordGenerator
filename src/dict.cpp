#include <iostream>

#include <fstream>
#include <vector>
#include <algorithm>

#include "index.h"
#include "defines.h"

int loadDictionaryIndex(const std::string& lang, bool verbose=false, const std::string& binary="")
{
        std::string path = std::string(binary) + std::string("/resources/") + DICTIONARY_PATH + lang;
        if (verbose)
        {
                std::cout << "Loading dictionary from " << path << "\n";
        }
        std::ifstream file(path);
        int maxIndex = 0;
        std::string line;
        while (std::getline(file, line))
        {
                for (size_t i = 0; i < line.size(); i++)
                {
                        if (line[i] == ',')
                        {
                                maxIndex++;
                        }
                }
        }
        file.close();

        if (verbose)
        {
                std::cout << "Dictionary loaded with " << maxIndex << " words\n";
        }
        return maxIndex;
}

std::vector<std::string> loadWordsFromDictionary(const std::string& lang, std::vector<int>& indexes,
                                                 bool verbose=false, const std::string& binary="")
{
        if (verbose)
        {
                std::cout << "Loading words from dictionary\n";
        }
        std::string path = std::string(binary) + std::string("/resources/") + DICTIONARY_PATH + lang;
        std::ifstream file(path);
        std::vector<std::string> words;
        words.reserve(indexes.size());
        std::string line;
        int index = 0;
        while (std::getline(file, line))
        {
                std::vector<std::string> splitted;
                std::string word = "";
                for (size_t i = 0; i < line.size(); i++)
                {
                        if (line[i] == ',')
                        {
                                splitted.push_back(word);
                                word = "";
                        }
                        else
                        {
                                word += line[i];
                        }
                }
                splitted.push_back(word);

                for (size_t i = 0; i < splitted.size(); i++)
                {
                        auto it = std::find(indexes.begin(), indexes.end(), index + i);
                        int j = std::distance(indexes.begin(), it);
                        if (it != indexes.end())
                        {
                                if (splitted[i].size() < MIN_WORD_LENGTH || splitted[i].size() > MAX_WORD_LENGTH)
                                {
                                        indexes[j] += 1;
                                        makeIndexesUnique(indexes);
                                }
                                else
                                {
                                        words.push_back(splitted[i]);
                                }
                        }
                }
                index += splitted.size();
        }
        file.close();

        if (verbose)
        {
                std::cout << "Words loaded\n";
        }

        return words;
}
