#include <stdio.h>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector< pair<int,int> > >GRAPH(100001);
vector<vector<int> >allPaths;
int m = 100000;

// inline void print_path(vector<int>path)
// {
//     cout<<"[ ";
//     for(int i=0;i<path.size();++i)
//     {
//         cout<<path[i]<<" ";
//     }
//     cout<<"]"<<endl;
// }

bool isadjacency_node_not_present_in_current_path(int node,vector<int>path)
{
    for(int i=0;i<path.size();++i)
    {
        if(path[i]==node)
            return false;
    }
    return true;
}

void findpaths(int source ,int target ,int totalnode,int totaledge)
{
    vector<int>path;
    path.push_back(source);
    queue< pair<vector<int>,int> >q;
    pair<vector<int>,int> p(path,0);
    q.push(p);

    while(!q.empty())
    {
        p=q.front();
        q.pop();
        path = p.first;
        int last_nodeof_path=path[path.size()-1];
        if(last_nodeof_path==target)
        {
            m = min (m,p.second);
        }
        for(int i=0;i<GRAPH[last_nodeof_path].size();++i)
        {
            if(isadjacency_node_not_present_in_current_path(GRAPH[last_nodeof_path][i].first,path))
            {
                vector<int>new_path(path.begin(),path.end());
                new_path.push_back(GRAPH[last_nodeof_path][i].first);
                pair<vector<int>,int> p2(new_path,p.second);
                
                if (GRAPH[last_nodeof_path][i].second == -1)  {
                    p2.second+=1;
                }
                q.push(p2);
            }
        }
    }
}

// int countInversions(vector<int> path) {
//     int ans = 0;
//     for (int i = 0; i < path.size() -1; i++) {
//         vector<pair<int,int> > vec = GRAPH[path[i]];
//         for (int j = 0; j < vec.size(); j++) {
//             if (vec[j].first == path[i+1] && vec[j].second == -1) {
//                 ans++;
//                 // printf("%d %d\n",path[i],path[i+1]);
//             }
//         }
//     }
//     return ans;
// }


int main()
{
    int N,M,u,v,source,target;
        scanf("%d%d",&N,&M);
        for(int i=1;i<=M;++i)
        {
            scanf("%d%d",&u,&v);
            pair<int,int> p1(v,1);
            GRAPH[u].push_back(p1);
            pair<int,int> p2(u,-1);
            GRAPH[v].push_back(p2);
        }
        findpaths(1,N,N,M);
    // int m = 100000;
    // for (int i =0; i < allPaths.size();i++) {
    //     m = min(m,countInversions(allPaths[i]));
    // }
    printf("%d\n",m);
    return 0;
}
