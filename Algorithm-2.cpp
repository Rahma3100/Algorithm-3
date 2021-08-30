
#include <stdio.h>
#include <stdlib.h>
 
// A linked list 
struct Node {
    int key;
    struct Node* next;
};
 
struct Queue {
    struct Node *front, *rear;
};
 
struct Node* newNode(int k)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
 struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
void enQueue(struct Queue* q, int k)
{
    struct Node* temp = newNode(k);
 
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    q->rear->next = temp;
    q->rear = temp;
}
 
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
 
    struct Node* temp = q->front;
 
    q->front = q->front->next;
 
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}
 
int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 2);
    enQueue(q, 4);
    enQueue(q, 6);
    deQueue(q);
    enQueue(q, 8);
    enQueue(q, 10);
    deQueue(q);
    printf("Queue Front : %d \n", q->front->key);
    printf("Queue Rear : %d", q->rear->key);
    return 0;
}
