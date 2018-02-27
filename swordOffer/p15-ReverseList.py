class Solution:
    def ReverseList(self, head):
        if not head: return None
        hl, hn = None, head.next
        while 1:
            head.next = hl
            if not hn:
                return head
            hl, head, hn = head, hn, hn.next