#include <iostream>
#include <vector>


int remove_elem(std::vector<int>& nums, int val)
{
	int k = 0;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] == val)
		{
			nums.erase(nums.begin() + i);
		}
		k++;
	}
	for (auto elements : nums)
	{
		std::cout << elements;
	}
	std::cout << std::endl;
	return k;
}

int main()
{
	std::vector<int> vec = { 3, 2, 2, 3};
	std::cout << remove_elem(vec, 3);
	
	return 0;
}
