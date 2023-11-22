#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class Stack_array_based{

private:
    int size{};
    int top{};
    int *array{};
public:
    Stack_array_based(int size): size(size),top(-1)
    {
        array =new int [size];
    }
int isfull()
{
    return top==size-1;
}
int isempty()
{
    return top==-1;
}
void display()
{
    for(int i=top;i>=0;i--)
        cout<<array[i]<<" ";
    cout<<"\n";
}
void push(int x)
{
    assert(!isfull());
    array[++top]=x;
}
int pop()
{
    assert(!isempty());
    return array[top--];
}
int peek()
{
    assert(!isempty());
    return array[top];
}
};
class Stack_linkedlist_based
{
private:
    struct Node
    {
        int data{};
        Node* next{};
        Node(int data):data(data){}
    };
    Node * head{};
public:
    void push(int value)
    {
        Node* item=new Node(value);
        item->next=head;
        head=item;
    }
    int isempty()
    {
        return !head;
    }
    int pop()
    {
        assert(!isempty());
        int element=head->data;
        Node* temp=head;
        head=head->next;
        delete temp;
        return element;
    }
    int peek()
    {
        assert(!isempty());
        int element=head->data;
        return element;
    }
};
int precedence(char op)
    {
        if(op=='+'||op=='-')
            return 1;
        if(op=='*'||op=='/')
            return 2;
        return 0;
    }
 string infixtopostfix(string &infix)
    {
        Stack_linkedlist_based operators;
        string postfix="";
        for(int i=0; i<infix.size(); i++)
        {
            if(isdigit(infix[i]))
            {
                postfix+=infix[i];
            }
            else if(infix[i]=='(')
            {
                operators.push(infix[i]);
            }
            else if(infix[i]==')')
            {
                while(operators.peek()!='(') postfix+=operators.pop();
                operators.pop();
            }
            else
            {
                while(!operators.isempty()&&precedence(operators.peek())>=precedence(infix[i]))//note that precedence of '(' is 0 by definition which is less than any operator
                {
                    postfix+=operators.pop();
                }
                operators.push(infix[i]);
            }
        }
        while(!operators.isempty())
            postfix+=operators.pop();
        return postfix;
    }
int main()
{
/*Stack_array_based s(5);
s.push(2);
s.push(5);
s.push(1);
while(!s.isempty())
{
    cout<<s.peek()<<" ";
     s.pop();
}
*/
/*Stack_linkedlist_based w;
w.push(7);
w.push(9);
w.push(10);
while(!w.isempty())
{
    cout<<w.peek()<<" ";
     w.pop();
}
*/

string x;
cin>>x;
cout<<infixtopostfix(x);

    return 0;
}
