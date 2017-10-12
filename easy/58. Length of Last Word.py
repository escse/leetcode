class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        ss = s.split()
        return 0 if len(ss)==0 else len(ss[-1])