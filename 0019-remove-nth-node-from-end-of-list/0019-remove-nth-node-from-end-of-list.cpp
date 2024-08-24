class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        
        // First pass to count the total number of nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Edge case: if the node to remove is the head
        if (count == n) {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head
            return newHead;
        }

        // Calculate the position to remove
        int positionToRemove = count - n;
        temp = head;

        // Traverse to the node before the one to be removed
        for (int i = 0; i < positionToRemove - 1; ++i) {
            temp = temp->next;
        }

        // `temp` now points to the node before the one to be removed
        ListNode* nodeToRemove = temp->next;
        temp->next = temp->next->next;

        delete nodeToRemove; // Free the memory of the removed node

        return head;
    }
};
