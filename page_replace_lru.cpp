// #include <stdio.h>

// int findLRU(int time[], int n)
// {
//       int i, minimum = time[0], pos = 0;

//       for (i = 1; i < n; ++i)
//       {
//             if (time[i] < minimum)
//             {
//                   minimum = time[i];
//                   pos = i;
//             }
//       }
//       return pos;
// }

// int main()
// {
//       int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

//       printf("Enter number of frames: ");
//       scanf("%d", &no_of_frames);

//       printf("Enter number of pages: ");
//       scanf("%d", &no_of_pages);

//       printf("Enter reference string: ");

//       for (i = 0; i < no_of_pages; ++i)
//             scanf("%d", &pages[i]);
      

//       for (i = 0; i < no_of_frames; ++i)
//             frames[i] = -1;
      

//       for (i = 0; i < no_of_pages; ++i)
//       {
//             flag1 = flag2 = 0;

//             for (j = 0; j < no_of_frames; ++j)

//             {
//                   if (frames[j] == pages[i])

//                   {
//                         counter++;

//                         time[j] = counter;

//                         flag1 = flag2 = 1;
//                         break;

//                   }
//             }

//             if (flag1 == 0)
//             {
//                   for (j = 0; j < no_of_frames; ++j)
//                   {
//                         if (frames[j] == -1)
//                         {
//                               counter++;
//                               faults++;

//                               frames[j] = pages[i];

//                               time[j] = counter;

//                               flag2 = 1;

//                               break;
//                         }
//                   }
//             }

//             if (flag2 == 0)
//             {
//                   pos = findLRU(time, no_of_frames);

//                   counter++;
//                   faults++;

//                   frames[pos] = pages[i];
                  
//                   time[pos] = counter;
//             }

//             printf("\n");

//             for (j = 0; j < no_of_frames; ++j)
//             {
//                   printf("%d\t", frames[j]);
//             }
//       }

//       printf("\n\nTotal Page Faults = %d", faults);

//       return 0;
// }

#include<bits/stdc++.h>
using namespace std;
  
// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity)
{
    // To represent set of current pages. We use
    // an unordered_set so that we quickly check
    // if a page is present in set or not
    set <int> s;
  
    // To store the pages in FIFO manner
    queue<int> indexes;
  
    // Start from initial page
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            cout << s.size() << " ";
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i])==s.end())
            {
                // Insert the current page into the set
                s.insert(pages[i]);
  
                // increment page fault
                page_faults++;
  
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
        }
  
        // If the set is full then need to perform FIFO
        // i.e. remove the first page of the queue from
        // set and queue both and insert the current page
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Store the first page in the 
                // queue to be used to find and
                // erase the page from the set
                int val = indexes.front();
                  
                // Pop the first page from the queue
                indexes.pop();
  
                // Remove the indexes page from the set
                s.erase(val);
  
                // insert the current page in the set
                s.insert(pages[i]);
  
                // push the current page into
                // the queue
                indexes.push(pages[i]);
  
                // Increment page faults
                page_faults++;
            }
        }
    }
  
    return page_faults;
}
  
// Driver code
int main()
{
    int pages[] = {7, 0, 1, 2, 1, 5};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);
    return 0;
}