#include <iostream>

#include "index.h"
#include "dict.h"
#include "password.h"
#include "defines.h"

int main()
{
	srand(time(NULL));
	int maxIndex = loadDictionaryIndex("pl");

	std::vector<int> indexes = generateRandomIndexes(4, maxIndex);
	std::vector<std::string> words = loadWordsFromDictionary("pl", indexes);

	words = styleWords(words);
	std::string combined = combineWords(words, "_");
	std::cout << combined << std::endl;
	return 0;
}
