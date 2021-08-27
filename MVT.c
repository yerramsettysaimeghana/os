#include <stdio.h>
void main()
{
      int memory, process_size = 0, no_of_process, i;

      printf("enter the memory capacity: ");
      scanf("%d", &memory);
      
      printf("enter the no of processes: ");
      scanf("%d", &no_of_process);
      
      for (i = 0; i < no_of_process; i++)
      {
            printf("\nenter memory req for process %d: ", i + 1);
            scanf("%d", &process_size);

            if (process_size <= memory){

                  printf("the memory allocated for process %d is: %d ", i + 1, process_size);

                  memory = memory - process_size;
                  printf("\nremaining memory is: %d", memory);
            }

            else
                  printf("memory is not allocated for process %d", i + 1);


            printf("\nexternal fragmentation for this process is: %d", memory);
      }
}