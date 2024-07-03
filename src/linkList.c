#include <malloc.h>
#include <stdio.h>
#include "../inc/linkList.h"


/**
 * @brief   ������ͷ���ĵ�������
 * @param   �޲���
 * @return  ��������ָ��
 * @note
*/
LinkList *createLinkList()
{
    LinkList *linkList = malloc(sizeof(LinkList));
    if (linkList == NULL)
    {
        perror("linkList malloc");
    }

    linkList->head.next = NULL;
    linkList->listNum = 0;

    return linkList;
}

/**
 * @brief   ͷ�巨����
 * @param   *linkList������ָ��
 *          data������������
 * @return  ����ɹ�����0��ʧ�ܷ���-1
 * @note
*/
int insertLinkListByHead(LinkList *linkList, Element_t data)
{
    LinkNode *temp = &linkList->head;

    LinkNode *newNode = malloc(sizeof(LinkNode));
    if (newNode == NULL)
    {
        perror("newNode malloc");
        return -1;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    linkList->listNum++;

    return 0;
}

/**
 * @brief   ָ��λ�ò���
 * @param   *linkList������ָ��
 *          data������������
 *          pos��������λ��
 * @return  ����ɹ�����0��ʧ�ܷ���-1
 * @note
*/
int insertLinkListByPos(LinkList *linkList, unsigned int pos, Element_t data)
{
    if (pos < 0 || pos > linkList->listNum)
    {
        printf("pos invailed\n");
        return -1;
    }
    LinkNode *p = &linkList->head;
    int i = -1;
    while (p && i != pos - 1)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
    {
        return -1;
    }
    LinkNode *newNode = malloc(sizeof(LinkNode));
    if (newNode == NULL)
    {
        perror("newNode malloc");
    }

    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    linkList->listNum++;

    return 0;
}

/**
 * @brief   ��ֵɾ��
 * @param   *linkList������ָ��
 *          data����ɾ������
 * @return  ɾ���ɹ�����0��ʧ�ܷ���-1
 * @note
*/
int deleteLinkList(LinkList *linkList, Element_t data)
{
    LinkNode *p = &linkList->head;
    while (p->next && p->next->data != data)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("no data\n");
        return -1;
    }
    LinkNode *temp = p->next;
    p->next = temp->next;
    free(temp);
    linkList->listNum--;

    return 0;
}

/**
 * @brief   ������ӡ����
 * @param   *linkList������ָ��
 * @return  �޷���ֵ
 * @note
*/
void showLinkList(const LinkList *linkList)
{
    LinkNode *p = linkList->head.next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief   �ͷ�����
 * @param   *linkList������ָ��
 * @return  �޷���ֵ
 * @note
*/
void releaseLinkList(LinkList *linkList)
{
    LinkNode *p = &linkList->head;
    LinkNode *temp;
    while (p->next)
    {
        temp = p->next;
        p->next = temp->next;
        free(temp);
        linkList->listNum--;
    }
    free(linkList);
}

/**
 * @brief   ��ͷ����������
 * @param   linklist������ͷ�ڵ�
 * @return  
 * @note
*/
void reverseList(LinkList *linkList){
    //��ʼ��
    LinkNode *t1 = linkList->head.next;
    linkList->head.next = NULL;
    //ͷ�巨
    LinkNode *bak;
    while (t1)
    {
        bak = t1->next;
        t1->next = linkList->head.next;
        linkList->head.next = t1;
        t1 = bak;
    }

}