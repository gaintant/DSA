class Solution {
public:
    vector<char> findValid(string s, int k){
        map<char, int> mp;
        vector<char> valids;
        for(auto ch : s)
            mp[ch]++;
        for(auto item : mp)
            if(item.second >=k) valids.push_back(item.first);
        return valids;
    }
    bool isValid(string &curr, string& s, int k){
        int i=0, n = curr.size();
        if(n == 0) return true;
        for(auto ch : s)
            if(ch == curr[i%n])
                i++;
        return i >= k*n;
    }
    string dfs(vector<char>& valids, string& s, int k, string& curr){
        if(! isValid(curr, s, k))
            return "";
        string ans = curr;
        for(auto ch : valids){
            curr.push_back(ch);
            string child = dfs(valids,s, k, curr);
            curr.pop_back();
            if(child.size() >= ans.size()) ans = child;
            // cout<<"curr :"<<curr<<" ans: "<<ans<<endl;
        }
        return ans;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<char> valids = findValid(s, k);
        string ans = "";
        return dfs(valids, s, k, ans);
    }
};