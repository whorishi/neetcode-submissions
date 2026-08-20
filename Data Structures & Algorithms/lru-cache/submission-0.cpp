class Dlist{
public:
    int value;
    Dlist* next;
    Dlist* prev;

    Dlist(int val){
        this->value = val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    int n;
    unordered_map<int,Dlist*>keynode;
    unordered_map<int,int>keyval;
    Dlist* head;
    Dlist* tail;
    LRUCache(int capacity) {
        this->n=capacity;
        head=nullptr;
        tail=nullptr;
    }

    
    int get(int key) {
        if(keyval.find(key) == keyval.end()) return -1;
        Dlist* currNode = keynode[key];
        if(currNode == head) return keyval[key];
        
        Dlist* p = currNode->prev;
        Dlist* nxt = currNode->next;
        
        if(p) p->next = nxt;
        if(nxt) nxt->prev = p;
        else tail = p;

        currNode->next = head;
        currNode->prev = NULL;
        if(head) head->prev = currNode;
        head = currNode;

        return keyval[key];
    }
    
    void put(int key, int val) {
        if(keyval.find(key)==keyval.end()){
            if(keyval.size()==n){
                Dlist* lastNode = tail;
                int lastKey = lastNode->value;
                tail=tail->prev;
                if(!tail){
                    head=NULL;
                }else{
                    tail->next=NULL;
                }
                keyval.erase(lastKey);
                keynode.erase(lastKey);
                delete lastNode;
            }
            keyval[key]=val;
            Dlist* currNode = new Dlist(key);
            keynode[key]=currNode;
            if(!head){
                head=currNode;
                tail=currNode;
            }else{
                currNode->next=head;
                head->prev=currNode;
                head=currNode;
            }
        }else{ 
            keyval[key]=val;
            get(key);
        }
    }
};