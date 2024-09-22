# include <stdio.h>
# define Vertex 5
# define Max 1000

int minKey(int [Vertex],bool [Vertex]);
void primMST(int [Vertex][Vertex]);
void update_key_parent(int,int [Vertex][Vertex],int [Vertex],int [Vertex],bool [Vertex]);
void printMST(int [Vertex],int [Vertex][Vertex]);

int main()
{
    int graph[Vertex][Vertex] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}

int minKey(int key[Vertex],bool mst[Vertex])
{
    int min = Max;
    int minIndex=-1;

    for(int v=0; v<Vertex; v++)
    {
        if(mst[v]==false && min>key[v])
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void update_key_parent(int min,int graph[Vertex][Vertex],int key[Vertex],int parent[Vertex],bool mst[Vertex])
{
    for(int v=0; v<Vertex; v++)
    {
        if(graph[min][v]!=0 && mst[v]==false && graph[min][v]<key[v])
        {
            key[v] = graph[min][v];
            parent[v] = min;
        }
    }
}

void printMST(int parent[Vertex],int graph[Vertex][Vertex])
{
    int least_distance = 0;
    printf("Edge  : Weight\n");
    for(int v=1; v<Vertex; v++)
    {
        printf("\n%d - %d  : %d",parent[v],v,graph[v][parent[v]]);
        least_distance+=graph[v][parent[v]];
    }
    printf("\n\nMinimun Distance : %d",least_distance);
}

void primMST(int graph[Vertex][Vertex])
{
    int key[Vertex];
    int parent[Vertex];
    bool mst[Vertex];

    for(int v=0; v<Vertex; v++)
    {
        key[v] = Max;
        parent[v] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int v=0; v<Vertex-1; v++)
    {
        int min = minKey(key,mst);
        mst[min] = true;

        update_key_parent(min,graph,key,parent,mst);
    }
    printMST(parent,graph);
}
