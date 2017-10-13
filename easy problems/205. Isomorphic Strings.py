class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): return False
        d = dict()
        for ss, tt in zip(s, t):
            if d.has_key(ss) and d[ss] != tt:
                return False
            else:
                d[ss] = tt
        return len(set(d.values())) == len(d.values())