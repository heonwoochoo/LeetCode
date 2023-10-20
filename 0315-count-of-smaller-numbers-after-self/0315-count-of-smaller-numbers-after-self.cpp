class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> indexedNums;
        indexedNums.resize(n);

        for (int i = 0; i < n; i++)
        {
            indexedNums[i] = { nums[i], i };
        }
        
        mergeSort(indexedNums, 0, n - 1, result);

        return result;
    }

    void mergeSort(vector<pair<int, int>>& indexedNums, int left, int right, vector<int>& result) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(indexedNums, left, mid, result);
        mergeSort(indexedNums, mid + 1, right, result);

        vector<pair<int, int>> merged;
        int i = left;
        int j = mid + 1;
        int cnt = 0;

        while (i <= mid && j <= right)  
        {
            if (indexedNums[i].first > indexedNums[j].first)
            {
                merged.push_back(indexedNums[j]);
                cnt++;
                j++;
            }
            else
            {
                merged.push_back(indexedNums[i]);
                result[indexedNums[i].second] += cnt;
                i++;
            }
        }

        while (i <= mid)
        {
            result[indexedNums[i].second] += cnt;
            merged.push_back(indexedNums[i]);
            i++;
        }

        while (j <= right)
        {
            merged.push_back(indexedNums[j]);
            j++;
        }

        for (int i = left; i <= right; ++i)
        {
            indexedNums[i] = merged[i - left];
        }
    }
};