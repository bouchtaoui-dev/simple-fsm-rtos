//
//  simple_circular_queue.h
//
//  Created by Nordin Bouchtaoui on 15/11/2018.
//  Copyright © 2018 Nordin Bouchtaoui. All rights reserved.
//

#ifndef simple_circular_queue_h
#define simple_circular_queue_h


/**
 * Sets the array of a certain size to be used.
 */
void set_circular_queue(void* qu[], int len);

/**
 * Adds an object to the queue.
 * Important! If the queue is full,
 * the oldest added item in the queue deleted!
 */
void push_item_object(void *item);

/**
 * Gets an object from the queue.
 * Important! This will remove the object from the queue!
 */
void* pop_item_object(void);

/**
 * Gets object from head of the queue.
 * This will not remove the object from the queue.
 */
void* peak_head_object(void);

/**
 * Gets an object at a certain index
 */
void* peak_object_at(int index);

/**
 * Gets the number of items in the queue.
 */
int number_of_items_in_queue(void);


#endif /* simple_circular_queue_h */
