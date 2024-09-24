class Solution {
public:
    struct trie{
        map<char, trie*> mp;
        trie(){
        }
    };
    void insert(trie *head, string &s){
        for(auto ch : s){
            if(head->mp[ch] == NULL)
                head->mp[ch] = new trie();
            head = head->mp[ch];
        }
    }
    int find(trie *head, string &s){
        int ans = 0;
        for(auto ch : s){
            if(head->mp[ch] == NULL)
                return ans;
            head = head->mp[ch];
            ans++;
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie *head= new trie();
        int ans = 0;
        for(auto v : arr1){
            string s = to_string(v);
            insert(head, s);
        }
        for(auto v : arr2){
            string s = to_string(v);
            ans = max(find(head, s), ans);
        }
        return ans;
    }
};