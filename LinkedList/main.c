#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"
#include "double_linked_list.h"
#include "test_single_linked_list.h"
#include "test_doubleLinkedList.h"
#include <esp_task_wdt.h>

void app_main()
{
    struct singleLinkedList *list = (struct singleLinkedList *)malloc(sizeof(struct singleLinkedList));
    // test1_singleLinkedList(list, 10, 4);
    // test2_SingleLinkedList(list, 5, 4,8);
    // test3_singleLinkedList(list, 2, 5, 1);
    // test4_singleLinkedList(list, 5);
    // test5_singleLinkedList(list);

    // struct doubleLinkedList *list = (struct doubleLinkedList *)malloc(sizeof(struct doubleLinkedList));
    // test1_doubleLinkedList(list, 2, 8, 0, 20);
    // test2_doubleLinkedList(list, 4, 15, 0);
    // test3_doubleLinkedList(list, 0);
    // printDoubleLinkedList(list);
    // test4_doubleLinkedList(list);

    fflush(stdout);
    free(list);
}