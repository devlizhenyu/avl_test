#include <iostream>
using namespace std;


#define max1 13




void create_graph(int adj[][13]);
void graph_dfs(int adj[][13],int* visit);
void dfs(int adj[][13],int i,int* visit,int group);
void graph_bfs(int adj[][13],int start,int end,int* dis);


/*************************邻接表实现************************ */
struct edgenode
{
    int data;
    edgenode* next;
    edgenode(int x):data(x),next(NULL){}
    edgenode(){}
};

struct adjlist
{
    int data;
    edgenode* next;
    adjlist(int x):data(x),next(NULL){}
    adjlist(){}
};

void create_graph(adjlist* adj);
void graph_dfs(adjlist* adj,int* visit);
void dfs(adjlist* adj,int i,int* visit,int group);
void graph_bfs(adjlist* adj,int start,int end,int* dis);