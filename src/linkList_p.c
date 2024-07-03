#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkList_p.h"


/**
 * @brief   指定位置插入
 * @param   head：头指针
 *          data：待插入数据
 *          pos：待插入位置
 * @return  返回插入的节点
 * @note
*/
LinkNode *insertLinkListByPos_p(LinkNode *head, unsigned int pos, Element_t data)
{
    //定义虚拟节点，充当头节点
    LinkNode dummpy;
    dummpy.next = head;

    //借助辅助指针，指向pos-1的位置上
    LinkNode *p = &dummpy;
    int i = -1;
    while (p && i != pos -1)
    {
        p = p->next;
        ++i;
    }
    //辅助指针的判断
    if (p == NULL)
    {
        printf("pos invalid\n");
        return dummpy.next;
    }
    //插入新节点
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
 * @brief   按值删除
 * @param   *linkList：链表指针
 *          data：待删除数据
 * @return  删除成功返回0，失败返回-1
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
 * @brief   遍历打印链表
 * @param   head：头指针
 * @return  无返回值
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
 * @brief   释放链表
 * @param   head：头指针
 * @return  无返回值
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