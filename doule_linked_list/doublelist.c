#include <stdio.h> 
#include <malloc.h>
#include "doublelist.h"

/* Declare a user structure containing a general double-linked list */
typedef struct circle_queue {
    int id;
    struct list_head my_list;
}NODE;

/* Initialize user structure */
NODE* queue_init() 
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    init_list_head(&head->my_list);
    
    return head;
}

/* Create a new node  */
NODE *new_node(int id)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if(p == NULL){
        printf("p get Error!\n");
    }
    
    p->id = id;
    init_list_head(&p->my_list);
    
    return p;
}

/* Insert node from tail*/
void queue_add(NODE *p, NODE *new)
{
    list_add(&p->my_list, &new->my_list);
}

/* Modify node at specified location */
void queue_modify(NODE *p, int num, int data)
{
    int i = 0;
    NODE *mdfy;
    struct list_head *plist;
    
    plist = &p->my_list;
    for (i = 0; i < num; i++) {
       plist = plist->next;
    }
    mdfy = list_entry(plist, typeof(*mdfy), my_list);
    mdfy->id = data;
}

/* Delete node at specified location */
void queue_del(NODE *p, int num)
{
    int i = 0;
    NODE *del;
    struct list_head *plist;
    
    plist = &p->my_list;
    for (i = 0; i < num; i++) {
       plist = plist->next;
    }
    del = list_entry(plist, typeof(*del), my_list);

    list_del(plist);
    free(del);
}

/* Show all of node */
void queue_show(NODE *head)
{
    NODE *pos;
    
    list_for_each_entry(pos, &head->my_list, my_list) {
        printf("%d ", pos->id);
    }
    printf("\n");
}

int main()
{
    static int i = 0;
    NODE *node_test;
    struct list_head *ptr;

    node_test = queue_init();
    
    for(i = 0; i < 7; i++) {
        NODE *new;
        new = new_node(i);
        queue_add(node_test, new);
    }
    printf("初始数据： \n");
    queue_show(node_test);
    printf("删除第2个成员： \n");
    queue_del(node_test, 2);
    queue_show(node_test);
    printf("修改第三个数据为10： \n");
    queue_modify(node_test, 3, 10);
    queue_show(node_test);
    
    return 0;
}
