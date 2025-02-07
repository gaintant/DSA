class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> color;
        vector<int> ans;
        map<int, int> colorCount;
        int tc = 0;
        for(auto q : queries){
            if(colorCount[q[1]]++ == 0)
                tc++;
            if(color[q[0]] != 0 && --colorCount[color[q[0]]] == 0)
                tc--;
            color[q[0]] = q[1];
            ans.push_back(tc);
        }
        return ans;
    }
};