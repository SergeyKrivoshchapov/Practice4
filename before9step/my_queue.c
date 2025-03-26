#include "my_queue.h"

int enqueue(WIFI_queue* queue, WIFI data) 
{
    WIFI_item* new_item = (WIFI_item*)malloc(sizeof(WIFI_item));
    if (!new_item)
    {
	printf("Can't create new item");
	return 1;
    }
    new_item->data = data;
    if (queue->head == NULL)
    {
        new_item->next = queue->head;
        queue->head = new_item;
        new_item->prev = NULL;
        return 0;
    }
    new_item->next = queue->head;
    queue->head->prev = new_item;
    queue->head = new_item;
    return 0;
}

WIFI dequeue(WIFI_queue* queue) 
{
    WIFI data = {0};
    if (queue->head == NULL) 
    {
        printf("Empty.\n");
        return data;
    }
    
    struct WIFI_item* temp = queue->head;

    while (temp->next) temp = temp->next;
    
    data = temp->data;
    
    if (temp->prev) temp->prev->next = NULL;
    else queue->head = NULL;
    
    free(temp);
    temp = NULL;
    
    return data;
}

void extract_data(WIFI_queue* queue)
{
    WIFI data = dequeue(queue);
    WIFI empty = {0};
    if (memcmp(&data, &empty, sizeof(WIFI)) != 0)
    {
        printf("Extracted from queue: \n");
        print_struct(&data);
    }
}

void print_queue(const WIFI_queue* queue) 
{
    WIFI_item* current = queue->head;
    while (current != NULL) 
    {
        print_struct(&current->data);
        current = current->next;
    }
}

void delete_queue(WIFI_queue* queue) 
{
    while (queue->head != NULL) dequeue(queue);
}


