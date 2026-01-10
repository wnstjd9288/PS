#include <stdlib.h>
typedef int data_t;
#define OPER +
#define IDENT 0
typedef struct
{
    int len;
    data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(int len)
{
    vec_ptr result = malloc(sizeof(vec_rec));
    if (!result)
        return NULL;

    result->len = len;

    if (len > 0)
    {
        result->data = malloc(len * sizeof(data_t));
        if (!result->data)
        {
            free(result);
            return NULL;
        }
    }
    else
    {
        result->data = NULL;
    }

    return result;
}
int get_vec_element(vec_ptr v, int index, data_t *dest)
{
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}
int vec_length(vec_ptr v)
{
    return v->len;
}
data_t *get_vec_start(vec_ptr v)
{
    return v->data;
}