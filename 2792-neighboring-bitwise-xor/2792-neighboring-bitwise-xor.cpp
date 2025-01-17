class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for(auto d : derived){
            s = d^s;
        }
        if(s == 0) return true;
        // s = 1;
        // for(auto d : derived){
        //     s = d^s;
        // }
        // if(s == 1) return true;
        return false;
    }
};