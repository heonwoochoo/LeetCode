int cnt[3];
class Solution {
public:
    void sortColors(vector<int>& nums) {
        memset(cnt, 0, sizeof(int) * 3);
        for (auto num : nums)
        {
            cnt[num]++;
        }
        for (auto& num : nums)
        {
            if (cnt[0] > 0)
            {
                num = 0;
                cnt[0]--;
            }
            else if (cnt[1] > 0)
            {
                num = 1;
                cnt[1]--;
            }
            else // cnt[2] >0
            {
                num = 2;
                cnt[2]--;
            }
        }
    }
};