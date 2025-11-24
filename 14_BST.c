#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//
// Algo: insert(root, data)
// Step 0: 	Start
// Step 1: 	if root == NULL, return createNode(data)
// Step 2: 	if data < root.data, root.left = insert(root.left, data)
// Step 3: 	else if data > root.data, root.right = insert(root.right, data)
// Step 4: 	return root
// Step 5: 	Stop
//
// Algo: delete(root, key)
// Step 0: 	Start
// Step 1: 	if root == NULL, return root
// Step 2: 	if key < root.data, root.left = delete(root.left, key)
// Step 3: 	else if key > root.data, root.right = delete(root.right, key)
// Step 4: 	else
// Step 4.1:		if root.left == NULL AND root.right == NULL, free(root), return NULL
// Step 4.2:		else if root.left == NULL, temp = root.right, free(root), return temp
// Step 4.3:		else if root.right == NULL, temp = root.left, free(root), return temp
// Step 4.4:		else, temp = findMin(root.right), root.data = temp.data, root.right = delete(root.right, temp.data)
// Step 5: 	return root
// Step 6: 	Stop

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* delete(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    root = delete(root, 70);

    inorder(root);
    printf("\n");

    return 0;
}

