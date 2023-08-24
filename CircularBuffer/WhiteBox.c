#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"
#include "WhiteBox.h"

/*
Check that the following is true after running
initCircularBuffer:
•buffer.maxLength equals BUFFER_SIZE ✔︎
•buffer.head equals 0 ✔︎
•buffer.tail equals 0 ✔︎
*/
int WhiteBox1(struct circularBuffer* bufferPtr,  int* data, int BUFFER_SIZE)
{
    initCircularBuffer(bufferPtr, data, BUFFER_SIZE); 
    if ((bufferPtr->maxLength == BUFFER_SIZE) && (bufferPtr->head == 0) && (bufferPtr->tail == 0) )
    {
        printf("Buffer.maxLength %d, BUFFER_SIZE %d, bufferHead %d, bufferTail %d\n", bufferPtr->maxLength, BUFFER_SIZE, bufferPtr->head, bufferPtr->tail);
        printf("WhitekBox1 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox1 Failed\n");
        return 0;
    }
    return 2;
}

/*
addElement()
•WhiteBox2 :Add an element to an empty buffer, when the element should be added at
the beginning of the buffer array. ✔︎
•WhiteBox3 :Add an element to an empty buffer, when the element should be added at
some other place than the beginning of the buffer array.
•WhiteBox4 :Add an element to a buffer already containing one element. Different
placements of the tail and header might need to be considered, and you
need to figure out which combinations are relevant.
•WhiteBox5 :Add an element to a buffer already containing BUFFER_SIZE-1 elements.
Different placements of the tail and header might need to be considered,
and you need to figure out which combinations are relevant.
*/
int WhiteBox2(struct circularBuffer* bufferPtr, int Value)
{
    addElement(bufferPtr, Value);
    printBuffer(bufferPtr);
    if (bufferPtr->data[0] == Value)
    {
        printf("WhitekBox2 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox2 Failed\n");
        return 0;
    }
    return 2;
}

int WhiteBox3(struct circularBuffer* bufferPtr, int Value, int Posetion,int BUFFER_SIZE)

{
    Posetion--;
    if (Posetion >= BUFFER_SIZE)
    {
        printf("BUFFER SIZE TOO SMALL FOR YOUR ELEMENT\n");
        return 0;
    }
    else
    {
        printf("Value printed in Posetion : %d\n", Posetion); 
        setTail(bufferPtr, Posetion);
        addElement(bufferPtr, Value);
        printBuffer(bufferPtr);

        if (bufferPtr->data[bufferPtr->tail - 1] == Value)
        {
            printf("WhitekBox3 Passed\n");
            return 1;
        }
        else
        {
        printf("WhitekBox3 Failed\n");
        return 0;
        }
    }
}

int WhiteBox4(struct circularBuffer* bufferPtr,int BUFFER_SIZE)
{
    int Posetion = 3;
    setHead(bufferPtr,Posetion);
    printf("Head Posetion : %d\n", bufferPtr->head);
    printf("Tail Posetion : %d\n", bufferPtr->tail); 
    addElement(bufferPtr, 5);
    addElement(bufferPtr, 1);
    printBuffer(bufferPtr);
    printf("Head Posetion : %d\n", bufferPtr->head);
    printf("Tail Posetion : %d\n", bufferPtr->tail); 
    if ((bufferPtr->head != 0) || (bufferPtr->tail >= bufferPtr->head))
    {
        printf("WhitekBox4 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox4 Failed\n");
        return 0;
    }
}

int WhiteBox5(struct circularBuffer* bufferPtr,int BUFFER_SIZE,int Value)
{
    setHead(bufferPtr, BUFFER_SIZE - 2);
    addElement(bufferPtr,Value );
    printBuffer(bufferPtr);
    printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
    if (bufferPtr->data[BUFFER_SIZE - 2] == Value)
    {
        printf("WhitekBox5 Passed\n");
        return 1;
    }
    else 
    {
        printf("WhitekBox5 Failed\n");
        return 0;
    } 
}

/*
removeValue()
•WhiteBox6 :Remove elements with the argument value if buffer contains 1 element.
Different placements of the tail and header might need to be considered,
and you need to figure out which combinations are relevant.
•WhiteBox7 :Remove element with specified value if buffer is full.
    – Different placements of the tail and header might need to be 
    considered, and you need to figure out which combinations are relevant.
    – Different placements of the elements (one or more) to remove might
    need to be considered, and you should figure out which.
•WhiteBox8 :Try remove elements with specified value if buffer is empty.
*/

int WhiteBox6(struct circularBuffer* bufferPtr,int Value)
{
    addElement(bufferPtr, Value);
    printBuffer(bufferPtr);
    removeValue(bufferPtr, Value);
    printf("\n");
    printBuffer(bufferPtr);
    printf("Head Posetion : %d\n", bufferPtr->head);
    printf("Tail Posetion : %d\n", bufferPtr->tail); 
    if(contains(bufferPtr,Value) == INT_MIN)
    {
        printf("WhitekBox6 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox6 Failed\n");
        return 0;
    }
}

int WhiteBox7(struct circularBuffer* bufferPtr,int Value,int BUFFER_SIZE)
{
    int ValueToAdd = 0;
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        addElement(bufferPtr, ValueToAdd);
        ValueToAdd++;
    }
    printBuffer(bufferPtr);
    printf("\n");
    removeValue(bufferPtr, Value);
    printf("\n");
    printBuffer(bufferPtr);
    printf("\n");
    printf("Head Posetion : %d\n", bufferPtr->head);
    printf("Tail Posetion : %d\n", bufferPtr->tail); 
    if (contains(bufferPtr, Value) == INT_MIN)
    {
        printf("WhitekBox7 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox7 Failed\n");
        return 0;
    }
    
}

int WhiteBox8(struct circularBuffer* bufferPtr,int value, int BUFFER_SIZE)
{
    printBuffer(bufferPtr);
    printf("\n");
    if (removeValue(bufferPtr,value) == INT_MIN)
    {
        printf("WhitekBox8 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox8 Failed\n");
        return 0;
    }
    
}

/*
removeHead()
•WhiteBox9 :Remove element when buffer contains only 1 element. Different placements
of the tail and header might need to be considered, and you need to figure
out which combinations are relevant.
•WhiteBox10 :Remove element when buffer contains two elements. Different placements
of the tail and header might need to be considered, and you need to figure
out which combinations are relevant.
•WhiteBox11 :Remove element when buffer contains three elements. Different placements
of the tail and header might need to be considered, and you need to figure
out which combinations are relevant.
•WhiteBox12 :Try remove element when circular buffer is empty. Different placements of
the tail and header might need to be considered, and you need to figure
out which combinations are relevant.
*/

int WhiteBox9(struct circularBuffer* bufferPtr, int HeadPosetion, int Value)
{

    setHead(bufferPtr, HeadPosetion);
    addElement(bufferPtr, Value);
    printf("\n");
    printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
    printBuffer(bufferPtr);
    removeHead(bufferPtr);
    if (bufferPtr->head == bufferPtr->tail)
    {
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printBuffer(bufferPtr);
        printf("\n");
        printf("WhitekBox9 Passed\n");
        return 1;
    }
    else
    {
        printf("WhitekBox9 Failed\n");
        return 0;
    }
}

int WhiteBox10(struct circularBuffer* bufferPtr, int HeadPosetion, int Value1, int Value2)
{
    setHead(bufferPtr, HeadPosetion);
    addElement(bufferPtr, Value1);
    addElement(bufferPtr, Value2);
    printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
    printf("\n");
    printBuffer(bufferPtr);
    printf("\n");
    removeHead(bufferPtr);
    if ((bufferPtr->head+1 == bufferPtr->tail) || (bufferPtr->tail == 0))
    {
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printBuffer(bufferPtr);
        printf("\n");
        printf("WhitekBox10 Passed\n");
        return 1;
    }
    else
    {
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printBuffer(bufferPtr);
        printf("WhitekBox10 Failed\n");
        return 0;
    }
}

int WhiteBox11(struct circularBuffer* bufferPtr, int HeadPosetion, int Value1,int Value2,int Value3)
{
    setHead(bufferPtr, HeadPosetion);
    addElement(bufferPtr, Value1);
    addElement(bufferPtr, Value2);
    addElement(bufferPtr, Value3);
    printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
    printf("\n");
    printBuffer(bufferPtr);
    printf("\n");
    removeHead(bufferPtr);
    if ((bufferPtr->head +2 ==bufferPtr->tail) || (bufferPtr->tail == 0))
    {
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printBuffer(bufferPtr);
        printf("\n");
        printf("WhitekBox11 Passed\n");
        return 1;
    }
    else
    {
        printBuffer(bufferPtr);
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printf("WhitekBox11 Failed\n");
        return 0;
    }
    
}

int WhiteBox12(struct circularBuffer* bufferPtr,int HeadPosetion,int TailPosetion)
{
    setTail(bufferPtr, TailPosetion);
    setHead(bufferPtr, HeadPosetion);
    printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
    printBuffer(bufferPtr);
    
    printf("\n");
    if (removeHead(bufferPtr))
    {
        bufferPtr->tail++;
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printBuffer(bufferPtr);
        printf("\n");
        printf("WhitekBox12 Passed\n");
        return 1;
    }
    else
    {
        printBuffer(bufferPtr);
        printf("Head posetion : %d\nTail posetion : %d\n", bufferPtr->head, bufferPtr->tail);
        printf("WhitekBox11 Failed\n");
        return 0;
    }
}
