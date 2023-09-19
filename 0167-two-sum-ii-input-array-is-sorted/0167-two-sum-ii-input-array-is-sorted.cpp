class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
		int p2 = numbers.size() - 1;
		while (p1 != p2)
		{
			int sum = numbers[p1] + numbers[p2];
			if (sum == target) return vector<int>{p1 + 1, p2 + 1};
			else if (sum < target) p1++;
			else p2--;
		}
		return vector<int>{};
    }
};