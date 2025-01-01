class Solution {
    public int maxScore(String s) {
        int oneCount = (int) s.chars().filter(c -> c=='1').count();
		int zeroCount = 0;
		int ans  = 0;

		for(int i=0; i< s.length()-1; i++){
			char c = s.charAt(i);
			if(c == '0')
				zeroCount++;
			else
				oneCount--;
            ans = Integer.max(zeroCount + oneCount, ans);
		}
		return ans;
    }
}