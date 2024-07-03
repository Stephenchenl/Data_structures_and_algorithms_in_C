#include <stdio.h>
#include <stdlib.h>
#include "../inc/binaryTree.h"


/**
 * @brief   ����������
 * @param   root�����ڵ�
 * @return  ������rootΪ���Ķ�����
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
 * @brief   �������ڵ�
 * @param   val:�ڵ�����
 * @return  ���ؽڵ�
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
 * @brief   �������ڵ������
 * @param   node�����ڵ�
 * @return
 * @note
*/
void visitTreeNode(treeNode *node){
    if(node){
        printf("%c ",node->data & 0xff);
    }
}

/**
 * @brief   ���ڵ��������
 * @param   tree:������
 *          parent:���׽ڵ�
 *          left:���ӽڵ�
 *          right:���ӽڵ�
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
 * @brief   ǰ�к������
 * @param   node����ǰ�����Ľڵ�
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
 * @brief   ǰ�к������
 * @param   tree��������
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
 * @brief   �ͷŶ�����
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