#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/linkList_p.h"



int main() {

    LinkNode *head = NULL;

    head = insertLinkListByPos_p(head,0,1);
    head = insertLinkListByPos_p(head,1,2);
    head = insertLinkListByPos_p(head,2,3);
    head = insertLinkListByPos_p(head,3,4);

    deleteLinkList_p(head,2);

    showLinkList_p(head);

    releaseLinkList_p(head);


    system("pause");

    return 0;
}