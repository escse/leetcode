"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        self.employees = employees
        self.c = []
        self.getIds(id)
        res = sum([self.employees[i-1].importance for i in self.c])
        return res

    
    def getIds(self, id):
        self.c.append(id)
        for i in self.employees[id-1].subordinates:
            self.getIds(i)

print Solution().getImportance([[1,2,[2]], [2,3,[]]], 2)???