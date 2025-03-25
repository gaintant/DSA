class Solution {
public:
    bool solve(vector<vector<int>>& rectangles){
        sort(rectangles.begin(), rectangles.end());
        int pre = -1, c = 0;
        for(auto r : rectangles){
            if(r[0] >= pre)
                c++;
            pre = max(pre, r[2]);
            // cout<<c<<" "<<pre<<endl;
        }
        return c > 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if(solve(rectangles)) return true;
        for(int i=0; i<rectangles.size(); i++){
            // cout<<rectangles[i][0];
            rectangles[i][0] = rectangles[i][1];
            rectangles[i][2] = rectangles[i][3];
        }
        // cout<<" ========================="<<endl;
        return solve(rectangles);
    }
};