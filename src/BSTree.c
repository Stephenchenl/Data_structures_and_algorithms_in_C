#include <stdio.h>
#include <stdlib.h>
#include "../inc/BSTree.h"


/**
 * @brief   �������ڵ�
 * @param   val������
 * @return
 * @note
*/
static BSNode *createBSNode(Element_t val){
    BSNode *node = malloc(sizeof(BSNode));
    if(node == NULL){
        perror("malloc");
        return NULL;
    }
    node->left = node->right = NULL;
    node->data = val;

    return node;
}

/**
 * @brief   ����ڵ�
 * @param   tree������������
 *          node����ǰ�����ڵ�
 *          val������
 * @return  ���ز���Ľڵ�
 * @note
*/
static BSNode *insertBSNode(BSTree *tree, BSNode *node, Element_t val){
    if(node == NULL){
        return createBSNode(val);
    }
    if(val < node->data){
        node->left = insertBSNode(tree,node->left,val);
    }
    else if(val > node->data){
        node->right = insertBSNode(tree,node->right,val);
    }
    return node;
}
void insertBSTree(BSTree *tree, Element_t val){
    if(tree){
        tree->root = insertBSNode(tree,tree->root,val);
    }
}

/**
 * @brief   �����ڵ�����
 * @param   node����ǰ�����ڵ�
 *          val����������ֵ
 * @return  �����������Ľڵ�
 * @note
*/
static BSNode *searchNode(BSNode *node,Element_t val){
    if(node == NULL){
        return NULL;
    }
    if(val < node->data){
        return searchNode(node->left,val);
    }
    else if(val > node->data){
        return searchNode(node->right,val);
    }
    else{
        return node;
    }
}
void searchBSTree(BSTree *tree, Element_t val){
    BSNode *node = searchNode(tree->root,val);
    if(node){
        printf("find %d element\n",node->data);
    }
    else{
        printf("not find\n");
    }
}

/**
 * @brief   �����ĸ�
 * @param   node����ǰ�����ڵ�
 * @return
 * @note
*/
static int getHeight(BSNode *node){
    if(node == NULL){
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}
int getBSTreeHeight(BSTree *tree){
    if(tree){
        return getHeight(tree->root);
    }
    return 0;
}