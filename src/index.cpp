#include <iostream>
#include <vector>

void makeIndexesUnique(std::vector<int>& indexes, bool verbose=false)
{
	if (verbose)
	{
		std::cout << "Making indexes unique\n";
	}
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

	if (verbose)
	{
		std::cout << "Indexes made unique\n";
	}
}

int generateRandomIndex(int maxIndex, int min=0, bool verbose=false)
{
	if (verbose)
	{
		std::cout << "Generating random index\n";
	}
	int index = rand() % (maxIndex - min) + min;
	if (verbose)
	{
		std::cout << "Generated index " << index << "\n";
	}
	return index;
}

std::vector<int> generateRandomIndexes(int count, int maxIndex, int min=0, bool verbose=false)
{
	if (verbose)
	{
		std::cout << "Generating random indexes\n";
	}
	std::vector<int> indexes;
	indexes.reserve(count);
	for (int i = 0; i < count; i++)
	{
		indexes.push_back(generateRandomIndex(maxIndex, min));
	}
	if (verbose)
	{
		std::cout << "Generated " << count << " indexes\n";
	}

	return indexes;
}
