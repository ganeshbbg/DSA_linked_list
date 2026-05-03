/************************INCLUDE***************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/************************END_OF_INCLUDE*******************************/

/************************UNSIGNED VARIABLE******************************/
uint8_t tot_list;
/************************END_OF_UNSIGNED*******************************/
/************************STRUCT VARIABLE*******************************/

typedef struct linkedlist{
    struct linkedlist *next;
    uint8_t data;
} linkedlist;

/************************END_OF_STRUCT*********************************/

/************************PROTOTYPE***************************************/
void fwd_tranversal(linkedlist *list);
void create_list(linkedlist **list, uint8_t a_data);
void reverse_transversal(linkedlist *list);
void insert_node(linkedlist *list,int a_data,int pos);
void delete_node(linkedlist *list, int pos);
/************************END_OF_PROTOTYE*********************************/


void delete_node(linkedlist *list, int pos)
{
    linkedlist *curr = NULL ;
    
    linkedlist *temp = list, *remove = NULL;
    int cnt = 0;
    printf("\ndelete node @ %d", pos);
    //temp = temp->next;
    while(temp){
        if(pos == 0){
            /*not required */
        }
        else{
            if((pos-1) == cnt){
                curr = temp;
                remove = temp->next;
                curr->next = remove->next;
            }
            
        }
        temp = temp->next;
        cnt++;
    }
}
void insert_node(linkedlist *list,int a_data,int pos)
{
    linkedlist *cur = NULL, *temp = list, *new_1 = NULL;
    int cnt = 0;
    printf("\n insert node @ = %d", pos);
    if(pos == 0)
    {
        new_1 = (linkedlist *)(malloc(sizeof(linkedlist)));
            new_1->data = a_data;
            cur = temp->next;
            temp->next = new_1;
            new_1->next = cur;
    }
    else
    {
        temp = temp->next;
        while(temp)
        {
            if((pos - 1)== cnt)
            {
                new_1 = (linkedlist *)(malloc(sizeof(linkedlist)));
                new_1->data = a_data;
                cur = temp->next;
                temp->next = new_1;
                new_1->next = cur;
            }
            cnt++;
            temp = temp->next;
        }
    }
}

void fwd_tranversal(linkedlist*list){
    printf("\n printing forward = ");
    linkedlist *temp = NULL;
    temp = list->next;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverse_transversal(linkedlist *list){

    linkedlist *curr = list,*next_node = NULL,*prev = NULL;
    printf("\n print reverse = ");
    while(curr){
        next_node = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next_node;
    }
    while(prev){
        printf("%d ", prev->data);
        prev = prev->next;

    }
}

void create_list(linkedlist **list,uint8_t a_data){
    linkedlist *l_list;
    *list = (linkedlist *)(malloc(sizeof(linkedlist)));
    if(list == NULL){
        printf("\nmemory not ceated");

    }
    else{
        (*list)->data = a_data;
        (*list)->next = NULL;
    }
}



int main(void){
    uint8_t list_idx = 0;
    linkedlist *head = NULL, *temp = NULL, *node = NULL;
    printf("\n totat list = ");
    scanf("%d", &tot_list);
    create_list(&head, 0);
    
    temp = head;
    for(list_idx = 1; list_idx <= tot_list; list_idx++){
        create_list(&node, list_idx);
        temp->next = node;
        temp = node;
    }

    insert_node(head, 12, 0);
    temp = head;
    fwd_tranversal(temp);
    delete_node(head, 6);
    temp = head;
    fwd_tranversal(temp);
    temp = head;
    reverse_transversal(temp);
    
}

