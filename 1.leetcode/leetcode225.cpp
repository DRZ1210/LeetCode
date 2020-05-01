/*************************************************************************
	> File Name: leedcode225.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 10时57分00秒
 ************************************************************************/
typedef struct Queue {
    int *data;
    int head, tail;
    int size, cnt;
} myQueue;

myQueue *myQueueCreate(int size) {
    myQueue *q = (myQueue *)malloc(sizeof(myQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

void myQueuePush(myQueue *obj, int x) {
    if (!obj) return ;
    if (obj->cnt == obj->size) return ;
    obj->data[obj->tail++] = x;
    if (obj->cnt == obj->size) obj->tail = 0;
    obj->cnt++; 
}

int myQueuePop(myQueue *q) {
    if (!q) return ;
    if (q->cnt == 0) return ;
    q->head ++;
    if (q->head == q->size) q->head = 0;
    q->cnt--;
    return 1;
}

int myQueueFront(myQueue *q) {
    return q->data[q->head];
}

int myQueueEmpty(myQueue *q) {
    return q->cnt == 0;
}

void myQueueFree(myQueue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}


typedef struct {
    myQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = myQueueCreate(size);
    s->q2 = myQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if  (!myQueueEmpty(obj->q1)) {
        myQueuePush(obj->q1, x);
    } else {
        myQueuePush(obj->q2, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    myQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    myQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element = myQueueFront(p);
    myQueuePop(p);
    while (!myQueueEmpty(p)) {
        myQueuePush(q, element);
        element = myQueueFront(p);
        myQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    myQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    myQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    myQueuePop(p);
    while (!myQueueEmpty(p)) {
        element = myQueueFront(p);
        myQueuePop(p);
        myQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return myQueueEmpty(obj->q1) && myQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if (!obj) return;
    myQueueFree(obj->q1);
    myQueueFree(obj->q2);
    free(obj);
}

