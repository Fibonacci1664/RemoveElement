#include<iostream>
#include <vector>
#include <algorithm>

int removeElement(std::vector<int>& nums, int val)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	// Create an iterator to hold the new off the end pos
	// Removing the value as we go
	auto it = std::remove(nums.begin(), nums.end(), val);

	// Resize the vector to the new size
	nums.resize(std::distance(nums.begin(), it));

	return nums.size();
}

int altRemoveElement(std::vector<int>& nums, int val)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	// Create a var to hold the slow-ruuner
	int i = 0;

	// Loop over the vector
	for (int j = 0; j < nums.size(); ++j)
	{
		// If the value at curr index is not what we're looking for
		if (nums[j] != val)
		{
			// These will either be pointing to the same index
			// in which case this assignment wont make a difference
			// Or, it will swap out the val to remove with whatever is at index j
			nums[i] = nums[j];
			++i;
		}
	}

	// Resize to remove any tail end vals
	nums.resize(i);

	return nums.size();
}

int main()
{
	std::vector<int> numVec {1, 2, 4, 1, 0, 2, 3, 1, 1};
	//std::vector<int> numVec { 3, 2, 2, 3 };

	//int ans = removeElement(numVec, 1);
	int ans = altRemoveElement(numVec, 1);

	std::cout << "ans = " << ans << '\n';

	for (int i = 0; i < numVec.size(); ++i)
	{
		std::cout << "[ " << numVec[i] << " ], ";
	}

	return 0;
}