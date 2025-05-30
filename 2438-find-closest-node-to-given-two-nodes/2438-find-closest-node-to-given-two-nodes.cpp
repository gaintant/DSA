class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), d=0;
        vector<int> d1(n+1, INT_MAX), d2(n+1, INT_MAX);
        while(node1 != -1 && d1[node1] == INT_MAX){
            d1[node1] = d++;
            node1 = edges[node1];
        }
        d=0;
        while(node2 != -1 && d2[node2] == INT_MAX){
            d2[node2] = d++;
            node2 = edges[node2];
        }
        int ans = INT_MAX, index = -1;
        for(int i=0;i<n; i++)
            if(ans > max(d1[i], d2[i]))
                {ans = max(d1[i], d2[i]); index = i;}
        return index;
    }
};