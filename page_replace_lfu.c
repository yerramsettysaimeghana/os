#include <stdio.h> 

int  main()
{
      int pages[50], i, j, k, no_of_pages, no_of_frames, cntr[20], frames[20], min, pf = 0;

      printf("\nEnter number of page references -- ");
      scanf("%d", &no_of_pages);

      printf("\nEnter the referenc e string--");

      for (i = 0; i < no_of_pages; i++)
            scanf("%d", &pages[i]);

      printf("\nEnter the available no.of no_of_frames--");
      scanf("%d", &no_of_frames);

      for (i = 0; i < no_of_frames; i++)
      {
            cntr[i] = 0;
            frames[i] = -1;
      }

      printf("\nThe Page Replacement Process is–\n");

      for (i = 0; i < no_of_pages; i++)
      {
            for (j = 0; j < no_of_frames; j++)

                  if (pages[i] == frames[j])

                  {
                        cntr[j]++;
                        break;
                        if (j == no_of_frames)

                        {
                              min = 0;

                              for (k = 1; k < no_of_frames; k++)

                                    if (cntr[k] < cntr[min])

                                          min = k;

                              frames[min] = pages[i];
                              cntr[min] = 1;
                              pf++;
                        }

                        printf("\n");

                        for (j = 0; j < no_of_frames; j++)
                              printf("\t%d", frames[j]);

                        if (j == no_of_frames)
                              printf("\tPF No.% d", pf);
                  }

            printf("\n\nTotal number of page faults--%d", pf);
      }
}