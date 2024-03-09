#include <stdio.h>
#include <stdlib.h>
#include "simple_circular_queue.h"

int test(void) {
    // insert code here...
    printf("Start test circular queue!\n");
    printf("\n");

    int* myQu[10];
    set_circular_queue((void**)myQu, 10);

    printf("Adding 10 objects...\n");
    for(int i=0; i<10;i++) {
        int *object = malloc(sizeof(int)*1);
        *object = i;

        push_item_object(object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("How array now looks like:\n");
    for (int i=0; i<10; i++) {
        printf("array  memaddr: 0x%x data: %d\n", (unsigned int)myQu[i], (int)*myQu[i]);
    }
    printf("\n");

    printf("Adding another 5 objects...\n");
    for(int i=0; i<5;i++) {
        int *object = malloc(sizeof(int)*1);
        *object = i+10;

        push_item_object(object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("How array now looks like:\n");
    for (int i=0; i<10; i++) {
        printf("array  memaddr: 0x%x data: %d\n", (unsigned int)myQu[i], (int)*myQu[i]);
    }
    printf("\n");

    printf("How objects look in circular queue:\n");
    for (int i=0; i<10; i++) {
        int *object = peak_object_at(i);
        printf("object memaddr: 0x%x data: %d\n", (unsigned int)object, (int)*object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("Now popping 5 objects...\n");
    for (int i=0; i<5; i++) {
        int *object = pop_item_object();

        if(object) free(object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("Now popping 5 objects...\n");
    for (int i=0; i<5; i++) {
        int *object = pop_item_object();

        if(object) free(object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("Adding 3 objects...\n");
    for(int i=0; i<3;i++) {
        int *object = malloc(sizeof(int)*1);
        *object = i;

        push_item_object(object);
    }
    printf("Number of items in queue: %d\n", number_of_items_in_queue());
    printf("\n");

    printf("How array now looks like:\n");
    for (int i=0; i<10; i++) {
        printf("array  memaddr: 0x%x data: %d\n", (unsigned int)myQu[i], myQu[i]?(int)*myQu[i]:(int)NULL);
    }
    printf("\n");

    //return 0;
    exit(EXIT_SUCCESS);
}

int main() {
    // printf("Salam alikoum brothers and sisters!\n");
    test();
}
