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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < lists.size(); i++) {
            pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            ListNode* minNode = pq.top().second;
            temp->next = minNode;
            pq.pop();
            if (minNode->next != nullptr) pq.push({minNode->next->val, minNode->next});
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
