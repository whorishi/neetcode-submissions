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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return nullptr;
        ListNode* first=head;
        n--;
        while(first && n--){
            first=first->next;
        }
        ListNode* second=nullptr;

        while(first->next!=NULL){
            if(second==NULL) second=head;
            else second=second->next;

            first=first->next;
        }
        if(!second) head=head->next;
        else second->next = second->next->next;
        return head;
    }
};

// 1 2
