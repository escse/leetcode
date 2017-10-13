class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = 0
        s = len(nums)
        k = 0
        while i < s:
            if k + i == s: break
            while (nums[i] == 0):
                nums[i:-1] = nums[i+1:]
                nums[-1] = 0
                k += 1
            i += 1????