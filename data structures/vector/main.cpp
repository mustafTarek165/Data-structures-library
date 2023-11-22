#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class Vector{
private:
int size=0;
int *arr=nullptr;
int capacity=0;
public:
    Vector(int size):
        size(size)
        {
            if(size<0)
                size=1;
                capacity=size;
            arr=new int[capacity]{};
        }
    ~Vector()
    {
        delete [] arr;
        arr=nullptr;
    }
    int get(int idx)
    {
        assert(0<=idx&&idx<size);
        return arr[idx];
    }
    void set(int idx,int val)
    {
       assert(0<=idx&&idx<size);
       arr[idx]=val;
    }
    void print ()
    {
       for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
       cout<<"\n";
    }
    int find(int value)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
                       return i;
        }
        return -1;
    }
    int get_front()
   {
        return arr[0];
   }

    int get_back()
    {
          return arr[size-1];
    }
    void expand_capacity()
    {
        capacity*=2;
        int *arr2=new int [capacity]{};
        for(int i=0;i<size;i++)
            arr2[i]=arr[i];
        swap(arr2,arr);
        delete [] arr2;
    }
    void push_back(int value) //  amortized O(1)
    {
        if(size==capacity)
            expand_capacity();
        arr[size++]=value;
    }
};
int main()
{
fast
Vector v(10);
for(int i=0;i<10;i++)
    v.set(i,i);
v.print();
cout<<v.find(5)<<" "<<v.find(20)<<endl;
v.push_back(16);
v.print();
return 0;
}
