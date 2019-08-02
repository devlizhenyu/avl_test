#include <iostream>
#include "graph.h"
#include <queue>
#include <string.h>
using namespace std;


/* 

参考  https://www.cnblogs.com/mcomco/p/10298021.html
*/
/**********************************邻接矩阵测试用例************************************* */
void dfs_test()
{
    int adj[max1][max1];
    int visit[max1]={0};
    memset(&adj[0][0],0,max1*max1*sizeof(int));
    create_graph(adj);
    graph_dfs(adj,visit);
    cout<<""<<endl;

    int count=0;
    for(int group=1;group<=12;group++)
    {
        if(count==max1)
        {
            break;
        }
        cout<<"group:"<<group<<endl;
        for(int i=-0;i<=12;i++)
        {
            if(visit[i]==group)
            {
                cout<<i<<" ";
                count++;
            }
        }
        cout<<""<<endl;
    }
    return;
}

void bfs_test()
{
    int adj[max1][max1];
    int dis[max1]={0};
    int start=0;
    int end=0;

    memset(&adj[0][0],0,max1*max1*sizeof(int));
    create_graph(adj);
    graph_bfs(adj,start,end,dis);
    cout<<""<<endl;

    for(int i=0;i<=12;i++)
    {
        cout<<i<<"距离点"<<start<<"距离是"<<dis[i]<<endl;
    }
    return;
}

/*******************************邻接表测试用例********************************** */
void dfs_test1()
{
    adjlist adj[max1];
    int visit[max1]={0};
    for(int i=0;i<=12;i++)
    {
        adj[i].data=i;
        adj[i].next=NULL;
    }
    create_graph(adj);
    graph_dfs(adj,visit);
    cout<<""<<endl;

    int count=0;
    for(int group=1;group<=12;group++)
    {
        if(count==max1)
        {
            break;
        }
        cout<<"group:"<<group<<endl;
        for(int i=-0;i<=12;i++)
        {
            if(visit[i]==group)
            {
                cout<<i<<" ";
                count++;
            }
        }
        cout<<""<<endl;
    }
    return;
}

void bfs_test1()
{
    adjlist adj[max1];
    int dis[max1]={0};
    int start=0;
    int end=0;

    for(int i=0;i<=12;i++)
    {
        adj[i].data=i;
        adj[i].next=NULL;
    }
    create_graph(adj);
    graph_bfs(adj,start,end,dis);
    cout<<""<<endl;

    for(int i=0;i<=12;i++)
    {
        cout<<i<<"距离点"<<start<<"距离是"<<dis[i]<<endl;
    }
    return;
}




int main()
{
    dfs_test();
    cout<<""<<endl;
    bfs_test();
    cout<<""<<endl;
    dfs_test1();
    cout<<""<<endl;
    bfs_test1();
    return 0;
}