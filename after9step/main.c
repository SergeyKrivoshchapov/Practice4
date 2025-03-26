#include "WIFI.h"
#include "my_queue.h"
int main()
{
	// Инициализация в динамической памяти трёх экземпляров структуры
	printf("Creating first struct.\n");
	WIFI* router1 = dynamic_struct_create("TPLINK", 2, Is5G);

	if (router1 == NULL) return 1; // Проверка корректности инициализации экземпляра

	printf("First: \n");
	print_struct(router1); // Вывод сведений о структуре

	printf("Creating second struct.\n");
	WIFI* router2 = dynamic_struct_create("TPLINK", 6, Is5G);

	if (router2 == NULL) return 1;
	
	printf("Second: \n");
	print_struct(router2);

	printf("Creating third struct.\n");
	WIFI* router3 = dynamic_struct_create("ROSTELECOM", 2, Not5G);
	
	if (router3 == NULL) return 1;

	printf("Third: \n");
	print_struct(router3);
	
	printf("Creating fourth struct.\n");
	WIFI* router4 = dynamic_struct_create("ACER", 10, Is5G);
	
	if (router4 == NULL) return 1;

	printf("Fourth: \n");
	print_struct(router4);

	printf("Creating fifth struct.\n");
	WIFI* router5 = dynamic_struct_create("Router", 6, Not5G);
	
	if (router5 == NULL) return 1;

	printf("Fifth: \n");
	print_struct(router5);

	// Инициализация очереди
	printf("Initializing queue with five structs.\n");
	WIFI_queue* router_queue = (WIFI_queue*)malloc(sizeof(WIFI_queue));
	if (router_queue == NULL) 
	{
		printf("Can't create queue.\n");
		return 1;
	}
	router_queue->head = NULL;
	
	// Добавляем элементы в начало очереди
	if (enqueue(router_queue, router1) == 1) return 1;
	if (enqueue(router_queue, router2) == 1) return 1;
	if (enqueue(router_queue, router3) == 1) return 1;
	if (enqueue(router_queue, router4) == 1) return 1;
	if (enqueue(router_queue, router5) == 1) return 1;

	print_queue(router_queue); // Вывод сведений о каждом элементе очереди

	printf("Extracting last element:\n");
	extract_data(router_queue); // Извлечение последнего элемента очереди

	printf("Extracting last element:\n");
	extract_data(router_queue); // Извлечение последнего элемента очереди

	printf("Extracting last element:\n");
	extract_data(router_queue); // Извлечение последнего элемента очереди

	printf("Queue after extracting three last elements.\n");
	print_queue(router_queue);

	printf("Removing all elements from queue\n");
	delete_queue(router_queue); // Удаление всех элементов полностью.
	
	printf("Queue is clear\n");

	//Освобождение динамической памяти, выделенной под экземпляры структуры
	dynamic_struct_free(router1);
	dynamic_struct_free(router2);
	dynamic_struct_free(router3);
	dynamic_struct_free(router4);
	dynamic_struct_free(router5);

	return 0;
}
