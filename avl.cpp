#include "avl.h"
#include <queue>
#include <iostream>
using namespace std;

static avltree* FindLeftMax(avltree* node);
static void Reblance(avltree* &node);

//获取某个节点的高度，节点是空返回-1
int GetTreeHeight(avltree* &node)
{
    if(node==NULL)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

void ModifyTreeHeight_Bf(avltree* &node)
{
    int left_height=GetTreeHeight(node->left);
    int right_height=GetTreeHeight(node->right);

    if(left_height>right_height)
    {
        node->height= left_height+1;
    }
    else
    {
        node->height= right_height+1;
    }
    node->bf=left_height-right_height;
    return;
}

//单右旋
void SingleRotateRight(avltree* &node)
{
    avltree* temp=node->left;

    node->left=temp->right;
    temp->right=node;
    node=temp;
    ModifyTreeHeight_Bf(node->right);
    ModifyTreeHeight_Bf(node);
    return;
}

//单右旋
void SingleRotateLeft(avltree* &node)
{
    avltree* temp=node->right;

    node->right=temp->left;
    temp->left=node;
    node=temp;
    ModifyTreeHeight_Bf(node->left);
    ModifyTreeHeight_Bf(node);

    return;  
}

//先左旋在右旋
void DoubleRotateLeftRight(avltree* &node)
{
    SingleRotateLeft(node->left);
    SingleRotateRight(node);
    return;
}

//先右旋在左旋
void DoubleRotateRightLeft(avltree* &node)
{
    SingleRotateRight(node->right);
    SingleRotateLeft(node);
    return;
}

//插入
void insert(avltree* &node,int val)
{
    if(node==NULL)
    {
        //找到叶子节点
        node=new avltree(val);
        return;
    }

    if(node->data==val)
    {
        return;
    }

    if(val<node->data)
    {
        //左子树
        insert(node->left,val);
        ModifyTreeHeight_Bf(node);
        if(node->bf>1)
        {
            /* 
            if(val<node->left->data)
            {
                //左左需要单右旋
                SingleRotateRight(node);
            }
            else
            {
                DoubleRotateLeftRight(node);
            }
            */
            Reblance(node);
        }
    }
    else
    {
        //右子树
        insert(node->right,val);
        ModifyTreeHeight_Bf(node);
        if(node->bf<-1)
        {
            /* 
            if(val>node->right->data)
            {
                //右右需要单左旋
                SingleRotateLeft(node);
            }
            else
            {
                DoubleRotateRightLeft(node);
            }
            */
            Reblance(node);
        }        
    }
    return;
}

bool remove(avltree* &node,int val)
{
    if(node==NULL)
    {
        //找不到删除失败
        return false;
    }

    if(node->data==val)
    {
        if(node->left==NULL && node->right==NULL)
        {
            delete node;
            node=NULL;
            return true;
        }
        if(node->left!=NULL && node->right==NULL)
        {
            avltree* temp=node;
            node=node->left;
            delete temp;  
            temp=NULL;
            return true;    
        }
        if(node->left==NULL && node->right!=NULL)
        {
            avltree* temp=node;
            node=node->right;
            delete temp;   
            temp=NULL; 
            return true;   
        }

        //左右孩子都有
        if(node->left!=NULL && node->right!=NULL)
        {
            avltree* temp=FindLeftMax(node);
            node->data=temp->data;
            remove(node->left,temp->data);
            ModifyTreeHeight_Bf(node);
/* 
            if(node->bf<-1)
            {
                //平衡，左子树删除等价于右子树加一个
                if(GetTreeHeight(node->right->left) > GetTreeHeight(node->right->right))
                {
                    DoubleRotateRightLeft(node);
                }
                else
                {
                    SingleRotateLeft(node);
                }
                return true;
            }

            if(node->bf>1)
            {
                if(GetTreeHeight(node->left->left) > GetTreeHeight(node->left->right))
                {
                    SingleRotateRight(node);
                }
                else
                {
                    DoubleRotateLeftRight(node);
                }
                return true;
            }    
            */
            Reblance(node);        
            return true;
        }
    }

    if(val<node->data)
    {
        if(!remove(node->left,val))
            return false;
        
        ModifyTreeHeight_Bf(node);
        /* 
        if(node->bf<-1)
        {
            //平衡，左子树删除等价于右子树加一个
            if(GetTreeHeight(node->right->left) > GetTreeHeight(node->right->right))
            {
                DoubleRotateRightLeft(node);
            }
            else
            {
                SingleRotateLeft(node);
            }
        }
        */
       Reblance(node);
    }
    else
    {
        if(!remove(node->right,val))
            return false;
        
        ModifyTreeHeight_Bf(node);
        /* 
        if(node->bf>1)
        {
            if(GetTreeHeight(node->left->left) > GetTreeHeight(node->left->right))
            {
                SingleRotateRight(node);
            }
            else
            {
                DoubleRotateLeftRight(node);
            }
        }
        */
       Reblance(node);
    }
    return true;
}

static avltree* FindLeftMax(avltree* node)
{
    avltree* temp=node->left;
    while (temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

static void Reblance(avltree* &node)
{
    if(node->bf<-1)
    {
        if(GetTreeHeight(node->right->left) > GetTreeHeight(node->right->right))
        {
            DoubleRotateRightLeft(node);
        }
        else
        {
            SingleRotateLeft(node);
        }
        return;
    }

    if(node->bf>1)
    {
        if(GetTreeHeight(node->left->left) > GetTreeHeight(node->left->right))
        {
            SingleRotateRight(node);
        }
        else
        {
            DoubleRotateLeftRight(node);
        }
        return;
    }
}


/*******************************************遍历avl****************** */
void PreOrder(avltree* node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
    return;
}

void InOrder(avltree* node)
{
    if(node==NULL)
    {
        return;
    }
    
    InOrder(node->left);
    cout<<node->data<<" ";
    InOrder(node->right);
    return;
}

void PostOrder(avltree* node)
{
    if(node==NULL)
    {
        return;
    }
   
    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data<<" ";
    return;
}

//广度优先搜索
void BreadthFirstSearch(avltree *root)
{
    queue<avltree*> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        avltree *node = nodeQueue.front();
        cout << node->data << ' ';
        nodeQueue.pop();
        if (node->left)
        {
            nodeQueue.push(node->left);
        }
        if (node->right)
        {
            nodeQueue.push(node->right);
        }
    }
}