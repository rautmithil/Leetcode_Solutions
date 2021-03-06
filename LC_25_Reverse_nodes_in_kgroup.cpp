/* 
@author Mithil Raut
@version 1.0 01/21/18
Problem:  25. Reverse Nodes in k-Group
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
    * Misread the question and took the longer route. reverseGroup swaps the first and last elements of the linked list.
    * reverseKGroup iterates between groups of numbers based on value ok 'k'.
    * For example: [1,2,3,4,5,6,7] with k = 2
    * is processed by breaking into [1,2] [3,4] [5,6]  k=2
**/
class Solution {
public:
    //Recursive function which swaps the first and last elements of the linked list
    ListNode* reverseGroup(ListNode* head, int k) {
        ListNode* first = head;
        if (k <= 0)
            return head;
        if (k == 1)
            return head;
        if (countNodes(head)<k)
            return head;
        
        if (head == NULL)
            return head;
        ListNode* last = head;
        for(int i = 0; i < k-1; i++){
            last = last->next;
        }
        
        
        ListNode* tfirst = first;
        ListNode* tlast = last;
        first = last;
        last = tfirst;
        ListNode* tthead = head;
        
        for(int i = 0; i < k-2; i++){
            tthead = tthead->next;
        }
        tthead->next = last;
        head = tfirst->next;
        last->next = tlast->next;
        ListNode* thead = head;
        while(thead->next!=NULL){
            //cout<<thead->val<<endl;
            thead = thead->next;
        }
        
        head = reverseGroup(head,k-2);
        first->next = head;
        return first;   
    }
    //Count the number of elements in a linkedlist
    int countNodes(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count ++;
            head=head->next;
        }
        return count;
            
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 0)
            return head;
        if (k == 1)
            return head;
        if (countNodes(head)<k)
            return head;
        if (head == NULL)
            return head;
        
        int interval = countNodes(head)/k;
        int f = 0;
        
        //Temperary variables to store addresses
        ListNode* ohead = head;
        ListNode* realhead;
        ListNode* phead;
        ListNode* qhead;
        ListNode* tphead;
        ListNode* nexthead;
        
        for(int i =0;i<interval;i++){
            int count = 0;
            
            //Iterate through first k numbers to get to k+1th element
            while(count < (k-1)){
                head=head->next;
                count++;
            }
            
            nexthead = head->next;
            head->next=NULL;
            head = ohead;
            
            if(f==0){
                realhead = reverseGroup(head, k); //Keep a seperate pointer for the 1st result to mark the beginning
                phead = realhead;
            }else{
                phead = reverseGroup(head, k);
                tphead->next = phead;
            }
            
            while(phead->next!=NULL){
                phead=phead->next;   
            }
            if(f < interval -1)
                tphead = phead;

            head = nexthead;
            ohead = head;
            f++;
        }
        phead->next = nexthead;  //Put the remaing elements in the end of the list.
        return realhead;        
    }
};