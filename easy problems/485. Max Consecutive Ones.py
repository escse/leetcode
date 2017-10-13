class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        c = 0
        l = 0
        for n in nums:
            if n:
                c += 1
                res = max(res, c)
            else:
                c = 0
        return res
        