#include <iostream>
#include <vector>
#include <list>
using namespace std;
//Cycle Detection in Undirected Graph using DFS
class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleDFS(int u, vector<bool>& vis, int par){
        vis[u] = true;
        for(int v : l[u]){
            if(!vis[v]){
                if(isCycleDFS(v, vis, u)){
                    return true;
                }
            } else if(v != par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){ //O(V + E)
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, -1)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);


    cout << (g.isCycle() ? "True" : "False");
    return 0;
}