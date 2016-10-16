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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode * newHead=new ListNode(-1),*newHeadIt;
        newHead->next=head;
        newHeadIt=newHead;
        while(1){
            ListNode * temNode=newHeadIt;
            int i=0;
            while(i<k&&temNode){
                temNode=temNode->next;
                i++;
            }
            if(!temNode){
                break;
            }
            ListNode * n1=NULL,*n2=NULL,*n3=NULL;
            n1=newHeadIt->next;
            n2=n1->next;
            newHeadIt->next=temNode;
            newHeadIt=n1;
            n1->next=temNode->next;
            i=0;
            while(i++<k-1){
                n3=n2->next;
                n2->next=n1;
                n1=n2;
                n2=n3;
            }
        }
        return newHead->next;
    }
};