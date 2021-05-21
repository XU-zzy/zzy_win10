#include<stdio.h>

#define RED     1
#define BLACK   2

typedef int KEY_TYPE;

typedef struct _rbtree_node{
    //rbtree
    unsigned char color;
    rbtree_node *parent;
    rbtree_node *left;
    rbtree_node *right;
    //end
    
    KEY_TYPE key;

    //value

} rbtree_node;

struct rbtree{
    rbtree_node *root;
    //空黑 将所有叶子节点指向这里，当作判断是叶子节点还是NULL的方法，NULL没有颜色属性
    rbtree_node *nil;   
};

//rotate旋转
//六根指针指向变化
//插入节点的时候，要通过左旋或右旋来调整平衡，以维持红黑树的性质

//左旋
void rbtree_left_rotate(rbtree *T,rbtree_node *x){
    //NULL ->> T->nil
    if(x == T->nil)   return ;

    rbtree_node *y = x->right;

    //1
    //先让x指向y的右节点
    x->right = y->left;
    if(y->left != T->nil){
        y->left->parent = x;
    }

    //2
    //让x的父节点指向y
    y->parent = x->parent;
    //如果x的父节点是哨兵，那就让y成为root节点
    //之后判断x是其父节点的左节点还是右节点
    if(x->parent == T->nil){
        T->root = y;
    }else if(x == x->parent->left) {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    //3
    //建立x与y的关系，让x成为y的左节点
    y->left = x;
    x->parent = y;

}

//右旋
//只需要：x->y , y->x , left -> right , right -> left就可以了
void rbtree_right_rotate(rbtree *T,rbtree_node *y){
    if(y == T->nil)   return ;

    rbtree_node *x = y->left;

    //1
    y->left = x->right;
    if(x->right != T->nil){
        x->right->parent = y;
    }

    //2
    x->parent = y->parent;
    if(y->parent == T->nil){
        T->root = x;
    }else if(y == y->parent->right) {
        y->parent->right = x;
    }else{
        y->parent->left = x;
    }

    //3
    x->right = y;
    y->parent = x;
 
}


//插入节点
void rbtree_insert(rbtree *T,rbtree_node *z){
    rbtree_node *node = T->root;
    rbtree_node *tmp = T->nil;

    while(node != T->nil){
        tmp = node;

        if(z->key < node->key){
            node = node->left;
        }else if(z->key > node->key){
            node = node->right;
        }else{  //Exist
            return ;
        }
    }

    z->parent = tmp->parent;
    if(z->key < tmp->key){
        tmp->left = z;
    }else if(z->key > tmp->key){
        tmp->right = z;
    }else{
        T->root = z;
    }

    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;

    rbtree_insert_fixup(T,z);

}

void rbtree_insert_fixup(rbtree *T,rbtree_node *x){

}
