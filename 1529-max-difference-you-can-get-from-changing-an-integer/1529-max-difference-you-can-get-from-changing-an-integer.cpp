class Solution {
public:
    int  highValueDiff(string num){
        int n = num.size(), i=0;
        while(i < n && num[i] == '9')
            i++;
        if(i == n) return 0;
        return getDiff(num, '9', num[i]);
    }
    int  lowValueDiff(string num){

        int n = num.size(), i=0;
        if(num[0] != '1')
            return getDiff(num, '1', num[0]);
        for(auto val : num)
            if(val != '1' && val != '0')
                return getDiff(num, '0', val);
        return 0;
    }

    int getDiff(string num, char a, char b){
        long long ans = 0;
        for(auto val : num){
            if(val == b)
                ans += a - b;
            ans *= 10;
        }
        return ans/10;
    }
    int maxDiff(int num) {
        string value = to_string(num);
        return highValueDiff(value) - lowValueDiff(value);
    }
};