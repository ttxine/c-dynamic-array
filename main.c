#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

DEFINE_ARRAY_LIST_GET(get_int, int);
DEFINE_ARRAY_LIST_POP(pop_int, int);
DEFINE_ARRAY_LIST_INSERT(insert_int, int);
DEFINE_ARRAY_LIST_APPEND(append_int, int);
DEFINE_ARRAY_LIST_REMOVE(remove_int, int);

int main() {
    ArrayList* array_list;
    int is_appended;
    int *val;

    array_list = array_list_create(5);

    /* Insertion */
    for (int i = 0; i < 5; ++i) {
        if ((val = (int*) malloc(sizeof(int))) == NULL)
            return -1;
        *val = i;

        insert_int(array_list, i, val);
    }

    /* Length */
    printf("Array contains %u items.\n", array_list_length(array_list));

    /* Get 1/2 */
    for (int i = 0; i < 5; ++i)
        printf("array_list[%u] = %d\n", i, *get_int(array_list, i));

    /* Append */
    is_appended = append_int(array_list, get_int(array_list, 4));
    if (is_appended == -1) return -1;
    printf("array_list[5] = %d\t(array was extended after append)\n",
           *get_int(array_list, 5));

    /* Is empty 1/2 */
    printf("Is array empty: %u\n", array_list_is_empty(array_list));

    /* remove */
    printf("array_list[3] has been removed: %d\n",
        *remove_int(array_list, 3));

    /* pop */
    printf("Popped element: %d\n", *pop_int(array_list));

    for (int i = 0; i < 4; ++i)
        printf("array_list[%u] = %d\n", i, *get_int(array_list, i));

    /* Clear */
    array_list_clear(array_list);

    /* Get 2/2 */
    printf("get_int(0) == NULL: %u\t(array has been cleared)\n",
           get_int(array_list, 0) == NULL);

    /* Is empty 2/2 */
    printf("Is array empty: %u\t(array has been cleared)\n",
           array_list_is_empty(array_list));

    return 0;
}
