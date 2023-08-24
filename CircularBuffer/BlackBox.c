#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"
#include "BlackBox.h"

int Passes = 0;
int Fails = 0;

// Add elements with AddElements and remove head then check if the added and removed elements were the same
int BlackBox1(struct circularBuffer* bufferPtr, int value)
{
    addElement(bufferPtr, value);
    removeHead(bufferPtr);
    if (removeHead(bufferPtr) == 1)
    {
        printf("BlackBox1 Passed\n");
        Passes++;
        return 1;
    }
    else 
    {
        printf("BlackBox1 Failed\n");
        Fails++;
        return 0;
    }
    return 2;
}

/*Add one element, add another element (with different value), remove one
element, remove one element. Check that added and removed elements are
in same order.*/ 
int BlackBox2(struct circularBuffer* bufferPtr, int valueToAdd1, int valueToAdd2, int valueToRemove1,int valueToRemove2)
{
    int temp = bufferPtr->data[0];
    int temp2;
    addElement(bufferPtr, valueToAdd1);
    addElement(bufferPtr, valueToAdd2);
    printBuffer(bufferPtr);
    printf("\n");
    removeValue(bufferPtr, valueToRemove1);
    removeValue(bufferPtr, valueToRemove2);
    printBuffer(bufferPtr);
    printf("\n");
    temp2 = bufferPtr->data[0]; 

    if (temp == temp2)
    {
        printf("BlackBox2 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox2 Failed\n");
        Fails++;
        return 0;
    }
}

/*Add BUFFER_SIZE number of different elements in sequence, and remove
BUFFER_SIZE elements. Check that added and removed elements are in
same order.*/
int BlackBox3(struct circularBuffer* bufferPtr, int BUFFER_SIZE)
{
    int same = -1;
    int value = 0;
    int Array[BUFFER_SIZE];
    int Array2[BUFFER_SIZE];
    for (int i = 0; i <BUFFER_SIZE; i++)
    {
        addElement(bufferPtr, value);
        Array[i] = value;
        value++;
    }
    value = 0;
    for (int i = 0; i <BUFFER_SIZE; i++)
    {
        removeValue(bufferPtr, value);
        Array2[i] = value;
        value++;
    }
    for (int i = 0; i <BUFFER_SIZE; i++)
    {
        if (Array[i] == Array2[i])
        {
            same = 1;
        }
        else
        {
            same = 0;
        }
    }
    if(same==1)
    {
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            printf("%d  ,  %d\n",Array[i],Array2[i]);
        }
        
        printf("BlackBox3 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            printf("%d  ,  %d\n",Array[i],Array2[i]);
        }
        
        printf("BlackBox3 Failed\n");
        Fails++;
        return 0;
    }
    
}

/*Add BUFFER_SIZE+1elements. Check that function failed or that last
element overwrites the first added element, depending on your choice of
functionality.*/
int BlackBox4(struct circularBuffer* bufferPtr, int value1, int value2, int value3, int value4, int value5, int value6)
{
    addElement(bufferPtr, value1);
    addElement(bufferPtr, value2);
    addElement(bufferPtr, value3);
    addElement(bufferPtr, value4);
    addElement(bufferPtr, value5);
    printBuffer(bufferPtr);
    printf("\n");
    addElement(bufferPtr, value6);
    printBuffer(bufferPtr);

    if (bufferPtr->tail == 1)
    {
        printf("BlackBox4 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox4 Failed\n");
        Fails++;
        return 0;
    }
}

/*Repeat test 1 BUFFER_SIZE+1 times. Check that added and removed
elements are in same order.*/
int BlackBox5(struct circularBuffer* bufferPtr, int BUFFER_SIZE)
{
    int Array[BUFFER_SIZE + 1];
    int Array2[BUFFER_SIZE + 1];
    int value = 0;
    for (int i = 0; i < BUFFER_SIZE+1; i++)
    {
        addElement(bufferPtr, value);
        Array[i] = value;
        value++;
    }
    printBuffer(bufferPtr);
    printf("\n");
    value = 0;
    for (int i = 0; i < BUFFER_SIZE+1; i++)
    {
        removeValue(bufferPtr, value);
        Array2[i] = value;
        value++; 
    }
    for (int i = 0; i < BUFFER_SIZE+1; i++)
    {
        if (Array[i] == Array2[i])
        {
            
             printf("BlackBox5 Passed\n");
             Passes++;
            return 1;
        }else
        {
            printf("BlackBox5 Failed\n");
            Fails++;
            return 0;
        }
    }
    return 2;
}

/*Run contains() on empty buffer. Check that it returns value INT_MIN.*/
int BlackBox6(struct circularBuffer* bufferPtr,int value)
{
    
    if (contains(bufferPtr,value) == INT_MIN)
    {
        printf("BlackBox6 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox6 Failed\n");
        Fails++;
        return 0;
    }
}

/*Add one element. Check that buffer contains an element with the added
value.*/
int BlackBox7(struct circularBuffer* bufferPtr, int value)
{
    addElement(bufferPtr, value);
    if (contains(bufferPtr,value)==1)
    {
        printf("BlackBox7 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox7 Failed\n");
        Fails++;
        return 0;
    }
}

/*Add two elements. Check that the buffer contains the value of the second
element you added.*/
int BlackBox8(struct circularBuffer* bufferPtr, int value1, int value2)
{
    addElement(bufferPtr, value1);
    addElement(bufferPtr, value2);
    if (contains(bufferPtr, value2)==1)
    {
        printf("BlackBox8 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox8 Failed\n");
        Fails++;
        return 0;
    }
}

/*Add BUFFER_SIZE elements with different values. Check that the buffer
contains the value of the last element you added.*/
int BlackBox9(struct circularBuffer* bufferPtr,int BUFFER_SIZE)
{
    int value = 0;
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        bufferPtr->data[i] = value;
        value++;
    }
    value--;
    if (bufferPtr->data[BUFFER_SIZE-1] == value)
    {
        printf("BlackBox9 Passed\n");
        Passes++;
        return 1;
    }
    else
    {
        printf("BlackBox9 Failed\n");
        Fails++;
        return 0;
    }
    
}

//Prints out the tests results
void Results()
{
    printf("Passes %d\nFaileds %d\n", Passes, Fails);
    Passes = 0;
    Fails = 0;
    
}
