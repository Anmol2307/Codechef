#include <iostream>
#include <list>
#include <cstdio>
#include <queue>
#include <cstdlib>
 
using namespace std;
int m = 1000000;
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<pair<int,int> > *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
    bool isReachable(int s, int d);
    bool isadjacency_node_not_present_in_current_path(int node,list<int>path);
    int findPath(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int,int> >[V+1];
}
 
void Graph::addEdge(int v, int w)
{
    pair <int,int> p(w,1);
    adj[v].push_back(p); // Add w to v’s list.
    p.first = v; p.second = -1;
    adj[w].push_back(p);
}
 
// void Graph::DFSUtil(int v, bool visited[])
// {
//     // Mark the current node as visited and print it
//     visited[v] = true;
//     cout << v << " ";
 
//     // Recur for all the vertices adjacent to this vertex
//     list<int>::iterator i;
//     for(i = adj[v].begin(); i != adj[v].end(); ++i)
//         if(!visited[*i])
//             DFSUtil(*i, visited);
// }
 
// // DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
// void Graph::DFS(int v)
// {
//     // Mark all the vertices as not visited
//     bool *visited = new bool[V+1];
//     for(int i = 1; i <= V; i++)
//         visited[i] = false;
 
//     // Call the recursive helper function to print DFS traversal
//     DFSUtil(v, visited);
// }

// A BFS based function to check whether d is reachable from s.
// bool Graph::isReachable(int s, int d)
// {
//     // Base case
//     if (s == d)
//       return true;
 
//     // Mark all the vertices as not visited
//     bool *visited = new bool[V+1];
//     for (int i = 0; i < V; i++)
//         visited[i] = false;
 
//     // Create a queue for BFS
//     list<int> queue;
 
//     // Mark the current node as visited and enqueue it
//     visited[s] = true;
//     queue.push_back(s);
 
//     // it will be used to get all adjacent vertices of a vertex
//     list<int>::iterator i;
 
//     while (!queue.empty())
//     {
//         // Dequeue a vertex from queue and print it
//         s = queue.front();
//         queue.pop_front();
 
//         // Get all adjacent vertices of the dequeued vertex s
//         // If a adjacent has not been visited, then mark it visited
//         // and enqueue it
//         for (i = adj[s].begin(); i != adj[s].end(); ++i)
//         {
//             // If this adjacent node is the destination node, then return true
//             if (*i == d)
//                 return true;
 
//             // Else, continue to do BFS
//             if (!visited[*i])
//             {
//                 visited[*i] = true;
//                 queue.push_back(*i);
//             }
//         }
//     }
 
//     return false;
// }

bool Graph::isadjacency_node_not_present_in_current_path(int node,list<int>path)
{
    list<int>::iterator itr=path.begin();
    itr++;
    for(;itr!=path.end();itr++)
    {
        if(*itr==node)
            return false;
    }
    return true;
}

int Graph::findPath(int s, int d) {
    
    list <list <int> > allPaths;
    list<int>path;
    path.push_back(s);
    path.push_front(0);
    queue<list<int> >q;
    q.push(path);

    while(!q.empty())
    {
        path=q.front();
        q.pop();

        int last_nodeof_path=path.back();
        // printf("%d\n",last_nodeof_path);
        if(last_nodeof_path==d)
        {
            allPaths.push_back(path);
            // printf("%d\n",path.front());
            m = min (m,path.front());
        }

        list<pair<int,int> >::iterator itr = adj[last_nodeof_path].begin();

        for(;itr!=adj[last_nodeof_path].end();itr++)
        {
            if(isadjacency_node_not_present_in_current_path((*itr).first,path))
            {
                list<int>new_path(path.begin(),path.end());
                new_path.push_back((*itr).first);
                int val = new_path.front();
                new_path.pop_front();
                if ((*itr).second == -1) val++;
                new_path.push_front(val);
                q.push(new_path);
            }
        }
    }
    return m;
}
 
int main()
{
    
    int n,m;
    scanf("%d %d",&n,&m);
    Graph g(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        g.addEdge(x, y);
    }

    // list <list <int> > paths = g.findPath(1,n);
    int ans = g.findPath(1,n);
    // printf("%lu\n",paths.size());
    // exit(0);
    // list <list <int> >::iterator it;

    // for (it = paths.begin(); it != paths.end();it++) {
    //     list<int> lst = *it;
    //     list<int>::iterator i = lst.begin();
    //     for (;i!=lst.end();i++) {
    //         printf("%d ",*i);
    //     }
    //     printf("\n");
    // }
    printf("%d\n",ans);
    return 0;
}