#ifndef LINKLIST_H
#define LINKLIST_H


/**
 * @brief   带头结点的单向链表结构定义及方法
*/
typedef int Element_t;
typedef struct linkNode
{
    Element_t data;
    struct linkNode *next;
} LinkNode;

typedef struct linkList
{
    LinkNode head;
    int listNum;
} LinkList;

LinkList *createLinkList();
int insertLinkListByHead(LinkList *linkList, Element_t data);
int insertLinkListByPos(LinkList *linkList, unsigned int pos, Element_t data);
int deleteLinkList(LinkList *linkList, Element_t data);
void showLinkList(const LinkList *linkList);
void releaseLinkList(LinkList *linkList);
void reverseList(LinkList *linkList);

#endif