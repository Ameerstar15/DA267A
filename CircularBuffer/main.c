#include <stdio.h>
#include <stdlib.h>
#include <esp32/rom/ets_sys.h>
#include "circular_buffer.h"
#include "BlackBox.h"
#include "WhiteBox.h"


/*
 * Change the value of BUFFER_SIZE if you want to change the size of the buffer. 
 */ 
#define BUFFER_SIZE 5

void app_main() {

    
    // Some code to help you get started
    struct circularBuffer buffer;
    int *buffer_data = (int*) malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    
   /* printf("\n\n\n");
    printf("****************BLACK BOX TESTING *******************");
    printf("\n");

    //BlackBox1(&buffer, 1);
    //BlackBox2(&buffer, 1, 2, 1, 2);
    //BlackBox3(&buffer, BUFFER_SIZE);
    //BlackBox4(&buffer, 1, 2, 3, 4, 5, 6);
    //BlackBox5(&buffer, BUFFER_SIZE);
    //BlackBox6(&buffer, 5);
    //BlackBox7(&buffer, 5);
    //BlackBox8(&buffer, 2, 0);
    //BlackBox9(&buffer, BUFFER_SIZE);
    //Results(); */


    printf("**************** White Box TESTING *******************\n");
    //WhiteBox1(&buffer, buffer_data, BUFFER_SIZE);
    //WhiteBox2(&buffer, 5);
    //WhiteBox3(&buffer, 4, 4, BUFFER_SIZE);
    //WhiteBox4(&buffer, BUFFER_SIZE);
    //WhiteBox5(&buffer, BUFFER_SIZE, 4);
    //WhiteBox6(&buffer, 10);

    // Choose a value to remove between 0 - 4 
    //WhiteBox7(&buffer, 4, BUFFER_SIZE);

    //WhiteBox8(&buffer, 7, BUFFER_SIZE);
    //WhiteBox9(&buffer, 3, 4);
    //WhiteBox10(&buffer, 4, 4, 8);
    //WhiteBox11(&buffer, 2, 200, 100, 50);
    WhiteBox12(&buffer, 2, 0);
    
    printf("\n\n\n");

    free(buffer_data);
}