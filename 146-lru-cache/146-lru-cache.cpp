class Node{
        
        public:
        int key;
        int value;
        Node *prev;
        Node *next;
        
        Node()
        {
            this->prev = NULL;
            this->next = NULL;
        }
        
        Node(int k, int v)
        {
            this->key = k;
            this->value = v;
            Node();
        }
};

class LRUCache {
public:
    int cap;
    map<int, Node*> m;
    Node *head, *tail;
    
    LRUCache(int capacity) {
        cap = capacity;
        m.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node *node)
    {
        Node *prevnode = node->prev;
        Node *nextnode = node->next;
        
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    
    void add(Node *node)
    { 
        Node *headnext = head->next;
        
        head->next = node;
        node->prev = head;
        node->next = headnext;
        headnext->prev = node;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1; 
        
        Node *currnode = m[key];
        remove(currnode);
        add(currnode);
        return m[key]->value;
    }
    
    void put(int key, int value) {
        
        if(m.count(key)==0)
        {
            if(m.size() == cap)
            {
                m.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node *newnode = new Node(key, value);
            add(newnode);
            m[key] = newnode;
        }
        else
        {
            Node *currnode = m[key];
            remove(currnode);
            
            // for a given key , value may get updated
            currnode->value = value;
            add(currnode);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */