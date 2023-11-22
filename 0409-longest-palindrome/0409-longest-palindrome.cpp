int arr[200];
class Solution {
public:
    int longestPalindrome(string s) {
        memset(arr, 0, sizeof(int) * 200);
        int cnt = 0;
        bool odd = false;

        for (char c : s)
        {
            arr[c]++;
        }

        for (int i = 'A'; i <= 'z'; i++)
        {
            if (arr[i] % 2 == 0)
            {
                cnt += arr[i];
            }
            else
            {
                odd = true;
                cnt += (arr[i] - 1);
            }
        }
        if (odd) cnt++;
        return cnt;
    }
};