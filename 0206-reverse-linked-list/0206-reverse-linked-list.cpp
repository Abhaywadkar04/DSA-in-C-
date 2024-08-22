/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* front;
        ListNode* pre=NULL;

        while(temp!=NULL){
            front=temp->next;
            temp->next=pre;
            pre=temp;
            temp=front;
        }

        return pre;
        
        
        
        
    }
};