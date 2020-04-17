#include<iostream>
#include<iomanip>

void knapSack(int, int , int[], int[]);

int getMax(int,int);

int main() {

  //the first element is set to -1 as
  //we are storing item from index 1
  //in val[] and wt[] array
  int val[] = {-1, 100, 20, 60, 40};  //value of the items
  int wt[] = {-1, 3, 2, 4, 1};        //weight of the items

  int n = 4;  //total items
  int W = 5;  //capacity of knapsack

    knapSack(W, n, val, wt);

    return 0;
  }


int getMax(int x, int y)
{
    if(x > y)
    {
      return x;
    } else
    {
      return y;
    }
}


void knapSack(int W, int n, int val[], int wt[])
{
    int i, w;

    //value table having n+1 rows and W+1 columns
    int V[n+1][W+1];

      //fill the row i=0 with value 0
      for(w = 0; w <= W; w++)
      {
        V[0][w] = 0;
      }

      //fille the column w=0 with value 0
      for(i = 0; i <= n; i++)
      {
        V[i][0] = 0;
      }

      //fill the value table
     for(i = 1; i <= n; i++)
     {
        for(w = 1; w <= W; w++)
        {
             if(wt[i] <= w)
             {
              V[i][w] = getMax(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
             }
             else
             {
                 V[i][w] = V[i-1][w];

             }
         }
     }

             //max value that can be put inside the knapsack
     std::cout<<"Max Value: "<< V[n][W]<<std::endl;

}
