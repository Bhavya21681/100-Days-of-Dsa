/*Problem: Deque (Double-Ended Queue)*/
#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *prev;
struct node *next;
};

struct deque {
struct node *front;
struct node *rear;
int size;
};

void push_front(struct deque *dq, int val) {
struct node *nn = (struct node *)malloc(sizeof(struct node));
nn->data = val;
nn->prev = NULL;
nn->next = dq->front;
if (dq->front == NULL) {
dq->front = dq->rear = nn;
} else {
dq->front->prev = nn;
dq->front = nn;
}
dq->size++;
}

void push_back(struct deque *dq, int val) {
struct node *nn = (struct node *)malloc(sizeof(struct node));
nn->data = val;
nn->next = NULL;
nn->prev = dq->rear;
if (dq->rear == NULL) {
dq->front = dq->rear = nn;
} else {
dq->rear->next = nn;
dq->rear = nn;
}
dq->size++;
}

int pop_front(struct deque *dq) {
if (dq->front == NULL) return -1;
struct node *temp = dq->front;
int val = temp->data;
dq->front = dq->front->next;
if (dq->front == NULL) dq->rear = NULL;
else dq->front->prev = NULL;
free(temp);
dq->size--;
return val;
}

int pop_back(struct deque *dq) {
if (dq->rear == NULL) return -1;
struct node *temp = dq->rear;
int val = temp->data;
dq->rear = dq->rear->prev;
if (dq->rear == NULL) dq->front = NULL;
else dq->rear->next = NULL;
free(temp);
dq->size--;
return val;
}

int get_front(struct deque *dq) {
if (dq->front == NULL) return -1;
return dq->front->data;
}

int get_back(struct deque *dq) {
if (dq->rear == NULL) return -1;
return dq->rear->data;
}

int is_empty(struct deque *dq) {
return dq->size == 0;
}

int get_size(struct deque *dq) {
return dq->size;
}

void clear_deque(struct deque *dq) {
while (!is_empty(dq)) pop_front(dq);
}

void display(struct deque *dq) {
struct node *temp = dq->front;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
struct deque dq = {NULL, NULL, 0};
int choice, value, result;
while (1) {
printf("1.push_front 2.push_back 3.pop_front 4.pop_back 5.front 6.back 7.size 8.empty 9.clear 10.display 11.exit\n");
scanf("%d", &choice);
if (choice == 1) {
scanf("%d", &value);
push_front(&dq, value);
} else if (choice == 2) {
scanf("%d", &value);
push_back(&dq, value);
} else if (choice == 3) {
result = pop_front(&dq);
if (result == -1) printf("empty\n");
else printf("%d\n", result);
} else if (choice == 4) {
result = pop_back(&dq);
if (result == -1) printf("empty\n");
else printf("%d\n", result);
} else if (choice == 5) {
result = get_front(&dq);
if (result == -1) printf("empty\n");
else printf("%d\n", result);
} else if (choice == 6) {
result = get_back(&dq);
if (result == -1) printf("empty\n");
else printf("%d\n", result);
} else if (choice == 7) {
printf("%d\n", get_size(&dq));
} else if (choice == 8) {
printf("%d\n", is_empty(&dq));
} else if (choice == 9) {
clear_deque(&dq);
} else if (choice == 10) {
display(&dq);
} else if (choice == 11) {
break;
}
}
return 0;
}
