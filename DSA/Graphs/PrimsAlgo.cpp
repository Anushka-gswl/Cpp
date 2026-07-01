#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//Prim's Algo is only used for undirected, weighted and connected graphs
//Greedy Algo

//TC => O(E log V), SC => O(V + E)

class Edge{
public:
    int v;
    int wt;
 
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void prims(int src, vector<vector<Edge>> g){
    int V = g.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //pair<edge wt, neighbour>
    vector<bool> inMST(V, false);
    int minCost = 0;

    pq.push({0,src});

    while(!pq.empty()){
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            minCost += wt;
            for(Edge e : g[u]){
                if(!inMST[e.v]){
                    pq.push({e.wt, e.v});
                }
            }
        }
    }

    cout << minCost;
}

int main(){
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,10));
    g[0].push_back(Edge(3,30));
    g[0].push_back(Edge(2,15));

    g[1].push_back(Edge(3,40));

    g[3].push_back(Edge(2,50));

    g[1].push_back(Edge(0,10));
    g[3].push_back(Edge(0,30));
    g[2].push_back(Edge(0,15));

    g[3].push_back(Edge(1,40));

    g[2].push_back(Edge(3,50));

    prims(0, g);

    return 0;
}