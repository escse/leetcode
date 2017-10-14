class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        i = 1
        while sum + i * 9 * 10**(i-1) < n:
            sum += i * 9 * 10**(i-1)
            i += 1
        n -= sum
        n -= 1
        s = str(10**(i-1) + (n/i))
        return int(s[n%i])