#include<iostream>


const int INF = 9999; //contant to represent infinity

const int V = 4; //total number of vertices in the graph

void displayMST(int graph[V][V], int markedCell[V][V]) //this function will display the MST
{
   int r, c;
  for (r = 0; r < V-1; r++)
  {
    for (c = r+1; c < V; c++)
    {
       if(markedCell[r][c])
          {
            std::cout<<"Edge:"<< r<< "--"<< c <<"   Weight:" << graph[r][c]<<std::endl;
          }
        }
      }

    }

void prim(int graph[V][V]) 
{
   int count = 0,
    min,
    expectedR,
    expectedC;

   bool  solved = false;


  int markedCell[V][V] = {{0}};
  /**
     * this array holds the marked vertices
     * 0 = unmarked
     * 1 = marked
     */
    bool markedVertex[V] = {false};
    markedVertex[0] = true;

 while(!solved)

 {
   min = INF;
   count = 0;
   expectedR = -1;
   expectedC = -1;

         /**
          * find minimum weight from marked vertex
          *
          * note!
          * graph[][] is a square matrix
          * diagonal elements of the graph[][] are zeros
          * and elements on either sides are same
          * example: element graph[1][0] is same as graph[0][1]
          * so, we will check only one side of the diagonal
          */
for (int r = 0; r < V; r++)
  {

  if (markedVertex[r] == true)
    {

    for (int c = r; c < V; c++)
    {

     if (graph[r][c] != 0 && graph[r][c] < min && !markedCell[r][c])
     {

           min = graph[r][c];
           expectedR = r;
           expectedC = c;

       }
     }
   }
  }

         /**
          * mark the newly found vertex for MST
          */
 if (expectedR != -1 && expectedC != -1)
   {
        markedCell[expectedR][expectedC] = 1;
        markedCell[expectedC][expectedR] = 1;
        markedVertex[expectedR] = 1;
        markedVertex[expectedC] = 1;
   }

         /**
          * check if the graph is solved
          */
 for (int i = 0; i < V; i++)
    {
   if (markedVertex[i])
       {
          count++;
        }
         }
    if (count == V)
    {
           solved = true;
     }

       }

       displayMST(graph, markedCell);

     }


int main()
{

 int graph[V][V] =  {

        {0, 5, 10, INF},
         {5, 0, 4, 11},
         {10, 4, 0, 5},
         {INF, 11, 5, 0}

       };


 prim(graph);

       return 0;
}




