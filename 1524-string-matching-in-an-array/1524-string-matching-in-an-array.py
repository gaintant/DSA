class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ans = set()
        for word in words:
            for par in words:
                if word != par and word in par:
                    ans.add(word)
        return list(ans)