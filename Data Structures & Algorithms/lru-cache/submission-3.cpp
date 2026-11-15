class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node; 
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)){
            Node* temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            Node* temp = cache[key];
            remove(temp);
            insert(temp);
            temp->val = value;
        } else {
            Node* newNode = new Node(key, value);
            if (cache.size() >= cap){
                Node* lru = tail->prev;
                cache.erase(lru->key);
                remove(lru);
                delete(lru);
            }
            insert(newNode);
            cache[key] = newNode;
        }
    }
};
