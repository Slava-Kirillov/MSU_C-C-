//
// Created by slava on 25.09.17.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int key;
    struct _node *left, *right;
} node;

node* create_node(int val) {
    node* nnode = (node*) malloc(sizeof(node));
    nnode->key = val;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

node* insert_node(node *root, int val) {
    if (root == NULL) root = create_node(val);
    if (val < root->key)
        if (root->left == NULL)
            root->left = create_node(val);
        else
            insert_node(root->left, val);
    if (val > root->key)
        if (root->right == NULL)
            root->right = create_node(val);
        else
            insert_node(root->right, val);
    return root;
}

node* find_node(node *root, int val) {
    if (root == NULL)
        return NULL;
    if (val == root->key)
        return root;
    if (val < root->key)
        return find_node(root->left, val);
    if (val > root->key)
        return find_node(root->right, val);
}

int left_most(node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

node* delete_node(node *root, int val) {
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
        root->key = left_most(root->left);
        root->left = delete_node(root->left, root->key);
        return root;
    }
    if (val < root->key) {
        root->left = delete_node(root->left, val);
        return root;
    }
    if (val > root->key) {
        root->right = delete_node(root->right, val);
        return root;
    }
    return root;
}

void print_tree(node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->key);
        print_tree(root->right);
    }
}

int ten_degree(int d) {
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
        dig = (*--string - '0') * ten_degree(n);
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
        if (s[0] == '+') tree = insert_node(tree, key);
        if (s[0] == '-') tree = delete_node(tree, key);
        if (s[0] == '?') {
            node *result = find_node(tree, key);
            if (result == NULL) {
                printf("%d no\n", key);
            }else{
                printf("%d yes\n", key);
            }
        }
    }
    print_tree(tree);
}

