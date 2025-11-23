#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &head->data);
    head->next = head;
    return head;
}

void traverse(struct node* head){
    struct node* ptr = head;
    while (ptr->next!=head)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
    printf("\n");
}

struct node* insertAtBeginning(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    struct node*ptr = head;
    while (ptr->next!=head)
    {
        ptr = ptr->next;
    }
    temp->next = head;
    ptr->next = temp;
    head = temp;
    return head;
}

struct node* insert(struct node* head, int data, int loc){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node* ptr = head;
    int i = 1;
    while (i < loc-1)
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
    struct node* p = head;
    while (ptr->next!=head)
    {
        ptr = ptr->next;
    }
    head = head->next;
    ptr->next = head;
    free(p);
    return head;
}

struct node* delete(struct node* head, int element){
    struct node* ptr=head;
    struct node* p;
    if (ptr->data == element)
    {
        while (ptr->next!=head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    
    while (ptr->next!=head)
    {
        if (ptr->next->data  == element)
        {
            p = ptr->next;
            ptr->next = p->next;
            free(p);
            return head;
        }
        else{
            ptr = ptr->next;
        }  
    }
    printf("Element not found for deletion\n");
    return head;
}

void search(struct node* head, int data){
    struct node* ptr =  head;
    int i = 1;

    if (ptr->data == data)
    {
        printf("Element found at %d\n", i);
        return;
    }
    ptr = ptr->next;
    i++;
    while (ptr!=head)
    {
        if (ptr->data == data){
            printf("Element found at %d", i);
            return;            
        }else{
            ptr = ptr->next;
            i++;
        }   
    }
    printf("Element not found in the list\n");
}

struct node* merge(struct node* head, struct node* head2){
    struct node* ptr = head;
    while (ptr->next!=head)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
    ptr= head2;
    while (ptr->next!=head2)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    return head;
}

int main(){
    struct node* head = createNode();
    struct node* second = createNode();
    struct node* third = createNode();

    head->next = second;
    second->next = third;
    third->next = head;

    traverse(head);

    head = insertAtBeginning(head, 0);
    traverse(head);

    head = insert(head, 25, 4);
    traverse(head);

    head = deleteFirst(head);
    traverse(head);

    head = delete(head, 10);
    traverse(head);

    search(head, 25);

    struct node* head2 = createNode();
    struct node* second2 = createNode();
    struct node* third2 = createNode();

    head2->next = second2;
    second2->next = third2;
    third2->next = head2;

    head = merge(head, head2);
    traverse(head);

    return 0;
}

