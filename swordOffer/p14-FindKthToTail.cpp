/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr) return nullptr;
        ListNode *p = pListHead;
        int length = 1;
        while (p = p->next) {
            ++length;
        }
        if (k > length) return nullptr;
        int toGo = length - k;
        while (toGo--) {
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};