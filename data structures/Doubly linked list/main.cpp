#include <iostream>
using namespace std;
class doubly_linked_list
{
private:
    struct Node
    {
        int data{};
        Node*next{};
        Node* prev{};
        Node(int data) :data(data) {}
        void st(Node* next,Node* prev)
        {
            this->next=next;
            this->prev=next;
        }
    };
    Node* head{};
    Node* tail{};
    int length=0;
      delete_node(Node* node)
    {
        --length;
        delete node;
    }
    void link(Node* first,Node *second)
    {
        if(first)
            first->next=second;
        if(second)
            second->prev=first;
    }
    Node *delete_and_link(Node* cur)
    {
        Node *ret=cur->prev;
        link(cur->prev,cur->next);
        delete_node(cur);
        return ret;
    }
public:
void print_reversed()
{
    for(Node *cur=tail;cur;cur=cur->prev)
        cout<<cur->data<<" ";
}
void print()
{
    for(Node *cur=head;cur;cur=cur->next)
        cout<<cur->data<<" ";
}
void insert_end(int value)
{
    Node* item=new Node(value);
    if(!head)
    {
        head=tail=item;
    }
    else
    {
        link(tail,item);
        tail=item;
    }
}
void insert_front(int value)
{
    Node* item=new Node(value);
    if(!head)
    {
        head=tail=item;
    }
    else
    {
        link(item,head);
        head=item;
    }
}
void delete_front()
{
    if(!head)
        return ;
    Node *cur =head->next;
    delete_node(head);
    head=cur;
    if(head)
        head->prev=nullptr;
    else if(!length)
        tail=nullptr;
}
void delete_node_with_key(int value)
{
    if(!length)
        return;
    if(head->data==value)
        delete_front();
    else
    {
        for(Node *cur=head;cur;cur=cur->next)
        {
            if(cur->data==value)
            {
                cur=delete_and_link(cur);
                if(!cur->next)
                    tail=cur;
                break;
            }
        }
    }
}

};
int main()
{
 doubly_linked_list s;
s.insert_front(12);
s.insert_front(4);
s.insert_front(10);
s.print();

    return 0;
}
