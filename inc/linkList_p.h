#ifndef LINKLIST_P_H
#define LINKLIST_P_H

/**
 * @brief   ��ͷ���ĵ�������ṹ���弰����
*/
typedef int Element_t;
typedef struct linkNode
{
    Element_t data;
    struct linkNode *next;
} LinkNode;


LinkNode *insertLinkListByPos_p(LinkNode *head, unsigned int pos, Element_t data);
void showLinkList_p(LinkNode *head);
LinkNode *deleteLinkList_p(LinkNode *head, Element_t data);
void releaseLinkList_p(LinkNode *head);

#endif
