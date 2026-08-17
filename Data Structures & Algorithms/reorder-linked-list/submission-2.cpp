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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;     // Tracks the previous node
        ListNode* curr = head;        // Tracks the current node
        ListNode* next_node = nullptr; // Temporarily saves the next node
        
        while (curr != nullptr) {
            next_node = curr->next; // 1. Save the next node
            curr->next = prev;      // 2. Reverse the current node's link
            prev = curr;            // 3. Move 'prev' one step forward
            curr = next_node;       // 4. Move 'curr' one step forward
        }
        
        return prev; // 'prev' now points to the new head node
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* midNode;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<" ";
        ListNode* p=head;
        while(p->next!=slow){
            p=p->next;
        }
        p->next=NULL;

        midNode = slow;

        

        ListNode* a = head;
        ListNode* b = reverseList(midNode);

        // while(a){
        //     cout<<a->val<<" ";
        //     a=a->next;
        // }
        // cout<<endl;
        // while(b){
        //     cout<<b->val<<" ";
        //     b=b->next;
        // }

        int turn=1;
        while(a && b){
            if(turn){
                ListNode* tempa = a;
                a=a->next;
                tempa->next=b;
            }else{
                ListNode* tempb = b;
                b=b->next;
                tempb->next=a;
            }
            turn=!turn;
        }

    }
};
