#include <iostream>
#include<iomanip>

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

const int MAX = 100;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y)
{
  if(x < y)
  {
    return x;
  }else {
     return y;
  }
}
int main() {

  int i, j;


  Job jobs[5] = {     //jobs with deadline and profit
    {"j1", 2,  60},
    {"j2", 1, 100},
    {"j3", 3,  20},
    {"j4", 2,  40},
    {"j5", 1,  20},
  };

  Job temp;

int n = 5;  //number of jobs

  for(i = 1; i < n; i++)   //sort the jobs profit wise in descending order
    {
      for(j = 0; j < n - i; j++)
      {
        if(jobs[j+1].profit > jobs[j].profit)
        {
          temp = jobs[j+1];

          jobs[j+1] = jobs[j];

          jobs[j] = temp;
        }
      }
    }
std::cout<<" Sorted jobs based on profit (descending order) "<<std::endl;
std::cout<< std::setw(10) <<"Job"<<std::setw(10)<<"Deadline"<< std::setw(10)<<"Profit"<<std::endl;

 for(i = 0; i < n; i++)
 {
    std::cout<< std::setw(10) <<jobs[i].id<<std::setw(10)<<jobs[i].deadline<< std::setw(10)<<jobs[i].profit<<std::endl;
 }

jobSequencingWithDeadline(jobs, n);

return 0;
    }

void jobSequencingWithDeadline(Job jobs[], int n)
{
      //variables
      int i, k, maxprofit;

      //free time slots
      int timeslot[MAX];

      //filled time slots
      int filledTimeSlot = 0;


      int dmax = 0;

      for(i = 0; i < n; i++) //find max deadline value
      {
          if(jobs[i].deadline > dmax)
          {
            dmax = jobs[i].deadline;
          }
        }

        //free time slots initially set to -1 [-1 denotes EMPTY]
        for(i = 1; i <= dmax; i++)
        {
          timeslot[i] = -1;
        }
        std::cout<<"dmax: "<<dmax<<std::endl;


        for(i = 1; i <= n; i++)
        {
          k = minValue(dmax, jobs[i - 1].deadline);

          while(k >= 1)
          {
            if(timeslot[k] == -1)
            {

               timeslot[k] = i-1;

               filledTimeSlot++;
               break;
             }
            k--;
          }

                    //if all time slots are filled then stop
         if(filledTimeSlot == dmax)
         {
             break;
          }

     }
        //required jobs
        std::cout<<" \nRequired Jobs:  ";

          for(i = 1; i <= dmax; i++)
          {
           std::cout<<jobs[timeslot[i]].id;

            if(i < dmax)
            {
              std::cout<<" --> ";
            }
          }

          //required profit
          maxprofit = 0;
          for(i = 1; i <= dmax; i++)
          {
            maxprofit += jobs[timeslot[i]].profit;
          }
          std::cout<<"\n Max Profit: "<<maxprofit<<std::endl;

        }
