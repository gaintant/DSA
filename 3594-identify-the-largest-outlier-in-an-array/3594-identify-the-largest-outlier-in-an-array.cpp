class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        set<int> s;
        map<int, int> mp;
        for(auto ele : nums){
            sum += ele;
            s.insert(ele);
            mp[ele]++;
        }
        for(auto ele : nums){
            if(s.find(sum - 2*ele) != s.end() && (sum - 2*ele != ele || mp[ele] != 1))
                ans = max(sum - 2*ele, ans);
        }
        return ans;
    }
};