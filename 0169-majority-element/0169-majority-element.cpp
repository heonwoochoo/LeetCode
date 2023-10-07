class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (auto num : nums)
        {
            mp[num]++;
        }

        pair<int,int> p = {0,0};
        for (auto& e : mp)
        {
            if (p.second < e.second)
            {
                p.first = e.first;
                p.second = e.second;
            }
        }

        return p.first;
    }
};