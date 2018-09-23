#ifndef STACK_H
#define STACK_H
#include <stack>
#include "node.h"
using namespace std;
template <typename T>
struct Stack {
    stack<Node<T>*> stack_nodes;
};

#endif
