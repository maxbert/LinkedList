#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {int i; struct node *next;};

void print_list(struct node *a){
  while(a->next){
    printf("%d--->",a->i);
    a = a->next;
  }
  printf("%d--->",a->i);
}

struct node *insert_front(struct node *a, int j){
  struct node *x;
  x = ((struct node *)(malloc(sizeof(struct node))));
  x->i = j;
  x->next = a;
  return x;
}
void free_list(struct node *a){
  free(a);
  if (a->next){
    free_list(a->next);
  }
}

int main(){

  struct node *a;
  a = (struct node*)malloc(sizeof(struct node));
  a->i = 3;
  struct node *b = insert_front(a,2);
  struct node *c = insert_front(b,1);
  printf("c-->b-->a\n");
  print_list(c);

  printf("\nc-->b\n");
  print_list(b);

  printf("\na\n");
  print_list(a);
  free_list(b);
  printf("\nfreed b\n");
  print_list(c);
  printf("\n");
  return 0; 
}

  
