#include <simple_circular_queue.h>
#include <stdlib.h>

// local variables
void **main_queue = NULL;   // this will be an array of pointers, hence **
int max_qu_len = 0;         // maximum queue length
int head = -1;              // head of the queue
int tail = -1;              // tail of the queue
int num_of_items = 0;       // number of added items in queue




void reset_main_queue() {
    if(main_queue) {
        for (int i=0; i<max_qu_len; i++) {
            void *item = main_queue[i];
            if(item) free(item);
        }

        max_qu_len = 0;
        head = -1;
        tail = -1;
        num_of_items = 0;
    }
}

void set_circular_queue(void * qu[], int len) {
    if(!qu) return;

    reset_main_queue();

    main_queue = qu;
    max_qu_len = len;
}

int is_qu_full() {
    if( (head == tail + 1) ||
       (head == 0 && tail == max_qu_len-1))
        return 1;

    return 0;
}

int is_qu_empty() {
    if(head == -1)
        return 1;
    else
        return 0;
}

void push_item_object(void *item) {
    if(!item) return;

    if(is_qu_full()) {
        // we need to remove task in the head
        // this means the oldest unprocessed event has to be dropped/ignored,
        // because of too many events
        void* front = main_queue[head];
        if(front) free(front);  // remove this object

        // if head is on end of queue
        if(head == max_qu_len-1) {
            // tail takes over head, head is than moved cell
            tail = head;
            head = 0;
        } else {
            tail = head++;
        }
        main_queue[tail] = item; // replace the old object
    } else {
        if(head == -1) head = 0;
        tail = (tail + 1) % max_qu_len;
        main_queue[tail] = item;
        num_of_items++;
    }
}

void* pop_item_object() {
    if(is_qu_empty()) {
        return NULL;
    } else {
        void* item = main_queue[head];
        main_queue[head] = NULL; // clear item in the queue
        if (head == tail){
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % max_qu_len;
        }
        num_of_items--;

        return item;
    }
}

void* peak_head_object() {
    if(is_qu_empty()) {
        return NULL;
    } else {
        return main_queue[head];
    }
}

void* peak_object_at(int index) {
    if(is_qu_empty()) {
        return NULL;
    } else {
        return main_queue[index];
    }
}

int number_of_items_in_queue() {
    return num_of_items;
}
