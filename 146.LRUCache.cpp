class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node *prev;
            node *next;
            node(int _key, int _val){
                key = _key;
                val = _val;
            } 
    };
    node *head = new node(-1, -1);
    node *tail  = new node (-1, -1);

    int cap;
    unordered_map<int, node*>m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        node * temp = m[key];

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
        return temp->val;
    }
    
    void put(int key, int value) {
        node *temp = new node({key, value});
        if(m.find(key)!=m.end()){
            node *t2 = m[key];
            m[key] = temp;
            t2->prev->next = t2->next;
            t2->next->prev = t2->prev;
            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
        }
        else if(m.size()<cap){
            m[key] = temp;
            // temp->prev->next = temp->next;
            // temp->next->prev = temp->prev;
            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
        }else{
            int k = tail->prev->key;
            cout<<k;
            m.erase(k);
            m[key] = temp;
            node * dlt = tail->prev;
            m.erase(dlt->key);
            m[key] = temp;
            dlt ->prev->next = tail;
            tail->prev = dlt->prev;

            temp->prev =head;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */