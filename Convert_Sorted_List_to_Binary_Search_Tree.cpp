/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode* sortedListToBST(ListNode* head) {

        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        return BuildBST(head, 0, len - 1);
    }
    TreeNode* BuildBST(ListNode*& list, int start, int end) { // DO NOT FORGET & !!!
        if (start > end) return NULL;
        int mid = (start + end) / 2; //if use start + (end - start) >> 1, test case will break, strange!
        TreeNode* leftChild = BuildBST(list, start, mid - 1);
        TreeNode* parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = BuildBST(list, mid + 1, end);
        return parent;
    }
};
