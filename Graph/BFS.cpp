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
 
void BFS(int start){
  deque<int> que;
  que.push_back(start);
  NodeList[start]->discovered = 1;
 
  int curr_id, adj_id;
  GraphNode* curr_node;
  GraphNode* adj_node;
 
  while(que.size() != 0){
    curr_id = que[0];
    que.pop_front();
    printf("%d ", curr_id);
    curr_node = NodeList[curr_id];
 
    for(int i = 0; i < curr_node->adjacency.size(); i++){
      adj_id = curr_node->adjacency[i];
      adj_node = NodeList[adj_id];
      if(adj_node->discovered == 0){
        adj_node->discovered = 1;
        que.push_back(adj_id);
      }
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
 
  printf("BFS Traversal: ");
  BFS(0);
 
  printf("\n");
  return 0;
}