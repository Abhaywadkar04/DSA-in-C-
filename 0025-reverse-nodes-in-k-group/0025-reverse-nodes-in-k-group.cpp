class Solution {
public:
    // Helper function to reverse a segment of the list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Helper function to get the k-th node from the current node
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* current = head;
        while (current != nullptr && k > 1) {
            current = current->next;
            k--;
        }
        return current;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* current = head;

        while (true) {
            // Find the end node of the current group
            ListNode* kth = getKthNode(current, k);
            if (kth == nullptr) break; // Less than k nodes remaining, no need to reverse

            ListNode* nextGroupStart = kth->next; // The start of the next group
            kth->next = nullptr; // Temporarily terminate the current group

            // Reverse the current group
            ListNode* newGroupHead = reverseLinkedList(current);

            // Connect the previous group with the new group
            prevGroupEnd->next = newGroupHead;
            current->next = nextGroupStart;

            // Update pointers for the next group
            prevGroupEnd = current;
            current = nextGroupStart;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};
