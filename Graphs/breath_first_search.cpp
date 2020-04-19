#include <iostream>







/*
 *Step 1: consider a vertex as the starting vertex.
 *Step 2: We enqueue starting vertex  in the queue.
 *Step 3: We set visited[starting vertex] = true which means we have visited the vertex.
 *Step 4: Print starting vertex as the first result.
 *Step 5: If the queue is not empty then, dequeue the first vertex in the stack. Else STOP.
 *Step 6: Set i = dequeue vertex from the queue.
 *Step 7: If visited[j] == false AND Adj[i][j] == 1
 *Step 8: Set visited[j] = true.
 *Step 9: Enqueue j in the queue.
 *Step 10: If j reaches the last index go to step 5.
 */
const int QUEUE_SIZE = 20;
const int MAX = 20;

//queue
int queue[QUEUE_SIZE];
int queue_front, queue_end;
void enqueue(int v);
int dequeue();

void bfs(int Adj[][MAX], int n, int source);

int main()
{

  int Adj[][MAX] = {
    {0,1,0,0},
    {0,1,1,1},
    {1,0,0,1},
    {0,0,1,0}
     };

   int n = 4;  //no. of vertex
   int starting_vertex = 2;

    bfs(Adj, n, starting_vertex);

    return 0;

 }


void bfs(int Adj[][MAX], int n, int source)

{
        int i, j;                                 //variables

        bool visited[MAX];                      //visited array to flag the vertex that were visited

        queue_front = 0;
        queue_end = 0;

       for(i = 0; i < MAX; i++)                 //set visited for all vertex to 0 (means unvisited)
       {
         visited[i] = false;
       }

        visited[source] = true;                 //mark the visited source

        enqueue(source);                       //enqueue visited vertex

        std::cout<<source<<std::endl;

        while(queue_front <= queue_end)
        {

          i = dequeue();

         for(j = 0; j < n; j++)
         {

         if(visited[j] == false && Adj[i][j] == 1)
         {

            visited[j] = true;                    //mark vertex as visited

            enqueue(j);                           //push vertex into stack

            std::cout<<j<<std::endl;
          }
     }
 }

}


void enqueue(int v)
{
    queue[queue_end] = v;
    queue_end++;
}

int dequeue()
{
    int index = queue_front;
    queue_front++;
    return queue[index];
}
