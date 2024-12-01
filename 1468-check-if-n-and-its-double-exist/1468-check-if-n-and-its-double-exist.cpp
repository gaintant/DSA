class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        // sort(arr.begin(), arr.end());
        for(auto ele : arr){
            if(s.find(ele) != s.end())
                return true;
            if(ele%2 == 0)
                s.insert(ele/2);
            s.insert(2*ele);
        }    
        return false;
    }
};