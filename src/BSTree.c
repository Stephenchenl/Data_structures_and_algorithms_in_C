#include <stdio.h>
#include <stdlib.h>
#include "../inc/BSTree.h"


/**
 * @brief   创建树节点
 * @param   val：数据
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
 * @brief   插入节点
 * @param   tree：二叉搜索树
 *          node：当前遍历节点
 *          val：数据
 * @return  返回插入的节点
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
 * @brief   搜索节点数据
 * @param   node：当前遍历节点
 *          val：待搜索的值
 * @return  返回搜索到的节点
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
 * @brief   求树的高
 * @param   node：当前遍历节点
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