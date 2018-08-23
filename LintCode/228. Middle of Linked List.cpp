/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        ListNode *fast;
        ListNode *slow;
        fast = head;
        slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            if(fast != NULL){
                slow = slow->next;
            }
            else{
                break;
            }
        }
        return slow;
    }
};
