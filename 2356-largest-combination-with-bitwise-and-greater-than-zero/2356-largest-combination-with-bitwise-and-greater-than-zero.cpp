class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // vector<int> b(32, 0);
        int ans =0;
        for(int i=0; i<31; i++){
            int c = 0;
            int t = 1<<i;
            for(auto cand : candidates){
                if(cand&t)
                    c++;
            }
            ans = max(c, ans);
        }
        return ans;
    }
};