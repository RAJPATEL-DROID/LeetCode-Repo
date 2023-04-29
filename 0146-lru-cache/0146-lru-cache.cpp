class LRUCache {
public:
//      class node {
//             public : 
//                 int key;
//                 int val;
//                 node* next;
//                 node* prev;
//                 node(int _key,int _val){
//                     key = _key;
//                     val = _val;
//                 }
//         };
        
//         node* head =new node(-1,-1);
//         node* tail =new node(-1,-1);
        
//         int sz;
//         unordered_map<int,node*> m;
     
//     void addNode(node* newnode){
//         node* temp = head->next;
//         newnode->next = temp;
//         newnode->prev = head;
//         head->next = newnode;
//         temp->prev = newnode;
//     }    
    
//     void deleteNode(node* delnode){
//         node *delprev = delnode->prev;
//         node *delnext = delnode->next;
//         delnext->prev = delprev;
//         delprev->next = delnext;
//     }
//     //Constructor for initializing the cache capacity with the given value.
//     LRUCache(int cap)
//     {
//         // code here
//         sz = cap;
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     //Function to return value corresponding to the key.
//     int get(int key)
//     {
//         // your code here
//         if(m.find(key) != m.end()){
//             node *resnode = m[key];
//             int res =resnode->val;
//             m.erase(key);
//             deleteNode(resnode);
//             addNode(resnode);
//             m[key] = head->next;
//             return res;
//         }
//         return -1;
//     }
    
//     //Function for storing key-value pair.
//     void put(int key, int value)
//     {
//         // your code here   
//         if(m.find(key)  != m.end()){
//             node* existingnode = m[key];
//             m.erase(key);
//             deleteNode(existingnode);
//         }
//         if(m.size() == sz){
//             m.erase(tail->prev->key);
//             deleteNode(tail->prev);
//         }
        
//         addNode(new node(key,value));
//         m[key] = head->next;
//     }
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um; 

public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        li.splice(li.begin(), li, um[key]);
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
            return;
        }
        
        if (um.size() == capacity) {
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }
        
        li.emplace_front(key, value);
        um[key] = li.begin();
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */