#ifndef DICT_H
#define DICT_H

#include <string>
#include <vector>

int loadDictionaryIndex(const std::string& lang);
std::vector<std::string> loadWordsFromDictionary(const std::string& lang, std::vector<int>& indexes);

#endif // DICT_H
