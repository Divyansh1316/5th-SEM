#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int burst[n], priority[n], index[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &burst[i], &priority[i]);
        index[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = priority[i], m = i;
        for (int j = i; j < n; j++)
        {
            if (priority[j] > temp)
            {
                temp = priority[j];
                m = j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i], &index[m]);
    }
    int t = 0;
    printf("Order of process Execution is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", index[i], t, t + burst[i]);
        t += burst[i];
    }
    printf("\n");
    printf("ProcessId\tBurst Time\tWait Time\n");
    int wait_time = 0;
    int total_wait_time = 0, total_Turn_Around = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t\t%d\t\t\t%d\n", index[i], burst[i], wait_time);
        total_wait_time += wait_time;
        total_Turn_Around += wait_time + burst[i];
        wait_time += burst[i];
    }
    float avg_wait_time = (float)total_wait_time / n;
    printf("Average Waiting time is %f\n", avg_wait_time);

    float avg_Turn_Around = (float)total_Turn_Around / n;
    printf("Average TurnAround Time is %f\n", avg_Turn_Around);

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t", index[i]);
    }

    printf("\n");
    int t1 = 0;
    printf("%d ", t1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t1 + burst[i]);
        t1 += burst[i];
    }

    return 0;
}
