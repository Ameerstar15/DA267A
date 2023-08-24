#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "double_linked_list.h"

int counterDouble = 0;

int getCountDouble()
{
  return counterDouble;
}

/*
 * This function should add a new element with value 'value' to the argument linked list.
 * A new value should be added even if the list already contains an element with the
 * argument value.
 *
 * When adding elements, you should make sure that the linked list is sorted based on the
 * 'data' field in the linkedListElements, so that the element with smallest value is the
 * first element in the list, followed by the second smallest element, etc.
 *
 * Please note that you need to dynamically allocate memory (using malloc or calloc) to
 * your new element.
 *
 * When adding an element to your double linked list, you have the choice to start either
 * from the beginning or the end of the list when searching for the position where to
 * insert a new element. It is up to you how to decide which search strategy to use.
 *
 *
 * Return values:
 *   'value' - If a new element with value 'value' successfully added to the list.
 *   INT_MIN (defined in limits.h) - If a new element could not be added to the list.
 */
int addElementDoubleLinkedList(struct doubleLinkedList *list, int value)
{
  struct doubleLinkedListElement *element = (struct doubleLinkedListElement *)malloc(sizeof(struct doubleLinkedListElement));

  if (element)
  {
    element->data = value;
    list->first = element;
    element->previous = NULL;
    counterDouble++;
    sortDoubleList(list, counterDouble);
    printf("Added value %d\n", value);
    return 1;
  }
  else
  {
    printf("value %d couldnt be added\n", value);
    return INT_MIN;
  }
}

/*
 * This function should initialize the linked list structure that is given as
 * argument to the function, that is setting list->first and list->last to NULL
 */
void initDoubleLinkedList(struct doubleLinkedList *list)
{
  printf("initializing the list\n");
  list->first = NULL;
  list->last = NULL;
}

/*
 * This function should remove the first element in the linked list, i.e., list->first.
 *
 * Don't forget to free memory (using free) of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeFirstElementDoubleLinkedList(struct doubleLinkedList *list)
{
  struct doubleLinkedListElement *element = list->first;
  if (element == NULL)
  {
    printf("Nothing to remove yet \n");
    return INT_MIN;
  }
  else if (list->first->next != NULL)
  {
    int temp = 0;
    list->first = element->next;
    temp = element->data;
    printf("First %d element were removed\n",element->data);
    free(element);
    counterDouble--;
    return temp;
  }
  else
  {
    return INT_MIN;
  }
  return 2;
}

/*
 * This function should remove the last element in the linked list.
 *
 * Don't forget to free memory (using free) of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeLastElementDoubleLinkedList(struct doubleLinkedList *list)
{
  int i = 0;
  int temp = 0;
  struct doubleLinkedListElement *element = list->first;
  if (element)
  {
    for (i = 0; i < counterDouble - 1; i++)
    {
      element = element->next;
    }
    printf("Last %d were removed\n", temp = element->data);
    free(element);
    counterDouble--;
    return temp;
  }
  else
  {
    printf("List is empty, try adding an element\n");
    return INT_MIN;
  }
}

void printDoubleLinkedList(struct doubleLinkedList *list)
{
  struct doubleLinkedListElement *element;
  element = list->first;
  int i = 0;

  if ((list->first != NULL) || (getCountDouble() >= 0))
  {
    while (i < counterDouble)
    {
      printf("%d\n", element->data);
      element = element->next;
      i++;
    }
  }
  else
  {
    printf("Nothing to print\n");
  }
}

void sortDoubleList(struct doubleLinkedList *list, int counterDouble)
{
  int i = 0;
  struct doubleLinkedListElement *element = list->first;
  do
  {
    if (element->data > element->next->data)
    {
      swapDouble(element, element->next);
    }
    element = element->next;
    i++;
  } while (i < counterDouble);
}

void swapDouble(struct doubleLinkedListElement *a, struct doubleLinkedListElement *b)
{
  int tmp = b->data;
  b->data = a->data;
  a->data = tmp;
}

int searchStructDouble(struct doubleLinkedList *list, int value)
{
  struct doubleLinkedListElement *ptr;
  ptr = list->first;
  int i = 0;
  while (i <= counterDouble)
  {
    if (list->first == NULL)
    {
      printf("empty list\n");
      return 0;
    }

    else if (ptr->data == value)
    {
      printf("value %d were found!!\n", value);
      return 1;
      ptr = ptr->next;
      free(ptr);
      i++;
    }
    else
    {
      printf("Value %d were not found  !!\n", value);
      i++;
      return 0;
    }
  }
  i = 0;

  return 5;
}
