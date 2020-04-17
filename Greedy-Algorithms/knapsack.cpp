#include <iostream>
#include<iomanip>

struct Item {   //list of items to be included in the knapsack
  char id[5];
  int weight;   //weight of items
  int value;    // value of items
  float density;      //value per weight
};

void fractionalKnapsack(Item items[], int n, int W);

int main(void) {
  //variables
  int i, j;

  //list items
Item items[6] = {
          {"i1",  6, 6, 0},
          {"i2", 10, 2, 0},
          {"i3",  3, 1, 0},
          {"i4",  5, 8, 0},
          {"i5",  1, 3, 0},
          {"i6",  3, 5, 0}
        };


Item temp;              //temp item

int n = 6;             //number of items

int W = 15;            //max weight limit of knapsack


     for(i = 0; i < n; i++) //compute desity for each item
     {

        items[i].density = float(items[i].value) / items[i].weight;

         }

   for(i = 1; i < n; i++)      //sort by density in descending order
   {
       for(j = 0; j < n - i; j++)
       {
           if(items[j+1].density > items[j].density)
           {
                  temp = items[j+1];
                  items[j+1] = items[j];
                  items[j] = temp;

            }
        }
    }

fractionalKnapsack(items, n, W);

return 0;

}

/*
*Calculate value per weight for each item ( i.e density)
*Sort the items as per  density in descending order
*Take as much item as possible not already taken in the knapsack
*/

void fractionalKnapsack(Item items[], int n, int W)
{

    int i, wt;
    float value;
    float totalWeight = 0, totalBenefit = 0;

    for(i = 0; i < n; i++)
    {

      if(items[i].weight + totalWeight <= W)
      {

         totalWeight += items[i].weight;
         totalBenefit += items[i].value;

         std::cout<<"Selected Item: "<<items[i].id <<"       Weight: "<< items[i].weight <<
                    "         Value: "<<items[i].value<< "         Total Weight: "<<totalWeight<< "         Total Benefit: "<< totalBenefit<<std::endl;

       } else

      {

         wt = static_cast<int>((W - totalWeight));        //find the weight that can be taken to fill the knapsack

         if(wt != 0)
         {
             value = wt * (float(items[i].value) / items[i].weight);  //value of remaining weight

             totalWeight += wt;

             totalBenefit += value;


             std::cout<<"Selected Item: "<<items[i].id <<"       Weight: "<< wt <<"         Value: "<<value<<
                        "Total Weight: "<<totalWeight<< "         Total Benefit: "<< totalBenefit<<std::endl;
             break;
         }


       }
    }
          std::cout<<std::endl;
          std::cout<<" Total Weight: "<<totalWeight<<std::endl;
          std::cout<<" Total Benefit: "<<totalBenefit<<std::endl;

}
