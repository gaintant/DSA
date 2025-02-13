class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        int ans = 0;
        for(auto i : nums)
            pq.push(-i);
        while(-pq.top() < k){
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(x + x + y);
            ans++; 
        }
        return ans;
    }
};