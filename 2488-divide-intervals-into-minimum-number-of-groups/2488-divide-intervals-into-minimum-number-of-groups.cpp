class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size();
        pq.push(intervals[0][1]);
        for(int i=1; i<n; i++){
            if(pq.top() < intervals[i][0])
                pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};