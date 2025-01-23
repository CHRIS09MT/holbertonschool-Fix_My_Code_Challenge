#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int p = 0;

    if (*head == NULL)
    {
        return (-1);
    }

    tmp = *head;

    /* Traverse the list to find the node at the given index */
    while (tmp != NULL && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    if (tmp == NULL)  /* Index is out of range */
    {
        return (-1);
    }

    /* If the node to be deleted is the first node */
    if (tmp == *head)
    {
        *head = tmp->next;
        if (*head != NULL)  /* Update the prev pointer if the list is not empty */
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        /* Update the prev pointer of the next node, if it exists */
        if (tmp->next != NULL)
        {
            tmp->next->prev = tmp->prev;
        }

        /* Update the next pointer of the previous node */
        if (tmp->prev != NULL)
        {
            tmp->prev->next = tmp->next;
        }
    }

    free(tmp);  /* Free the memory of the node */

    return (1);
}
