#include <iostream>
#include "avl.h"
using namespace std;

int main()
{
    avltree* head=NULL;
/* 
    for(int i=1;i<10;i++)
    {
        insert(head,i);
    }
*/
    insert(head,5);
    insert(head,9);
    insert(head,8);
    insert(head,4);
    insert(head,6);
    insert(head,1);
    insert(head,10);
    insert(head,7);
    insert(head,2);
    insert(head,3);

    InOrder(head);
    cout<<""<<endl;

    BreadthFirstSearch(head);
    cout<<""<<endl;

    remove(head,8);
    BreadthFirstSearch(head);
    cout<<""<<endl;

    remove(head,7);
    BreadthFirstSearch(head);
}