class Solution {
    // Function to get the collision point where two lists intersect
    ListNode* collisionPoint(ListNode* headA, ListNode* headB, int count) {
        // Move the pointer of the longer list ahead by `count`
        while (count > 0) {
            headA = headA->next;
            count--;
        }

        // Traverse both lists together
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA; // Intersection point found
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr; // No intersection found
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0;
        int count2 = 0;
        ListNode* temp = headA;

        while (temp != nullptr) {
            count1++;
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr)
         {
            count2++;
            temp = temp->next;
        }

        if (count1 > count2)
         {
            return collisionPoint(headA, headB, count1 - count2);
        } else {
            return collisionPoint(headB, headA, count2 - count1);
        }
    }
};
