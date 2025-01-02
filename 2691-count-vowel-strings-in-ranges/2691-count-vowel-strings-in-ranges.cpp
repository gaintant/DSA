class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = words.size();
        vector<int> c(n, 0);

        for(int i=0; i<n; i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size() -1]))
                c[i]++;
            if(i > 0)
                c[i] += c[i-1];
        }
        for(auto q : queries){
            int count = q[0] == 0 ? c[q[1]] : c[q[1]] - c[q[0]-1];
            ans.push_back(count);
        }
        return ans;
    }
};