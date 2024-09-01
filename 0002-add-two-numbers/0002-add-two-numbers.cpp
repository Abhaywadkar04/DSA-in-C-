class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* currentNode = dummyNode;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;
        }
        
        ListNode* result = dummyNode->next;
        delete dummyNode; // Free the dummy node memory
        return result;
    }
};
