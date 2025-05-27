class Solution {
public:
    int differenceOfSums(int n, int m) {
        int t = n/m;
        return n*(n+1)/2 - m*(t + 1)*t;
    }
};