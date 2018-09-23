#ifndef ITERATOR_H
#define ITERATOR_H
#include "stack.h"
template <typename T>
class Iterator {
    private:
        Node<T>* current;
        Node<T>* temp;
        Stack<T>* stack_nodes;
    public:
        Iterator();
        Iterator(Node<T>* node);
        Iterator<T> operator=(Iterator<T> node);
        bool operator!=(Iterator<T> cmp);
        Iterator<T> operator++();
        T operator*();
};

template<class T> Iterator<T>::Iterator()
{
    current=nullptr;
    temp=nullptr;
    stack_nodes = new Stack<T>;
}
//Test
template<class T> Iterator<T>::Iterator(Node<T>* node)
{
    temp=node;
}
//Test
template<typename T> T Iterator<T>::operator*()
{
    if(this->current!=nullptr){
        return this->current->data;
    }
    return 0;
}
template<typename T> Iterator<T> Iterator<T>::operator++()
{
    current=nullptr;
    if(temp!=nullptr){
        stack_nodes->stack_nodes.push(temp);
        temp=temp->left;
    }
    else{
        current=stack_nodes->stack_nodes.top();
        stack_nodes->stack_nodes.pop();
        temp=current;
        temp=temp->right;
    }
    return *this;
}
template<typename T> bool Iterator<T>::operator!=(Iterator<T> node)
{
    if (this->current==node.temp)
    {
        delete stack_nodes;
        return false;
    }
    else{
        return true;
    }
}
template<typename T> Iterator<T> Iterator<T>::operator=(Iterator<T> node)
{
    this->temp=node.temp;
    return *this;
}


#endif
