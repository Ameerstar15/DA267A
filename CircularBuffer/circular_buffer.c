#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"


/*This function is used to initalize the buffer using, e.g. a statically allocated array
of integers.*/

void initCircularBuffer(struct circularBuffer* bufferPtr, int* data, int maxLength) {
  bufferPtr->data = data;
  bufferPtr->head = 0;
  bufferPtr->tail = 0;
  bufferPtr->elements = 0;
  bufferPtr->maxLength = maxLength;
}

/*This function should check if the buffer pointed to by bufferPtr contains at
least one element with the value specified by the value argument.*/ 
int contains(struct circularBuffer* bufferPtr, int value)
 {
  
    for (int i = 0; i < bufferPtr->maxLength; i++)
   {if (bufferPtr->data[i] == value)
   {
      printf("Value %d were found\n" , value);
      return 1;
    }
    }
       /*if no element with the argument value was
        not found.*/
       printf("Value %d were not found in your buffer\n", value);
       printf("INT_MIN\n");
       return INT_MIN;
  }
 

  int addElement(struct circularBuffer* bufferPtr, int value)
  {
    
    // if the buffer is not full
    if (emptyOrFullCircularBuffer(bufferPtr) == 0 || emptyOrFullCircularBuffer(bufferPtr) == 1)
    {
      bufferPtr->data[bufferPtr->tail] = value;
      printf("Value %d added !\n", value);
      bufferPtr->elements++;
      bufferPtr->tail = (bufferPtr->tail + 1); // or bufferPtr.tail = (bufferPtr->tail + 1)% buffer->maxLength  instead of the whole if statment below
      if (bufferPtr->tail >= bufferPtr->maxLength)
      {
        bufferPtr->tail = 0;
      }
      /*if (bufferPtr->tail <= bufferPtr->head)
        {
          bufferPtr->head++;
        }*/
      }
      else 
      {
        printf("INT_MIN\n");
        return INT_MIN;
      }
       return 0;
  }

  void setTail(struct circularBuffer* bufferPtr, int Posetion)
  {
    bufferPtr->tail = Posetion; 
  }

  void setHead(struct circularBuffer* bufferPtr, int Posetion)
  {
    bufferPtr->head = Posetion;
    if (bufferPtr->tail <= bufferPtr->head)
    {
      setTail(bufferPtr, Posetion);
    }
  }

 int removeValue(struct circularBuffer* bufferPtr, int value)
  {
    if (contains(bufferPtr,value) == 1)
    {
        for (int i = 0; i < bufferPtr->maxLength; i++)
      {
        
        if (bufferPtr->data[i] == value)
        {
          printf("Value %d removed\n", value);
          int Distance;
          if (bufferPtr->tail == bufferPtr->head || bufferPtr->tail < bufferPtr->head)
          {
            //Distance = (bufferPtr->tail + bufferPtr->maxLength-1) - i;
            Distance = bufferPtr->elements-1;
          }
          else 
          {
            Distance = bufferPtr->tail - i;
          }
           
          int temp = i + 1;
          for (int j = 0; j <= Distance; j++)
          {
            
            
            if (bufferPtr->data[i] == bufferPtr->data[bufferPtr->maxLength-1])
            {
              bufferPtr->data[i] = bufferPtr->data[0];
              
            }
            else
            {
            bufferPtr->data[i] = bufferPtr->data[temp];
            i++;
            temp++;
            }
            
          }if (bufferPtr->tail == 0)
          {
            
            bufferPtr->tail = bufferPtr->maxLength - 1;
            if (bufferPtr->head > 0)
            {
              bufferPtr->head--;
            }
            bufferPtr->data[bufferPtr->maxLength-1] = -1;
          }else
          {
            bufferPtr->tail--;
            bufferPtr->data[bufferPtr->tail] = -1;
          }
          bufferPtr->elements--;
        }
        
      } return 0;
     }else
        {
          printf("INT_MIN\n");
           return INT_MIN;
        }
  }
      
  

  int removeHead(struct circularBuffer* bufferPtr)
  {
    if(emptyOrFullCircularBuffer(bufferPtr) == 0)
    {
      printf("Value : %d was removd from head\n", bufferPtr->data[bufferPtr->head]);
      bufferPtr->data[bufferPtr->head] = -1; 
      if(bufferPtr->head == bufferPtr->maxLength-1)
      {
        bufferPtr->head = 0;
      }
      else
      {
        bufferPtr->head++;
      }
      if ((emptyOrFullCircularBuffer(bufferPtr) == 1))
      {
        bufferPtr->tail++;
      }

      return 1;
    }
    return 2;
  } 
  

 void printBuffer(struct circularBuffer* bufferPtr){
     for (int i = 0; i < bufferPtr->maxLength; i++)
     {
        
         printf("Data: %d \n ", bufferPtr->data[i]);
     } 
   }

   int emptyOrFullCircularBuffer(struct circularBuffer* bufferPtr)
    {
      if (bufferPtr->elements == bufferPtr->maxLength || bufferPtr->elements > bufferPtr->maxLength)
      {
        printf("Buffer is full \n");
        return 1;
      }if (bufferPtr->elements < bufferPtr->maxLength)
      {
        printf("Buffer is empty \n");
        return 0;
      }
      else
        
      return 2;
    }

  