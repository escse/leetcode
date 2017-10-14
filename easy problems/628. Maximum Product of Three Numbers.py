class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        v1 = heapq.nlargest(3, nums)
        v2 = heapq.nsmallest(2, nums)
        return v1[0] * max(v1[1] * v1[2], v2[0] * v2[1])