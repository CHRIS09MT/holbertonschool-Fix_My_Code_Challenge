#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints a doubly linked list of integers
 *
 * @h: A pointer to the first element of a list
 *
 * Return: The number of elements printed
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t n = 0;  // Initialize the count of printed elements

    while (h)  // Traverse the list until the end
    {
        printf("%d\n", h->n);  // Print the current node's value
        h = h->next;  // Move to the next node
        n++;  // Increment the count
    }
    return n;  // Return the total count of printed elements
}