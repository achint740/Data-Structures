
/*
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

    void levelOrder(Node * root) {
     queue<Node*>q;
     q.push(root);
     q.push(NULL);
    while(!q.empty())
    {
        Node* t = q.front();
        q.pop();
      if(t)
      {
          std::cout<<t->data<<" ";
          if(t->left)
            q.push(t->left);
          if(t->right)
            q.push(t->right);
          //q.pop();
      }
      else
      {
          //std::cout<<" ";
          if(!q.empty())
             q.push(NULL);
      }
    }
    }

