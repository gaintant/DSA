class Solution {
public:
    using  ll = long long;
    vector<int> sol(string s, int k){
        int one = 0, zero = 0 ;
        int i=0, j=0, n =s.size();
        vector<int> ans ;
        while(j < n){
            if(s[j] == '0') zero++;
            else one++;
            if(one <= k || zero <= k){
                j++;
                ans.push_back(j - i);
            }
            else{
                if(s[i] == '0') zero--;
                else one--;
                if(s[j] == '0') zero--;
                else one--;
                i++;
            }
        }
        return ans;
    }
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& qs) {
        vector<int>  a= sol(s, k);
        int n = s.size();
        vector<ll> preSum(n);
        vector<ll> ans(qs.size());
        for(int i=0; i<qs.size();i++){
            qs[i].push_back(i);
        }
        sort(qs.begin(), qs.end());
        preSum[0] = a[0];
        for(int i=1; i<n;i++){
            preSum[i] = a[i] + preSum[i-1];
            a[i] -= i;
        }
        int j = 0;
        for(auto q : qs){
            while(j < n && a[j] + q[0] > 0)
                j++;
            if(j > q[1]){
                ll t = q[1] - q[0] + 1;
                ans[q[2]] = ((t*(t+1))/2);
            }
            else{
                ll t = j - q[0];
                ans[q[2]] = ((t*(t+1))/2 + preSum[q[1]] - preSum[j-1]);
            }
        }
        return ans;
    }
};
