#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;
    node * get_next(vector<node*>&ancestors)
    {
        if(ancestors.size()==0)
            return nullptr;
        node *node=ancestors.back();
        ancestors.pop_back();
        return node;
    }
    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)// target has 2 childrens
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }
      bool find_chain(vector<node*>&ancestors,int target,node *cur)
    {
        ancestors.pb(cur);
        if(target==cur->data)
            return true;
        if(target<cur->data)
            return cur->left&&find_chain(ancestors,target,cur->left);
           return cur->right&&find_chain(ancestors,target,cur->right);
    }
    pair<bool,int>successor1(int target)
    {
        vector<node *>ancestors;
        if(!find_chain(ancestors,target,root))
        return {false,-1};
        node* child=get_next(ancestors);
        if(child->right)
        return {true,findMin(child->right)->data};
        node *parent=get_next(ancestors);
        while(parent &&parent->right==child)
            child=parent,parent=get_next(ancestors);
        if(parent)
        return {true,parent->data};
        return {false ,-1};
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);

    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

      void find_chain(int target)
      {
          vector<node*>ancestors;
          find_chain(ancestors,target,root);
          for(auto i:ancestors) cout<<i->data<<" ";
          cout<<endl;
      }
      void successor(int target)
      {
          pair<bool,int>suc=successor1(target);
          cout<<suc.second<<endl;
      }

};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
       t.remove(20);
        t.successor(25);
    return 0;
}
