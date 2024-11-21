#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <vector>

std::vector<std::string> styleWords(const std::vector<std::string>& words, bool verbose=false);
std::string combineWords(const std::vector<std::string>& words, const std::string& separator, bool verbose=false);

#endif // PASSWORD_H
