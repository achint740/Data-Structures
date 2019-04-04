
/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

node* r;
void decode_huff(node * root, string s,int i=0,int f=0)
{
    if(s[i]=='\0')
      return;
    if(f==0)
     {
         r = root;
         f-=1;
     }
   if(s[i]=='0')
   {
       if((root->left)->data)
        {
            cout<<(root->left)->data;
            decode_huff(r,s,i+1,f);
        }
     else
       decode_huff(root->left,s,i+1,f);
   }
   else
   {
      if((root->right)->data)
      {
          cout<<(root->right)->data;
          decode_huff(r,s,i+1,f);
      }
      else
        decode_huff(root->right,s,i+1,f);
   }
  return;  
}

