class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int i1= 0, i2=n-1;
        while(i1<n && s1[i1] == s2[i1])
            i1++;
        if(i1 == n) return true;
        while(i2 > i1 && s1[i2] == s2[i2])
            i2--;
        for(int i=i1+1; i<i2; i++){
            if(s1[i] != s2[i])
                return false;
        }
        return i2 > i1 && s1[i1] == s2[i2] && s2[i1] == s1[i2]; 
    }
};