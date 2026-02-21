class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // int N = 1000009; 
        // vector<bool> isPrime(N+1, true);
        // isPrime[0] = isPrime[1] = false;

        // for(int i = 2; i*i <= N; i++) {
        //     if(isPrime[i]) {
        //         for(int j = i*i; j <= N; j += i) {
        //             isPrime[j] = false;
        //         }
        //     }
        // }


        // int ans = 0;
        // for(int i=left; i<=right; i++){
        //     if(isPrime[__builtin_popcount(i)] == true) ans++;
        // }

        // return ans;

        // since, max num is 10^6, max bit can be around floor(log2(right)) + 1

        unordered_set<int> primes = {2,3,5,7,11,13,17,19};
        int ans = 0;
        for(int i = left; i <= right; i++)
            if(primes.count(__builtin_popcount(i))) ans++;
        return ans;
    }
};
