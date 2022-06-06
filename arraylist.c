#include <memory.h>         /* memset() */
#include <stdlib.h>         /* malloc(), realloc(), NULL */
#include "arraylist.h"

static int array_list_expand(ArrayList* array_list);

ArrayList*
array_list_create(int n) {
    ArrayList *array_list;
    size_t entries_size;

    if (n < 0) return NULL;

    array_list = (ArrayList *) malloc(sizeof(ArrayList));
    if (array_list == NULL) return NULL;

    /* Allocate memory for an array and fill it with NULL */
    entries_size = 2 * n * sizeof(void*);
    array_list->entries = (void **) malloc(entries_size);
    if (array_list->entries == NULL) {
        free(array_list);
        return NULL;
    }
    memset(array_list->entries, 0, entries_size);

    array_list->size = entries_size;
    array_list->length = n;
    return array_list;
}

int
array_list_insert(ArrayList* array_list, unsigned int i, void* val) {
    if (i >= array_list->length) return -1;

    array_list->entries[i] = val;
    return 0;
}

int
array_list_append(ArrayList* array_list, void* val) {
    /*
     * If the new length is greater than the actual size, then we allocate
     * memory for the array, twice the previous one, and copy the elements of
     * the old array into it.
     */
    if (++array_list->length > array_list->size / sizeof(void*))
        if (array_list_expand(array_list) == -1)
            return -1;

    array_list->entries[array_list->length - 1] = val;
    return 0;
}

void*
array_list_pop(ArrayList* array_list) {
    void* entry;

    if (array_list->length == 0) return NULL;

    entry = array_list->entries[--array_list->length];
    array_list->entries[array_list->length] = NULL;
    return entry;
}

void*
array_list_remove(ArrayList* array_list, unsigned int i) {
    void *temp, *entry;

    if (i >= array_list->length) return NULL;

    for (int j = i + 1; j < array_list->length; ++j, ++i) {
        temp = array_list->entries[i];
        array_list->entries[i] = array_list->entries[j];
        array_list->entries[j] = temp;
    }

    entry = array_list->entries[--array_list->length];
    array_list->entries[array_list->length] = NULL;
    return entry;
}

void*
array_list_get(ArrayList* array_list, unsigned int i) {
    return i < array_list->length ? array_list->entries[i] : NULL;
}

void
array_list_clear(ArrayList* array_list) {
    free(array_list->entries);
    array_list->entries = malloc(0);
    array_list->length = array_list->size = 0;
}

unsigned int
array_list_length(ArrayList* array_list) {
    return array_list->length;
}

int
array_list_is_empty(ArrayList* array_list) {
    return array_list->length == 0;
}

static int
array_list_expand(ArrayList* array_list) {
    size_t new_entries_size;
    void** new_entries;

    new_entries_size = array_list->size > 0 ? array_list->size * 2 : 16;
    new_entries = (void**) malloc(new_entries_size);

    if (new_entries == NULL) {
        new_entries = (void**) realloc(array_list->entries, new_entries_size);

        if (new_entries == NULL) return -1;

        memset(
            new_entries + array_list->length,
            0,
            new_entries_size - array_list->size
        );
    } else {
        memset(new_entries, 0, new_entries_size);
        for (int i = 0; i < array_list->length; ++i)
            new_entries[i] = array_list->entries[i];

        free(array_list->entries);
    }

    array_list->entries = new_entries;
    array_list->size = new_entries_size;
    return 0;
}
