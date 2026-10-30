class Node {
    public:
        int val;
        Node* next;
    
    
        Node(int v){
            val = v;
            next = nullptr;
        }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        
    }

    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++){
            if (!temp){return -1;}
            temp = temp->next;
        }
        return temp ? temp->val : -1;

    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
    }

    bool remove(int index) {
        if (index < 0 || !head) return false;

    if (index == 0) {
        Node* old = head;
        head = head->next;
        if (!head) tail = nullptr;   // removed the only node
        delete old;
        return true;
    }

    Node* prev = head;
    for (int i = 0; i < index - 1; i++) {
        if (!prev->next) return false;
        prev = prev->next;
    }
    Node* target = prev->next;
    if (!target) return false;       // index out of range

    prev->next = target->next;
    if (target == tail) tail = prev; // removed the last node
    delete target;
    return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* temp = head;
        while (temp){
            res.push_back(temp->val);
            temp = temp->next;
        }
        return res;
    }
};
