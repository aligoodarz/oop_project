#include "stack.h"

template <typename E>
Stack<E>::Stack(int cap) : S(new E[cap]), capacity(cap), t(-1) {}

template <typename E>
int Stack<E>::size() const
{
    return (t + 1);
}

template <typename E>
bool Stack<E>::empty() const
{
    return (t < 0);
}

template <typename E>
const E &Stack<E>::top() const
{
    if (empty())
        std::cout << "Stack is empty";
    return S[t];
}

template <typename E>
void Stack<E>::push(const E &e)
{
    if (size() == capacity)
        std::cout << "Stack is full already";
    S[++t] = e;
}

template <typename E>
void Stack<E>::pop()
{
    --t;
}
