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
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* actual){
        // if actual is NULL
        if(actual==NULL){
            return NULL;
        }

        // If current node is already cloned than return from existing cloned Map.
        if(oldToNew.count(actual)){
            return oldToNew[actual];
        }

        Node* node = new Node(actual->val);

        // save the node into map
        oldToNew[actual]=node;

        // copy the neighbors
        for(int i=0;i<actual->neighbors.size();i++){
            node->neighbors.push_back(dfs(actual->neighbors[i]));
        }

        return node;
        
    }
public:
    Node* cloneGraph(Node* node) {
        Node* root = new Node();
        if(node==NULL){
            return NULL;
        }
        else if(node!=NULL){
            root = dfs(node);
        }

        return root;

    }
};
