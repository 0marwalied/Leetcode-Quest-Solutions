class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>isPrime(right + 1, 1), primes;
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i; j <= right; j += i) isPrime[j] = 0;
            }
        }
        int mn = INT_MAX, ans1(-1), ans2(-1);
        for (int i = 1; i < primes.size(); i++) {
            if (mn > primes[i] - primes[i - 1] && left <= primes[i - 1] && primes[i] <= right) {
                mn = primes[i] - primes[i - 1];
                ans1 = primes[i - 1], ans2 = primes[i];
            }
        }
        return {ans1, ans2};
    }
};