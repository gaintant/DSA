class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxVal = values[0];
        int n = values.size();
        int ans = INT_MIN;
        for(int i=1; i<n; i++){
            ans = max(ans, maxVal + values[i] - i);
            maxVal = max(maxVal, values[i] + i);
        }
        return ans;
    }
};