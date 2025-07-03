class Solution {
    public char kthCharacter(int k, int b ) {
        // System.out.println(k + " " +  b);
        if(k == 1)
            return 'a';
        if(k <= b/2)
            return kthCharacter(k, b/2);
        else
            return (char)(1 + kthCharacter(k - b/2, b/2));
    }
    public char kthCharacter(int k){
        return kthCharacter(k, 512);
    }
}