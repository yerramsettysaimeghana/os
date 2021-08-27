#include<iostream>
using namespace std;

int main(){
      int processes;
      cout << "Enter the no of processes : " ;
      cin >> processes;
      int burst_time[processes],i;
      for(i=0;i<processes;++i){

            cout << "Enter the burst time of process" << i+1 << "  ";
            cin >> burst_time[i];
      }
      
      int waiting_time[processes],avg_waiting_time=0;

      waiting_time[0]=0;

      for(i=1;i<processes;++i){
            waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
            avg_waiting_time += waiting_time[i];
      }

      cout << "processes\t burst time \twaiting time \tturn around time "<< endl;

      int turn_around_time[processes],avg_turn_around_time=0;

      for(i=0;i<processes;++i){

            turn_around_time[i]=waiting_time[i]+burst_time[i];
            avg_turn_around_time += turn_around_time[i];
            cout << i+1 << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;

      }

      
      cout << "Average turn around time is " << float(avg_turn_around_time)/float(processes) << endl;

      cout << "Average waiting time is "<< float(avg_waiting_time)/float(processes) << endl;

}