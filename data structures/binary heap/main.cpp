#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class MinHeap
{
private:
int *array{};
int size{};
int capacity{1000};
int left(int node)
{
    int p=2*node+1;
    if(p>=size)
        return -1;
    return p;
}
int right(int node)
{
    int p=2*node+2;
    if(p>=size)
        return -1;
    return p;
}
int parent(int node)
{
    return node==0?-1:(node-1)/2;
}
public:
    MinHeap()
    {
        array=new int [capacity]{};
        size=0;
    }
    ~MinHeap()
    {
        delete[] array;
        array=nullptr;
    }
     void heapify_up(int child_pos)
     {
         int par_pos=parent(child_pos);
         if(child_pos==0||array[par_pos]<array[child_pos])
            return ;
         swap(array[child_pos],array[par_pos]);
         heapify_up(par_pos);
     }
     void heapify_down(int par_pos)
     {
         int child_pos=left(par_pos);
         int right_child=right(par_pos);
         if(child_pos==-1)
            return ;
        if(right_child!=-1&&array[right_child]<array[child_pos])
            child_pos=right_child;
        if(array[par_pos]>array[child_pos])
        {
            swap(array[par_pos],array[child_pos]);
            heapify_down(child_pos);
        }
     }
         bool isempty()
         {
             return size? 0:1;
         }
    void push(int key)
    {

        array[size++]=key;
        heapify_up(size-1);
    }
      void pop()
      {
           assert(!isempty());
          array[0]=array[--size];
          heapify_down(0);
      }

        int top()
        {
            assert(!isempty());
            return array[0];
        }
        //note: binary heap creation using heapify_down method is O(n) time complexity
};
int main()
{
 MinHeap heap;
heap.push(2);
heap.push(17);
heap.push(22);
heap.push(10);
heap.push(8);
heap.push(37);
heap.push(14);
heap.push(19);
heap.push(7);
heap.push(6);
heap.push(5);
heap.push(12);
heap.push(25);
heap.push(30);
while(!heap.isempty())
{
    cout<<heap.top()<<" ";
    heap.pop();
}
    return 0;
}
