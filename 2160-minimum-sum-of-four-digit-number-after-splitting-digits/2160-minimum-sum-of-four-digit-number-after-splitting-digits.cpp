class Solution {
public:
    int minimumSum(int num) {
        array<int,4> arr;
        string numStr = to_string(num);
        for (int i = 0; i < 4; i++)
        {
            arr[i] = (int)numStr[i] - 48;
        }

        sort(arr.begin(), arr.end());

        int num1;
        int num2;

        num1 = arr[0] * 10 + arr[2];
        num2 = arr[1] * 10 + arr[3];

        return num1 + num2;
    }
};