class Solution {
    public char kthCharacter(int k){
        k--;
        int curr = 0;
        for(int i=1; i<512; i *= 2){
            if((k & i) != 0)
                curr++;
        }
        return (char)(curr + 'a');
    }
}