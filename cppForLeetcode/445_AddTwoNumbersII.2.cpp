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
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        ListNode result = ListNode(-1);
        ListNode *tail = &result;
        if(len1 > len2)
        {
            int count = len1 - len2;
            while(count != 0)
            {
                ListNode *newNode = new ListNode(l1->val);
                l1 = l1->next;
                tail->next = newNode;
                tail = tail->next;
                count -= 1;
            }
        }
        if(len1 < len2)
        {
            int count = len2 - len1;
            while(count != 0)
            {
                ListNode *newNode = new ListNode(l2->val);
                l2 = l2->next;
                tail->next = newNode;
                tail = tail->next;
                count -= 1;
            }
        }
        if(len1 == 0 || len2 == 0) return result.next;
        ListNode *tempNode = addList(l1, l2);
        if(tempNode->val < 10)
        {
            tail->next = tempNode;
            return result.next;
        }
        if(result.next == NULL)
        {
            ListNode *newNode = new ListNode(tempNode->val / 10);
            tempNode->val = tempNode->val % 10;
            newNode->next = tempNode;
            return newNode;
        }
        else
        {
            int jinwen = addJinwei(result.next, tempNode->val / 10);
            tempNode->val = tempNode->val % 10;
            tail->next = tempNode;
            if(jinwen != 0)
            {
                ListNode *newNode = new ListNode(jinwen);
                newNode->next = result.next;
                return newNode;
            }
            return result.next;
        }

    }
    int addJinwei(ListNode *head, int jinwei)
    {
        int jinweiR = 0;
        if(head->next == NULL)
        {
            head->val += jinwei;
            jinweiR = head->val/10;
            head->val = head->val % 10;
            return jinweiR;
        }
        jinweiR = addJinwei(head->next, jinwei);
        head->val += jinweiR;
        jinweiR = head->val / 10;
        head->val %= 10;
        return jinweiR;
    }
    ListNode *addList(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL)
        {
            return NULL;
        }
        ListNode *tempNode = addList(l1->next, l2->next);
        ListNode *head = new ListNode(l1->val + l2->val);
        if(tempNode == NULL) return head;
        head->val += tempNode->val / 10;
        tempNode->val = tempNode->val % 10;
        head->next = tempNode;
        return head;
    }
    int getLength(ListNode *head)
    {
        int count = 0;
        while(head != NULL)
        {
            count += 1;
            head = head->next;
        }
        return count;
    }
};