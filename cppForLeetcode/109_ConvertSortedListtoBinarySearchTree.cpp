#include <iterator>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode *fast = head, *slow = head;
        ListNode *prev = head;
        while(slow->next != NULL && fast->next->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        
        prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
    }
};

int main(void)
{
}