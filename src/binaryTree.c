#include <stdio.h>
#include <stdlib.h>
#include "../inc/binaryTree.h"


/**
 * @brief   创建二叉树
 * @param   root：根节点
 * @return  返回以root为根的二叉树
 * @note
*/
binaryTree *createBinaryTree(treeNode *root){
    binaryTree *tree = malloc(sizeof(binaryTree));
    if(tree == NULL){
        perror("malloc");
        return NULL;
    }
    if(root){
        tree->root = root;
        tree->count = 1;
    }
    else{
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

/**
 * @brief   创建树节点
 * @param   val:节点数据
 * @return  返回节点
 * @note
*/
treeNode *createTreeNode(Element_t val){
    treeNode *node = malloc(sizeof(treeNode));
    if(node == NULL){
        perror("malloc");
        return NULL;
    }
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

/**
 * @brief   访问树节点的数据
 * @param   node：树节点
 * @return
 * @note
*/
void visitTreeNode(treeNode *node){
    if(node){
        printf("%c ",node->data & 0xff);
    }
}

/**
 * @brief   将节点插入树中
 * @param   tree:二叉树
 *          parent:父亲节点
 *          left:左子节点
 *          right:右子节点
 * @return
 * @note
*/
void insertBinaryTree(binaryTree *tree, treeNode *parent, treeNode *left, treeNode *right){
    if(tree && parent){
        parent->left = left;
        parent->right = right;
        if(left){
            tree->count++;
        }
        if(right){
            tree->count++;
        }
    }
}

/**
 * @brief   前中后序遍历
 * @param   node：当前遍历的节点
 * @return
 * @note
*/
static void preOrderNode(treeNode *node){
    if(node){
        visitTreeNode(node);
        preOrderNode(node->left);
        preOrderNode(node->right);
    }
}
static void inOrderNode(treeNode *node){
    if(node){
        inOrderNode(node->left);
        visitTreeNode(node);
        inOrderNode(node->right);
    }
}
static void posOrderNode(treeNode *node){
    if(node){
        posOrderNode(node->left);
        posOrderNode(node->right);
        visitTreeNode(node);
    }
}

/**
 * @brief   前中后序遍历
 * @param   tree：二叉树
 * @return
 * @note
*/
void preOrderBinaryTree(binaryTree *tree){
    if(tree){
        preOrderNode(tree->root);
        printf("\n");
    }
}
void inOrderBinaryTree(binaryTree *tree){
    if(tree){
        inOrderNode(tree->root);
        printf("\n");
    }
}
void posOrderBinaryTree(binaryTree *tree){
    if(tree){
        posOrderNode(tree->root);
        printf("\n");
    }
}

/**
 * @brief   释放二叉树
 * @param
 * @return
 * @note
*/
static void freeNode(binaryTree *tree, treeNode *node){
    if(node){
        freeNode(tree,node->left);
        freeNode(tree,node->right);
        free(node);
        tree->count--;
    }
}
void releaseBinaryTree(binaryTree *tree){
    if(tree){
        freeNode(tree,tree->root);
        printf("tree have %d node lost\n",tree->count);
        free(tree);
    }
}