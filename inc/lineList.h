#ifndef LINELIST_H
#define LINELIST_H

typedef int Element_t;

typedef struct lineList
{
    Element_t *data;
    int cur_len;
    int capacity;
}LineList_t;

LineList_t* createLineList(int capacity);
void releaselineList(LineList_t *list);
void pushlineList(LineList_t *list, Element_t value);
void poplineList(LineList_t *list);
void showLineList(const LineList_t *list);
bool isEmpty(LineList_t *list);
bool isFull(LineList_t *list);


#endif