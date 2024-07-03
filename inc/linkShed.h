#ifndef LINKSHED_H
#define LINKSHED_H

typedef int Element_t;
typedef struct
{
    Element_t data;
    struct linkSheNode *next;
}LinkShedNode;

LinkShedNode *pushShed(LinkShedNode *top, Element_t data);
LinkShedNode *popShed(LinkShedNode *top, Element_t data);


#endif