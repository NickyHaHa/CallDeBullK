#include <stdio.h>
#include <deque>
using namespace std;
 
class GraphNode{
public:
  int id;
  deque<int>adjacency;
  int discovered;
 
  GraphNode(int _id){
    id = _id;
    discovered = 0;
  }
  void dump(){
    printf("Vertex: %d, I'm adjacent to: ", id);
    int i;
    for(i = 0; i<adjacency.size(); i++){
      printf("%d ", adjacency[i]);
    }
    printf("\n");
  };
};
 
deque<GraphNode*> NodeList;
void DFS(int vertex){
  GraphNode* curr = NodeList[vertex];
  curr->discovered = 1;
  printf("%d ", vertex);
  int i, next;
  for( i = 0; i < curr->adjacency.size(); i++){
    next = curr->adjacency[i];
    if(NodeList[next]->discovered == 0){
      DFS(next);
    }
  }
}
 
int main(){
  int node_count, edge_count;
  printf("Enter no of vertices: ");
  scanf(" %d", &node_count);
  printf("Enter no of edges: ");
  scanf(" %d", &edge_count);
 
  int i, j;
  for(i = 0; i<node_count; i++){
    NodeList.push_back( new GraphNode(i) );
  }
 
  printf("Enter %d pairs of verteices: \n", edge_count);
  for( j = 0; j < edge_count; j++ ){
    int node_1, node_2;
    scanf("%d %d", &node_1, &node_2);
    NodeList[node_1]->adjacency.push_back(node_2);
    NodeList[node_2]->adjacency.push_back(node_1);
  }
 
  for( i = 0; i < NodeList.size(); i++ ){
    NodeList[i]->dump();
  }
 
  printf("DFS Traversal: ");
  DFS(0);
 
  printf("\n");
  return 0;
}