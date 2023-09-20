class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr.insert(arr.begin(), nums.begin(), nums.end());
        sums.resize(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sums[right] - sums[left] + arr[left];
    }

    vector<int> arr;
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */