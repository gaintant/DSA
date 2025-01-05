class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftVec(n+1, 0);
        for(auto shift : shifts){
            if(shift[2] == 1)
                shiftVec[shift[0]]++, shiftVec[shift[1] + 1]--;
            else
                shiftVec[shift[0]]--, shiftVec[shift[1] + 1]++;
        }
        int totShift = 0;
        for(int i=0; i<n; i++){
            totShift += shiftVec[i];
            int c = (s[i] - 'a' + totShift + 260000)%26;
            s[i] = c + 'a';
        }
        return s;
    }
};