class Solution {
public:
    long long count(vector<int>& a, int b){
        long long c = 0;
        for(auto i : a){
            c += (i + b -1)/b;
        }
        return c;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = 1, h = INT_MAX;
        long long mid = (l + h)/2;
        while(l < h){
            if(count(quantities, mid) <= n)
                h = mid;
            else
                l = mid + 1;
            mid = (l + h)/2;
        }
        return l;
    }
};