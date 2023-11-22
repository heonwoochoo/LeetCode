class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        char target = colors[0];
        int maxCost = neededTime[0];

        for (int i = 1; i < colors.size(); i++)
        {
            if (target == colors[i])
            {
                if (maxCost >= neededTime[i]) sum += neededTime[i];
                else
                {
                    sum += maxCost;
                    maxCost = neededTime[i];
                }
            }
            else
            {
                target = colors[i];
                maxCost = neededTime[i];
            }
        }

        return sum;
    }
};