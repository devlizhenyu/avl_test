#include <iostream>
#include "graph.h"
#include <queue>
#include <string.h>
using namespace std;


/***********************************邻接矩阵实现*************************************** */
void create_graph(int adj[][13])
{
    adj[0][1]=1;
    adj[0][2]=1;
    adj[0][5]=1;
    adj[0][6]=1;
    adj[1][0]=1;
    adj[2][0]=1;
    adj[3][4]=1;
    adj[3][5]=1;
    adj[4][3]=1;
    adj[4][5]=1;
    adj[4][6]=1;
    adj[5][3]=1;
    adj[5][4]=1;
    adj[6][0]=1;
    adj[6][4]=1;
    adj[7][8]=1;
    adj[8][7]=1;
    adj[9][10]=1;
    adj[9][11]=1;
    adj[9][12]=1;
    adj[10][9]=1;
    adj[11][9]=1;
    adj[11][12]=1;
    adj[12][9]=1;
    adj[12][11]=1;
    return;
}

//无向图dfs
void graph_dfs(int adj[][13],int* visit)
{
    int group=0;
    for(int i=0;i<=12;i++)
    {
        if(!visit[i])
        {
            group++;
            visit[i]=group;
            cout<<i<<" ";
            dfs(adj,i,visit,group);
        }
    }
}

void dfs(int adj[][13],int i,int* visit,int group)
{
    for(int j=0;j<=12;j++)
    {
        if(adj[i][j] && !visit[j])
        {
            visit[j]=group;
            cout<<j<<" ";
            dfs(adj,j,visit,group);
        }
    }
    return;
}


//无向图bfs求最短路径
void graph_bfs(int adj[][13],int start,int end,int* dis)
{
    queue<int> q;
    q.push(start);
    int visit[13]={0};
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        visit[temp]=1;
        cout<<temp<<" ";
        for(int i=0;i<=12;i++)
        {
            if(adj[temp][i] && !visit[i])
            {
                visit[i]=1;
                dis[i]=dis[temp]+1;
                q.push(i);
            }
        }
    }
    return;
}

/**************************************邻接表实现********************************** */
void create_graph(adjlist* adj)
{
    adj[0].next=new edgenode(1);
    adj[0].next->next=new edgenode(2);
    adj[0].next->next->next=new edgenode(5);
    adj[0].next->next->next->next=new edgenode(6);
    adj[1].next=new edgenode(0);
    adj[2].next=new edgenode(0);
    adj[3].next=new edgenode(4);
    adj[3].next->next=new edgenode(5);
    adj[4].next=new edgenode(5);
    adj[4].next->next=new edgenode(3);
    adj[4].next->next->next=new edgenode(6);
    adj[5].next=new edgenode(4);
    adj[5].next->next=new edgenode(3);
    adj[5].next->next->next=new edgenode(0);
    adj[6].next=new edgenode(4);
    adj[6].next->next=new edgenode(0);
    adj[7].next=new edgenode(8);
    adj[8].next=new edgenode(7);
    adj[9].next=new edgenode(10);
    adj[9].next->next=new edgenode(11);
    adj[9].next->next->next=new edgenode(12);
    adj[10].next=new edgenode(9);
    adj[11].next=new edgenode(9);
    adj[11].next->next=new edgenode(12);
    adj[12].next=new edgenode(9);
    adj[12].next->next=new edgenode(11);
    return;
}

void graph_dfs(adjlist* adj,int* visit)
{
    int group=0;
    for(int i=0;i<=12;i++)
    {
        if(!visit[i])
        {
            group++;
            visit[i]=group;
            cout<<i<<" ";
            dfs(adj,i,visit,group);
        }
    }
    return;
}

void dfs(adjlist* adj,int i,int* visit,int group)
{
    edgenode* temp=adj[i].next;
    while(temp)
    {
        if(!visit[temp->data])
        {
            visit[temp->data]=group;
            cout<<temp->data<<" ";
            dfs(adj,temp->data,visit,group);
        }
        temp=temp->next;
    }
    return;
}

void graph_bfs(adjlist* adj,int start,int end,int* dis)
{
    queue<int> q;
    q.push(adj[start].data);
    int visit[max1]={0};
    while(!q.empty())
    {
        int temp=q.front();
        visit[temp]=1;
        q.pop();
        edgenode *temp1=adj[temp].next;
        cout<<temp<<" ";
        while(temp1)
        {
            if(!visit[temp1->data])
        {
            visit[temp1->data]=1;
            q.push(temp1->data);
            dis[temp1->data]=dis[temp]+1;
        }
            temp1=temp1->next;
        }
    }
    return;
}