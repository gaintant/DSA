class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        Map<Integer, Integer> cnts = new HashMap();
        cnts.put(0, 1);
        int cnt = 0;
        long ans = 0;
        for(Integer num : nums){
            if(num%modulo == k)
                cnt++;
            ans += cnts.getOrDefault((cnt-k + modulo)%modulo, 0);
            cnts.put(cnt%modulo, cnts.getOrDefault(cnt%modulo, 0)  + 1);
        }
        return ans;
    }
}