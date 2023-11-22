#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
int main()
{
    fast
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     ll bit=log2(n)+1;
     ll sum=0,mx=0,i;
     for( i=1;i<=n-bit;i++)
     {
         sum+=i*i;
         mx=max(mx,i*i);
     }
     ll v=n;
     for( i;i<=n;i++)
     {
         //cout<<i<<" "<<v<<endl;
         sum+=(i*v);

         mx=max(mx,i*v);
         v--;
     }
     cout<<sum-mx<<endl;
 }
    return 0;
}
