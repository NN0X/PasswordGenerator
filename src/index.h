#ifndef INDEX_H
#define INDEX_H

#include <vector>

void makeIndexesUnique(std::vector<int>& indexes, bool verbose=false);
int generateRandomIndex(int maxIndex, int min=0, bool verbose=false);
std::vector<int> generateRandomIndexes(int count, int maxIndex, int min=0, bool verbose=false);

#endif // INDEX_H
