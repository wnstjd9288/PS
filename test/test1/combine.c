#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "head.h"
void combine1(vec_ptr v, data_t *dest)
{
    int i;
    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++)
    {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}
void combine2(vec_ptr v, data_t *dest)
{
    int i;
    int length = vec_length(v);
    *dest = IDENT;
    for (i = 0; i < length; i++)
    {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}
void combine3(vec_ptr v, data_t *dest)
{
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    *dest = IDENT;
    for (i = 0; i < length; i++)
    {
        *dest = *dest OPER data[i];
    }
}
void combine4(vec_ptr v, data_t *dest)
{
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t x = IDENT;
    for (i = 0; i < length; i++)
    {
        x = x OPER data[i];
    }
    *dest = x;
}
void combine5(vec_ptr v, data_t *dest)
{
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t x = IDENT;
    int limit = length - 2;
    for (i = 0; i < limit; i += 8)
    {
        x = x OPER data[i] OPER data[i + 1] OPER data[i + 2] OPER data[i + 3] OPER data[i + 4] OPER data[i + 5] OPER data[i + 6] OPER data[i + 7];
    }
    for (; i < length; i++)
    {
        x = x OPER data[i];
    }
    *dest = x;
}
void combine6(vec_ptr v, data_t *dest)
{
    int i;
    int length = vec_length(v);
    int limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t x0 = IDENT;
    data_t x1 = IDENT;
    for (i = 0; i < limit; i += 2)
    {
        x0 = x0 OPER data[i];
        x1 = x1 OPER data[i + 1];
    }
    for (; i < length; i++)
    {
        x0 = x0 OPER data[i];
    }
    *dest = x0 OPER x1;
}
int main()
{
    data_t result;
    struct timeval before, after;
    long elapsed;

    gettimeofday(&before, NULL);
    combine1(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine1's running time: %ld(microsec)\n", elapsed);

    gettimeofday(&before, NULL);
    combine2(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine2's running time: %ld(microsec)\n", elapsed);

    gettimeofday(&before, NULL);
    combine3(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine3's running time: %ld(microsec)\n", elapsed);

    gettimeofday(&before, NULL);
    combine4(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine4's running time: %ld(microsec)\n", elapsed);

    gettimeofday(&before, NULL);
    combine5(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine5's running time: %ld(microsec)\n", elapsed);

    gettimeofday(&before, NULL);
    combine6(new_vec(100000000), &result);
    gettimeofday(&after, NULL);
    elapsed = (after.tv_sec - before.tv_sec) * 1000000L + (after.tv_usec - before.tv_usec);
    printf("Combine6's running time: %ld(microsec)\n", elapsed);
    return 0;
}