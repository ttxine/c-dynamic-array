#include <stdio.h>
#include "arraylist.h"

int main() {
    ArrayList* array_list = array_list_create(2);

    int val = 15;
    array_list_insert(array_list, 0, &val);
    int hval = 155;
    array_list_insert(array_list, 1, &hval);

    printf(
        "0: %d\t1: %d\n",
        *(int*) array_list_get(array_list, 0),
        *(int*) array_list_get(array_list, 1)
    );

    array_list_append(array_list, &val);
    printf("2: %d\tsize: %ld\n", *(int*) array_list_get(array_list, 2), array_list->size);
    array_list_append(array_list, &val);
    printf("3: %d\tsize: %ld\n", *(int*) array_list_get(array_list, 3), array_list->size);
    array_list_append(array_list, &val);
    printf("4: %d\tsize: %ld\n", *(int*) array_list_get(array_list, 0), array_list->size);

    array_list_clear(array_list);
    array_list_append(array_list, &val);
    printf("%d %ld\n", array_list->length, array_list->size);
    int sval = 75;
    array_list_append(array_list, &sval);
    printf("%d %ld\n", array_list->length, array_list->size);
    int tval = 115155;
    array_list_append(array_list, &tval);
    printf("%d %ld\n", array_list->length, array_list->size);

    printf(
        "0: %d\t1: %d\t2: %d\n",
        *(int*) array_list_get(array_list, 0),
        *(int*) array_list_get(array_list, 1),
        *(int*) array_list_get(array_list, 2)
    );

    void* third = array_list_pop(array_list);
    printf(
        "0: %d\t1: %d\t2 (popped): %d\n",
        *(int*) array_list_get(array_list, 0),
        *(int*) array_list_get(array_list, 1),
        *(int*) third
    );

    return 0;
}
