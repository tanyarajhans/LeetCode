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
    Node* visited[102];
    
    void dfs(Node* curr, Node* temp){
        visited[temp->val]=temp;
        for(auto u: curr->neighbors){
            if(visited[u->val]==NULL){
                Node* v=new Node(u->val);
                temp->neighbors.push_back(v);
                dfs(u, v);
            }
            else
                temp->neighbors.push_back(visited[u->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        memset(visited, NULL, sizeof(visited));
        Node* copy=new Node(node->val);
        visited[node->val]=copy;
        for(auto curr: node->neighbors){
            if(visited[curr->val]==NULL){
                Node* temp=new Node(curr->val);
                copy->neighbors.push_back(temp);
                dfs(curr, temp);
            }
            else{
                copy->neighbors.push_back(visited[curr->val]);
            }
        }
        return copy;
    }
};