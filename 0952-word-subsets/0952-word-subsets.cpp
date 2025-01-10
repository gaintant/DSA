class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> store(26, 0);
        for(auto word : words2){
            vector<int> c(26, 0);
            for(auto ch : word){
                c[ch -'a']++;
            }
            for(int i=0; i<26; i++)
                store[i] = max(store[i], c[i]);
        }
        for(auto word: words1){
            vector<int> c(26, 0);
            for(auto ch : word){
                c[ch -'a']++;
            }
            bool toAdd = true;
            for(int i=0; i<26; i++){
                toAdd = toAdd & (c[i] >= store[i]);
            }
            if(toAdd) ans.push_back(word);
        }

        return ans;
    }
};