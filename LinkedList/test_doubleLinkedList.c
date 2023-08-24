#include "double_linked_list.h"
#include "stdio.h"
#include "limits.h"

/*
- adds two elements
- print
- remove head
- add 2 elements
- remove two heads
- print
- return 1 if list have one element left
*/
int test1_doubleLinkedList(struct doubleLinkedList *list, int value1, int value2, int value3, int value4)
{   
    int temp = 0;
    initDoubleLinkedList(list);
    printf("******* Teest1 doubleLinkedList *******\n");
    addElementDoubleLinkedList(list, value1);
    addElementDoubleLinkedList(list, value2);
    if (value1 >= value2)
    {
        temp = value1;
    }
    // if n2 is greater than both n1 and n3, n2 is the largest
    if (value2 >= value1)
    {
        temp = value2;
    }

    printDoubleLinkedList(list);
    removeFirstElementDoubleLinkedList(list);
    printDoubleLinkedList(list);
    addElementDoubleLinkedList(list, value3);
    addElementDoubleLinkedList(list, value4);
    if (temp >= value4 && temp >= value3)
    {
        temp = temp;
    }
    // if n2 is greater than both n1 and n3, n2 is the largest
    if (value3 >= temp && value3 >= value4)
    {
        temp = value3;
    }
    if (value4 >= temp && value4 >= value3)
    {
        temp = value4;
    }

    printDoubleLinkedList(list);
    removeFirstElementDoubleLinkedList(list);
    removeFirstElementDoubleLinkedList(list);
    printDoubleLinkedList(list);

    if (searchStructDouble(list, temp) == 1)
    {
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
}

/*
    -add two elements
    -print
    -remove head first then last
    -print
    -add another element
    -print
*/
int test2_doubleLinkedList(struct doubleLinkedList *list, int value1, int value2, int value3)
{
    initDoubleLinkedList(list);
    addElementDoubleLinkedList(list, value1);
    addElementDoubleLinkedList(list, value2);
    printDoubleLinkedList(list);
    removeFirstElementDoubleLinkedList(list);
    removeLastElementDoubleLinkedList(list);
    printDoubleLinkedList(list);
    addElementDoubleLinkedList(list, value3);
    printDoubleLinkedList(list);

    if (searchStructDouble(list, value3) == 1)
    {
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
}

/*
    -run searchStructDouble() on an empty list
*/
int test3_doubleLinkedList(struct doubleLinkedList *list, int value)
{
    initDoubleLinkedList(list);
    printf("******** Test3 doubleLinkedList ******\n");
    if (searchStructDouble(list, value) == 0)
    {
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
}

/*
    -remove head while list is empty
*/
int test4_doubleLinkedList(struct doubleLinkedList *list)
{
    initDoubleLinkedList(list);
    printf("******* Test4 doubleLinkedList *******\n");
    if (removeFirstElementDoubleLinkedList(list) == INT_MIN)
    {
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
}


/*
    - remove last while list is empty
*/
int test5_doubleLinkedList(struct doubleLinkedList *list)
{
    initDoubleLinkedList(list);
    printf("********* Test5 doubleLinkedList *********\n");
    if(removeLastElementDoubleLinkedList(list)== INT_MIN)
    {
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
}


