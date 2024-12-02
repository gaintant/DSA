class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        s = sentence.split()
        for c in range(len(s)):
            if s[c].startswith(searchWord):
                return c + 1
        return -1
                
            