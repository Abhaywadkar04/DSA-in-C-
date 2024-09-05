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
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)return head;

        ListNode* temp=head;
        vector<int>s;

         while (temp != nullptr) {
            s.push_back(temp->val);
            if (temp->next == nullptr) break; // Prevent accessing next of nullptr
            temp = temp->next->next;
        }

        // Traverse even-indexed nodes (2nd, 4th, 6th, ...)
        temp = head->next;
        while (temp != nullptr) {
            s.push_back(temp->val);
            if (temp->next == nullptr) break; // Prevent accessing next of nullptr
            temp = temp->next->next;
        }

        temp=head;

        for(int i=0;i<s.size();i++){
            temp->val=s[i];
            temp=temp->next;
        }

        return head;
        
    }
};