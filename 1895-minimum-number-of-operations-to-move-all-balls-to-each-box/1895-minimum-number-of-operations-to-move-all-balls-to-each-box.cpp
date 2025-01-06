class Solution {
public:
    vector<int> minOperations(string boxes) {
        int totBall = 0, currBall=0;
        int init = 0, n = boxes.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                totBall++; 
                init += i;
            }
        }
        for(int i=0; i<n; i++){
            ans[i] = init;
            if(boxes[i] =='1'){
                totBall--;
                currBall ++;
            }
            init += (currBall - totBall);
        }
        return ans;
    }
};