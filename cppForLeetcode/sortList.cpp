#include "Common.h"

struct ListNode
{
    int cal;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}

};

    ListNode* insertionSortList(ListNode* head) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *index = head;
        while(index != NULL)
        {
            ListNode *nextIndex = index->next;
            ListNode *insertPos = fakeHead;
            while(insertPos->next != NULL && index->val > insertPos->next->val)
            {
                insertPos = insertPos->next;
            }
            index->next = insertPos->next;
            insertPos->next = index;
            
            index = nextIndex;
        }
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
