/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> nodes;
    void bfs(Node* root){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* temp = q.front();
                q.pop();

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

                nodes.push_back(temp);
            }
            nodes.push_back(nullptr);
        }
    }
    Node* connect(Node* root) {
        if(!root)return {};
        bfs(root);
        for(int i = 0; i < nodes.size() ; i++){
            if(nodes[i])
                nodes[i]->next = nodes[i + 1];
        }
        return nodes[0];
    }
};