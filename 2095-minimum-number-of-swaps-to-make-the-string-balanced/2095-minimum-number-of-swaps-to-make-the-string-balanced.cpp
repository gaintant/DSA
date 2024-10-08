class Solution {
public:
    int minSwaps(string s) {
        int curr =0, ans =0;
        for(auto ch : s){
            if(ch == '[')
                curr++;
            else if(curr == 0){
                ans++;
                curr++;
            }
            else
                curr--;
        }
        return ans;
    }
};