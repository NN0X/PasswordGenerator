#ifndef INDEX_H
#define INDEX_H

#include <vector>

void makeIndexesUnique(std::vector<int>& indexes);
int generateRandomIndex(int maxIndex, int min=0);
std::vector<int> generateRandomIndexes(int count, int maxIndex, int min=0);

#endif // INDEX_H
