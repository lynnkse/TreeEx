#include "../../inc/node.h"

Node::Node(int _data):
    data(_data),
    left(NULL),
    right(NULL)
{}

Node * Node::GetLeft() const
{
    return left;
}

Node * Node::GetRight() const
{
    return right;
}


Node * Node::AddLeft(Node * _node)
{
    left = _node;

    return left;
}

Node * Node::AddRight(Node *  _node)
{
    right = _node;

    return right;
}

std::size_t Node::GetData() const
{
    return data;
}

Node::~Node()
{
    delete(left);
    delete(right);
}
