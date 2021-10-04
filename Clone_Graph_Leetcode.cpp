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
    
    Node* func(Node* node, map <Node*, Node*> &mape) {
        if(!node) return NULL;
        if(mape.find(node) != mape.end())
            return mape[node];
        Node* a = new Node(node->val);
        mape[node] = a;
        for(auto i: (node->neighbors)) {
            (a->neighbors).push_back(func(i, mape));
        }
        return a;
    }
    
    Node* cloneGraph(Node* node) {
        map <Node*, Node*> mape;
        return func(node, mape);
    }
};
