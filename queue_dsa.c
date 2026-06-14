/************************INCLUDE***************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/************************END_OF_INCLUDE*******************************/

/************************UNSIGNED VARIABLE******************************/

/************************END_OF_UNSIGNED*******************************/

/************************STRUCT VARIABLE*******************************/
/*Implement the array queue */
#define QUEUE_SIZE  5U

typedef struct{
    uint8_t q_Arr[QUEUE_SIZE];
    int head;
    uint8_t tail;
} Queue;
/************************END_OF_STRUCT*********************************/

/************************PROTOTYPE***************************************/
bool is_queueEmpty(Queue *l_queue);
bool is_queueFull(Queue *l_queue);
void en_queue(Queue *q, uint8_t l_data);
void dequeue(Queue *q);
void print_queue(Queue *q);
void peek_queue(Queue *q);
/************************END_OF_PROTOTYE*********************************/
bool is_queueEmpty(Queue *l_queue){
    bool l_result;
    ;
    if(l_queue->head == (l_queue->tail - 1)){
        l_result = true;
    }
    else{
        l_result = false;
    }
    return l_result;
}

bool is_queueFull(Queue *l_queue){
    bool l_result;
    //printf("\n head = %d tail = %d", l_queue->head, l_queue->tail);
    if(l_queue->head == l_queue->tail){
        l_result = true;
    }
    else{
        l_result = false;
    }
    return l_result;

}

void en_queue (Queue *q,uint8_t l_data){

    if(is_queueFull(q)){
        printf("\n Queue Full \n");
    }
    else{
        printf("\n Enqueue");
        //printf("\n l_data = %d", l_data);
        q->q_Arr[q->tail] = l_data;
       // printf("\nq->q_Arr =  %d", q->q_Arr[q->tail]);
        q->tail++;
    }
    
}

void dequeue(Queue *q){
    
    if(is_queueEmpty(q)){
        
        printf("\n Queue Empty \n");
    }
    else{

        printf("\n Dequeue \n");
        //q->q_Arr[q->head];
        q->head++;
    }
}

void print_queue(Queue *q){
    uint8_t l_idx;
    if(is_queueEmpty(q)){
        printf("\n Queue Empty" );
    }
    else{
        for (l_idx = q->head + 1; l_idx < q->tail; l_idx++){
        printf("%d ", q->q_Arr[l_idx]);
        }
    }
    
}

void peek_queue(Queue *q){
    if(is_queueEmpty(q)){
        printf("\n Queue Empty" );
    }
    else{
        printf("\npeek = %d",q->q_Arr[q->head + 1]);
    }
    
}

int main(void){
    Queue q;
    uint8_t l_idx = 0;

    q.head = -1;

    for (l_idx = 1; l_idx < QUEUE_SIZE; l_idx++){
        en_queue(&q, l_idx);
    }
    printf("\nprint Queue \n");
    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
   // dequeue(&q);

    printf("\n print Queue \n");
    print_queue(&q);

    printf("\npeek Queue");
    peek_queue(&q);
}