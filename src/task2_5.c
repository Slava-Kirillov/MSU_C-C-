#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Element{
    char word[100];
    struct Element *next;
} Element;

typedef struct List{
    Element *firstElement;
} List;

List *createList(){
    List *list = malloc(sizeof(struct List));
    return list;
}

Element *getLastElem(List *head){
    if (head->firstElement != NULL) {
        Element *tmp = head->firstElement;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        return tmp;
    }
    return NULL;
}

void push(List *pushList, char *data){
    Element *element = malloc(sizeof(struct Element));
    strcpy(element->word,data);
    element->next = NULL;
    Element *lastElement = getLastElem(pushList);
    if (lastElement != NULL) {
        lastElement->next = element;
    }else{
        pushList->firstElement = element;
    }
}

void printList(List *list){
    Element *element = list->firstElement;
    if (element != NULL){
        do{
            printf("%s", element->word);
            printf("%c", ' ');
            element = element->next;
        }while (element != NULL);
    }
    printf("%c", '\n');
}

void deleteElementLikeEndElement(List *list){
    Element *lastElement = getLastElem(list);
    Element *element = list->firstElement;
    Element *previousElement;
    int flag = 0;
    if (element != NULL){
        while (element->next != NULL && flag == 0) {
            if (strcmp(element->word, lastElement->word) == 0) {
                list->firstElement = element->next;
                free(element);
                element = list->firstElement;
            } else {
                flag = 1;
                element = element->next;
                previousElement = list->firstElement;
            }
        }
        while (element->next != NULL){
            if (strcmp(element->word,lastElement->word)==0){
                element = element->next;
                free(previousElement->next);
                previousElement->next = element;
            }else{
                previousElement = element;
                element = element->next;
            }
        }
    }
}

void main(){
    List *list = createList();
    char s[100];
    while(scanf("%s", s) == 1){
        push(list, s);
    }
    deleteElementLikeEndElement(list);
    printList(list);
}