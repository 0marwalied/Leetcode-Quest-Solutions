class Solution {
public:
    int countPrimes(int n) {
        vector<int>isPrime(max(2, n ), 1); int primes(0);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                primes++;
                for (int j = i; j < n; j += i)isPrime[j] = 0;
            }
        }
        return primes;
    }
};