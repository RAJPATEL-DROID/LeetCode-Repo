class LRUCache {
public:
     class node {
            public : 
                int key;
                int val;
                node* next;
                node* prev;
                node(int _key,int _val){
                    key = _key;
                    val = _val;
                }
        };
        
        node* head =new node(-1,-1);
        node* tail =new node(-1,-1);
        
        int sz;
        unordered_map<int,node*> m;
     
    void addNode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }    
    
    void deleteNode(node* delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        sz = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key) != m.end()){
            node *resnode = m[key];
            int res =resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void put(int key, int value)
    {
        // your code here   
        if(m.find(key)  != m.end()){
            node* existingnode = m[key];
            m.erase(key);
            deleteNode(existingnode);
        }
        if(m.size() == sz){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */