#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "sorthead.h"
int *mkarr(int n)
{
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        // 적당히 해싱
        arr[i] = ((rand() % 1000000007 + 34384321) % 13871 * 1345 + 3221) % 1000000;
    }
    return arr;
}
long getTime(struct timeval before, struct timeval after)
{
    return (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
}
int main()
{
    srand(time(NULL));

    struct timeval before, after;
    int n = 50000;
    int *origin = mkarr(n);
    int *cp = malloc(n * sizeof(int));

    printf("arr: ");
    for (int i = 0; i < 6; i++)
        printf("%d, ", origin[i]);
    printf("... (%d elements)\n", n);

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    bubble_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Bubble Sort's Performance: %ld(microsec)\n", getTime(before, after));

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    insertion_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Insertion Sort's Performance: %ld(microsec)\n", getTime(before, after));

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    selection_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Selection Sort's Performance: %ld(microsec)\n", getTime(before, after));

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    quick_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Quick Sort's Performance: %ld(microsec)\n", getTime(before, after));

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    merge_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Merge Sort's Performance: %ld(microsec)\n", getTime(before, after));

    memcpy(cp, origin, n * sizeof(int));
    gettimeofday(&before, NULL);
    heap_sort(cp, n);
    gettimeofday(&after, NULL);
    printf("Heap Sort's Performance: %ld(microsec)\n", getTime(before, after));
}