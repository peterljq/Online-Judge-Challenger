/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> s1;
        ListNode* ptr = head;
        while(ptr != NULL){
            int temp = ptr->val;
            s1.push(temp);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr != NULL){
            int temp2 = s1.top();
            s1.pop();
            ptr->val = temp2;
            ptr = ptr->next;
        }
        return head;
    }
};