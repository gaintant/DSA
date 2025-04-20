class Solution {
    public int numRabbits(int[] answers) {
        int n = answers.length;
        Map<Integer,Integer> mp = new HashMap();
        for(int i=0; i<n; i++){
            mp.computeIfAbsent(answers[i], k -> 0);
            mp.put(answers[i], mp.get(answers[i]) + 1);
        }
        int ans = 0;
        for(Map.Entry<Integer, Integer> m: mp.entrySet()){
            ans += ((m.getValue() + m.getKey())/(m.getKey() + 1))*(m.getKey() + 1);
        }
        return ans;
    }
}