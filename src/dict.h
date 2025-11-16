#ifndef DICT_H
#define DICT_H

#include <string>
#include <vector>

#include "intredef.h"

int loadDictionaryIndex(const std::string& lang, bool verbose=false, std::string binary="");
std::vector<std::string> loadWordsFromDictionary(const std::string& lang, std::vector<int>& indexes, bool verbose=false, std::string binary="");

#endif // DICT_H
