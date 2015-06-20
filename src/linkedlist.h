#ifndef linkedlist_H
#define linkedlist_H



struct ListElement{
	struct ListElement *next; //Pointer Next will point to the next element
	int value; //Value will store integer number that given by users
};

struct LinkedList{
	struct ListElement *head; //Pointer head will always point to the first element
	struct ListElement *tail; //Pointer Tail will always point to the last element
	int length;
};


struct ListElement *createListElement(int value);
struct LinkedList *creatLinkedList();
void addList(struct ListElement *newElement, struct LinkedList *list);
#endif // linkedlist_H
