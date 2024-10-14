class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num : nums){
            pq.push(num);
        }
        long long ans = 0;
        while(k--){
            ans += pq.top();
            pq.push((pq.top() + 2)/3);
            pq.pop();
        }
        return ans;
    }
};