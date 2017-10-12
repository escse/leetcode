class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        c = 0
        s = []
        num1 = list(num1)
        num2 = list(num2)
        while num1 or num2:
            if num1:
                a = int(num1.pop())
            else:
                a = 0
            if num2:
                b = int(num2.pop())
            else:
                b = 0
            c += a + b
            s.append(str(c%10))
            c /= 10
        if c != 0:
            s.append(str(c))
        s.reverse()
        return "".join(s)
    
print Solution().addStrings("123", "878")