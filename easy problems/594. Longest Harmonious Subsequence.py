class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = len(nums)
        if s == 0:
            return 0
        d = dict()
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        res = 0
        for k, v in d.items():
            if k + 1 in d:
                res = max(res, v + d[k+1])
        return res