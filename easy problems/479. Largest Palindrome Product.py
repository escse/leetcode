class Solution(object):
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = [9, 906609, 9966006699, 877]
        if n & 1:
            return s[n/2]% 1337
        else:
            return (10**n-1)*((10**(n/2)-1)*10**(n/2)+1) % 1337
            