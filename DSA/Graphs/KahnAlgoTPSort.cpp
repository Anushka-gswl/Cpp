#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);//only directed edges
    }

    void bfsKahn(){ //O(V + E)
        vector<int> indegree(V, 0);
        vector<int> ans;
        for(int i = 0; i < V; i++){
            for(int v : l[i]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int v : l[curr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(ans.size() != V){
            cout << "It is a cyclic graph so topological sort is not possible.";
            return;
        }
        for(int a : ans){
            cout << a << " ";
        }
    }
};

int main(){
    Graph g(6);

    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.bfsKahn();

    return 0;
}