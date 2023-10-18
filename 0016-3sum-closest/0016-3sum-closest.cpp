class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minOffset = 1000000;
        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            while (p1 < p2)
            {
                int sum = nums[i] + nums[p1] + nums[p2];
                int offset = abs(target - sum);
                if (offset < minOffset)
                {
                    minOffset = offset;
                    res = sum;
                }
                if (sum > target)
                {
                    p2--;
                }
                else if (sum < target)
                {
                    p1++;
                }
                else // sum == target
                {
                    return sum;
                }
            }
        }

        return res;
    }
};