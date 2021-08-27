#include<iostream>
using namespace std;

class procon{
      public:
      int mutex=1,empty=5,item=0,full=0;

      int wait(int el){
            return --el;
      }

      int signal(int el){
            return ++el;
      }

      void producer(){
            if(mutex == 0 || empty == 0)
                  cout << "Buffer is Full" << endl;
            
            else{
                  mutex=wait(mutex);
                  empty=wait(empty);
                  full=signal(full);
                  ++item;
                  cout << "Producer produces the item " << item << endl;
                  mutex=signal(mutex);
            }
      }

      void consumer(){
            if(mutex == 0 || empty == 5)
                  cout << "Buffer is Empty" << endl;

            else{
                  mutex=wait(mutex);
                  empty=signal(empty);
                  full=wait(full);
                  cout << "Consumer consumes the item " << item << endl;
                  --item; 
                  mutex=signal(mutex);
            }
      }
};

int main(){
      procon obj;
      int x;
      
      do{
            cout << "The Buffer size is " << obj.empty << endl;
            cout << "1.Producer  \t2.Consumer  \t3.exit" << endl;
            cin >> x;
            switch(x){
                  case 1:
                        obj.producer();
                        break;
                  case 2:
                        obj.consumer();
                        break;
                  case 3:
                        exit(0);
            }
      }while(1);
}