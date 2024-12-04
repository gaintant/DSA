class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0, j=0, n = str1.size(), m = str2.size();
        while(i<n && j < m){
            if(str1[i] == str2[j] || (str1[i] + 27 - str2[j])%26 == 0)
                j++;
            i++;
        }
        return j == m;
    }
};