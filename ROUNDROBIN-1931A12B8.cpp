#include<bits/stdc++.h>
using namespace std;

int main(){
      int processes,quantum_time;

      cout << "Enter the Quantum time  :";
      cin >> quantum_time;

      cout << "Enter the no of processes : " ;
      cin >> processes;

      int burst_time[processes],i,temp_burst_time[processes];

      for(i=0;i<processes;++i){
            cout << "Enter the burst time of process " << i+1 << "  ";
            cin >> burst_time[i];
            temp_burst_time[i]=burst_time[i];
      }


      bool check;
      int waiting_time[processes],avg_waiting_time=0,turn_around_time[processes],avg_turn_around_time=0,total_time=0;

      cout << "processes\t burst time \twaiting time \tturn around time "<< endl;

      while(1){
            
            check=true;

            for(i=0;i<processes;++i){


                  if(temp_burst_time[i] > 0){

                        check=false;

                        if(temp_burst_time[i] > quantum_time){

                              total_time += quantum_time;

                              temp_burst_time[i] -= quantum_time;
                        }

                        else{

                              total_time += temp_burst_time[i];

                              temp_burst_time[i] = 0;

                              waiting_time[i]= total_time - burst_time[i];

                              avg_waiting_time += waiting_time[i];

                              turn_around_time[i] = waiting_time[i] + burst_time[i]; 
                              
                              avg_turn_around_time += turn_around_time[i];

                              cout << i+1 << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;

                        }
                  }

            }

            if(check==true)
                  break;

      }


      cout << "Average turn around time is " << float(avg_turn_around_time)/float(processes) << endl;

      cout << "Average waiting time is "<< float(avg_waiting_time)/float(processes) << endl;

}