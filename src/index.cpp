#include <iostream>
#include <vector>

void makeIndexesUnique(std::vector<int>& indexes)
{
	for (size_t i = 0; i < indexes.size(); i++)
	{
		for (size_t j = i + 1; j < indexes.size(); j++)
		{
			if (indexes[i] == indexes[j])
			{
				indexes[j] += 1;
			}
		}
	}
}

int generateRandomIndex(int maxIndex, int min=0)
{
	return rand() % (maxIndex - min) + min;
}

std::vector<int> generateRandomIndexes(int count, int maxIndex, int min=0)
{
	std::vector<int> indexes;
	indexes.reserve(count);
	for (int i = 0; i < count; i++)
	{
		indexes.push_back(generateRandomIndex(maxIndex, min));
	}

	return indexes;
}
