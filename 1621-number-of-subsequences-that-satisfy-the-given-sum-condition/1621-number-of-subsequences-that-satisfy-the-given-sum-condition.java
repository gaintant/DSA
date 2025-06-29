class Solution {
    int mod = 1000000007;
    // long pow(int i){
    //     long ans = 1;
    //     long curr = 2;
    //     while(i != 0){
    //         if(i%2 == 1)
    //             ans = (ans*curr)%mod;
    //         curr = (curr*curr)%mod;
    //         i /=2;
    //     }
    //     return ans;
    // }
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int i =0, j = nums.length-1;
        long ans = 0;
        long[] pow = new long[j+1];
        pow[0] = 1;
        for(int k=1; k<=j; k++)
            pow[k] = (pow[k-1]*2)%mod;
        while(i <= j){
            // System.out.println("" + i + " " + j + " " + ans);
            if(nums[i] + nums[j] > target)
                j--;
            else{
                ans =(ans + pow[j-i])%mod;
                i++;
            }
        }        
        return (int) ans;
    }
}