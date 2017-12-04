//
// Created by slava on 25.09.17.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int key;
    struct _node *left, *right;
} node;

node* createNode(int val)
{
    node* nnode = (node*) malloc(sizeof(node));
    nnode->key = val;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

node* insertNode(node *root, int val) {
    if (root == NULL) root = createNode(val);
    if (val < root->key)
        if (root->left == NULL)
            root->left = createNode(val);
        else
            insertNode(root->left, val);
    if (val > root->key)
        if (root->right == NULL)
            root->right = createNode(val);
        else
            insertNode(root->right, val);
    return root;
}

node* findNode(node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val == root->key)
        return root;
    if (val < root->key)
        return findNode(root->left, val);
    if (val > root->key)
        return findNode(root->right, val);
}

int rightMost(node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

node* deleteNode(node *root, int val)
{
    if (root == NULL) return NULL;
    if (root->key == val) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if (root->right == NULL && root->left != NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        root->key = rightMost(root->left);
        root->left = deleteNode(root->left, root->key);
        return root;
    }
    if (val < root->key) {
        root->left = deleteNode(root->left, val);
        return root;
    }
    if (val > root->key) {
        root->right = deleteNode(root->right, val);
        return root;
    }
    return root;
}

void printTree(node *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->key);
        printTree(root->right);
    }
}

int tenDegree(int d) {
    int res = 1;
    int x = 10;
    int i;
    for (i = 0; i < d; ++i) {
        res = res * x;
    }
    return res;
}

int str2int(char *string){
    ++string;
    int i = 0, n = 0;
    int dig, res1 = 0;
    while (*string != '\0'){
        ++i;
        ++string;
    }
    while (n < i) {
        dig = (*--string - '0') * tenDegree(n);
        res1 = res1 + dig;
        n++;
    }
    return res1;
}

void main(){
    node *tree = NULL;
    char s[100];
    int key;
    while(scanf("%s", s) == 1){
        key = str2int(s);
        if (s[0] == '+') tree = insertNode(tree, key);
        if (s[0] == '-') tree = deleteNode(tree, key);
        if (s[0] == '?') {
            node *result = findNode(tree, key);
            if (result == NULL) {
                printf("%d no\n", key);
            }else{
                printf("%d yes\n", key);
            }
        }
    }
    printTree(tree);
}

