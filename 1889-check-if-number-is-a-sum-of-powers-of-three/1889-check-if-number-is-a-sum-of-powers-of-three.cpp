class Solution {
public:
    bool checkPowersOfThree(int n) {
        // int count = 0;
        for(; n > 0; n /= 3){
            // cout<<n<<" "<<count<<" "<<n%3<<endl;
            if(n%3 == 2)
                return false;
        }
        return true;

    }
};