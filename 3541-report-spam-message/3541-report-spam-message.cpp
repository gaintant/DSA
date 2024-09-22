class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> banned;
        for(auto w : bannedWords)
            banned.insert(w);
        int c = 0;
        for(auto w  :message){
            if(banned.find(w) != banned.end())
                c++;
        }
        return c > 1;
    }
};