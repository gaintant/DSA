class Solution {
public:
    vector<int> getPrime(){
        vector<bool> found(1001, false);
        for(int i=2; i<=1000; i++){
            if(!found[i]){
                int j = i*i;
                while(j <= 1000){
                    found[j] = true;
                    j += i;  
                }
            }
        }
        vector<int> primes;
        primes.push_back(0);
        for(int i=2; i<= 1000; i++){
            if(!found[i])
                primes.push_back(i);
        }
        return primes;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = getPrime();
        int pre = 0;
        for(auto num : nums){
            if(num <= pre)
                return false;
            int diff = num - pre;
            auto it = --lower_bound(primes.begin(), primes.end(), diff);
            pre = num - *it;
        }
        return true;   
    }
};