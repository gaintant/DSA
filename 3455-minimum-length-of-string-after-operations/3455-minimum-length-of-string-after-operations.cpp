class Solution {
public:
    int minimumLength(string s) {
        vector<int> arr(26, 0);
        int ans =0;
        for(auto ch : s){
            arr[ch -'a']++;
        }
        for(auto v : arr){
            if(v != 0)
                ans += ((v%2 == 1)? 1 : 2);
        }
        return ans;
    }
};