#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(){
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Error in creating the node");
    }else{
        printf("Enter a value:");
        scanf("%d", &head->data);
        head->next = NULL;
    }
    return head;
}

void traverse(struct node* head){
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n"); 
}

struct node* insertAtBeginning(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    
    struct node* ptr = head;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = NULL;
    
    return head;
}

struct node* insert(struct node* head,int data, int loc){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node* ptr = head;
    int i = 1;
    while (i<loc-1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;

    return head;
}

struct node* deleteFirst(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* delete(struct node* head, int element){
    struct node* ptr = head;
    struct node* p = head;
    int flag = 0;
    if (ptr->data == element)
    {
        head = head->next;
        free(ptr);
        flag = 1;
    }else{
        while (ptr!=NULL && ptr->next!=NULL)
        {
            if (ptr->next->data==element)
            {
                p = ptr->next;
                ptr->next = p->next;
                free(p);
                flag = 1;
                return head; 
            }
            ptr = ptr->next;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
    return head;
}

void search(struct node* head, int element){
    struct node* ptr = head;
    int i = 1;
    while (ptr!= NULL)
    {
        if (element == ptr->data)
        {
            printf("Element %d found at location: %d\n", element, i);
            return;
        }
        
        ptr = ptr->next;
        i++;
    }
}

struct node* merge(struct node* head1, struct node* head2){
    struct node* ptr = head1;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next; 
    }
    ptr->next = head2;
    return head1;
}

struct node* reverse(struct node* head){
    struct node* before = NULL;
    struct node* after = NULL;
    struct node* ptr = head;
    
    while (ptr!=NULL)
    {
        after = ptr->next;
        ptr->next = before;
        before = ptr;
        ptr = after;
    }
    head = before;
    return head;
}

struct node* bubbleSort(struct node* head){
    int swapped;
    struct node* ptr = head;
    do
    {
        swapped = 0;
        ptr = head;
        while (ptr->next!=NULL)
        {
            if (ptr->data>ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        
    } while (swapped);
    return head;
}

int main(){
    struct node* head = createNode();
    struct node* second = createNode();
    struct node* third = createNode();
    head->next = second;
    second->next = third;
    
    traverse(head);

    head = insertAtBeginning(head, 01);
    traverse(head);

    head = insertAtEnd(head, 40);
    traverse(head);
    
    head = insert(head, 25, 4);
    traverse(head);

    head = deleteFirst(head);
    head = deleteLast(head);
    head = delete(head, 20);
    traverse(head);

    search(head, 20);

    struct node* head2 = createNode();
    struct node* second2= createNode();
    struct node* third2 = createNode();
    head2->next = second2;
    second2->next = third2;

    head = merge(head, head2);
    traverse(head);

    head = reverse(head);
    traverse(head);

    head = bubbleSort(head);
    traverse(head);

    return 0;
}

