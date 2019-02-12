/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int first = 0;
        int second = 0;
        int currentDigit = 0;
        ListNode result = new ListNode(0);
        ListNode ptr = result;
        while(l1 != null || l2 != null){
            ptr.next = new ListNode(0);
            ptr = ptr.next;
            first = (l1 == null)? 0:l1.val;
            second = (l2 == null)? 0:l2.val;
            currentDigit = first + second + carry;
            carry = (currentDigit >= 10)? 1:0;
            currentDigit %= 10;
            ptr.val = currentDigit;
            if(l1 != null){
                l1 = l1.next;
            }
            if(l2 != null){
                l2 = l2.next;
            }
        }
        if(carry == 1){
            ptr.next = new ListNode(1);
        }
        return result.next;
    }
}