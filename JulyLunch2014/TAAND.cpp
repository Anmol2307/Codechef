#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>
#include <bitset>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////

#define ALPHABET_SIZE (2)
#define INDEX(c) ((int)c - (int)'a')
  
// forward declration
typedef struct trie_node trie_node_t;
 
// trie node
struct trie_node
{
    // int words;
    int prefixes;
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie_t;
 
struct trie
{
    trie_node_t *root;
    int count;
};

int final=0;
 
trie_node_t *getNode(void)
{
    trie_node_t *pNode = new trie_node_t;

 
    pNode->value   = 0;
    // pNode->words = 0;
    pNode->prefixes = 0;
 
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    
    return pNode;
}
 
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

int convertDec (string str) {
  int sz = str.size();
  int ret = 0;
  for (int i = sz-1; i >=0; i--) {
    ret += pow(2,i)*(str[sz-1-i]-'0');
  }
  return ret;
}
 
void insert(trie_t *pTrie, string key)
{
    int length = key.size();
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
    string ans = "";

    
    for(int level = 0; level < length; level++ )
    {
      index = key[level] - '0';
      if(pCrawl->children[1] && index == 1){
        ans.push_back('1');
        // printf("%d %s\n",level,ans.c_str());
        pCrawl = pCrawl->children[1];
      }
      else if (index == 1 && pCrawl->children[0]){
        ans.push_back('0');
        // printf("%d %s\n",level,ans.c_str());
        pCrawl = pCrawl->children[0];
      }
      else if (index==0) {
        ans.push_back('0');
        if (pCrawl->children[0]) pCrawl = pCrawl->children[0];
        else if (pCrawl->children[1]) pCrawl = pCrawl->children[1];
      }
    }

    pCrawl = pTrie->root;


    for(int level = 0; level < length; level++ )
    {
        
        index = key[level] - '0';

        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
            pCrawl->prefixes += 1;
            // printf("1 %c %d\n",key[level],pCrawl->prefixes);
            // pCrawl->prefixes += 1;
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();            
            pCrawl = pCrawl->children[index];
            pCrawl->prefixes += 1;
            // printf("2 %c %d\n",key[level],pCrawl->prefixes);
            
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
    int use = convertDec(ans);
    if (final  < use) {
      final = use;
    }
    // printf("HERE %s %d %d\n",ans.c_str(),final,use);
}

int search(trie_t *pTrie, string key)
{
    int length = key.size();
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for(int level = 0; level < length; level++ )
    {
         index = key[level] - '0';
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    return (0 != pCrawl && pCrawl->value);
}

 
int countPrefixes(trie_t *pTrie, char key[])
{
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for(int level = 0; level < length; level++ )
    {
         index = key[level] - '0';
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
        printf("%c %d\n",key[level],pCrawl->prefixes);
    }
    return pCrawl->prefixes;
    // return (0 != pCrawl && pCrawl->prefixes);
}
 
int leafNode(trie_node_t *pNode)
{
    return (pNode->value != 0);
}
 
int isItFreeNode(trie_node_t *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}
 
bool deleteHelper(trie_node_t *pNode, string key, int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->value )
            {
                // Unmark leaf node
                pNode->value = 0;
 
                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return true;
                }
 
                return false;
            }
        }
        else // Recursive case
        {
            int index = key[level] - '0';
 
            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                // FREE(pNode->children[index]);
 
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }
 
    return false;
}
 
void deleteKey(trie_t *pTrie, char key[])
{
    int len = strlen(key);
 
    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}

int main  () {

  int n;
  inp(n);
  int arr[n];
  string bits[n];
  int max = 0;
  for (int i = 0; i < n; i++) {
    int x;
    inp(x);
    int l = 0;
    while (x) {
      bits[i].insert(0,1,(char)((x%2)+48));
      x /= 2;
      l++;
    }
    if (max < l) max = l;
    // printf("%s\n",bits[i].c_str());
  }

  for (int i = 0; i < n; i++) {
    int sz = bits[i].size();
    if (sz < max) bits[i].insert(0,max-sz,'0');
  }
    // for (int i = 0; i < n; i++) {
    //   printf("%s\n",bits[i].c_str());
    // }
  // exit(0);
  
  trie_t trie;
 
  initialize(&trie);
  for(int i = 0; i < n; i++){
    insert(&trie,bits[i]);
  }
  printf("%d\n",final);
}