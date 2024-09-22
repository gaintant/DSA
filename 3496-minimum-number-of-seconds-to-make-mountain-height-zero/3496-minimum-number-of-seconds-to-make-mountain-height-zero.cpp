class Solution {
public:
    long long height(long long  n, vector<int>& workerTimes) {
        long long h = 0;
        for (auto v : workerTimes) {
            double discriminant = 1 + 4 * (2.0 * n / v);

            double k = (-1 + sqrt(discriminant)) / 2;
            if(k > 0)
                h += static_cast<int>(k);
        }
        // cout<<n<<" "<<h<<endl;
        return h;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e16;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (height(mid, workerTimes) < mountainHeight)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};