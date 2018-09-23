#ifndef TREE_H
#define TREE_H
#include <cstdlib>
#include <iostream>
#include "iterator.h"
template <typename T>
class Tree
{
    private:
        Node<T>* root;
        Node<T>* InOrder_Tail;
    public:
        Tree();
        ~Tree();
        void Insert(Node<T> **&pointer, T data);
        void PreOrder(Node<T>* root);
        void InOrder(Node<T>* root);
        void PostOrder(Node<T>* root);
        void Main();
        Iterator<T> begin();
        Iterator<T> end();
};
template<class T> Tree<T>::Tree(){
    root=nullptr;
    InOrder_Tail=nullptr;
}
template<class T> Tree<T>::~Tree(){
    root=nullptr;
}
template<class T> void Tree<T>::Main(){
    int opcion;
    int date;
    Node<T>** pointer;
    int aux=0;
    do{
        Iterator<T> ite;
        cout << "Bienvenido al arbol binario" << endl;
        cout << "1) Insertar dato" << endl;
        cout << "2) Eliminar dato" << endl;
        cout << "3) Imprimir en PreOrder" << endl;
        cout << "4) Imprimir en InOrder" << endl;
        cout << "5) Imprimir en PostOrder" << endl;
        cout << "6) Iterador en InOrder" << endl;
        cout << "7) Salir" <<endl;
        cout << "Eliga el numero respectivo a lo que desea hacer:";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "Ingrese un numero: ";
            cin >> date;
            pointer=&root;
            Insert(pointer,date);
            pointer=nullptr;
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "PreOrder:" <<endl;
            PreOrder(root);
            cout << endl;
            break;
        case 4:
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            break;
        case 5:
            system("cls");
            cout << "PostOrder:" <<endl;
            PostOrder(root);
            cout << endl;
            break;
        case 6:
            system("cls");
            cout << "Iterator-InOrder:" <<endl;
            for (ite = begin(); ite!=end(); ++ite) {
                if(*ite!=0){
                    cout << *ite << " - ";
                }
            }
            cout << *ite;
            cout << endl;
            break;
        default:
            system("cls");
            break;
        }
    }
    while(opcion!=7);
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
        InOrder_Tail=root;
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

template<typename T> Iterator<T> Tree<T>::begin()
{
    Iterator<T> ite(root);
    return ite;
}
template<typename T> Iterator<T> Tree<T>::end()
{
    Iterator<T> ite(InOrder_Tail);
    return ite;
}
#endif // TREE_H
