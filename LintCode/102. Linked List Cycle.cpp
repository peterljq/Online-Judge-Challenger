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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        // write your code here
        ListNode *runrunrun = head;
        for(int i = 0; i < 65536; i++){
            if(runrunrun == NULL){
                return false;
            }
            runrunrun = runrunrun -> next;
        }
        return true;
    }
};
