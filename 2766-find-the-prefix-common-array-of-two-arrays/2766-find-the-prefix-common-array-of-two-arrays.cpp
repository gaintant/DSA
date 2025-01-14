class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> occurance(n+1,-1);
        for(int i=0;i<n;i++){
            occurance[A[i]] = i;
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[max(i, occurance[B[i]])]++;
        }
        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};