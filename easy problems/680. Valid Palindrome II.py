class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = len(s)
        self.s = s
        if self.Palindrome(s, 0, l):
             return True
        for i in range(len(s)/2):
            if s[i] != s[l-1-i]:
                return self.Palindrome(s, i, l-1-i) or self.Palindrome(s, i+1,l-i)
        return True
    
    def Palindrome(self, s, m, n):
        return all([s[m+i] == s[n-1-i] for i in range((n-m)/2+1)])