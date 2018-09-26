#ifndef MAIN_H
#define MAIN_H
#include "tree.h"

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
        cout << "7) Peso del nodo" <<endl;
        cout << "8) Salir" <<endl;
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
        case 2:
            cout << "Ingrese el numero que desea eliminar: ";
            cin >> date;
            pointer=&root;
            Delete(pointer,date);
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
        case 7:
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            cout << "Ingrese el numero del nodo que desea saber su peso: " << endl;
            cin >> date;
            cout << "El peso del nodo seleccionado es: ";
            Peso(root,date,false);
            cout << peso << endl;
            peso=0;
            break;
        default:
            system("cls");
            break;
        }
    }
    while(opcion!=8);
}
#endif
