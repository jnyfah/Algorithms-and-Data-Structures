#include <iostream>
#include <iomanip>

struct Activity {
  char id[5];
  int start;
  int finish;
};

void activitySelection(Activity activities[], int n);

int main(void) {

  //activities
  Activity activities[8] = {
    {"a1", 1, 3},
    {"a2", 0, 4},
    {"a3", 1, 2},
    {"a4", 4, 6},
    {"a5", 2, 9},
    {"a6", 5, 8},
    {"a7", 3, 5},
    {"a8", 4, 5}
  };

  //number of activities
  int n = 8;

  activitySelection(activities, n);

  return 0;
}

void activitySelection(Activity activities[], int n) {
  //variables
  int i, j;

  Activity temp;

  for(i = 1; i < n; i++)  //sort the activities based on finishing time in ascending order
  {
    for(j = 0; j < n - 1; j++)
    {
      if(activities[j].finish > activities[j+1].finish)
      {
        temp = activities[j];

        activities[j] = activities[j+1];

        activities[j+1] = temp;
      }
    }
  }

 std::cout<<" Sorted activities as per finish time (ascending order) "<<std::endl;

 std::cout<< std::setw(10) <<" Activity "<<std::setw(10)<<"Start"<< std::setw(10)<<"Finish"<<std::endl;

  for(i = 0; i < n; i++)
  {

   std::cout<< std::setw(10) <<activities[i].id<<std::setw(10)<<activities[i].start<< std::setw(10)<<activities[i].finish<<std::endl;

  }


  //select the first activity
  std::cout<<"-----Selected Activities-----\n"<<std::endl;
  std::cout<< std::setw(10) <<" Activity "<<std::setw(10)<<"Start"<< std::setw(10)<<"Finish"<<std::endl;

  std::cout<< std::setw(10) <<activities[0].id<<std::setw(10)<<activities[0].start<< std::setw(10)<<activities[0].finish<<std::endl;



  //select next activity whose start time is greater than
  //or equal to the finish time of the previously selected activity
  i = 0;
  for(j = 1; j < n; j++)
  {
    if(activities[j].start >= activities[i].finish) {

       std::cout<<std::setw(10) <<activities[j].id<<std::setw(10)<<activities[j].start<< std::setw(10)<<activities[j].finish<<std::endl;

      i = j;
    }
  }
}
