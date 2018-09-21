#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "node.h"
using namespace std;
template <typename T>
class Tree
{
    private:
        Node<T>* root;
    public:
        Tree();
        ~Tree();
        void Insert(Node<T> **&pointer, T data);
        void PreOrder(Node<T>* root);
        void InOrder(Node<T>* root);
        void PostOrder(Node<T>* root);
        void Main();
};
template<class T> Tree<T>::Tree(){
    root=nullptr;
}
template<class T> void Tree<T>::Main(){
    int date[]={8,3,10,1,6,14,4,7,13};
    for(int x=0;x<(sizeof(date) / sizeof(*date));x++){
        Node<T>** pointer=&root;
        Insert(pointer,date[x]);
        pointer=nullptr;
    }
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
}
template<class T> void Tree<T>::Insert(Node<T> **&pointer,T data){
    if(*pointer==nullptr){
        *pointer = new Node<T>(data);

    }
    else if(data < (*pointer)->data){
        pointer=&(*pointer)->left;
        Insert(pointer,data);
    }
    else if(data > (*pointer)->data){
        pointer=&(*pointer)->right;
        Insert(pointer,data);
    }
}
template<class T> void Tree<T>::PreOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        cout << root->data << " - ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

template<class T> void Tree<T>::InOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        InOrder(root->left);
        cout << root->data << " - ";
        InOrder(root->right);
    }
}

template<class T> void Tree<T>::PostOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " - ";
    }
}
#endif // TREE_H
