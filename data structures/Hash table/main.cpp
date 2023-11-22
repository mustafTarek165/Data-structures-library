#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
struct PhoneEntry{
const static int internal_limit=2147483647;
string name;
string phone_number;
int hash()
{
    return hash_string(name,internal_limit);
}

};
int main()
{

    return 0;
}
