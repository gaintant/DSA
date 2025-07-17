class Solution {
    public int maximumLength(int[] nums, int k) {
        int ans = 0;
        for(int i=0; i<k; i++){
            int[] lastIndexs = new int[k];
            int[] counts = new int[k];
            Arrays.fill(lastIndexs, -1);
            Arrays.fill(counts, 0);
            for(int j=0; j<nums.length; j++){
                int rem = nums[j]%k;
                if(i == rem) counts[rem]++;
                else if(lastIndexs[rem] < lastIndexs[i]) counts[rem]++;
                lastIndexs[rem] = j;
            }
            for(int j=0; j<k; j++){
                if(j == i) ans = Math.max(ans, counts[i]);
                else if (lastIndexs[i] > lastIndexs[j])
                    ans = Math.max(ans, 2*counts[j] + 1);
                else
                    ans = Math.max(ans, 2*counts[j]);
                // System.out.println(i + " " + j + " " + counts[j] + " " + ans);
            }
        }
        return ans;
    }
}