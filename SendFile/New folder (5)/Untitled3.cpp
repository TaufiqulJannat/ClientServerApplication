#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;
   Node *parent;
};

Node* create_node()
{
   Node *node = (Node*) malloc(sizeof(Node));
   return node;
}

bool has_bracket(string s)
{
   int i;

   for(i=0;i<s.size();i++)
   {
      if(s[i]=='(') return true;
   }
   return false;
}

int get_number(string s)
{
   int i;
   string num;
   for(i=0;s[i]!='('&&i<s.size();i++)
   {
      num+=s[i];
   }
   int ans = atoi(num.c_str());
   return ans;
}

string split(string s,string part)
{
   int i,br,sp;
   string s1,s2;
   for(i=0;i<s.size();i++)
   {
      if(s[i]=='(') { br = i; break; }
   }

   int bracket = 0;

   for(i=br+1;i<s.size();i++)
   {
      if(s[i]=='(') bracket++;
      if(s[i]==')') bracket--;
      if(s[i]==' '&&bracket==0) { sp = i; break; }
      s1+=s[i];

   }

   for(i=sp+1;i<s.size()-1;i++)
   {
        s2+=s[i];
   }
   if(part=="1st") return s1;
   else if(part=="2nd") return s2;
}

void make_tree(string s,Node *root)
{

  int info = get_number(s);
  root->data = info;
  root->left = create_node();
  root->right = create_node();

  if(has_bracket(s)==false) { root->left = NULL; root->right = NULL; return; }

  string s1,s2;
  s1 = split(s,"1st");
  s2 = split(s,"2nd");

  make_tree(s1,root->left);
  make_tree(s2,root->right);

}

void preorder(Node *root)
{
  if(root==NULL) return;

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
  if(root==NULL) return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

void inorder(Node *root)
{
  if(root==NULL) return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main()
{
    string s="10(11(4 3) 1(2(9 7) 5))";
    //getline(cin,s);
    Node *root = create_node();
    make_tree(s,root);

    cout<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;


   return 0;
}
