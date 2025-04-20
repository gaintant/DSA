class Solution {
    public int numRabbits(int[] answers) {
        int n = answers.length;
        Map<Integer,Integer> mp = new HashMap();
        for(int i=0; i<n; i++){
            mp.put(answers[i], mp.getOrDefault(answers[i], 0) + 1);
        }
        int ans = 0;
        for(Map.Entry<Integer, Integer> m: mp.entrySet()){
            ans += ((m.getValue() + m.getKey())/(m.getKey() + 1))*(m.getKey() + 1);
        }
        return ans;
    }
}