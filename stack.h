#include <string>
#include <stdexcept>

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
    cost E &top() const throw(StackEmpty);
    void push(const E &e);
    void pop() throw(StackEmpty);
};

class StackEmpty : public RuntimeException
{
public:
    StackEmpty(const std::string &err) : RuntimeException(err) {}
};
