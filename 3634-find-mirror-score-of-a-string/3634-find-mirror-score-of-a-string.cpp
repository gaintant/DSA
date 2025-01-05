class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<int>> marks(26);
        int n = s.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            int m = 25 - s[i] + 'a';
            if(!marks[m].empty())
                ans += i - marks[m].top(), marks[m].pop();
            else
                marks[s[i]-'a'].push(i);  
        }
        return ans;
    }
};