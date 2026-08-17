/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        map<Node*,Node*>m;
        Node* newhead = new Node(head->val);
        m[head]=newhead;

        Node* p = head;
        Node* q = newhead;
        while(p->next){
            Node* temp = new Node(p->next->val);
            temp->val = p->next->val;
            q->next = temp;
            m[p->next]=temp;
            p=p->next;
            q=q->next;
            
        }
        Node* a=newhead;
        while(head){
            a->random = m[head->random];
            head=head->next;
            a=a->next;
        }

        // while(newhead){
        //     cout<<newhead->val<<" ";
        //     newhead=newhead->next;
        // }

        return newhead;
    }
};
