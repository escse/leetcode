class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min = []
        self.data = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if not self.min:
            self.min.append(x) 
        else:
            self.min.append(min(self.min[-1], x))
        

    def pop(self):
        """
        :rtype: void
        """
        self.data.pop()
        self.min.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.data[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()