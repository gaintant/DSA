class Solution {
    int mod = 1000000007;
    long pow(int i){
        if(i == 0)
            return 1;
        long c = pow(i/2);
        if(i%2 == 1)
            return ( c*c*2)%mod;
        else    
            return (c*c)%mod;

    }
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int i =0, j = nums.length-1;
        long ans = 0;
        while(i <= j){
            // System.out.println("" + i + " " + j + " " + ans);
            if(nums[i] + nums[j] > target)
                j--;
            else{
                ans =(ans + pow(j-i))%mod;
                i++;
            }
        }        
        return (int) ans;
    }
}