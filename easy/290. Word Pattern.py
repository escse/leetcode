class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        if len(pattern) != len(str.split()): return False
        d = dict()
        for p, s in zip(pattern, str.split()):
            if d.has_key(p) and d[p] != s:
                return False
            else:
                d[p] = s
        return len(set(d.values())) == len(d.values())