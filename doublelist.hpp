#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include <iostream>
#include <cassert>

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() = default;
};

template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    
    ~DoubleList() { 
        clear(); 
    }
    
    DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr) {
        DoubleNode<T>* curr = other.head;
        while(curr != nullptr) {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    
    DoubleList& operator=(const DoubleList& other) {
        if (this != &other) {
            clear();
            DoubleNode<T>* curr = other.head;
            while(curr != nullptr) {
                push_back(curr->value);
                curr = curr->next;
            }
        }
        return *this;
    }
    
    bool empty() const { 
        return head == nullptr; 
    }
    
    bool full() const { 
        return false; 
    }
    
    std::size_t size() const {
        std::size_t count = 0;
        DoubleNode<T>* curr = head;
        while(curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    
    void push_front(const T& item) {
        DoubleNode<T>* node = new DoubleNode<T>(item, head, nullptr);
        if (head != nullptr) {
            head->prev = node;
        } else {
            tail = node;
        }
        head = node;
    }
    
    void push_back(const T& item) {
        DoubleNode<T>* node = new DoubleNode<T>(item, nullptr, tail);
        if (tail != nullptr) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
    }
    
    T& front() { 
        assert(!empty()); 
        return head->value; 
    }
    
    T& back() { 
        assert(!empty()); 
        return tail->value; 
    }
    
    void pop_front() {
        assert(!empty());
        DoubleNode<T>* node = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete node;
    }
    
    void pop_back() {
        assert(!empty());
        DoubleNode<T>* node = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete node;
    }
    
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void display() const {
        DoubleNode<T>* curr = head;
        while (curr != nullptr) {
            std::cout << curr->value << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    
    void display_reversed() const {
        DoubleNode<T>* curr = tail;
        while (curr != nullptr) {
            std::cout << curr->value << " ";
            curr = curr->prev;
        }
        std::cout << std::endl;
    }
};

#endif
