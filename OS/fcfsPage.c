#include <stdio.h>
int main()
{
    int num;
    printf("Enter Limit: ");
    scanf("%d", &num);
    printf("Enter page string: ");
    int incomingStream[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &incomingStream[i]);
    }
    int pageFaults = 0;
    int pageHits = 0;
    int frames;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf("Pages\tFrame 1\t\tFrame 2\t\tFrame 3\t\tPage Hits\n");
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageHits++;
            }
        }
        if (s == 0)
        {
            pageFaults++;
            if ((pageFaults <= frames))
            {
                temp[m] = incomingStream[m];
            }
            else
            {
                temp[(pageFaults - 1) % frames] = incomingStream[m];
            }
        }
        printf("%d\t\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
        printf("%d\n", s);
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    printf("Total Page Hits:\t%d\n", pageHits);
    return 0;
}
