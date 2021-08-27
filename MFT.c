#include <stdio.h>
int main()
{
      int memory_size, no_of_partitions, partition_size, process;

      int m1[4], i, f, total_internal_fragm = 0, f2 = 0, internal_frang, fra2, s1, temp_memory;
      
      printf("Enter the memory size:");
      scanf("%d", &memory_size);

      printf("Enter the no of partitions:");
      scanf("%d", &no_of_partitions);

      partition_size = memory_size / no_of_partitions;      

      printf("Each partn size is:%d", partition_size);

      printf("\nEnter the no of processes:");
      scanf("%d", &process);

      temp_memory = memory_size;

      for (i = 0; i < process; i++)
      {
            if (temp_memory < partition_size)
            {
                  printf("\nThere is no further memory for process%d", i + 1);
                  m1[i] = 0;
                  break;
            }

            else
            {
                  printf("\nEnter the memory req for process%d:", i + 1);
                  scanf("%d", &m1[i]);

                  if (m1[i] <= partition_size)
                  {
                        printf("\nProcess is allocated in partition%d", i + 1);

                        internal_frang = partition_size - m1[i];

                        printf("\nInternal fragmentation for process is:%d", internal_frang);
                        total_internal_fragm = total_internal_fragm + internal_frang;

                        temp_memory = temp_memory - partition_size;
                  }
                  else
                  {

                        printf("\nProcess not allocated in partition%d", i + 1);
                        s1 = m1[i];

                        while (s1 > partition_size)
                        {
                              s1 = s1 - partition_size;
                              
                              temp_memory = temp_memory - partition_size;     
                        }
                        temp_memory = temp_memory - partition_size;
                        fra2 = partition_size - s1;
                        f2 = f2 + fra2;
                        printf("\nExternal Fragmentation for this process is:%d", fra2);
                  }
            }
      }


      printf("\nProcess\tallocatedmemory");

      for (i = 0; i < process; i++)
            printf("\n%5d\t%5d", i + 1, m1[i]);

      f = total_internal_fragm + f2;

      printf("\nThe tot no of fragmentation is:%d", f);
      return 0;
}