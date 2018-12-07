#include <iterator>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        int temp = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                temp += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(temp % 10);
            tail = tail->next;
            temp = temp / 10;
        }
        if(temp != 0)
        {
            tail->next = new ListNode(temp);
            tail = tail->next;
        }
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};