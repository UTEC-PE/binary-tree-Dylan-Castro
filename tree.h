#ifndef TREE_H
#define TREE_H
#include <cstdlib>
#include <iostream>
#include "node.h"
#include "iterator.h"
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
        Iterator<T> begin();
};
template<class T> Tree<T>::Tree(){
    root=nullptr;
}
template<class T> Tree<T>::~Tree(){
    root=nullptr;
}
template<class T> void Tree<T>::Main(){
    int opcion;
    int date;
    Node<T>** pointer;
    do{
        cout << "Bienvenido al arbol binario" << endl;
        cout << "1) Insertar dato" << endl;
        cout << "2) Eliminar dato" << endl;
        cout << "3) Imprimir en PreOrder" << endl;
        cout << "4) Imprimir en InOrder" << endl;
        cout << "5) Imprimir en PostOrder" << endl;
        cout << "6) Salir" <<endl;
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
            cout << "PreOrder:" <<endl;
            PreOrder(root);
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
        default:
            system("cls");
            break;
        }
    }
    while(opcion!=6);
    /*int date[]={8,3,10,1,6,14,4,7,13};
    for(int x=0;x<(sizeof(date) / sizeof(*date));x++){

    }
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;*/
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
