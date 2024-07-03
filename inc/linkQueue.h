#ifndef LINKQUEUE_H
#define LINKQUEUE_H


typedef int Element_t;
typedef struct
{
    Element_t data;
    struct linkQueueNode *next;
}LinkQueueNode;

typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;




#endif