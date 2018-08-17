#include <iterator>
#include <stack>

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
        stack<int> sa;
        stack<int> sb;
        while(l1 != NULL){ sa.push(l1->val); l1 = l1->next; }
        while(l2 != NULL){ sb.push(l2->val); l2 = l2->next; }
        
        ListNode *head = NULL;
        int temp = 0;
        while(!sa.empty() || !sb.empty())
        {
            if(!sa.empty())
            {
                temp += sa.top();
                sa.pop();
            }
            if(!sb.empty())
            {
                temp += sb.top();
                sb.pop();
            }
            ListNode *newNode = new ListNode(temp % 10);
            newNode->next = head;
            head = newNode;
            temp = temp / 10;
        }
        if(temp != 0)
        {
            ListNode *newNode = new ListNode(temp % 10);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};