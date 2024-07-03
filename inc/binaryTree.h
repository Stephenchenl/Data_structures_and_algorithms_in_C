#ifndef BINARYTREE_H
#define BINARYTREE_H


typedef int Element_t;
typedef struct
{
    Element_t data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

typedef struct
{
    treeNode *root;
    int count;
}binaryTree;

binaryTree *createBinaryTree(treeNode *root);
treeNode *createTreeNode(Element_t val);
void visitTreeNode(treeNode *node);
void insertBinaryTree(binaryTree *tree, treeNode *parent, treeNode *left, treeNode *right);
static void preOrderNode(treeNode *node);
static void inOrderNode(treeNode *node);
static void posOrderNode(treeNode *node);
void preOrderBinaryTree(binaryTree *tree);
void inOrderBinaryTree(binaryTree *tree);
void posOrderBinaryTree(binaryTree *tree);


#endif