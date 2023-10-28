class Solution {
public:
    void DFS(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& arr, int sum, int index)
    {
        sum += candidates[index];
        arr.push_back(candidates[index]);

        if (sum > target) return;
        else if (sum == target)
        {
            res.push_back(arr);
            return;
        }
        else
        {
            for (int i = index; i < candidates.size(); i++)
            {
                DFS(res, candidates, target, arr, sum, i);
                arr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {        

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> arr;
        for (int i = 0; i < candidates.size(); i++)
        {
            DFS(res, candidates, target, arr, 0, i);
            arr.pop_back();
        }

        return res;
    }
};