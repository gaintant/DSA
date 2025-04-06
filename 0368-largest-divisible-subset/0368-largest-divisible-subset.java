class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int[][] dp = new int[n][2];

        for(int i=n-1; i>=0; i--){
            dp[i] = new int[]{-1, 1};
            for(int j=i+1; j<n; j++){
                if(nums[j]%nums[i] == 0 && dp[i][1] <= dp[j][1]){
                    dp[i] = new int[]{j, dp[j][1] + 1};
                }
            }
        }
        
        int startIndex = 0;
        for(int i=1; i<n; i++){
            if(dp[i][1] > dp[startIndex][1])
                startIndex = i;
        }
        List<Integer> ans = new ArrayList();
        while(startIndex != -1){
            ans.add(nums[startIndex]);
            startIndex = dp[startIndex][0];
        }
        return ans;
    }
}