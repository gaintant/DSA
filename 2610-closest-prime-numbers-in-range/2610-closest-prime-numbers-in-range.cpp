class Solution {
public:
    bool isPrime(int i){
        int l = sqrt(i);
        for(int j=2; j<=l; j++){
            if(i%j == 0)
                return false;
        }
        return true;
    } 
    vector<int> closestPrimes(int left, int right) {
        left = max(left, 2);
        int pre = -1;
        int ans = INT_MAX;
        vector<int> r = {-1,-1};
        for(long long i=left; i <= right; i++){
            if(isPrime(i)){
                if(pre != -1 && ans > i-pre){
                    ans = i-pre;
                    r = {pre, (int)i};
                }
                pre = i;
            }
        }
        return r; 
    }
};