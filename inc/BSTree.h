#ifndef BSTREE_H
#define BSTREE_H


typedef int Element_t;
typedef struct
{
    Element_t data;
    struct treeNode *left;
    struct treeNode *right;
}BSNode;

typedef struct
{
    treeNode *root;
    int count;
}BSTree;

static BSNode *createBSNode(Element_t val);
static BSNode *insertBSNode(BSTree *tree, BSNode *node, Element_t val);
void insertBSTree(BSTree *tree, Element_t val);
static BSNode *searchNode(BSNode *node,Element_t val);
void searchBSTree(BSTree *tree, Element_t val);
static int getHeight(BSNode *node);
int getBSTreeHeight(BSTree *tree);


#endif