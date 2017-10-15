class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = collections.Counter(nums)
        maxVal = max(v for _, v in d.items())
        maxKey = [k for k, v in d.items() if v == maxVal]
        startpos = dict()
        endpos = dict()
        for i in range(len(nums)):
            v = nums[i] 
            if v not in maxKey:
                continue
            if v not in startpos:
                startpos[v] = i
                endpos[v] = i
            else:
                endpos[v] = i
        return min(endpos[v] - startpos[v] for v in maxKey) + 1