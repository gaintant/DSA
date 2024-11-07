class Solution {
public:
    int bitCount(int num){
        int reqBits = 0;
        for(int j=0; j<31; j++){
            if(num& (1 << j))
                reqBits++;
        }
        return reqBits;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int oldMax = INT_MIN;
        while(i <n){
            int newMax = INT_MIN;
            int newMin = INT_MAX;
            int reqBit = bitCount(nums[i]);
            int c = reqBit;
            while(i < n && c == reqBit){
                newMax = max(newMax, nums[i]);
                newMin = min(newMin, nums[i]);

                i++;
                if(i < n)
                    c = bitCount(nums[i]);
            }
            if(newMin < oldMax)
                return false;
            oldMax = newMax;
        }
        return true;
    }
};