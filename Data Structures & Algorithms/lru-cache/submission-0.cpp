class LRUCache {
public:
    
    struct Node{
        int key;
        int val;
        struct Node* next;
        struct Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> lookTable;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

   
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (lookTable.contains(key)){
            Node* node = lookTable[key];
            remove(node);
            insertFront(node);
            return node->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (lookTable.contains(key)){
            lookTable[key]->val = value;
            remove(lookTable[key]);
        } else {
            Node* newNode = new Node(key, value);
            lookTable[key] = newNode;
            if (lookTable.size() > cap){
                Node* lru = tail->prev;
                lookTable.erase(lru->key);
                remove(lru);
                delete lru;
            }
            
        }
        insertFront(lookTable[key]);
    }
};
