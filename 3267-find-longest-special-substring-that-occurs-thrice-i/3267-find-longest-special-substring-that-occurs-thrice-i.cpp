class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        for(int i =n-2; i> 0; i--){
            map<string, int> mp;
            for(int j=0; j<=n-i; j++){
                int k = j+1;
                while(k < j + i && s[k] == s[j])
                    k++;
                if(k != j + i)
                    continue;
                // cout<<s.substr(j, i)<<endl;
                if(++mp[s.substr(j, i)] == 3)
                    return i;
            }
        }
        return -1;
    }
};