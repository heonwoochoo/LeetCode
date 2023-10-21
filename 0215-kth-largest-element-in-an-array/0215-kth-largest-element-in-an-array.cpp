class Solution {
public:
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int i = left;
        int j = mid + 1;
        vector<int> merge;
        while (i <= mid && j <= right)
        {
            if (nums[i] < nums[j])
            {
                merge.push_back(nums[i]);
                i++;
            }
            else
            {
                merge.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            merge.push_back(nums[i]);
            i++;
        }

        while (j <= right)
        {
            merge.push_back(nums[j]);
            j++;
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = merge[i - left];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);

        return nums[n - k];
    }
};