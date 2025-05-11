class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int e = -1, n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]%2 == 0) 
                e = i;
            else if(i-e >= 3) 
                return true;
        }
        return false;
    }
};