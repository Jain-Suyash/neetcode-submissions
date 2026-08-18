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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* temp = head;
        ListNode* prevNode;
        ListNode* nextNode;
        ListNode* kthNode;

        while (temp != nullptr) {
            int cnt = k - 1;
            kthNode = temp;
            while (kthNode != nullptr && cnt > 0) {
                cnt--;
                kthNode = kthNode->next;
            }
            if (kthNode == nullptr) {
                if (prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);
            if (temp == head)
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }

   private:
    void reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }
};
