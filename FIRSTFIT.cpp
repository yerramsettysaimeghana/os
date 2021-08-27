#include<iostream>

using namespace std;

int main(){

      int no_of_blocks,no_of_process,i,j;

      cout << "Enter the No of Blocks  : ";

      cin >> no_of_blocks;

      int block[no_of_blocks];

      for(i=0;i<no_of_blocks;++i){

            cout << "Enter size of block " << i+1 << " :" ;

            cin >> block[i];

      }

      cout << "Enter the No of processes  : ";

      cin >> no_of_process;

      int process[no_of_process],allocation[no_of_process],flag[no_of_process];

      for(i=0;i<no_of_process;++i){

            cout << "Enter size of process " << i+1 << " :";

            cin >> process[i];

            allocation[i] = -1;

            flag[i]=-1;
      }

      for(i=0;i<no_of_process;++i)

            for(j=0;j<no_of_blocks;++j)

                  if(flag[j] == -1 && block[j] >= process[i] ){

                        allocation[i] = j;
                        flag[j]=0;
                        break;

                  }
      cout << "\nprocess no \t process size \t block no " << endl;

      for(i=0;i<no_of_process;++i){

            if(allocation[i] == -1 )

                  cout << i+1 << "\t\t" << process[i] << "\t\t Not Allocated " << endl;

            else
                  cout << i+1 << "\t\t" << process[i] << "\t\t" << allocation[i]+1 << endl;

      }




}