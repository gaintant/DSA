class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        int c2 = 0, val;
        for(int i=0; i<31; i++){
            val = 1<<i;
            if( (num2 & val) != 0)
                c2++;
        }
        for(int i=30; i >=0; i--){
            val = 1<<i;
            if((num1 & val) != 0 && c2 != 0){
                ans += val; c2--;
            }
        }
        for(int i=0; i<31 &&c2 >0; i++){
            val = 1<<i;
            if((num1&val) == 0){
                ans+=val; c2--;
            }
        }
        return ans;
    }
};