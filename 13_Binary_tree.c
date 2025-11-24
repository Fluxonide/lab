//Algorithm 
// Algo: preorder_traversal(current)
// Step 0: 	Start
// Step 1: 	display(current.data)
// Step 2:	if current.l_child != NULL, then
// Step 2.1:		preorder_traversal(current.l_child)
// Step 3: 	end if
// Step 4:	if current.r_child !=NULL) 
// Step 4.1:		preorder_traversal(current.r_child)
// Step 5:	end if
// Step 6:	Stop
//
// Algo: inorder_traversal(current)
// Step 0: 	Start
// Step 1:	if current.l_child != NULL, then
// Step 1.1:		inorder_traversal(current.l_child)
// Step 2: 	end if
// Step 3: 	display(current.data)
// Step 4:	if current.r_child !=NULL) 
// Step 4.1:		inorder_traversal(current.r_child)
// Step 5:	end if
// Step 6:	Stop
//
// Algo: postorder_traversal(current)
// Step 0: 	Start
// Step 1:	if current.l_child != NULL, then
// Step 1.1:		postorder_traversal(current.l_child)
// Step 2: 	end if
// Step 3:	if current.r_child !=NULL) 
// Step 3.1:		postorder_traversal(current.r_child)
// Step 4:	end if
// Step 5: 	display(current.data)
// Step 6:	Stop
//
// Algo: insertLeft(parent, value)
// Step 0: 	Start
// Step 1: 	if parent.l_child == NULL, then
// Step 1.1:		create new node with value
// Step 1.2:		parent.l_child = new node
// Step 2: 	else
// Step 2.1:		display "Left child already exists"
// Step 3: 	end if
// Step 4: 	Stop
//
// Algo: insertRight(parent, value)
// Step 0: 	Start
// Step 1: 	if parent.r_child == NULL, then
// Step 1.1:		create new node with value
// Step 1.2:		parent.r_child = new node
// Step 2: 	else
// Step 2.1:		display "Right child already exists"
// Step 3: 	end if
// Step 4: 	Stop
//
// Algo: deleteLeaf(parent, value)
// Step 0: 	Start
// Step 1: 	if parent == NULL, Stop
// Step 2: 	if parent.l_child is target AND is leaf
// Step 2.1:		delete parent.l_child
// Step 2.2:		parent.l_child = NULL
// Step 2.3:		Stop
// Step 3: 	if parent.r_child is target AND is leaf
// Step 3.1:		delete parent.r_child
// Step 3.2:		parent.r_child = NULL
// Step 3.3:		Stop
// Step 4: 	deleteLeaf(parent.l_child, value)
// Step 5: 	deleteLeaf(parent.r_child, value)
// Step 6: 	Stop



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

