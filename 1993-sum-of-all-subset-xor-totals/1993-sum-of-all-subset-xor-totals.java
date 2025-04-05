class Solution {
    int ans;
    void solve(int[] nums, int i, int c){
        // System.out.println(String.format("%d %d %d", i, c, ans));
        if(i == nums.length)
            ans += c;
        else{
            solve(nums, i+1, c);
            c ^= nums[i];
            solve(nums, i+1, c);
        }
    }
    public int subsetXORSum(int[] nums) {
        // Integer ans = 0;
        solve(nums, 0,0);
        return ans;
    }
}