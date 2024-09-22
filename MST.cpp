# include <stdio.h>
# define Vertex 5
# define infinite 1000

void primMST(int [Vertex][Vertex]);
void printMST(int [Vertex][Vertex],int [Vertex]);
int min_Key(int [Vertex][Vertex],int [Vertex],bool [Vertex]);
void update_Parent(int ,int [Vertex][Vertex],int [Vertex],bool [Vertex],int [Vertex]);

int main()
{
    int graph[Vertex][Vertex] = { 
                        { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}

int min_Key(int graph[Vertex][Vertex],int key[Vertex],bool visited[Vertex])
{
    int min = infinite;
    int minIndex=-1;
    for(int v=0; v<Vertex; v++)
    {
        if(!visited[v] && min>key[v])
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void update_Parent(int min,int graph[Vertex][Vertex],int key[Vertex],bool visited[Vertex],int parent[Vertex])
{
    for(int v=0; v<Vertex; v++)
    {
        if(graph[min][v] && key[v]>graph[min][v] && !visited[v])
        {
            key[v] = graph[min][v];
            parent[v] = min;
        }
    }
}

void printMST(int graph[Vertex][Vertex],int parent[Vertex])
{
    int min=0;
    printf("\n");
    for(int v=1; v<Vertex; v++)
    {
        printf("\n%d - %d : %d",v,parent[v],graph[v][parent[v]]);
        min+=graph[v][parent[v]];
    }
    printf("\n\nMin Cost : %d",min);
}

void primMST(int graph[Vertex][Vertex])
{
    int parent[Vertex];
    int key[Vertex];
    bool visited[Vertex];

    for(int v=0; v<Vertex; v++)
    {
        key[v] = infinite;
        visited[v] = false;
        parent[v] = -1;
    }

    key[0] = 0;
    parent[0]=-1;
    
    for(int v=1; v<Vertex; v++)
    {
        int min = min_Key(graph,key,visited);
        visited[min] = true;

        update_Parent(min,graph,key,visited,parent);
    }
    printMST(graph,parent);
}