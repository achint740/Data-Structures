
/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node* insert(Node* root,int data)
{

    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if((data)<=(root->data))
        root->left =insert(root->left,data);

    if((data)>(root->data))
        root->right = insert(root->right,data);

    return root;
}

