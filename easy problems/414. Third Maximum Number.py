class Solution(object):
    def thirdMax(self, nums):
        nums = set(nums)
        if len(nums) < 3:
            return max(nums)
        nums.remove(max(nums))
        nums.remove(max(nums))
        return max(nums)

class Solution(object):
    def thirdMax(self, nums):
        nums = list(set(nums))
        v = heapq.nlargest(3, nums)
        if len(v) == 3: return min(v)
        return max(v)