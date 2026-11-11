class LRUCache {
public:

    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> table;
    Node* head;
    Node* tail;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

    }

    void insert(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }


    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if (table.contains(key)){
            Node* temp = table[key];
            remove(temp);
            insert(temp);
            return table[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (table.contains(key)){
            Node* temp = table[key];
            remove(temp);
            insert(temp);
            temp->val = value;
        } else {
            Node* newNode = new Node(key, value);
            if (table.size() == cap){
                Node* temp = tail->prev;
                table.erase(temp->key);
                remove(temp);
                delete temp;
            }
            insert(newNode);
            table[key] = newNode;
        }
    }
};
