#include <stddef.h>                             /* size_t */

typedef struct array_list {
    unsigned int length;                        /* Count of entries */
    size_t size;                                /* Actual size */
    void** entries;
} ArrayList;

/**
 * @brief               Creates array
 * 
 * @param n             initial array length
 * @return              created array or NULL on failure
 */
ArrayList*
array_list_create(int n);

/**
 * @brief               Inserts the element into specified position
 * 
 * @param array_list    the array to insert into
 * @param i             the index
 * @param val           the value
 * @return              0 or -1 on failure
 */
int
array_list_insert(ArrayList* array_list, unsigned int i, void* val);

/**
 * @brief               Appends the element to the end of an array
 * 
 * @param array_list    the array to append to
 * @param val           the value
 * @return              0 or -1 on failure
 */
int
array_list_append(ArrayList* array_list, void* val);

/**
 * @brief               Removes element at the end of the array
 * 
 * @param array_list    the array to remove the element from
 * @return              the value of removed element
 */
void*
array_list_pop(ArrayList* array_list);

/**
 * @brief               Removes element at specified position
 * 
 * @param array_list    the array to remove the element from
 * @param i             the index
 * @return              the value of removed element
 */
void*
array_list_remove(ArrayList* array_list, unsigned int i);

/**
 * @brief               Returns the element at the specified position
 * 
 * @param array_list    the array
 * @param i             the index
 * @return              the value of element
 */
void*
array_list_get(ArrayList* array_list, unsigned int i);

/**
 * @brief               Removes all elements of the array
 * 
 * @param array_list    the array to remove the elements from
 */
void
array_list_clear(ArrayList* array_list);

/**
 * @brief               Return the number of elements in the array
 * 
 * @param array_list    the array
 * @return              the number of elements
 */
unsigned int
array_list_length(ArrayList* array_list);

/**
 * @brief Checks if the array is empty
 * 
 * @param array_list 
 * @return int
 */
int
array_list_is_empty(ArrayList* array_list);
