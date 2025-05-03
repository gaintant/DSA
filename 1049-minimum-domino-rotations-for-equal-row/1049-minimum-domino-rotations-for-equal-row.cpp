class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int tc = 1, bc=1;
        int n = tops.size();
        for(int i=1; i<n; i++){
            if(tops[i] == tops[0] || bottoms[i] == tops[0])
                tc++;
            if(tops[i] == bottoms[0] || bottoms[i] == bottoms[0])
                bc++;
        }
        cout<<tc<<" "<<bc;
        if(tc == n){
            int c1 = n, c2 = n;
            for(auto top : tops)
                if(top == tops[0])
                    c1--;
            for(auto bottom : bottoms)
                if(bottom == tops[0])
                    c2--;
            return min(c1, c2);
        }
        if(bc == n){
            int c1 = n, c2 = n;
            for(auto top : tops)
                if(top == bottoms[0])
                    c1--;
            for(auto bottom : bottoms)
                if(bottom == bottoms[0])
                    c2--;
            return min(c1, c2);
    
        }
        return -1;
    }
};