#ifndef NODE
#define NODE

#include <cstddef>

class Node
{
public:
    ~Node();
    explicit Node(int _data);
    Node * AddLeft(Node * _node);
    Node * AddRight(Node * _node);
    Node * GetLeft() const;
    Node * GetRight() const;
    size_t GetData() const;
private:
    int data;
    Node* left;
    Node* right;
};

#endif //NODE
