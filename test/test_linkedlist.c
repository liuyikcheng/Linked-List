#include "unity.h"
#include "linkedlist.h"
#include "listElement.h"
#include "addList.h"
#include <stdio.h>
#include <malloc.h>

void setUp(void)
{
}

void tearDown(void)
{
}


/**
 *
 *     |-----------|
 *     |     2     |-------->NULL
 *     |-----------|
 *
 *
 **/
// To test the initiated element contain the wanted value and a pointer point to NULL
void test_linkedList_listelement(void)
{
	struct ListElement *element = malloc(sizeof(struct ListElement));
	element = createListElement(2);
	TEST_ASSERT_EQUAL(2,element->value);
	TEST_ASSERT_EQUAL(NULL,element->next);
}

/**
 *
 *     head------->NULL
 *
 *     tail------->NULL
 *
 *
 **/
// To test the created head and tail are pointing to ground
void test_linkedList_head_and_tail_both_should_return_NULL(void)
{
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
}


/**
 *
 *        head------------>                           head-------> |-----------|
 *                                 ===========>                    |     2     |-------->NULL
 *        tail------------>                           tail-------> |-----------|
 *                
 *
 **/

// Below tests are to test the values that pointed by head and tail after input a certain number of values
void test_linkedList_given_2_head_should_point_to_2_tail_should_point_to_2(void){
	struct ListElement *element = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	element = createListElement(2);
	list = creatLinkedList();
	addList(element,list);
	TEST_ASSERT_EQUAL(2,list->head->value);
	TEST_ASSERT_EQUAL(2,list->tail->value);
}

/**
 *
 *
 *                                                               
 *     head-------> |-----------|                               head-------> |-----------|         |-----------|
 *                  |     2     |-------->NULL    ========>                  |     2     |-------> |     3     |------>NULL
 *     tail-------> |-----------|                                            |-----------|         |-----------|                                                                            
 *                                                                                                      ^
 *                                                                                                      | 
 *                                                               tail-----------------------------------
 *   
 **/
void test_linkedList_given_3_2_head_should_point_to_3_tail_should_point_to_2(void){
	struct ListElement *element = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	addList(createListElement(3),list);
	TEST_ASSERT_EQUAL(3,list->tail->value);
	TEST_ASSERT_EQUAL(2,list->head->value);
}


/**
 *
 *
 *                                                               head--------->|-------|       |-------|       |-------|
 *       head-------> |-------|       |-------|                                |   2   |-----> |   3   |-----> |   5   |------>NULL
 *                    |   2   |-----> |   3   |------>NULL  ======>            |-------|       |-------|       |-------|
 *                    |-------|       |-------|                                                                     ^   
 *                                        ^                                                                         |
 *                                        |                                 tail------------------------------------
 *         tail---------------------------
 *   
 **/
void test_linkedList_given_2_3_5_head_should_point_to_2_tail_should_point_to_5(void){
	struct ListElement *element = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	addList(createListElement(3),list);
	addList(createListElement(5),list);
	TEST_ASSERT_EQUAL(5,list->tail->value);
	TEST_ASSERT_EQUAL(2,list->head->value);
}

/**
 *
 *
 *                                                               
 *     head-------> |-----------|                               head------->NULL 
 *                  |     2     |-------->NULL    ========>                  
 *     tail-------> |-----------|                               tail------->NULL                                                                                         
 *                                                                           
 *                                                                            
 *   
 **/
void test_stack_given_empty_linkedlist_then_add_2_should_add_element_2_to_the_list_and_remove_it_and_return_empty_list(void){
	struct ListElement *element = malloc(sizeof(struct ListElement));
	struct ListElement *removedElement = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	removedElement = elementRemoved(list);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(NULL,list->head);
}

/**
 *
 *
 *                                                                        head---------> |-------|
 *       head-------> |-------|       |-------|                                          |   2   |------>NULL
 *                    |   2   |-----> |   3   |------>NULL  ======>                      |-------|
 *                    |-------|       |-------|                                               ^   
 *                                        ^                                                   |
 *                                        |                                 tail--------------
 *         tail---------------------------
 *   
 **/
 void test_stack_given_empty_linkedlist_then_add_2_and_3_should_add_element_2_and_3_to_the_list_and_remove_element_3(void){
	struct ListElement *element = malloc(sizeof(struct ListElement));
	struct ListElement *removedElement = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	addList(createListElement(3),list);
	removedElement = elementRemoved(list);
	TEST_ASSERT_EQUAL(2,list->tail->value);
	TEST_ASSERT_EQUAL(2,list->head->value);
 }
 
 /**
 *
 *
 *                                                                                       head---------> |-------|       |-------|
 *       head-------> |-------|      |-------|       |-------|                                          |   2   |-----> |   3   |------>NULL
 *                    |   2   |----> |   3   |-----> |   5   |------>NULL  ======>                      |-------|       |-------|
 *                    |-------|      |-------|       |-------|                                                             ^   
 *                                                      ^                                                                  |
 *                                                      |                                                tail--------------
 *         tail------------------------------------------
 *   
 **/
 void test_stack_given_empty_linkedlist_then_add_2_and_3_and_5_should_add_element_2_and_3_and_5_to_the_list_and_remove_element_5(void){
  struct ListElement *element = malloc(sizeof(struct ListElement));
	struct ListElement *removedElement = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	addList(createListElement(3),list);
	addList(createListElement(5),list);
	removedElement = elementRemoved(list);
	TEST_ASSERT_EQUAL(3,list->tail->value);
	TEST_ASSERT_EQUAL(2,list->head->value);
 }
 
 
 /**
 *
 *
 *                                                                                       head---------> |-------|
 *       head-------> |-------|      |-------|       |-------|                                          |   2   |------>NULL
 *                    |   2   |----> |   3   |-----> |   5   |------>NULL  ======>                      |-------|
 *                    |-------|      |-------|       |-------|                                               ^   
 *                                                      ^                                                   |
 *                                                      |                                 tail--------------
 *         tail------------------------------------------
 *   
 **/
 void test_stack_given_empty_linkedlist_then_add_2_and_3_and_5_should_add_element_2_and_3_and_5_to_the_list_and_remove_element_3_and_5(void){
  struct ListElement *element = malloc(sizeof(struct ListElement));
	struct ListElement *removedElement = malloc(sizeof(struct ListElement));
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list = creatLinkedList();
	addList(createListElement(2),list);
	addList(createListElement(3),list);
	addList(createListElement(5),list);
	removedElement = elementRemoved(list);
	removedElement = elementRemoved(list);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_EQUAL(2,list->tail->value);
	TEST_ASSERT_EQUAL(2,list->head->value);
 }