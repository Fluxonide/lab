#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l_child, *r_child;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->l_child = NULL;
    newNode->r_child = NULL;
    return newNode;
}

void insertLeft(struct node* parent, int value) {
    if (parent->l_child == NULL)
        parent->l_child = createNode(value);
    else
        printf("Left child already exists!\n");
}

void insertRight(struct node* parent, int value) {
    if (parent->r_child == NULL)
        parent->r_child = createNode(value);
    else
        printf("Right child already exists!\n");
}


void deleteLeaf(struct node* parent, int value) {
    if (parent == NULL) return;

    if (parent->l_child && parent->l_child->data == value) {
        if (parent->l_child->l_child == NULL && parent->l_child->r_child == NULL) {
            free(parent->l_child);
            parent->l_child = NULL;
        }
        return;
    }

    if (parent->r_child && parent->r_child->data == value) {
        if (parent->r_child->l_child == NULL && parent->r_child->r_child == NULL) {
            free(parent->r_child);
            parent->r_child = NULL;
        }
        return;
    }

    deleteLeaf(parent->l_child, value);
    deleteLeaf(parent->r_child, value);
}


void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->l_child);
        preOrder(root->r_child);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->l_child);
        printf("%d ", root->data);
        inOrder(root->r_child);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->l_child);
        postOrder(root->r_child);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = createNode(10);

    insertLeft(root, 20);
    insertRight(root, 30);

    insertLeft(root->l_child, 40);
    insertRight(root->l_child, 50);

    printf("Pre-order: ");
    preOrder(root);
    printf("\n");

    printf("In-order: ");
    inOrder(root);
    printf("\n");

    printf("Post-order: ");
    postOrder(root);
    printf("\n");

    deleteLeaf(root, 50);

    printf("\nAfter deleting 50:\n");
    printf("In-order: ");
    inOrder(root);
    printf("\n");

    return 0;
}

