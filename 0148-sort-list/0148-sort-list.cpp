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
    ListNode* sortList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }


        vector<int>n;
        ListNode* temp=head;
        while(temp!=nullptr){
            n.push_back(temp->val);
            temp=temp->next;
        }

        sort(n.begin(),n.end());
        temp=head;
        for(int i=0;i<n.size();i++){
            temp->val=n[i];
            temp=temp->next;
        }

        return head;
        
        
    }
};