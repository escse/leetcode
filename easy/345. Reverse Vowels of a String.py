class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = 'aeiou'
        chars = [c for c in s if c in vowels]
        ns = ''
        for i in range(len(s)):
            if s[i] in vowels:
                nw += chars[-1]
                chars.pop()
            else:
                ns += s[i]
        return s???