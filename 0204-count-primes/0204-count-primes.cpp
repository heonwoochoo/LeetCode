bool primes[5000001];
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        memset(primes, true, sizeof(bool) * n);
        if (n <= 1) return 0;

        for (int i = 2; i < sqrt(n); i++)
        {
            if (primes[i] == true)
            {
                for (int j = i + i; j < n; j += i)
                {
                    primes[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (primes[i] == true) count++;
        }

        return count;
    }
};