#ifndef TREE_H
#define TREE_H
#include "node.h"
template <typename T>
class Tree
{
    private:
        Node<T>* root;
    public:
        Tree();
        ~Tree();
        void Insert(T data);
};
template<class T> Tree<T>::Tree(){
    root=nullptr;
}
template<class T> void Tree<T>::Insert(T data){
    Node<T>* temp = root;
    do{

    }while();
    if(root==nullptr){
        root = new Node<T>(data);
    }
    else if(data < root->data){

    }

}

#endif // TREE_H
