#include <stdio.h>

int main()

{
      int i, j, no_of_pages, pages[50], frame[10], no_of_frames, k, avail, page_fault = 0;

      printf("ENTER THE NUMBER OF PAGES:\n");
      scanf("%d", &no_of_pages);

      printf("ENTER THE PAGE NUMBERS :\n");

      for (i = 1; i <= no_of_pages; i++)
            scanf("%d", &pages[i]);

      printf("ENTER THE NUMBER OF FRAMES :");
      scanf("%d", &no_of_frames);

      for (i = 0; i < no_of_frames; i++)
            frame[i] = -1;

      j = 0;


      printf("ref string\t page frames\n");

      for (i = 1; i <= no_of_pages; i++)

      {
            printf("%d\t\t", pages[i]);

            avail = 0;

            for (k = 0; k < no_of_frames; k++)

                  if (frame[k] == pages[i])

                        avail = 1;

            if (avail == 0)

            {
                  frame[j] = pages[i];

                  j = (j + 1) % no_of_frames;

                  page_fault++;

                  for (k = 0; k < no_of_frames; k++)

                        printf("%d\t", frame[k]);
            }

            printf("\n");
      }

      printf("Page Fault Is %d", page_fault);

      return 0;
}