class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> a(26, 0);
        for(auto c : word2){
            a[c- 'a']++;
        }
        int c = word2.size(), i =0, n = word1.size(), j=0;
        long long ans = 0;
        while(j < n){
            while(c > 0 && i < n){
                if(a[word1[i++] - 'a']-- > 0)
                    c--;
            }
            if(c == 0)
                ans += n - i + 1;
            if(a[word1[j++] - 'a']++ >= 0)
                c++;
        }
            
        return ans;
    }
};