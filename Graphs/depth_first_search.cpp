#include <iostream>




/*
 * Step 1: We consider a vertex as the starting vertex, in this case vertex 3.
 *Step 2: We push vertex 3 into the stack.
 *Step 3: We set visited[3] = 1 which means we have visited vertex 3.
 *Step 4: Print starting vertex 3 as the first result.
 *Step 5: If the stack is not empty then, take the top vertex in the stack. Else STOP.
 *Step 6: Set i = vertex at the top of the stack.
 *Step 7: If visited[j] == false AND Adj[i][j] == 1 where j = 0 to 3, then Next result is j
 *Step 8: Set visited[j] = true.
 *Step 9: Push j into the stack. Go to step 5.
 */

const int MAX = 20;

void dfs(int Adj[][MAX], int n, int source);

int main(void)
{

  int Adj[][MAX] = { //Adj matrix
    {0,1,0,0},
    {0,1,1,1},
    {1,0,0,1},
    {0,0,1,0}
  };
  int n = 4;               //no. of vertex
  int starting_vertex = 3;

    dfs(Adj, n, starting_vertex);

    return 0;
}


void dfs(int Adj[][MAX], int n, int start)
  {

    int i, j;                                //variables
    bool change = false;

    bool visited[MAX];                      //visited array to flag the vertex that were visited

    int top = 0;                           //top of the stack

    int stack[MAX];                       //stack

    for(i = 0; i < MAX; i++)              //set visited for all vertex to 0 (means unvisited)
      {
        visited[i] = false;
      }

    visited[start] = true;               //mark the visited source

    stack[top] = start;                 //push the vertex into stack

    std::cout<< start <<std::endl;

    while(top >= 0)                     //continue till stack is not empty
    {

      change = false;

      i = stack[top];                   //get vertex at the top of the stack

    for(j = 0; j < n; j++)
     {

        if(visited[j] == 0 && Adj[i][j] == 1)
          {

           visited[j] = true;                   //mark vertex as visited

           top++;                            //push vertex into stack
           stack[top] = j;

           std::cout<<j<<std::endl;          //print the vertex as result

           change = true;                    //vertex visited

           break;
           }
       }
         if(change == false)
         {
             top--;
          }
       }
           std::cout<<std::endl;
}
