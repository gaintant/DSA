class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN, n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i =0; i<n; i++){
            minVal = min(minVal, nums[i][0]);
            maxVal = max(maxVal, nums[i][0]);
            pq.push({nums[i][0], i, 1});
        }
        int curMin= minVal, curMax = maxVal;
        vector<int> temp = pq.top();
        pq.pop();
        while( nums[temp[1]].size() > temp[2]){
            pq.push({nums[temp[1]][temp[2]], temp[1], temp[2] + 1});
            curMin = pq.top()[0];
            curMax = max(curMax, nums[temp[1]][temp[2]]);
            if(curMax - curMin < maxVal - minVal){
                maxVal = curMax; minVal = curMin;
            }
            // cout<<curMin<<" "<<curMax<<endl;
            temp = pq.top();
            pq.pop();
        }
        return {minVal, maxVal};
    }
};