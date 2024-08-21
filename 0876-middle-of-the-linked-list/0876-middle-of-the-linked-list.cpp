class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Step 1: Count the total number of nodes
        ListNode* temp = head;
        int count = 0;
        
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        // Step 2: Find the middle node
        int mid = count / 2; // Integer division for the middle index
        
        temp = head;
        for (int i = 0; i < mid; ++i) {
            temp = temp->next;
        }
        
        return temp; // This is the middle node
    }
};
