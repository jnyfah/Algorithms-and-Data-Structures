#include<iostream>

/**
 * weighted edge of the graph
 */
struct Edge {

  int start;    //starting vertex (node) of the edge
  int end;    //ending vertex (node) of the edge
  int weight;    //weight of the edge

};
struct Graph {

  int E;    //number of edges in the graph
  int V;    //number of vertices in the graph
  struct Edge* edge;  //pointer to array of edges

};

/**
 * this is for the subset
 */
struct subset {

  int parent;    //this is the parent of the subset
  int rank;    //this is the rank of the subset

};
struct Graph* createGraph(int E, int V) {

  //creating graph pointer
   Graph* graph = new Graph;

  //assign no. of edge and no. of vertex
  graph->E = E;
  graph->V = V;

  //pointer to edge
  graph->edge = new Edge;

  //return graph pointer
  return graph;
}

/**
 * this function will find the subset in which
 * the vertex i belongs
 */
int Find(struct subset subsets[], int i)
{

  if (subsets[i].parent != i)
  {

    subsets[i].parent = Find(subsets, subsets[i].parent);

  }

  return subsets[i].parent;
}

/**
 * this function will perform union operation on two subsets
 */
void Union(struct subset subsets[], int vertXSubset, int vertYSubset)
{

  int rootOfX = Find(subsets, vertXSubset);
  int rootOfY = Find(subsets, vertYSubset);

    if (subsets[rootOfX].rank < subsets[rootOfY].rank)
    {

        subsets[rootOfX].parent = rootOfY;

    }
    else if (subsets[rootOfX].rank > subsets[rootOfY].rank)
    {

        subsets[rootOfY].parent = rootOfX;

    }
    else
    {

            subsets[rootOfY].parent = rootOfX;
            subsets[rootOfX].rank++;

        }
    }

    /**
     * this function will sort the edges of a graph by weight
     * in ascending order
     */
void sort(struct Graph* graph)
    {

      //variables
  int i, j, noOfEdges = graph->E;
  Edge* tempEdge = new Edge;
      //bubble sort
        //you can use any other sorting of your choice
  for (i = 1; i < noOfEdges; i++)
  {
    for (j = 0; j < noOfEdges - i; j++)
          {

     if (graph->edge[j].weight > graph->edge[j+1].weight)
     {

         tempEdge->start = graph->edge[j].start;
         tempEdge->end = graph->edge[j].end;
         tempEdge->weight = graph->edge[j].weight;

         graph->edge[j] = graph->edge[j+1];

         graph->edge[j+1].start = tempEdge->start;
         graph->edge[j+1].end = tempEdge->end;
         graph->edge[j+1].weight = tempEdge->weight;

       }
    }
  }
}

           /**
            * this function will display the MST (minimum spanning tree)
            */
void displayMST(struct Graph* graphMST)
{
     int i, noOfEdges = graphMST->E;
     for (i = 0; i < noOfEdges; i++)
     {
       std::cout<<"Edge: "<<graphMST->edge[i].start<<"-->"<<graphMST->edge[i].end<<"    Weight:"<<graphMST->edge[i].weight<<std::endl;

      }
 }

           /**
            * this function will return 1 if cycle is found
            * in the graph otherwise 0
            */
 int hasCycle(struct Graph* graph)
 {

     int i, j, vertXSubset, vertYSubset;

     int V = graph->V;               //total number of vertices in the graph
     int E = graph->E;

     subset* subsets = new subset;

     for (i = 0; i < V; i++)            //initialize subset
     {

          subsets[i].parent = i;
          subsets[i].rank = 0;

       }


     for (j = 0; j < E; j++)             //detect cycle
      {

        vertXSubset = Find(subsets, graph->edge[j].start);
        vertYSubset = Find(subsets, graph->edge[j].end);

         if (vertXSubset == vertYSubset)
         {
                return 1;

          }
         Union(subsets, vertXSubset, vertYSubset);

           }
               return 0;

           }

void kruskal(struct Graph* graph)
{

    int i, j;

    int E = graph->E;                          //number of edges and vertices in the graph
    int V = graph->V;

    sort(graph);

    struct Graph* graphMST = createGraph(V - 1, V);

    for (i = 0, j = 0; i < E && j < V - 1; i++)
    {

        graphMST->edge[j] = graph->edge[i];
        graphMST->E = j + 1;

     if (!hasCycle(graphMST))
     {

       j++;

     }

    }

  displayMST(graphMST);

}


int main ()
{

                               //total number of edges and vertices
 int E = 5;
 int V = 4;

 struct Graph* graph = createGraph(E, V);


  graph->edge[0].start = 0;
  graph->edge[0].end = 1;
  graph->edge[0].weight = 2;

  //edge: A -- C
  graph->edge[1].start = 0;
  graph->edge[1].end = 2;
  graph->edge[1].weight = 2;

  //edge: B -- C
  graph->edge[2].start = 1;
  graph->edge[2].end = 2;
  graph->edge[2].weight = 1;

  //edge: B -- D
  graph->edge[3].start = 1;
  graph->edge[3].end = 3;
  graph->edge[3].weight = 5;

  //edge: D -- C
  graph->edge[4].start = 3;
  graph->edge[4].end = 2;
  graph->edge[4].weight = 3;


 kruskal(graph);
  return 0;
}
