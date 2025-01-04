class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> a(26);
        int n = s.size();
        for(int i=0; i<n; i++){
            a[s[i] - 'a'].push_back(i);    
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            if(a[i].size() < 2)
                continue;
            int st = a[i][0] , end = a[i][a[i].size() -1];
            for(int j=0; j<26; j++){
                auto it = upper_bound(a[j].begin(), a[j].end(), st);
                if(it != a[j].end() && *it < end)
                    ans++;
            }
        }
        return ans;
    }
};