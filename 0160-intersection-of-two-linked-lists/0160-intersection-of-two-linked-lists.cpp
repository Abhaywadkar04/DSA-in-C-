

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> map;

        ListNode* temp = headA;
        while (temp != nullptr) {
            map[temp] = true; // Mark this node as seen in list A
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr) {
            if (map.find(temp) != map.end()) {
                return temp; // This node is present in both lists
            }
            temp = temp->next;
        }

        return nullptr; // No intersection found
    }
};
