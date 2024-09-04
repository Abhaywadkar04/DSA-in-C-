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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next==nullptr || k==0)return head;

        ListNode* temp=head;
        int len=1;
        while(temp->next != nullptr){
            len++;
            temp=temp->next;
        }
        temp->next=head;
        int n=k % len;

        if (n == 0) {
            temp->next = nullptr; // Break the circle
            return head;
        }

        temp=head;
        int m=len-n;


        ListNode* newTail = head;
        for (int i = 1; i < m; ++i) {
            newTail = newTail->next;
        }

        head=newTail->next;
        newTail->next=nullptr;

return head;

        
    }
};