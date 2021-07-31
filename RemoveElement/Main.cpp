#include<iostream>
#include <vector>
#include <algorithm>

int removeElement(std::vector<int>& nums, int val)
{
	// Create an iterator to hold the new off the end pos
	// Removing the value as we go
	auto it = std::remove(nums.begin(), nums.end(), val);

	// Resize the vector to the new size
	nums.resize(std::distance(nums.begin(), it));

	return nums.size();
}

int main()
{
	std::vector<int> numVec {1, 2, 4, 7, 0, 2, 3, 1, 1};
	int ans = removeElement(numVec, 1);

	std::cout << "ans = " << ans << '\n';

	for (int i = 0; i < numVec.size(); ++i)
	{
		std::cout << "[ " << numVec[i] << " ], ";
	}

	return 0;
}