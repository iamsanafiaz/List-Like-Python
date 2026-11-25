#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_CAPACITY 8
#define DC DEFAULT_CAPACITY
typedef struct List{
  void**items;
  int capacity;
  int length;
}List;
List*List_create(){
  List*list=malloc(sizeof(List));
  list->items=malloc(DC*sizeof(void*));
  list->capacity=DC;
  list->length=0;
  return list;
}
void* List_get(List*list, int i){
  if (i<0 || i>=list->length) return NULL;
  return *(list->items + i);

}
void List_expand(List*list){
  int new_capacity= list->capacity+DC;
  list->capacity=new_capacity;
  list->items=realloc(list->items, new_capacity*sizeof(void*));
}
void List_append(List*list, void*item){
  if (list->capacity==list->length) List_expand(list);
  *(list->items+list->length)=item;
  list->length++;

}
void* List_pop(List* list) {
if(list->length == 0) return NULL;
  list->length--; // decrement the length
  void* popped_item = *(list->items + list->length);
  *(list->items + list->length) = NULL;
  return popped_item;
}

void List_free(List* list) {
  free(list->items);
  free(list);
}

int main() {
  List* list = List_create();

  printf("My C List Just Like Python\n\n");
  printf("Length of My List is: %d\n", list->length);
  printf("Capacity of my List is: %d\n\n", list->capacity);

  int num1 = 100;
  List_append(list, &num1);
  printf("appended int %d\n", num1);


  int num2 = 2000;
  List_append(list, &num2);
  printf("appended int %d\n", num2);


  printf("Now we again check capacity\n\n");
  printf("Length of My List is: %d\n", list->length);
  printf("Capacity of my List is: %d\n\n", list->capacity);

  float floatNum = 123.25;
  List_append(list, &floatNum);
  printf("appended float %.2f\n", floatNum);


  char mychar = 'S';
  List_append(list, &mychar);
  printf("My char: %c\n", mychar);

  char mychari = 'a';
  List_append(list, &mychari);
  printf("My char: %c\n", mychari);

  char mycharii = 'n';
  List_append(list, &mychari);
  printf("My char: %c\n", mychari);

  char mychariii = 'a';
  List_append(list, &mychariii);
  printf("My char:%c\n", mychariii);

  printf("length: %d\n", list->length);
  printf("capacity: %d\n", list->capacity);


  int num3 = 232;
  List_append(list, &num3);
  printf("appended int %d\n", num3);


  int num4 = 34;
  List_append(list, &num4);
  printf("appended int %d\n", num4);


  int num5 = 4000;
  List_append(list, &num5);
  printf("appended int %d\n", num5);

  printf("length: %d\n", list->length);
  printf("capacity: %d\n", list->capacity);



  char word1 = 'S';
  List_append(list, &word1);
  printf("My char: %c\n", word1);

  char word2 = 'a';
  List_append(list, &word2);
  printf("My char: %c\n", word2);

  char word3 = 'n';
  List_append(list, &word3);
  printf("My char: %c\n", word3);

  char word4 = 'a';
  List_append(list, &word4);
  printf("My char:%c\n", word4);


  char word5 = 'S';
  List_append(list, &word5);
  printf("My char: %c\n", word5);

  char word6 = 'a';
  List_append(list, &word6);
  printf("My char: %c\n", word6);

  char word7 = 'n';
  List_append(list, &word7);
  printf("My char: %c\n", word7);

  char word8 = 'a';
  List_append(list, &word8);
  printf("My char:%c\n", word8);

  printf("length: %d\n", list->length);
  printf("capacity: %d\n", list->capacity);

  
  List_free(list);
  return 0;

}

