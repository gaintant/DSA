class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 =0, sum2=0;
        bool change1 = false , change2 = false;
        for(auto num : nums1){
            if(num == 0){
                change1 = true;
                sum1++;
            }
            else
                sum1 += num;    
        }
        for(auto num : nums2){
            if(num == 0){
                change2 = true;
                sum2++;
            }
            else
                sum2 += num;
        }
        if(sum1 == sum2)
            return sum1;
        if(sum1 > sum2)
            return change2 ? sum1 : -1;    
        return change1 ? sum2 : -1;
    }
};