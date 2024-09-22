#include <stdio.h>
#define V 5

int stack[V];
int visited[V];
int top = -1;

int adjacency[V][V] = 
{{0,1,0,1,0},
{1,0,1,1,1},
{0,1,0,0,1},
{1,1,0,0,1},
{0,1,1,1,0}};

void dfs(int);

int main()
{
    for(int v=0; v<V; v++)
    {
        visited[v] = 0;
    }
    dfs(0);
    return 0;
}

void dfs(int vertex)
{
    visited[vertex] = 1;
    printf("Vertex : %d\n",vertex);

    for(int v=0; v<V; v++)
    {
        if(adjacency[vertex][v] && !visited[v])
        {
            stack[++top] = v;
            visited[v] = 1;
        }
    }   

    if(top!=-1)
    {
        dfs(stack[top--]);
    }
}
