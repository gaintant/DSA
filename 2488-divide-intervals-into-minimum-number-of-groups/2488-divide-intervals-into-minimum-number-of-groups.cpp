class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1, n = intervals.size();
        pq.push(intervals[0][1]);
        for(int i=1; i<n; i++){
            if(pq.top() < intervals[i][0])
                pq.pop();
            else
                ans++;
            pq.push(intervals[i][1]);
        }
        return ans;
    }
};