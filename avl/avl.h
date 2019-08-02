struct avltree
{
    avltree* left;
    avltree* right;
    int data;
    int height; 
    int bf;
    avltree(int x):data(x),height(0),bf(0),left(0),right(0){}
};


void insert(avltree* &node,int val);
bool remove(avltree* &node,int val);


void PreOrder(avltree* node);
void InOrder(avltree* node);
void PostOrder(avltree* node);
void BreadthFirstSearch(avltree *root);