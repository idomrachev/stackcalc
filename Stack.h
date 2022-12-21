#ifndef STACK_H
#define STACK_H 1

#include <vector>
#include <stdexcept>

template <class ValueType> class Stack {
private:
    std::vector<ValueType> elems;
public:
    Stack(size_t initialCapacity = 16):
        elems(0)
    {
        elems.reserve(initialCapacity);
    }

    size_t size() const {
        return elems.size();
    }

    bool empty() const {
        return (elems.size() == 0);
    }

    void clear() {
        elems.clear();
    }

    const ValueType& top() const {
        if (empty())
            throw std::underflow_error(" ");
        return elems.back();
    }

    ValueType& top() {
        if (empty())
            throw std::underflow_error(" ");
        return elems.back();
    }

    void push(const ValueType& x) {
        elems.push_back(x);
    }

    void pop() {
        if (empty())
            throw std::underflow_error(" ");
        elems.pop_back();
    }
};

#endif
