#include <iostream>

#include "index.h"
#include "dict.h"
#include "password.h"
#include "cli.h"
#include "defines.h"

#include "intredef.h"

#undef int
int main(int argc, char **argv)
{
#define int uint64_t
	
	Settings settings = parseArgs(argc, argv);
	if (settings.exit)
	{
		return 0;
	}

	int maxIndex = loadDictionaryIndex(settings.language, settings.verbose, settings.binary);

	for (int i = 0; i < settings.numPasswords; i++)
	{
		if (settings.verbose)
		{
			std::cout << "Generating password " << i + 1 << " of " << settings.numPasswords << "\n";
		}
		if (settings.targetLength != -1)
		{
			settings.numWords = settings.targetLength / MIN_PASSWORD_LENGTH;
			if (settings.verbose)
			{
				std::cout << "Target length set, generating " << settings.numWords << " words\n";
			}
		}
		if (settings.verbose)
		{
			std::cout << "Generating " << settings.numWords << " words\n";
		}
		std::vector<int> indexes = generateRandomIndexes(settings.numWords, maxIndex, settings.verbose);
		std::vector<std::string> words = loadWordsFromDictionary(settings.language, indexes, settings.verbose, settings.binary);
		
		if (settings.style)
		{
			words = styleWords(words, settings.verbose, settings.binary);
		}
		std::string combined = combineWords(words, settings.separator, settings.verbose);
		if (combined.size() + settings.numWords - 1 < settings.targetLength && settings.targetLength != -1)
		{
			i--;
			if (settings.verbose)
			{
				std::cout << "Password target length: " << settings.targetLength << " is not greater than generated length: " << combined.size() + settings.numWords - 1 << ", regenerating\n";
			}
		}
		else
		{
			std::cout << combined << "\n";
		}
	}
	return 0;
}
