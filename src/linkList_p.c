#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkList_p.h"


/**
 * @brief   ָ��λ�ò���
 * @param   head��ͷָ��
 *          data������������
 *          pos��������λ��
 * @return  ���ز���Ľڵ�
 * @note
*/
LinkNode *insertLinkListByPos_p(LinkNode *head, unsigned int pos, Element_t data)
{
    //��������ڵ㣬�䵱ͷ�ڵ�
    LinkNode dummpy;
    dummpy.next = head;

    //��������ָ�룬ָ��pos-1��λ����
    LinkNode *p = &dummpy;
    int i = -1;
    while (p && i != pos -1)
    {
        p = p->next;
        ++i;
    }
    //����ָ����ж�
    if (p == NULL)
    {
        printf("pos invalid\n");
        return dummpy.next;
    }
    //�����½ڵ�
    LinkNode *newNode = malloc(sizeof(LinkNode));
    if (newNode == NULL)
    {
        perror("newNode malloc");
        return dummpy.next;
    }

    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;

    return dummpy.next;
}

/**
 * @brief   ��ֵɾ��
 * @param   *linkList������ָ��
 *          data����ɾ������
 * @return  ɾ���ɹ�����0��ʧ�ܷ���-1
 * @note
*/
LinkNode *deleteLinkList_p(LinkNode *head, Element_t data)
{   
    LinkNode dummpy;
    dummpy.next = head;


    LinkNode *p = &dummpy;
    while (p->next && p->next->data != data)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("no data\n");
        return dummpy.next;
    }
    LinkNode *temp = p->next;
    p->next = temp->next;
    free(temp);

    return dummpy.next;
}


/**
 * @brief   ������ӡ����
 * @param   head��ͷָ��
 * @return  �޷���ֵ
 * @note
*/
void showLinkList_p(LinkNode *head)
{
    while (head)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}


/**
 * @brief   �ͷ�����
 * @param   head��ͷָ��
 * @return  �޷���ֵ
 * @note
*/
void releaseLinkList_p(LinkNode *head)
{
    LinkNode dummpy;
    dummpy.next = head;

    while (dummpy.next)
    {
        LinkNode *bak = dummpy.next;
        dummpy.next = bak->next;
        free(bak);
    }
}