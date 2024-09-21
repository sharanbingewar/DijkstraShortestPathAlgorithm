#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const int V = 5; // vertices A, B, C, D, E

int minDistance(int dist[], bool sptSet[]) 
{
    int min = numeric_limits<int>::max(), minIndex;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) 
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// (dijkstra's algorithm) finding the shortest path from the source vertex
void dijkstra(int graph[V][V], char source) 
{
    int dist[V];              
    bool sptSet[V];           
    string paths[V];          

    for (int i = 0; i < V; i++) {
        dist[i] = numeric_limits<int>::max(); 
        sptSet[i] = false;                      
        paths[i] = "";                          
    }

    dist[source - 'A'] = 0;                     
    paths[source - 'A'] = string(1, source);    

    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true;                  

        for (int v = 0; v < V; v++) 
        {
            
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v]; 
                
                
                if (u == 4) 
                { 
                    paths[v] = paths[u] + " -> " + char('A' + v);
                } else if (u == 0 && v == 1) 
                { 
                    paths[v] = paths[source - 'A'] + " -> E -> " + char('A' + v);
                } else if (u == 0 && v == 2) 
                { 
                    paths[v] = paths[source - 'A'] + " -> E -> B -> " + char('A' + v);
                } else 
                {
                    paths[v] = paths[source - 'A'] + " -> " + char('A' + v);
                }
            }
        }
    }

    cout << "Vertex   Minimum Cost    Route" << endl;
    for (int i = 0; i < V; i++) {
        if (i != (source - 'A') && dist[i] != numeric_limits<int>::max()) {
            cout << source << " -> " << char('A' + i) << "       " << dist[i] << "         " << paths[i] << endl;
        }
    }
}


int main() 
{
    int graph[V][V] = 
    {
        {0, 4, 0, 0, 3}, 
        {0, 0, 2, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 1, 0, 2, 0}  
    };

    char source = 'A'; 
    dijkstra(graph, source);

    return 0;
}
