#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "single_linked_list.h"
#include <driver/timer.h>
#include <esp_task_wdt.h>

int counter = 0;

int getCount()
{
  return counter;
}
/*
 * This function should add a new element with value 'value' to the argument linked list.
 * A new value should be added even if the list already contains an element with the
 * argument value.
 *
 * When adding elements, you should make sure that the linked list is sorted based on the
 * 'data' field in the linkedListElements, so that the element with smallest value is the
 * first element in the list, followed by the second smallest element, etc. *********   behöver testat ********
 *
 * Please note that you need to dynamically allocate memory (using malloc or calloc) to
 * your new element.
 *
 * Return values:
 *   'value' - If a new element with value 'value' successfully added to the list.
 *   INT_MIN (defined in limits.h) - If a new element could not be added to the list.
 */
int addElementSingleLinkedList(struct singleLinkedList *list, int value)
{

  struct singleLinkedListElement *element = (struct singleLinkedListElement *)malloc(sizeof(struct singleLinkedListElement));

  if (element)
  {
    element->data = value;
    element->next = list->first;
    list->first = element;
    printf("value %d were added !!\n", value);
    counter++;
    sortList(list, counter);
    return 1;
  }
  else
  {
    printf("couldn't add your element!!\n");
    return INT_MIN;
  }
}

/*
 * This function should initialize the linked list structure that is given as
 * argument to the function, that is setting list->first to NULL
 */
void initSingleLinkedList(struct singleLinkedList *list)
{
  printf("Initializing the list\n");
  list->first = NULL;
}

/*
 * This function should remove the first element in the linked list, i.e., list->first.
 *
 * Don't forget to free memory of the struct element you remove.
 *
 * Return values:
 *  list->first->data if the element was successfully removed.
 *  INT_MIN (defined in limits.h) - If no element could be removed (i.e. the list->first == NULL).
 */
int removeFirstElementSingleLinkedList(struct singleLinkedList *list)
{
  if (list->first != NULL)
  {
    struct singleLinkedListElement *temp;
    int value = list->first->data;
    temp = list->first->next;
    printf("value %d is being removed\n", value);
    list->first = NULL;
    free(list->first);
    list->first = temp;
    printf("value %d removed\n", value);
    counter--;
    return 1;
  }
  else if (list->first == NULL)
  {
    printf("List is empty nothing to delete\n");
    return INT_MIN;
  }
  else
  {
    printf("Failed to remove the first element\n");
    return INT_MIN;
  }
}

int removeLastElementSingleLinkedList(struct singleLinkedList *list)
{
  int value = 0;
  struct singleLinkedListElement *temp = list->first;
  struct singleLinkedListElement *previous = 0;
  int i = 0;

  if (list->first == NULL)
  {
    printf("List is empty nothing to delete\n");
    return INT_MIN;
  }
  else if (list->first->next == NULL)
  {
    printf("Freed the only element : %d\n", list->first->data);
    free(list->first->next);
    counter--;

    return 1;
  }
  else if (list->first != NULL)
  {
    // else traverse to the last node
    do
    {
      // store previous link node as we need to change its next val
      previous = temp;
      temp = temp->next;
      printf("traversing the list \n\n");
      i++;
    } while (i < counter - 1);
    // Curr assign 2nd last node's next to Null
    printf("%d deleted\n", temp->data);
    previous->next = NULL; // testa och kommentera bort denna raden ? funkar bra utan den i double linked list
    free(temp);
    counter--;
    return 1;
  }
  else
  {
    printf("INT MIN\n");

    return INT_MIN;
  }
}

/*
 * this function will allow us to go throught the list and search for a specific value
 * returns 1 if the value were found, 0 if not
 */
int searchStruct(struct singleLinkedList *list, int value)
{
  struct singleLinkedListElement *ptr;
  ptr = list->first;
  int i = 0;
  while (i <= counter)
  {
    if (list->first == NULL)
    {
      printf("empty list\n");
      return 0;
    }
    if (ptr->data == value)
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

/*prints th linked list */
void printsingleLinkedList(struct singleLinkedList *list)
{
  struct singleLinkedListElement *element;
  element = list->first;
  int i = 0;
  if (((list->first != NULL) && (getCount() > 0)))
  {
    while (i < counter)
    {
      printf("%d\n", element->data);
      element = element->next;
      i++;
    }
  }
  else if (getCount()==0)
  {
    printf("Your list is empty\n");
  }
}

/* swapping used in sortList()*/
void swap(struct singleLinkedListElement *a, struct singleLinkedListElement *b)
{
  int tmp = b->data;
  b->data = a->data;
  a->data = tmp;
}

/*
 * sorts the LinkedList
 */
void sortList(struct singleLinkedList *list, int count)
{
  int i = 0;
  struct singleLinkedListElement *element = list->first;
  do
  {
    if(element->next == NULL)
    {
      break;
    }
    else if ((element->data > element->next->data))
    {
      swap(element, element->next);
    }
    else
    {

    }
    element = element->next;
    i++;
  } while (i < counter);
}