#include "list.h"
#include <iostream>
using namespace std;



void bubble_sort_test()
{
    list *head=new list(4);
    list *node=new list(1);
    head->next=node;
    node->next=new list(3);
    node=node->next;
    node->next=new list(2);
    node=node->next;
    node->next=new list(5);

    head=bubble_sort(head);
    list_print(head);
    cout<<""<<endl;
    return;
}

void bubble_sort1_test()
{
    list *head=new list(4);
    list *node=new list(1);
    head->next=node;
    node->next=new list(3);
    node=node->next;
    node->next=new list(2);
    node=node->next;
    node->next=new list(5);

    head=bubble_sort1(head);
    list_print(head);
    cout<<""<<endl;
    return;
}

void reverse_test()
{
    list *head=new list(4);
    list *node=new list(1);
    head->next=node;
    node->next=new list(3);
    node=node->next;
    node->next=new list(2);
    node=node->next;
    node->next=new list(5);

    head=reverse(head);
    list_print(head);
    cout<<""<<endl;
    return;
}

int main()
{
    bubble_sort_test();
    bubble_sort1_test();
    reverse_test();
    return 0;
}