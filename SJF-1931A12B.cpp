#include<bits/stdc++.h>
using namespace std;

int main(){
      int noprocesses;
      cout << "Enter the no of processes : " ;
      cin >> noprocesses;
      int burst_time[noprocesses],i,processes[noprocesses];
      for(i=0;i<noprocesses;++i){
            cout << "Enter the burst time of process " << i+1 << "  ";
            cin >> burst_time[i];
            processes[i]=i+1;
      }

      for(i=0;i<noprocesses-1;++i)
            for(int j=0;j<noprocesses-i-1;++j){
                  if(burst_time[j]>burst_time[j+1]){
                        swap(burst_time[j],burst_time[j+1]);
                        swap(processes[j],processes[j+1]);
                  }
            }

      int waiting_time[noprocesses],avg_waiting_time=0;

      waiting_time[0]=0;

      for(i=1;i<noprocesses;++i){
            waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
            avg_waiting_time += waiting_time[i];
      }

      cout << "noprocesses\t burst time \twaiting time \tturn around time "<< endl;

      int turn_around_time[noprocesses],avg_turn_around_time=0;

      for(i=0;i<noprocesses;++i){

            turn_around_time[i]=waiting_time[i]+burst_time[i];
            avg_turn_around_time += turn_around_time[i];
            cout << processes[i ] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;

      }

      
      cout << "Average turn around time is " << float(avg_turn_around_time)/float(noprocesses) << endl;

      cout << "Average waiting time is "<< float(avg_waiting_time)/float(noprocesses) << endl;

}