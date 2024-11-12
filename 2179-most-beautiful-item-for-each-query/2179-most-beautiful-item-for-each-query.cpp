class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> ele; ele.push_back(0);
        map<int, int> price; price[0] = 0;
        vector<int> ans;
        int maxBeauty = 0;
        for(int i=0; i<items.size(); i++){
            if(items[i][1] > maxBeauty){
                ele.push_back(items[i][0]);
                price[items[i][0]] = items[i][1];
                maxBeauty = items[i][1];
            }
        }
        for(auto q : queries){
            int p = *--upper_bound(ele.begin(), ele.end(), q);
            ans.push_back(price[p]);
        }
        return ans;
    }
};