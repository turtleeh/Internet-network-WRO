#include <Vector.h>
 
#define infinite 999
 
int neighbors[2] = {1,3};
int distances[2] = {10,5};
 
struct vertex{
  int ID;
  Vector<int> connections;
  Vector<float> weight;
  float distance;
  int previous;
  bool visited;
  };
 
 
vertex minimumDistance(Vector<vertex> list){
  vertex min = list[1];
  for (int i; i<list.size();i++)
    if (list[i].distance<min.distance)
      min=list[i];
  return min;
} 
 
 
Vector<vertex> dijkstra(Vector<vertex> G, vertex S, vertex F){
    Vector<vertex> Q;
    for (int i; i<G.size(); i++){
        G[i].distance = infinite;
        if (G[i].ID != S.ID) {
          Q.push_back(G[i]);
          G[i].visited=false;}
 
    }
    S.distance = 0;
 
    while (Q.size()){
        vertex U = minimumDistance(Q);
        G[U.ID].visited=true;
        for (int i; i<U.connections.size(); i++)
          if (!G[U.connections[i]].visited){
            float tempDistance = U.distance + U.weight[i];
            if (tempDistance < G[U.connections[i]].distance)
                G[U.connections[i]].distance = tempDistance;
                G[U.connections[i]].previous = U.ID;
          }
}
return G;
}
void setup(){
  Serial.begin(9600);
 
 
  Vector<vertex> graph;
  vertex placeholder;
  placeholder.connections.clear();
  placeholder.weight.clear();
  placeholder.ID =0;
  placeholder.connections.push_back(2);
  placeholder.connections.push_back(3);
  placeholder.weight.push_back(2);
  placeholder.weight.push_back(5);
  graph.push_back(placeholder);
 
  placeholder.connections.clear();
  placeholder.weight.clear();
  placeholder.ID = 1;
  placeholder.connections.push_back(2);
  placeholder.connections.push_back(3);
  placeholder.weight.push_back(3);
  placeholder.weight.push_back(4);
  graph.push_back(placeholder);
 
  placeholder.connections.clear();
  placeholder.weight.clear();
  placeholder.ID = 2;
  placeholder.connections.push_back(1);
  placeholder.connections.push_back(0);
  placeholder.weight.push_back(3);
  placeholder.weight.push_back(2);
  graph.push_back(placeholder);
 
  placeholder.connections.clear();
  placeholder.weight.clear();
  placeholder.ID = 3;
  placeholder.connections.push_back(1);
  placeholder.connections.push_back(0);
  placeholder.weight.push_back(4);
  placeholder.weight.push_back(5);
  graph.push_back(placeholder);
 
  graph=dijkstra(graph, graph[0], graph[1]);
  Serial.print(graph[1].previous);
  Serial.print(graph[graph[1].previous].previous);
  Serial.print(graph[graph[graph[1].previous].previous].previous);
}
void loop() {
  }
