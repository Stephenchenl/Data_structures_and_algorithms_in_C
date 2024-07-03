#ifndef LINKLIST_H
#define LINKLIST_H


/**
 * @brief   ��ͷ���ĵ�������ṹ���弰����
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