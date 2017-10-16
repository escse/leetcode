class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while root:
            while (root.val - p.val) * (root.val - q.val) > 0:
                if root.val > p.val:
                    root = root.left
                else:
                    root = root.right
            return root