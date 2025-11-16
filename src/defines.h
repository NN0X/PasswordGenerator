#ifndef DEFINES_H
#define DEFINES_H

#define DICTIONARY_PATH "dictionaries/"
#define SIMILARITIES_PATH "similarities/"

#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 4
#define MIN_PASSWORD_LENGTH 10

#include "intredef.h"

const inline std::string SIMILAR = "aeios";

const inline int DEFAULT_NUM_PASSWORDS = 1;
const inline int DEFAULT_NUM_WORDS = 4;
const inline std::string DEFAULT_LANGUAGE = "pl";
const inline std::string DEFAULT_SEPARATOR = "_";
const inline bool DEFAULT_STYLE = true;
const inline int DEFAULT_TARGET_LENGTH = -1;
const inline bool DEFAULT_VERBOSE = false;

#endif // DEFINES_H
