#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class BinaryTree
{
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};
public:
    BinaryTree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
    void print_inorder()
    {
        if(left)
            left->print_inorder();
  cout << this->data << " ";
        if(right)
            right->print_inorder();
    }
     void print_preorder()
    {
        cout << this->data << " ";

        if(left)
            left->print_preorder();

        if(right)
            right->print_preorder();
    }

     void print_postorder()
    {
        if(left)
            left->print_postorder();

        if(right)
            right->print_postorder();
             cout << this->data << " ";
    }
    void add(vector<int>v,vector<char>d)
    {
        BinaryTree *current=this;
        for(int i=0;i<v.size();i++)
        {
            if(d[i]=='L')
            {
                if(!current->left)
                    current->left = new BinaryTree(v[i]);
                current=current->left;
            }
            else
            {
                if(!current->right)
                    current->right=new BinaryTree(v[i]);
                current=current->right;
            }

        }
     }

};
int main()
{
BinaryTree tree(50);
tree.add({2,4,7},{'L','L','L'});
tree.add({2,4,8},{'L','L','R'});
tree.add({2,5,9},{'L','R','R'});
tree.add({3,6,10},{'R','R','L'});
tree.print_inorder();
    return 0;
}
