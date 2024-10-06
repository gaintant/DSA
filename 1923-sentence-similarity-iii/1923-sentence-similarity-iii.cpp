class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        string s;
        vector<string> v1, v2;
        while(getline(ss1, s, ' '))
            v1.push_back(s);
        while(getline(ss2, s, ' '))
            v2.push_back(s);
        int i = 0 , j1 = v1.size()-1,j2 = v2.size() - 1;
        while(i <= min(j1 , j2) && v1[i] == v2[i])
            i++;
        while(j1 >=0 && j2 >= 0 && v1[j1] == v2[j2])
            j1--, j2--;
        cout<<i<<" "<<j1 <<" "<<j2;
        return j1 < i || j2 < i;
    }
};