class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for(auto d : derived){
            s = d^s;
        }
        return s == 0;
    }
};