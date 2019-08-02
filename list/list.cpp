#include "list.h"


//返回链表长度
int length(list *head)
{
    list *node=head;
    int len=0;

    while(node)
    {
        len++;
        node=node->next;
    }
    return len;
}


//插入到dest节点之后
void insert(list *dest,int data)
{
    if(dest==NULL)
    {
        return;
    }

    list *res=new list(data);
    list *temp=dest->next;
    dest->next=res;
    res->next=temp;
    return;
}

//冒泡排序,只交换data值，节点地址不变
list* bubble_sort(list *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    int len=length(head);
    
    for(int i=len-1;i>0;i--)
    {
        list *node=head;
        for(int j=0;j<i;j++)
        {
            if(node->data > node->next->data)
            {
                int temp=node->data;
                node->data=node->next->data;
                node->next->data=temp;
            }
            node=node->next;
        }
    }
    return head;
}

//冒泡排序，实际交换节点位置
list* bubble_sort1(list *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    int len=length(head);
    for(int i=len-1;i>0;i--)
    {
        list *node=head;
        list *pre=head;
        for(int j=0;j<i;j++)
        {
            if(node->data > node->next->data)
            {
                list *temp=node;
                list *temp1=node->next->next;
                node=node->next;
                node->next=temp;

                if(j==0)
                {
                    //第一次进来
                    head=node;
                    node->next->next=temp1;
                    pre=node;
                    node=node->next;
                    continue;
                }

                pre->next=node;
                pre=node;
                node->next->next=temp1;
            }
            node=node->next;
        }
    }

    return head;
}

//链表反转
list *reverse(list *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    list *pre=head;
    list *node=head->next;
    head->next=NULL;
    while(node)
    {
        list* temp=node->next;
        node->next=pre;
        pre=node;
        node=temp;
    }
    return pre;
}

void list_print(list *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}