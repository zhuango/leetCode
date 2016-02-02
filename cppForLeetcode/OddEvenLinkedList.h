#include "Common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class OddEvenLinkedList {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode newHead(0);
        ListNode oldHead(0);
        ListNode *tail = &newHead;
        ListNode *preHead = &oldHead;
        ListNode *pos = head;
        oldHead.next = head;
        int count = 1;
        while (pos != NULL)
        {
            if (count % 2 == 0)
            {
                preHead = pos;
                pos = preHead->next;
            }
            else
            {
                preHead->next = pos->next;

                pos->next = tail->next;
                tail->next = pos;
                tail = pos;

                pos = preHead->next;
            }
            count++;
        }
        tail->next = oldHead.next;
        oldHead.next = NULL;
        return newHead.next;
    }
};