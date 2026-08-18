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
    void reorderList(ListNode* head) {
        if (head->next != NULL) {
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* l1 = head;
            ListNode* l2 = reverseList(slow->next);
            while (l2 != NULL) {
                ListNode* temp1 = l1->next;
                ListNode* temp2 = l2->next;
                l1->next = l2;
                l2->next = temp1;
                l1 = temp1;
                l2 = temp2;
            }
            l1->next=NULL;
        }
    }

   private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
