# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def printList(l):
    while l:
        print l.val, 
        l = l.next
    print "\n"

def makeList(l):
    l = [ListNode(v) for v in l]
    for i in range(len(l)-1):
        l[i].next = l[i+1]
    return l[0]

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head:
            return head
        h = head
        cnt = 0
        while h:
            cnt += 1
            h = h.next
        h1 = head
        h2 = head
        for i in range(cnt/2):
            h2 = h2.next
        tmp = h2.next
        h2.next = None
        h2 = tmp
        h2 = self.reverseList(h2)
        while h1 and h2:
            h1n = h1.next
            h2n = h2.next
            h1.next = h2
            h2.next = h1n
            h1, h2 = h1n, h2n

    def reverseList(self, head):
        if not head:
            return None
        hl = None
        hn = head.next
        while 1:
            head.next = hl
            if not hn:
                return head
            hl, head, hn = head, hn, hn.next


l = makeList(range(15))
ll = Solution().reorderList(l)
printList(ll)