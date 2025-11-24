#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Node creation unsuccessfull");
        return newNode;
    }
    printf("Enter a value: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//
// Algo: insertAtBeginning(head, data)
// Step 0: 	Start
// Step 1: 	create new node temp
// Step 2: 	temp.data = data, temp.prev = NULL, temp.next = head
// Step 3: 	head.prev = temp
// Step 4: 	head = temp
// Step 5: 	return head
// Step 6: 	Stop
//
// Algo: insert(head, data, loc)
// Step 0: 	Start
// Step 1: 	create new node temp, temp.data = data
// Step 2: 	set ptr = head, p = head, i = 1
// Step 3: 	if loc == 1, temp.next = head, head.prev = temp, head = temp, return head
// Step 4: 	while i != loc, p = ptr, ptr = ptr.next, i++
// Step 5: 	p.next = temp, temp.prev = p
// Step 6: 	temp.next = ptr, ptr.prev = temp
// Step 7: 	return head
// Step 8: 	Stop
//
// Algo: deleteFirst(head)
// Step 0: 	Start
// Step 1: 	set ptr = head
// Step 2: 	head = head.next
// Step 3: 	head.prev = NULL
// Step 4: 	free(ptr)
// Step 5: 	return head
// Step 6: 	Stop
//
// Algo: delete(head, element)
// Step 0: 	Start
// Step 1: 	set ptr = head, p = head, i = 1
// Step 2: 	if head.data == element, head = head.next, head.prev = NULL, free(ptr), return head
// Step 3: 	while ptr != NULL AND ptr.data != element, p = ptr, ptr = ptr.next, i++
// Step 4: 	ptr.next.prev = p
// Step 5: 	p.next = ptr.next
// Step 6: 	free(ptr)
// Step 7: 	return head
// Step 8: 	Stop

void traverse(struct node* head){
    struct node* ptr = head;
    while (ptr->next!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
    printf("\n");
}

void reverse_traverse(struct node* last){
    struct node* ptr = last;
    while (ptr->prev!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d\n", ptr->data);
    printf("\n");
}

struct node* insertAtBeginning(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;  
}

struct node* insert(struct node* head, int data, int loc){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    
    int i = 1;
    struct node* ptr = head;
    struct node* p = head;
    if(loc == 1){
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    while (i!=loc)
    {
        p = ptr;
        ptr = ptr->next;
        i++;
    }
    
    p->next = temp;
    temp->prev = p;
    temp->next = ptr;
    ptr->prev = temp;
    
    return head;
}

struct node* deleteFirst(struct node* head){
    struct node* ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node* delete(struct node* head, int element){
    struct node* ptr = head;
    struct node* p = head;
    int i = 1;
    if (head->data == element)
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
    }
    while (ptr != NULL && ptr->data != element)
    {
        p = ptr;
        ptr = ptr->next;
        i++;
    }
    ptr->next->prev = p;
    p->next = ptr->next;
    free(ptr);
    return head;    
}

void search(struct node* head, int ele){
    struct node* ptr = head;
    int i = 1;
    while (ptr!=NULL)
    {
        if (ptr->data==ele)
        {
            printf("Element found at %d", i);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Element not found\n");
    return;
}

struct node* merge(struct node* head1, struct node* head2 ){
    struct node* ptr= head1;
    if (head1 == NULL && head2 ==NULL)
    {
        printf("List is empty");
    }else{
        while (ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
    }
    ptr->next = head2;
    head2->prev = ptr;
    return head1;
}

int main(){
    struct node* head = createNode();
    struct node* second = createNode();
    struct node* third = createNode();
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    traverse(head);
    reverse_traverse(third);

    head = insert(head, 25, 3);
    traverse(head);

    head = deleteFirst(head);
    traverse(head);

    head = delete(head, 25);
    traverse(head);

    search(head, 30);

    struct node* head2 = createNode();
    struct node* second2 = createNode();
    struct node* third2 = createNode();
    head2->next = second2;
    second2->prev = head2;
    second2->next = third2;
    third2->prev = second2;

    head = merge(head, head2);
    traverse(head);

    return 0;
}

