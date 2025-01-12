class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2 == 1)
            return false;
        int n=s.size(), c=0;
        for(int i=0; i<n; i++){
            if(s[i] == ')' && locked[i] == '1'){
                c++;
                if(c > (i+1)/2)
                    return false;
            }
        }
        c=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(' && locked[i] == '1'){
                c++;
                if(c > (n - i)/2)
                    return false;
            }
        }
        return true;
    }
};