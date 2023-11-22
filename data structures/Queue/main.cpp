#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

class singly_linked_list
{
private:
    struct Node
    {
        int data{};
        Node*next{};
        Node(int data) :data(data) {}
    };
    Node* head{};
    Node* tail{};
    int length=0;
    delete_node(Node* node)
    {
        --length;
        delete node;
    }
public:
      friend class Queue_linkedlist;
    int size_list()
    {
        return length;
    }
    void print()
    {
       for(Node* cur=head;cur;cur=cur->next)
       cout<<cur->data<<" ";
    }
    void insert_end(int value)
    {
        Node *item=new Node(value);
        if(!head) head=tail=item;
        else
        {
            tail->next=item;
            tail=item;
        }
        length++;
    }
    Node *get_nth(int n)
    {
        int cnt=0;
        for(Node* cur=head;cur;cur=cur->next)
        {
            if(++cnt==n)
                return cur;
        }
        return nullptr;
    }
    int search(int value)
    {
        int idx=0;
        for(Node* cur=head;cur;cur=cur->next,idx++)
        {
            if(cur->data==value)
                return idx;
        }
        return -1;
    }
    int search_improved(int value)// O(n)
    {
        int idx=0;
        Node *previous=nullptr;
        for(Node *cur=head;cur;cur=cur->next,idx++)
        {
            if(cur->data==value)
            {
                if(!previous) return idx;
                swap(previous->data,cur->data);
                return idx-1;
            }
            previous=cur;
        }
        return -1;
    }
    void delete_front()// O(1)
    {
        if(head)
        {
            Node *cur=head;
            head=head->next;
            delete_node(cur);
            if(!head)
                tail=nullptr;
        }
    }
    void delete_last()// O(n)
    {
        if(length<=1)
        {
            delete_front();
            return ;
        }
        Node*prev=get_nth(length-1);
        delete_node(tail);
        tail=prev;
        tail->next=nullptr;
    }
    void delete_nth(int n)
    {
        if(n<1||n>length)
            cout<<"Error no such node\n";
        else if(n==1)
            delete_front();
        else
        {
            Node* before_nth=get_nth(n-1);
            Node* nth=before_nth->next;
            bool is_tail= nth ==tail;
            before_nth->next=nth->next;
            if(is_tail)
                tail=before_nth;
            delete_node(nth);
        }
    }
    ~singly_linked_list()
    {
        while(head)
        {
            Node *cur=head->next;
            delete head;
            head=cur;
        }
    }
};
class Queue_linkedlist
{
singly_linked_list s;
public:

    void enqueue(int value)
    {
        s.insert_end(value);
    }
    void dequeue()
    {
        s.delete_front();
    }
    Node * front()
    {
        if(s.size_list()!=0)
        return s.get_nth(1);
        return nullptr;
    }
    void display()
    {
        s.print();
    }
      bool isempty()
      {
          return s.size_list()==0;
      }

};
class Queue_array
{
private:
    int size{};
    int front {};
    int rear {};
    int added_elements{};
    int *array{};
    int next(int pos)
    {
        ++pos;
        if(pos==size)
            pos=0;
        return pos;
    }
public:
    Queue_array(int size):
    size(size){array =new int [size];}
    bool isempty()
    {
        return added_elements==0;
    }
    bool isfull()
    {
        return added_elements==size;
    }
    void enqueue(int value)
    {
        assert(!isfull());
        array[rear]=value;
        rear=next(rear);
        added_elements++;
    }
    void dequeue()
    {
        assert(!isempty());
        int value=array[front];
        front=next(front);
        --added_elements;
    }
    void display()
    {
        if(isfull()) cout<<"full ";
        else if(isempty())
        {
            cout<<"empty ";
            return;
        }
        for(int cur=front,step=0;step<added_elements;++step,cur=next(cur))
            cout<<array[cur]<<" ";
    }

};
int main()
{
Queue_linkedlist q;
q.enqueue(3);
if(q.front()!=nullptr)
cout<<q.front()->data;

    return 0;
}
