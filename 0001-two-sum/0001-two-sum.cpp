#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool Pred(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	return lhs.first < rhs.first;
}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<pair<int, int>> pairs;
		pairs.resize(nums.size());
		for (int i = 0; i < nums.size(); ++i)
		{
			pairs[i] = {nums[i],i};
		}
		sort(pairs.begin(), pairs.end(), Pred);

		int p1 = 0;
		int p2 = nums.size() - 1;

		while (p1 != p2)
		{
			int sum = pairs[p1].first + pairs[p2].first;
			if (sum == target)
			{
				return vector<int>{pairs[p1].second, pairs[p2].second};
			}
			else if (sum > target)
			{
				p2--;
			}
			else // sum < target
			{
				p1++;
			}
		}
		return vector<int>{};
	}
};