


class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        self.map = dict()
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        self.data.append(val)
        if val in self.map and self.map[val]:
            self.map[val].add(len(self.data) - 1)
            return False
        else:
            self.map[val] = {len(self.data) - 1}
            return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.map or not self.map[val]:
            return False
        if self.data[-1] == val:
            self.map[val].remove(len(self.data)-1)
            self.data.pop()
        else:
            pos = self.map[val].pop()
            self.map[self.data[-1]].remove(len(self.data)-1)
            self.map[self.data[-1]].add(pos)
            self.data[pos], self.data[-1] = self.data[-1], self.data[pos]
            self.data.pop()
        return True
        

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.data[int(random.random() * len(self.data))]

methods = ["insert","remove","insert"]
args = [[1],[1],[1]]
s = RandomizedCollection()
m = {
    "insert": s.insert,
    "remove": s.remove,
    "getRandom": s.getRandom
}
i = 0
for arg, method in zip(args, methods):
    print s.data
    print s.map
    m[method](*arg)