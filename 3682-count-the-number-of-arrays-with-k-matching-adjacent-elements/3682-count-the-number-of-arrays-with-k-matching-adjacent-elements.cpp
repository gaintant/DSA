class Solution {
public:
    long long modPow(long long base, long long exponent, long long mod) {
        long long result = 1;  
        base = base % mod;  
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            exponent = exponent >> 1;
            base = (base * base) % mod;
        }
        return result;
    }
    long long nCk(int n, int k, int mod) {
        if (k > n || k < 0) return 0;

        long long numerator = 1; 
        long long denominator = 1; 

        for (int i = 0; i < k; i++) {
            numerator = (numerator * (n - i)) % mod; 
            denominator = (denominator * (i + 1)) % mod; 
        }

        long long denominatorInverse = modPow(denominator, mod - 2, mod);

        return (numerator * denominatorInverse) % mod;
    }

    int countGoodArrays(int n, int m, int k) {
        int mod = 1e9 + 7;
        if(m == 1){
            if(n == k +1)
                return 1;
            else
                return 0;
        }
        long long ans = m;
        ans = (ans *modPow((long long)m-1, (long long)n - k - 1,(long long) mod))%mod;
        ans = (ans *nCk(n-1, k, mod))%mod;
        return ans;    
    }
};