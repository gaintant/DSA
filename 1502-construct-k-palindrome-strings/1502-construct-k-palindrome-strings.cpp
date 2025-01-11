class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        vector<int> arr(26, 0);
        for(auto ch: s){
            arr[ch-'a']++;
        }
        for(auto i : arr){
            if(i%2 == 1)k--;
        }
        return k >=0;
    }
};