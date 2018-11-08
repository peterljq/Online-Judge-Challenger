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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL) return false;
        else{
            while(slow && fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow) return true;
            }
            return false;
        }
    }
};