#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree{
    Node *firstElement;
} Tree;

Tree *createEmptyTree(){
    Tree *tree = malloc(sizeof(struct Tree));
    tree->firstElement = malloc(sizeof(struct Node));
    return tree;
}

void insertNode(Tree *tree, int value){

}

void deleteNode(Tree *tree, int value){

}

void findNode(Tree *tree, int value){

}

void main(){
    Tree *tree = createEmptyTree();
    tree->firstElement->key = 10;
    printf("%d\n", tree->firstElement->key);
}

