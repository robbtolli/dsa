
#include "LinkedList.h"

template <typename Value> 
void LinkedList<Value>::Node::destroy() {
    if (_next) {
        _next->destroy();
        delete _next;
        _next = NULL;
    }
}

template <typename Value> 
LinkedList<Value>::LinkedList(const LinkedList &list) :
        _head(NULL), _tail(NULL) {
    LinkedList<Value>::Node *oldCurrent = NULL;
    LinkedList<Value>::Node *newCurrent = NULL;
    if (list._head) {
        _head = new LinkedList<Value>::Node(list._head->_value, list._head->_next);
        newCurrent = _head;
        oldCurrent = list._head->_next;
        _tail = newCurrent;
    }
    while (oldCurrent) {
        newCurrent->_next = new LinkedList<Value>::Node(oldCurrent->_value, oldCurrent->_next);
        oldCurrent = oldCurrent->_next;
        newCurrent = newCurrent->_next;
        _tail = newCurrent;
    }
}

template <typename Value> 
LinkedList<Value>::~LinkedList() {
    if (_head) {
        _head->destroy();
        delete _head;
        _head = NULL;
    }
}

// Removes and returns the head.
template <typename Value>
typename LinkedList<Value>::Node *LinkedList<Value>::decapitate() {
    LinkedList<Value>::Node *head = _head;
    if (head) {
        if (_tail == head) {
            _tail = NULL;
        }
        _head = head->_next;
    }
    return head;
}


template <typename Value>
void LinkedList<Value>::append(const LinkedList<Value> &list) {
    LinkedList<Value>::Node *oldCurrent = NULL;
    LinkedList<Value>::Node *newCurrent = NULL;
    if (list._head) {
        _tail->_next = new LinkedList<Value>::Node(list._head->_value, list._head->_next);
        newCurrent = _head;
        oldCurrent = list._head->_next;
        _tail = newCurrent;
    }
    while (oldCurrent) {
        newCurrent->_next = new LinkedList<Value>::Node(oldCurrent->_value, oldCurrent->_next);
        oldCurrent = oldCurrent->_next;
        newCurrent = newCurrent->_next;
        _tail = newCurrent;
    }
}

template <typename Value>
void LinkedList<Value>::insertFront(const Value &value) {
    _head = new LinkedList<Value>::Node(value, _head ? _head : NULL);
    if (_tail == NULL) { _tail = _head; }
}

template <typename Value>
void LinkedList<Value>::insertBack(const Value &value) {
    if (_tail) {
        _tail->_next = new LinkedList<Value>::Node(value, NULL);
        _tail = _tail->_next;
    } else {
        _head = new LinkedList<Value>::Node(value, NULL);
        _tail = _head;
    }
}

template <typename Value>
bool LinkedList<Value>::insertAfter(LinkedList<Value>::Node *node, 
        const Value &value) {
    if (node) {
        node->_next = new LinkedList<Value>::Node(value, node->_next);
    }
    return node;
}

template <typename Value>
typename LinkedList<Value>::Node *LinkedList<Value>::find(const Value &value) {
    LinkedList<Value>::Node *current = _head;
    while (current) {
        if (current->_value == value) { return current; }
        current = current->_next;
    }
    return NULL;
}

template <typename Value>
bool LinkedList<Value>::findAndRemove(const Value &value) {
    LinkedList<Value>::Node *prev = _head;
    LinkedList<Value>::Node *current = _head;
    bool found = false;
    while (current) {
        if (current->_value == value) {
            found = true; 
            break;
        }
        current = current->_next;
        prev = current;
    }
    if (found) {
        prev->_next = current->_next;
        delete current;
    }
    return found;
}

// DoubleLinkedList
template <typename Value>
void DoubleLinkedList<Value>::append(const DoubleLinkedList<Value> &list) {
    DoubleLinkedList<Value>::Node *oldCurrent = NULL;
    DoubleLinkedList<Value>::Node *newCurrent = NULL;
    if (list._head) {
        _tail->_next = new DoubleLinkedList<Value>::Node(
            list._head, list._head->_value, list._head->_next);
        newCurrent = _head;
        oldCurrent = list._head->_next;
        _tail = newCurrent;
    }
    while (oldCurrent) {
        newCurrent->_next = new DoubleLinkedList<Value>::Node(
            oldCurrent->_value, newCurrent, oldCurrent->_next);
        oldCurrent = oldCurrent->_next;
        newCurrent = newCurrent->_next;
        _tail = newCurrent;
    }
}

template <typename Value>
void DoubleLinkedList<Value>::insertFront(const Value &value) {
    _head = new DoubleLinkedList<Value>::Node(value, NULL, _head );
    if (_tail == NULL) { _tail = _head; }
}

template <typename Value>
void DoubleLinkedList<Value>::insertBack(const Value &value) {
    if (_tail) {
        _tail->_next = new DoubleLinkedList<Value>::Node(value, _tail, NULL);
        _tail = _tail->_next;
    } else {
        _head = new DoubleLinkedList<Value>::Node(value, NULL, NULL);
        _tail = _head;
    }
}

template <typename Value>
bool DoubleLinkedList<Value>::insertAfter(DoubleLinkedList<Value>::Node *node,
        const Value &value) 
{
    if (node) {
        node->_next = new DoubleLinkedList<Value>::Node(value, node, node->_next);
    }
    return node;
}

template <typename Value>
bool DoubleLinkedList<Value>::findAndRemove(const Value &value) {
    DoubleLinkedList<Value>::Node *prev = _head;
    DoubleLinkedList<Value>::Node *current = _head;
    bool found = false;
    while (current) {
        if (current->_value == value) {
            found = true; 
            break;
        }
        current = current->_next;
        prev = current;
    }
    if (found) {
        prev->_next = current->_next;
        delete current;
    }
    return found;
}


/*********************************************/

#include <iostream>

template <typename Value>
void printList(LinkedList<Value> list) {
    LinkedList<Value>::node current = list.getFirst();
    while (current) {
        
    }
}

int main() {
    LinkedList<int> listA, listB;
    listA.insertFront(10);
    listA.insertBack(9);
    listA.insertFront(20);
    listA.insertBack(8);
    listA.insertBack(7);
    listA.insertBack(6);
    listA.insertFront(30);
    
    LinkedList<int>::Node *node = NULL;
    while (node = listA.decapitate()) {
        std::cout << node->getValue() << " ";
    }
    std::cout << std::endl;
    
    return 0;
    
}