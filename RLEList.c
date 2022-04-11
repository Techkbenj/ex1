//#include "RLEList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char letter;
    int numOfReps;
    struct list* next;
} *RLEList;

RLEList RLEListCreate();
RLEList RLEListAppend(RLEList list, char value);
void RLEListDestroy(RLEList list);

int main()
{
    
    return 0;
}

RLEList RLEListCreate()
{
    RLEList ptr = malloc(sizeof(*ptr));
    if (!ptr)
    {
        return NULL;
    }
    ptr->letter = 'a';
    ptr->numOfReps = 0;
    ptr->next = NULL;
    return ptr;
}

void RLEListDestroy(RLEList list)
{
	while(list) {
		RLEList toDelete = list;
		list = list->next;
		free(toDelete);
	}
}

RLEList RLEListAppend(RLEList list, char value)
{
    if (list->numOfReps == 0)
    {
        list->letter = value;
        list->numOfReps = 1;
        return list;
    }
    RLEList nextNode = list;
    while (nextNode->next)
        {
            nextNode = list->next;
        }
    if (nextNode->letter == value)
    {
        nextNode->numOfReps += 1;
        return list;
    }
    RLEList newNode = RLEListCreate();
    newNode->letter = value;
    newNode->numOfReps = 1;
    nextNode->next = newNode;
    return list;
}

