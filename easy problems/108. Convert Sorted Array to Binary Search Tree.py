# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        l = len(nums)
        if (l == 1): return TreeNode(nums[0])
        if (l == 0): return None
        t = TreeNode(nums[l/2])
        t.left = self.sortedArrayToBST(nums[:l/2])
        t.right = self.sortedArrayToBST(nums[l/2+1:])
        return t
        