#include <iostream>
using namespace std;
struct list
{
    int data;
    list* next;
    list(int x):data(x),next(NULL){}  
};


void list_print(list *head);
list *reverse(list *head);
list* bubble_sort1(list *head);
list* bubble_sort(list *head);
void insert(list *dest,int data);
int length(list *head);