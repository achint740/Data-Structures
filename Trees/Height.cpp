

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        if(root==NULL)
          return -1;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
//         return 1+max(height(root->left),height(root->right));
        // Write your code here.
    }
