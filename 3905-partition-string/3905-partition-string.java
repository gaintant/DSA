class Solution {
    public List<String> partitionString(String s) {
        Set<String> seen = new HashSet();
        List<String> ans = new ArrayList();
        seen.add("");
        int i=0, n = s.length();
        while(i<n){
            StringBuilder sb = new StringBuilder();
            while(i<n && seen.contains(sb.toString()) == true){
                sb.append(s.charAt(i));
                i +=1;
            } 
            if(seen.contains(sb.toString()) == false)
                ans.add(sb.toString());
            seen.add(sb.toString());
        }
        return ans;
    }
}