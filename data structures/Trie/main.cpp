#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
class trie
{
private:
    static const int max_char=26;
    trie* child[max_char];
    bool isleaf;
public:
    trie()
    {
        memset(child,0,sizeof (child));
    }
    //time complexity is O(L),space complexity is O(alphabet_size * L * N)
    void insert(string str,int idx=0)
    {
        if(idx==str.size())
            isleaf=1;
        else
        {
            int cur=str[idx]-'a';
            if(child[cur]==0)
                child[cur]=new trie();
            child[cur]->insert(str,idx+1);
        }
    }
     bool word_exist(string str,int idx=0)
    {
        if(idx==str.size())
            return isleaf;

            int cur=str[idx]-'a';
            if(!child[cur])
                return false;
            return child[cur]->word_exist(str,idx+1);

    }
    bool prefix_exist(string str,int idx=0)
    {
        if(idx==str.size())
            return true;

            int cur=str[idx]-'a';
            if(!child[cur])
                return false;
            return child[cur]->prefix_exist(str,idx+1);

    }

};
int main()
{
trie tree;
tree.insert("ans");
tree.insert("abc");
tree.insert("xyz");
cout<<tree.word_exist("ans")<<endl;
cout<<tree.word_exist("xyz")<<endl;
cout<<tree.prefix_exist("an")<<endl;
cout<<tree.prefix_exist("az")<<endl;
    return 0;
}
