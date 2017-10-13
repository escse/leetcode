class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cnt = collections.Counter(s)
        return not (cnt.has_key('A') and cnt['A'] > 1 or s.find("LLL") != -1)
        