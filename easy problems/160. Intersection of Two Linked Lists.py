# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        hA = headA
        hB = headB
        cntA = 0
        cntB = 0
        while hA.next:
            hA = hA.next
            cntA += 1
        while hB.next:
            hB = hB.next
            cntB += 1
        if hA != hB:
            return None
        offset = abs(cntA - cntB)
        hA = headA
        hB = headB
        for i in range(offset):
            if cntA > cntB:
                hA = hA.next
            else:
                hB = hB.next
        while hA != hB:
            hA = hA.next
            hB = hB.next
        return hA
            
            