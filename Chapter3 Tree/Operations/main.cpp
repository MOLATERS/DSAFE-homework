#include <iostream>
typedef struct BItree{
    int data;
    struct BItree lchild;
    struct BItree rchild;
}BItree;

typedef struct queue{
    BItree a[200];
    int head;
    int tail;
};

void InitQueue(queue &Q)
{
    for (int i = 0; i <= 199; i++)
        Q.a[i] = {0, NULL, NULL};
    Q.head=0;
    Q.tail=0;
}

void EnQueue(queue &Q,BItree T)
{

}
void DeQueue(queue &Q,BItree &T)
{

}
void LevelOrder(Bitree T)
{

}
int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
