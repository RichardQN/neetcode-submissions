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
        unordered_map<Node*, int> indexes;
        vector<Node*> nodes;
        Node* temp = head;
        int i = 0;
        while (temp) {
            indexes[temp] = i;
            nodes.push_back(temp);
            i++;
            temp = temp->next;
        }
        vector<int> pairs(nodes.size());
        for (int j = 0; j < nodes.size(); j++) {
            if (nodes[j]->random == nullptr) {
                pairs[j] = -1;
            } else {
                int index = indexes[nodes[j]->random];
                pairs[j] = index;
            }
        }

        Node dummy(0);
        Node* tail = &dummy;
        
        vector<Node*> deep;
        for (int k = 0; k < nodes.size(); k++) {
            Node* newNode = new Node(nodes[k]->val);
            tail->next = newNode;
            tail = tail->next;
            deep.push_back(newNode);
        }

        /*for (int m = 0; m < nodes.size(); m++) {
            if (nodes[m+1] ==  nullptr) {
                deep[m]->next = nullptr;
            } else {
                deep[m]->next = deep[m+1];
            }
        }*/

        for (int x = 0; x < nodes.size(); x++) {
            if (pairs[x] == -1) {
                deep[x]->random = nullptr;
            } else {
                deep[x]->random = deep[pairs[x]];
            }
            
        }
        return dummy.next;


    }
};
