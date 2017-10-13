# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1 and not t2:
            return None
        if t1 and not t2:
            return self.copy(t1)
        if not t1 and t2:
            return self.copy(t2)
        n = TreeNode(t1.val + t2.val)
        n.left = self.mergeTrees(t1.left, t2.left)
        n.right = self.mergeTrees(t1.right, t2.right)
        return n

    def copy(self, t):
        if not t:
            return None
        n = TreeNode(t.val)
        n.left = self.copy(t.left)
        n.right = self.copy(t.right)
        return n