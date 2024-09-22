# include <stdio.h>
# define E 5

void make_Set(int [],int []);
int find_Parent(int [],int);
void sort_Edges(int [E][3]);
void union_Set(int,int,int [],int []);
void Krushkal(int [E][3]);

int main()
{
    int edges[5][3] = { { 0, 1, 10 }, 
                       { 0, 2, 6 }, 
                       { 0, 3, 5 }, 
                       { 1, 3, 15 }, 
                       { 2, 3, 4 } }; 
    Krushkal(edges);
    return 0;
}

void make_Set(int parent[],int rank[])
{
    for(int e=0; e<E; e++)
    {
        parent[e] = e;
        rank[e] = 0;
    }
}

int find_Parent(int parent[],int v)
{
    if(parent[v]!=v)
    {
        parent[v] = find_Parent(parent,parent[v]);
    }
    return parent[v];
}

void sort_Edges(int graph[E][3])
{
    int exchg=0;
    for(int i=0; i<E; i++)
    {
        exchg=0;
        for(int j=0; j<E-i; j++)
        {
            if(graph[j][2]>graph[j+1][2])
            {
                int t=graph[j][2];
                graph[j][2]=graph[j+1][2];
                graph[j+1][2]=t;

                t=graph[j][1];
                graph[j][1]=graph[j+1][1];
                graph[j+1][1]=t;

                t=graph[j][0];
                graph[j][0]=graph[j+1][0];
                graph[j+1][0]=t;

                exchg++;
            } 
        }
        if(exchg==0)
        {
            break;
        }
    }
}

void union_Set(int v1,int v2,int parent[],int rank[])
{
    v1 = find_Parent(parent,v1);
    v2 = find_Parent(parent,v2);

    if(rank[v1]>rank[v2])
    {
        parent[v2] = v1;
    }
    else if(rank[v2]>rank[v1])
    {
        parent[v1] = v2;
    }
    else
    {
        parent[v1] = v2;
        rank[v2]++;
    }
}

void Krushkal(int edges[E][3])
{
    int parent[E];
    int rank[E];
    sort_Edges(edges);
    make_Set(parent,rank);
    int min_cost=0;

    printf("Edges in graph\nv1 - v2 = E\n");

    for(int e=0; e<E; e++)
    {
        int v1 = find_Parent(parent,edges[e][0]);
        int v2 = find_Parent(parent,edges[e][1]);

        if(v1!=v2)
        {
            union_Set(v1,v2,parent,rank);
            min_cost+=edges[e][2];
            printf("\n%d - %d = %d",edges[e][0],edges[e][1],edges[e][2]);
        }
    }
    printf("\n\nMinimun cost of Spanning Tree : %d",min_cost);
}