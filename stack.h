#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

template <typename E>
class Stack
{
    enum
    {
        DEF_CAPACITY = 100
    };

public:
    Stack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E &top() const;
    void push(const E &e);
    void pop();

private:
    E *S;         // Array of stack elements
    int capacity; // Stack capacity
    int t;        // Top element index
};
