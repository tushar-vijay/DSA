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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;

        // locating pairs
        while(cnt < 2){
            if(temp == NULL){
                return head;
            }

            temp = temp->next;
            cnt++;
        }

        // rest of the LL
        ListNode* newNext = swapPairs(temp);

        // swap current part
        temp = head;
        ListNode* nextNode = temp->next;
        nextNode->next = temp;
        temp->next = newNext;

        return nextNode;
    }
};
