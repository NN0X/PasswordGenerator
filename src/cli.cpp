#include <iostream>

#include "cli.h"
#include "defines.h"

Settings parseArgs(int argc, char** argv)
{
	Settings settings;
	settings.exit = false;
	settings.numPasswords = DEFAULT_NUM_PASSWORDS;
	settings.numWords = DEFAULT_NUM_WORDS;
	settings.language = DEFAULT_LANGUAGE;
	settings.separator = DEFAULT_SEPARATOR;
	settings.style = DEFAULT_STYLE;
	settings.targetLength = DEFAULT_TARGET_LENGTH;
	settings.verbose = DEFAULT_VERBOSE;

	if (argc == 1)
	{
		return settings;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if (arg == "-h" || arg == "--help")
		{
			std::cout << "Usage: " << argv[0] << " [options]\n";
			std::cout << "Options:\n";
			std::cout << "  -h, --help\t\tShow this help message\n";
			std::cout << "  -w, --num-words\tNumber of words to generate\n";
			std::cout << "  -l, --language\tLanguage of the words\n";
			std::cout << "  -s, --separator\tSeparator between words\n";
			std::cout << "  -S, --style\t\tStyle the words\n";
			std::cout << "  -p, --num-passwords\tNumber of passwords to generate\n";
			std::cout << "  -t, --target-length\tMinimum length of the password\n";
			std::cout << "  -v, --verbose\t\tVerbose mode\n";
			settings.exit = true;
			return settings;
		}
		else if (arg == "-w" || arg == "--num-words")
		{
			if (i + 1 < argc)
			{
				settings.numWords = std::stoi(argv[i + 1]);
				i++;
			}
			else
			{
				std::cerr << "Number of words must be specified\n";
				settings.exit = true;
				return settings;
			}
			if (settings.numWords < 1)
			{
				std::cerr << "Number of words must be greater than 0\n";
				settings.exit = true;
				return settings;
			}
			if (settings.targetLength != -1)
			{
				std::cerr << "Cannot specify both number of words and target length\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-l" || arg == "--language")
		{
			if (i + 1 < argc)
			{
				settings.language = argv[i + 1];
				i++;
			}
			if (settings.language.empty())
			{
				std::cerr << "Language cannot be empty\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-s" || arg == "--separator")
		{
			if (i + 1 < argc)
			{
				settings.separator = argv[i + 1];
				i++;
			}
			if (settings.separator.empty())
			{
				std::cerr << "Separator cannot be empty\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-S" || arg == "--style")
		{
			if (i + 1 < argc)
			{
				std::string style = argv[i + 1];
				if (style == "1" || style == "true" || style == "TRUE" || style == "True" || style == "yes" || style == "YES" || style == "Yes")
				{
					settings.style = true;
				}
				else if (style == "0" || style == "false" || style == "FALSE" || style == "False" || style == "no" || style == "NO" || style == "No")
				{
					settings.style = false;
				}
				else
				{
					std::cerr << "Style must be a boolean value\n";
					settings.exit = true;
					return settings;
				}
				i++;
			}
			else
			{
				std::cerr << "Style must be specified\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-p" || arg == "--num-passwords")
		{
			if (i + 1 < argc)
			{
				settings.numPasswords = std::stoi(argv[i + 1]);
				i++;
			}
			else
			{
				std::cerr << "Number of passwords must be specified\n";
				settings.exit = true;
				return settings;
			}
			if (settings.numPasswords < 1)
			{
				std::cerr << "Number of passwords must be greater than 0\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-t" || arg == "--target-length")
		{
			if (i + 1 < argc)
			{
				settings.targetLength = std::stoi(argv[i + 1]);
				i++;
			}
			else
			{
				std::cerr << "Target length must be specified\n";
				settings.exit = true;
				return settings;
			}
			if (settings.targetLength < MIN_PASSWORD_LENGTH)
			{
				std::cerr << "Target length must be at least " << MIN_PASSWORD_LENGTH << "\n";
				settings.exit = true;
				return settings;
			}
		}
		else if (arg == "-v" || arg == "--verbose")
		{
			settings.verbose = true;
		}
		else
		{
			std::cerr << "Unknown option: " << arg << "\n";
			settings.exit = true;
			return settings;
		}
	}

	return settings;
}
