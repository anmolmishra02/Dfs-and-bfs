#include<bits/stdc++.h>
using namespace std;

class treenode
{
  public:
  int val;
  treenode*left;
  treenode*right;
  
  treenode(int v)
  {
    val=v;
    this->left=NULL;
    this->right=NULL;
  }
};

vector<vector<int>> levelorder(treenode*root)
{
  vector<vector<int>> ans;
  if(root==NULL)
  {
    return ans;
  }
  queue<treenode*> q;
  q.push(root);
  while(!q.empty())
  {
    int levelsize=q.size();
    vector<int> curr;
    for(int i=0;i<levelsize;i++)
    {
      treenode*n=q.front();
      q.pop();
      curr.push_back(n->val);
      if(n->left!=NULL)
      {
        q.push(n->left);
      }
      if(n->right!=NULL)
      {
        q.push(n->right);
      }
      
    }
    ans.push_back(curr);
  }
  return ans;
}



int main()
{
  treenode*root=new treenode(1);
  treenode*lef=new treenode(2);
  treenode*righ=new treenode(3);
  root->left=lef;
  root->right=righ;
  root->left->left=new treenode(4);
  root->left->right=new treenode(5);
  root->right->right=new treenode(7);
  vector<vector<int>> ans=levelorder(root);
  for(auto m:ans)
  {
    for(auto i:m)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
}
