class Solution {
public:
    struct trie{
        int c;
        map<char, trie*> mp;
        trie(){
            c = 0;
        }
    };
    void insert(trie * head, string &s){
        for(auto ch : s){
            if(head->mp[ch] == NULL)
                head->mp[ch] = new trie();
            head = head->mp[ch];
            head->c++;
        }
    }
    int count(trie * head, string &s){
        int c = 0;
        for(auto ch : s){
            head = head->mp[ch];
            c += head->c;
        }
        return c;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trie *head = new trie();
        vector<int> ans(words.size());
        for(auto word : words)
            insert(head, word);
        for(int i=0; i<words.size(); i++)
            ans[i]  = count(head, words[i]);
        return ans;
    }
};