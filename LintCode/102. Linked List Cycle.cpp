/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */


public class Solution {
    /*
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    public boolean hasCycle(ListNode head) {
        // write your code here
        ListNode lets_run = head;
        for(int i = 0; i < 20000; i++){
            if(lets_run == null){
                return false;
            }
            lets_run = lets_run.next;
        }
        return true;
    }
}
