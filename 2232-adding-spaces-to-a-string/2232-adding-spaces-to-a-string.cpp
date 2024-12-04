class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n = s.size(), m = spaces.size(),i,j;
        for(i=0, j=0; i<n; i++){
            if(j <m && i == spaces[j]){
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};