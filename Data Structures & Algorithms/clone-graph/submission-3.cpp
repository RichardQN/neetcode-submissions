/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloneMap;
        return dfs(node, cloneMap);

    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneMap){
        if (!node){
            return nullptr;
        }

        if (cloneMap.contains(node)){
            return cloneMap[node];
        }

        Node* clone = new Node(node->val);
        cloneMap[node] = clone;

        for (Node* neighbor : node->neighbors){
            clone->neighbors.push_back(dfs(neighbor, cloneMap));
        }

        return clone;
    }
};
