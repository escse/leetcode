/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        printList(head, v);
        return v;
    }
    void printList(ListNode* head, vector<int> &v) {
        if (head == nullptr) return;
        printList(head->next, v);
        v.push_back(head->val);
    }
};