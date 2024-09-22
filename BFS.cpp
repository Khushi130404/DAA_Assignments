#include <stdio.h>
#define V 5

int visited[V];
int queue[V];
int rear=-1;
int front=-1;

int adjacency[V][V] = 
{{0,1,0,1,0},
{1,0,1,1,1},
{0,1,0,0,1},
{1,1,0,0,1},
{0,1,1,1,0}};

void bfs(int);

int main()
{
    for(int v=0; v<V; v++)
    {
        visited[v] = 0;
    }
    bfs(0);
    return 0;
}

void bfs(int vertex)
{
    visited[vertex] = 1;
    printf("Vertex : %d\n",vertex);
    
    for(int v=0; v<V; v++)
    {
        if(adjacency[vertex][v] && !visited[v])
        {
            queue[++rear] = v;
            visited[v] = 1;
        }
    }

    if(front!=rear)
    {
        bfs(queue[++front]);
    }
}