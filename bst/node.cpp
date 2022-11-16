#include "bst.hpp"

using namespace bst;


BST::Node::Node(int data_, Node* parent_){
    data = data_;
    parent = parent_;
}

BST::Node::~Node()
{
    if (childs[LEFT] != nullptr)
    {
        delete childs[LEFT];
    }

    if (childs[RIGHT] != nullptr)
    {
        delete childs[RIGHT];
    }
}


bool BST::Node::isLeaf()
{
    return (childs[LEFT] == nullptr && childs[RIGHT] == nullptr);
}

bool BST::Node::hasChild(side which)
{
    return (childs[which] != nullptr);
}

void BST::Node::setChild(int data, side where)
{
    Node* to_set = new Node(data, this);

    childs[where] = to_set;
}

void BST::Node::setChild(Node* to_set, side where)
{
    childs[where] = to_set;
}

BST::Node* BST::Node::getChild(side where)
{
    return childs[where];
}



