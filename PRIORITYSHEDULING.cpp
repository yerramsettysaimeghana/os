#include<bits/stdc++.h>
using namespace std;

int main() {
      int noprocesses;
      cout << "Enter no of processes :" ;
      cin >> noprocesses;
      int processes[noprocesses],burst_time[noprocesses],priority[noprocesses],waiting_time[noprocesses];
      int i,j;
      
      for(i=0;i<noprocesses;++i){
            cout << "Enter burst time and priority time of process " << i+1 << endl;
            cin >> burst_time[i];
            cin >> priority[i];
            processes[i]=i+1;
      }
      int position;
      for(i=0;i<noprocesses;++i){
            
            position=i;

            for(j=i+1;j<noprocesses;++j)
                  if(priority[j] > priority[position])
                        position=j;

            swap(priority[i],priority[position]);
            swap(burst_time[i],burst_time[position]);
            swap(processes[i],processes[position]);
      }

      int avg_waiting_time=0,avg_turn_around_time=0;

      waiting_time[0]=0;

      for(i=1;i<noprocesses;++i){
            waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
            avg_waiting_time += waiting_time[i];
      }

      int turn_around_time[noprocesses];

      cout << "processes\t priority \t burst time \twaiting time \tturn around time "<< endl;

      for(i=0;i<noprocesses;++i){

            turn_around_time[i]=waiting_time[i]+burst_time[i];
            avg_turn_around_time += turn_around_time[i];
            cout << processes[i] << "\t\t" << priority[i]  << "\t\t"<< burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;

      }

      
      cout << "Average turn around time is " << float(avg_turn_around_time)/float(noprocesses) << endl;

      cout << "Average waiting time is "<< float(avg_waiting_time)/float(noprocesses) << endl;

}