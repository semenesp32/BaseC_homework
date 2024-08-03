//Всего памяти
/*Описана структура данных для хранения информации об использованной памяти: 
typedef struct list { void *address; size_t size; char comment[64]; struct list *next; } list;
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. 
Адрес хранится в поле address, поле size - соответствующий размер данного блока. 
Если список пустой, то функция должна возвращать NULL. Прототип функции: size_t totalMemoryUsage(list *head) 
Загрузите только текст данной функции
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void *findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    list *current = head;
    void *maxAddress = current->address;
    size_t maxSize = current->size;

    while (current != NULL)
    {
        if (current->size > maxSize)
        {
            maxSize = current->size;
            maxAddress = current->address;
        }
        current = current->next;
    }

    return maxAddress;
}

size_t totalMemoryUsage(list *head)
{
    size_t totalSize = 0;
    list *current = head;

    while (current != NULL)
    {
        totalSize += current->size;
        current = current->next;
    }

    return totalSize;
}

list *createNode(void *address, size_t size, const char *comment)
{
    list *newNode = (list *)malloc(sizeof(list));
    if (!newNode)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->address = address;
    newNode->size = size;
    snprintf(newNode->comment, sizeof(newNode->comment), "%s", comment);
    newNode->next = NULL;
    return newNode;
}

void insertNode(list **head, void *address, size_t size, const char *comment)
{
    list *newNode = createNode(address, size, comment);
    newNode->next = *head;
    *head = newNode;
}

void freeList(list *head)
{
    list *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void printList(list *head)
{
    while (head != NULL)
    {
        printf("Address: %p, Size: %zu, Comment: %s\n", head->address, head->size, head->comment);
        head = head->next;
    }
}

int main()
{
    list *memlist = NULL;

    int a, b, c;
    insertNode(&memlist, &a, sizeof(int), "main.c");
    insertNode(&memlist, &b, sizeof(int) * 3, "main.c");
    insertNode(&memlist, &c, sizeof(int) * 10, "main.c");

    printList(memlist);

    void *maxBlockAddress = findMaxBlock(memlist);
    if (maxBlockAddress != NULL)
    {
        printf("Max Block Address: %p\n", maxBlockAddress);
    }
    else
    {
        printf("The list is empty.\n");
    }

    size_t totalMemory = totalMemoryUsage(memlist);
    printf("Total Memory Usage: %zu bytes\n", totalMemory);

    freeList(memlist);

    return 0;
}

