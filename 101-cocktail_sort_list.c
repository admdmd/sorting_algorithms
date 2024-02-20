#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @left: The left node to be swapped
 * @right: The right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (*list == NULL || left == NULL || right == NULL)
        return;

    if (left->prev)
        left->prev->next = right;
    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;

    left->prev = right;
    right->next = left;

    if (*list == left)
        *list = right;

    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = NULL, *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped) {
        swapped = 0;

        start = (*list)->next;
        while (start != end) {
            if (start->n < start->prev->n) {
                swap_nodes(list, start->prev, start);
                swapped = 1;
            } else
                start = start->next;
        }

        if (!swapped)
            break;

        end = start->prev;

        while (start != end) {
            if (start->n < start->prev->n) {
                swap_nodes(list, start->prev, start);
                swapped = 1;
            } else
                start = start->prev;
        }
    }
}
