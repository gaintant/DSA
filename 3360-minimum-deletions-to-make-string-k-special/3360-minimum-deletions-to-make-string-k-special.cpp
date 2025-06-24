class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto ch : word){
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans = INT_MAX;
        for(int i=0; i<26; i++){
            // if(i == 0)
            //     continue;
            int val = freq[i] + k,p = 0 ;
            for(int j=0; j<26; j++){
                if(freq[j] == 0)
                    continue;
                if(freq[j] < freq[i])
                    p += freq[j];
                
                else if(freq[j] > val)
                    p += freq[j] - val;
            }
            ans = min(p, ans);
        }
        return ans;
    }
};