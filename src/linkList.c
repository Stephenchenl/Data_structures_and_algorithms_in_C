#include <malloc.h>
#include <stdio.h>
#include "../inc/linkList.h"


/**
 * @brief   创建带头结点的单向链表
 * @param   无参数
 * @return  返回链表指针
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
 * @brief   头插法插入
 * @param   *linkList：链表指针
 *          data：待插入数据
 * @return  插入成功返回0，失败返回-1
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
 * @brief   指定位置插入
 * @param   *linkList：链表指针
 *          data：待插入数据
 *          pos：待插入位置
 * @return  插入成功返回0，失败返回-1
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
 * @brief   按值删除
 * @param   *linkList：链表指针
 *          data：待删除数据
 * @return  删除成功返回0，失败返回-1
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
 * @brief   遍历打印链表
 * @param   *linkList：链表指针
 * @return  无返回值
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
 * @brief   释放链表
 * @param   *linkList：链表指针
 * @return  无返回值
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
 * @brief   带头结点的链表倒叙
 * @param   linklist：链表头节点
 * @return  
 * @note
*/
void reverseList(LinkList *linkList){
    //初始化
    LinkNode *t1 = linkList->head.next;
    linkList->head.next = NULL;
    //头插法
    LinkNode *bak;
    while (t1)
    {
        bak = t1->next;
        t1->next = linkList->head.next;
        linkList->head.next = t1;
        t1 = bak;
    }

}