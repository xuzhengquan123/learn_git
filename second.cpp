#include<stdio.h>    
#define MAX 100  
#define MAXCOST 0x7fffffff  

int graph[MAX][MAX];  

void prim(int graph[][MAX], int n)  
{  
    int lowcost[MAX];  
    int mst[MAX];  
    int i, j, min, minid, sum = 0;  
    for (i = 2; i <= n; i++)  
    {  
        lowcost[i] = graph[1][i];//lowcost存放顶点1可达点的路径长度 
        mst[i] = 1;//初始化以1位起始点 
    }  
    mst[1] = 0;
	printf("其设计方案如下：\n");  
    for (i = 2; i <= n; i++)  
    {  
        min = MAXCOST;  
        minid = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (lowcost[j] < min && lowcost[j] != 0)  
            {  
                min = lowcost[j];//找出权值最短的路径长度 
                minid = j; //找出最小的ID 
            }  
        }  
        printf("V%d-->V%d\n",mst[minid],minid); 
        sum += min;//求和 
        lowcost[minid] = 0;//该处最短路径置为0 
        for (j = 2; j <= n; j++)
        {  
            if (graph[minid][j] < lowcost[j])//对这一点直达的顶点进行路径更新 
            {  
                lowcost[j] = graph[minid][j];  
                mst[j] = minid;
            }  
        }  
    }  
    printf("在保证城市之间相互通信的同时，其最小总造价为%d\n",sum);
}  
int main()  
{  
    int i, j, k, m, n;  
    int x, y, cost;
	printf("请输入顶点个数和边数：");  
    scanf("%d%d",&m,&n);//m=顶点的个数，n=边的个数  

    for (i = 1; i <= m; i++)//初始化图 
    {  
        for (j = 1; j <= m; j++)  
        {  
            graph[i][j] = MAXCOST;  
        }  
    } 
	printf("请输入边的起始点、终止点及边的权值：\n");  
    for (k = 1; k <= n; k++)  
    {  
    scanf("%d%d%d",&i,&j,&cost);
        graph[i][j] = cost;  
        graph[j][i] = cost;  
    }  

    prim(graph, m);  
    return 0;  
}  

