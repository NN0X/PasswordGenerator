#ifndef CLI_H
#define CLI_H

#include <string>

struct Settings
{
	bool exit;
	int numPasswords;
	int numWords;
	std::string language;
	std::string separator;
	bool style;
	int targetLength;
	bool verbose;
};

Settings parseArgs(int argc, char** argv);

#endif // CLI_H
