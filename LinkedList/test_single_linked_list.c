#include <stdio.h>
#include <limits.h>
#include <single_linked_list.h>

int Passed = 1;
int Failed = 0;
/*
-  adds one element
- prints out the list
- add another
- print the list
*/
int test1_singleLinkedList(struct singleLinkedList *list, int value1, int value2)
{
    int p = 0;
    initSingleLinkedList(list);
    printf("Running test1_singleLinkedList\n");
    addElementSingleLinkedList(list, value1);
    printsingleLinkedList(list);
    p = searchStruct(list, value1);
    addElementSingleLinkedList(list, value2);
    printsingleLinkedList(list);
    p = p + searchStruct(list, value2);
    if (p == 2)
    {
        printf("test 1 Passed\n");
        return Passed;
    }
    else
    {
        printf("test 1 Failed\n");
        return Failed;
    }
    p = 0;
}

/*
-Add 2 element2 to the list
- print out the list
-remove the first element from the list
-print out the list
-adds a new element
-print
*/
int test2_SingleLinkedList(struct singleLinkedList *list, int value1, int value2, int value3)
{
    int temp = 0;
    initSingleLinkedList(list);
    printf("running test2_SingleLinkedList\n");
    addElementSingleLinkedList(list, value1);
    addElementSingleLinkedList(list, value2);
    printsingleLinkedList(list);
    removeFirstElementSingleLinkedList(list);
    printsingleLinkedList(list);
    addElementSingleLinkedList(list, value3);
    printsingleLinkedList(list);

    if (value1 <= value2 && value1 <= value3)
    {
        temp = value1;
        printf("temp %d\n", temp);
    }
    // if n2 is greater than both n1 and n3, n2 is the largest
    if (value2 <= value1 && value2 <= value3)
    {
        temp = value2;
        printf("temp %d\n", temp);
    }
    // if n3 is greater than both n1 and n2, n3 is the largest
    if (value3 <= value1 && value3 <= value1)
    {
        temp = value3;
        printf("temp %d\n", temp);
    }

    if (searchStruct(list, temp) == 0)
    {
        printf("test 2 Passed\n");
        return Passed;
    }
    else
    {
        printf("test 2 Failed\n");
        return Failed;
    }
}

/*
- adds 3 elements
- remove the last two elements
- print
*/
int test3_singleLinkedList(struct singleLinkedList *list, int value1, int value2, int value3)
{
    int temp = 0;
    initSingleLinkedList(list);
    printf("running test3_singleLinkedList\n");
    addElementSingleLinkedList(list, value1);
    addElementSingleLinkedList(list, value2);
    addElementSingleLinkedList(list, value3);
    printsingleLinkedList(list);
    printf("\n\n");
    removeLastElementSingleLinkedList(list);
    printf("\n\n");
    printsingleLinkedList(list);
    printf("\n\n");
    removeLastElementSingleLinkedList(list);

    if (value1 >= value2 && value1 >= value3)
    {
        temp = value1;
        printf("temp %d\n\n", temp);
    }
    // if n2 is greater than both n1 and n3, n2 is the largest
    if (value2 >= value1 && value2 >= value3)
    {
        temp = value2;
        printf("temp %d\n\n", temp);
    }
    // if n3 is greater than both n1 and n2, n3 is the largest
    if (value3 >= value1 && value3 >= value1)
    {
        temp = value3;
        printf("temp %d\n\n", temp);
    }
    printf("The list: \n");
    printsingleLinkedList(list);

    if (searchStruct(list, temp) == 0)
    {
        printf("test3 Passed\n");
        return Passed;
    }
    else
    {
        printf("test3 Failed\n");
        return Failed;
    }
}

/*
    -run searchStructDouble() on an empty list
*/
int test4_singleLinkedList(struct singleLinkedList *list, int value)
{
    initSingleLinkedList(list);
    printf("********* Test4 singleLinkedList *********\n");
    if (searchStruct(list, value) == 0)
    {
        printf("printing the list : \n");
        printsingleLinkedList(list);
        printf("Passed\n");
        return 1;
    }
    else
    {
        printf("Failed\n");
        return 0;
    }
    return 0;
}

/*
    - remove head while list is empty
*/
int test5_singleLinkedList(struct singleLinkedList *list)
{
    initSingleLinkedList(list);
    printf("printing the list :");
    printsingleLinkedList(list);
    printf("******** Test5 singleLinkedList ********\n");
    if (removeFirstElementSingleLinkedList(list) == INT_MIN)
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
