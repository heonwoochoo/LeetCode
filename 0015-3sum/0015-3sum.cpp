#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> s;
		sort(nums.begin(), nums.end());

		int prevTarget = 0;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			int target = -nums[i];

			if (i > 0 && prevTarget == target) continue;

			int p1 = i + 1;
			int p2 = nums.size() - 1;
			while (p1 < p2)
			{
				int sum = nums[p1] + nums[p2];
				if (sum == target)
				{
					s.insert(vector<int>{nums[i], nums[p1], nums[p2]});
					p1++;
				}
				else if (sum < target)
				{
					p1++;
				}
				else
				{
					p2--;
				}
			}
			prevTarget = target;
		}

		vector<vector<int>> res;
		for (auto nums : s)
		{
			res.push_back(nums);
		}

		return res;
	}
};