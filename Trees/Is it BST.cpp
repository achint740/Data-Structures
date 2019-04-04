/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
        bool checkBST(Node* r,int low=-1000000,int high=1000000)
{

    if(r==NULL)
         return true;

    if(r->data>low && r->data<high && checkBST(r->left,low,r->data) && checkBST(r->right,r->data,high))
          return true;
    
         return false;

}
