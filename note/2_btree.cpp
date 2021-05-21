#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//二叉树
#if 0
//树的实现和业务没有分离
struct bstree_node
{
    int key;   //key
    struct bstree_node *left;
    struct bstree_node *right;

    //value
    long start;
    long end;
    //
};

struct bstree
{
    struct bstree_node *root;
};


struct bstree *tree;
#else

typedef int KEY_VALUE;

#define BSTREE_ENTRY(name,type) \
        struct name{            \
            struct type *left;  \
            struct type *right; \
        }

//
//
struct bstree_node{

    //struct[] bst;
    BSTREE_ENTRY(,bstree_node) bst;

    KEY_VALUE key;

    //int key;

    //value
    //void *value;//不要这样写
};

struct bstree
{
    /* data */
    struct bstree_node *root;
};


#endif

//创建节点
struct bstree_node *bstree_create_node (KEY_VALUE key){
    struct bstree_node *node = (struct bstree_node*)malloc(sizeof(struct bstree_node));

    if(node == NULL){
        return NULL;
    }

    node->key = key;
    node->bst.left = node->bst.right = NULL;

    return node;

}

//插入节点
int bstree_insert(bstree *tree,KEY_VALUE key){
    
    assert(tree != NULL);

    if(tree->root == NULL){
        tree->root = bstree_create_node(key);
        return 0;
    }

    struct bstree_node *node = tree->root;
    struct bstree_node *tmp = tree->root;

    while(node != NULL){

        tmp = node;

        if(key > node->key){
            node = node->bst.right;
        }else if(key < node->key){
            node = node->bst.left;
        }else{
            //操作
            return 1;
        }
    }

    //node = NULL
    //tmp指向node上一个的位置

    //这里当key与寻找到的节点相同的情况，已经在循环内处理过了
    if(key < tmp->key){
        tmp->bst.left = bstree_create_node(key);
    }else{
        tmp->bst.right = bstree_create_node(key);
    }

    return 0;
}

//遍历
//前、中、后  前序和后序几乎没有应用场景
int bstree_traversal(struct bstree_node *node){
    if(node == NULL){
        return 0;
    }


    //递归
    printf("%4d",node->key);//先
    bstree_traversal(node->bst.left);
    // printf("%4d",node->key);//中
    bstree_traversal(node->bst.right);
    // printf("%4d",node->key);//后

    return 0;
}

#define ARRAY_LENGTH   20

int main(){

    int arr[ARRAY_LENGTH] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    struct bstree T = {0};

    for(int i = 0;i < ARRAY_LENGTH;i++){
        bstree_insert(&T,arr[i]);
    }

    bstree_traversal(T.root);
    printf("\n");
    
    return 0;
}

