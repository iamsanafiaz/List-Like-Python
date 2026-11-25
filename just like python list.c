#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_CAPACITY 8
#define DC DEFAULT_CAPACITY
typedef struct List{
    void** items;
    char*types;
    int capacity;
    int length;
}List;
List *List_create(){
    List*list=malloc(sizeof(List));
    list->types = malloc(DC * sizeof(char));
    list->items=malloc(DC*sizeof(void*));
    list->capacity=DC;
    list->length=0;
    return list;
}
void* List_get(List*list, int i){
    if (i<0 || i>=list->length)return NULL;
    return *(list->items +i);
}
void List_expand(List*list){
    int new_capacity=list->capacity+DC;
    list->capacity=new_capacity;
    list->items=realloc(list->items, new_capacity*sizeof(void*));
    list->types = realloc(list->types, new_capacity * sizeof(char));
}
void List_append(List*list, void*item, char type){
    if(list->capacity==list->length)List_expand(list);
    *(list->items+list->length)=item;
    *(list->types+list->length)=type;
    list->length++;
}
void* List_pop(List*list){
    if (list->length==0)return NULL;
    list->length--;
    void*popped_item=*(list->items+list->length);
    *(list->items+list->length)=NULL;
    return popped_item;
}
void List_print(List* list) {
    printf("\n[ ");

    for (int i = 0; i < list->length; i++) {

        if (list->types[i] == 'i') {
            printf("%d", *(int*)list->items[i]);
        }

        else if (list->types[i] == 'f') {
            printf("%.2f", *(float*)list->items[i]);
        }

        else if (list->types[i] == 'd') {
            printf("%f", *(double*)list->items[i]);
        }

        else if (list->types[i] == 'c') {
            printf("%c", *(char*)list->items[i]);
        }

        if (i < list->length - 1) {
            printf(", ");
        }
    }

    printf(" ]\n");
}
void List_free(List*list){
    free(list->types);
    free(list->items);
    free(list);
}


int main(){
    List*list=List_create();
    printf("This is the capacity of my list: %d\n", list->capacity);
    printf("This is the length of my list: %d\n", list->length);

    printf("Now i will Add Items Using Append\n\n");
    int num1= 23;
    List_append(list, &num1, 'i');
    printf("The Item Appended: %d\n", num1);
    int num2=564;
    List_append(list, &num2, 'i');
    printf("The Item Appended: %d\n", num2);
    float num3=54.2343242;
    List_append(list, &num3, 'f');
    printf("The Float item appended:%.2f\n",num3);
    float num4=3443.8124345;
    List_append(list, &num4, 'f');
    printf("The Float item appended:%.3f\n",num4);
    char chaari1='S';
    List_append(list, &chaari1, 'c');
    printf("This is my charachter: %c\n", chaari1);
    char chaari2='a';
    List_append(list, &chaari2, 'c');
    printf("This is my charachter: %c\n", chaari2);
    char chaari3='n';
    List_append(list, &chaari3, 'c');
    printf("This is my charachter: %c\n", chaari3);
    char chaari4='a';
    List_append(list, &chaari4, 'c');
    printf("This is my charachter: %c\n", chaari4);
    printf("This is the capacity of my list: %d\n", list->capacity);
    printf("This is the length of my list: %d\n", list->length);

    int num5=3445;
    List_append(list, &num5, 'i');
    printf("This is my Item: %d\n\n", num5);
    int num6=986;
    List_append(list, &num6, 'i');
    printf("This is my num 6: %d\n", num6);
    double num8=2321.23424;
    List_append(list, &num8, 'd');
    printf("This is Double: %f\n", num8);
    char chaari5='A';
    List_append(list, &chaari5, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari5);
    char chaari6='b';
    List_append(list, &chaari6, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari6);

    char chaari7='b';
    List_append(list, &chaari7, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari7);

    printf("This is the capacity of my list: %d\n\n", list->capacity);
    printf("This is the length of my list: %d\n", list->length);


    char chaari8='a';
    List_append(list, &chaari8, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari8);
    char chaari9='s';
    List_append(list, &chaari9, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari9);
    char chaari10='s';
    List_append(list, &chaari10, 'c');
    printf("This is My 5th Chari: %c\n", chaari10);

    char chaari11='i';
    List_append(list, &chaari11, 'c');
    printf("This is My 5th Chari: %c\n\n", chaari11);

    printf("This is the capacity of my list: %d\n", list->capacity);
    printf("This is the length of my list: %d\n", list->length);

    printf("Now this is my List:");

    List_print(list);
    List_free(list);
    return 0;
}
