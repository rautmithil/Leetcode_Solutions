/* 
@author Mithil Raut
@version 1.0 01/17/18
Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
    ListNode* add(ListNode* l1, ListNode* l2, int carry){    
        if(!l1 && !l2 && carry==0){
                    return NULL;
                }
        else {
            int a = 0;
            int b = 0;
            if(l1){
                a = l1->val;
            }
            if(l2){
                b = l2->val;
            }
            int sum = a + b + carry;
            ListNode *head = new ListNode(sum % 10);
            head->next = add(l1? l1->next:NULL, l2? l2->next:NULL, (sum/10));
            return head;
        }
    }
};