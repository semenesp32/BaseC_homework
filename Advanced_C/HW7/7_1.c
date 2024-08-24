//Отсортировать слова
/*Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом.
  Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы.
  Для сравнения строк можно использовать strcmp. Необходимо использовать данную структуру организации списка
  struct list
  {
   char word[20];
   struct list *next;
  }
   Необходимо реализовать односвязный список и обслуживающие его функции
   add_to_list, swap_elements, print_list, delete_list
   Формат ввода:
   Строка из английских символов 'a'-'z' и пробелов.В конце строки символ '.'
   Длина строки не более 1000 символов.
   Формат вывода:
   Упорядоченные по алфавиту слова. 
   
   Пример №1
Данные на входе:		efg abcd zzz.
Данные на выходе:	abcd efg zzz
Пример №2
Данные на входе:		fffff kkkkkk a.
Данные на выходе:	a fffff kkkkkk
*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct list
{
   char word[20];
   struct list *next;
}list;

//Функция добавления в список
void addToList(struct list **head, const char *word)
{
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    if (new_node == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->word, word, sizeof(new_node->word) - 1);
    new_node->word[sizeof(new_node->word) - 1] = '\0';
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct list *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

//Функция перестановки элементов
void swapElements(struct list *a, struct list *b)
{
    char temp[20];
    strncpy(temp, a->word, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';
    strncpy(a->word, b->word, sizeof(a->word) - 1);
    a->word[sizeof(a->word) - 1] = '\0';
    strncpy(b->word, temp, sizeof(b->word) - 1);
    b->word[sizeof(b->word) - 1] = '\0';
}
//Функция сортировки элементов в списке
void sortList(struct list *head)
{
    if (head == NULL)
    {
        return;
    }

    int swapped;
    struct list *ptr1;
    struct list *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->word, ptr1->next->word) > 0)
            {
                swapElements(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//Функция вывода списка на экран
void printList(struct list *head)
{
    struct list *current = head;
    while (current != NULL)
    {
        printf("%s", current->word);
        if (current->next != NULL)
        {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

//Функция удаления списка
void deleteList(struct list *head)
{
    struct list *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
	struct list *head = NULL;
    char input[MAX_LENGTH];

    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    len = strlen(input);
    if (len > 0 && input[len - 1] == '.')
    {
        input[len - 1] = '\0';
    }

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        addToList(&head, token);
        token = strtok(NULL, " ");
    }

    sortList(head);
    printList(head);
    deleteList(head);

    return 0;
}


