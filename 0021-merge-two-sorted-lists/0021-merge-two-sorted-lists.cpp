
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        std::vector<int> s;
        ListNode* temp = list1;
        ListNode* temp2 = list2;

        while (temp != nullptr) {
            s.push_back(temp->val);
            temp = temp->next;
        }
        while (temp2 != nullptr) {
            s.push_back(temp2->val);
            temp2 = temp2->next;
        }

        std::sort(s.begin(), s.end());

        if (s.empty()) {
            return nullptr;
        }

        ListNode* dummyList = new ListNode(s[0]);
        ListNode* currentNode = dummyList;

        for (size_t i = 1; i < s.size(); ++i) {
            currentNode->next = new ListNode(s[i]);
            currentNode = currentNode->next;
        }

        return dummyList;
    }
};
