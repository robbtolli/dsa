#ifndef NULL
#define NULL 0
#endif

template <typename Value>
class LinkedList {
public:
    class Node {
    protected:
        Node *_next;
        Value _value;
        Node(Value value, Node * next) :
                _value(value), _next(next) {}
        void destroy();
    public:
        const Value &getValue() const { return _value; }
        void setValue(const Value &value) { _value = value; }
        Node *getNext() { return _next; }
        friend class LinkedList<Value>;
                
    };

private:
    Node *_head;
    Node *_tail;

public:
    LinkedList() : _head(NULL), _tail(NULL) {}
    LinkedList(const LinkedList & list);
    virtual ~LinkedList();
    
    bool isEmpty() { return !_head; }
    
    
    // Removes and returns the head. 
    virtual Node *decapitate();
    Node *getFirst() { return _head; );
    Node *getLast() { return _tail; }
    
    virtual void append(const LinkedList &list);
    
    virtual void insertFront(const Value &value);
    virtual void insertBack(const Value &value);
    virtual bool insertAfter(Node *node, const Value &value);
    
    virtual Node *find(const Value &value);
    virtual bool findAndRemove(const Value &value);
    

};

#if 1
template <typename Value>
class DoubleLinkedList : public LinkedList<Value> {
public:
    class Node : public LinkedList<Value>::Node {
    protected:
        Node *_prev;
        Node(Value value, Node *prev, Node *next) :
            LinkedList<Value>::Node(value, next), _prev(prev) {}
    public:
        Node *getPrev() { return _prev; }
        friend class DoubleLinkedList<Value>;
        
    };
    
    virtual void append(const LinkedList &list);
    
    virtual void insertFront(const Value &value);
    virtual void insertBack(const Value &value);
    virtual bool insertAfter(Node *node, const Value &value);
    
    virtual bool findAndRemove(const Value &value);
    
    bool swap(Node* nodeA, Node* nodeB);
    
    

};
#endif
