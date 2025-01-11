class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> arr(26, 0);
        for(auto ch: s){
            arr[ch-'a']++;
        }
        int c = 0;
        for(auto i : arr){
            if(i%2 == 1)c++;
        }
        return c <= k && s.size() >= k;
    }
};