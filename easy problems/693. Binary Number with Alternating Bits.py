class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cur = 0
        if n & 1:
            cur = 0
        else:
            cur = 1
        while n:
            if cur == (n & 1):
                return False
            cur = n & 1
            n >>= 1
        return True