#include "bst.hpp"

using namespace bst;


BST::BST()
{
    root = new Node(0,nullptr);
}

BST::~BST()
{
    delete root; //would it be called without this line?
}

bst_iter_ty BST::insert(int data) //throws on malloc failure
{

}

void BST::remove(bst_iter_ty target) //
{

}

bool BST::isEmpty()
{

}

int BST::count()
{

}

bool BST::isPresent(int data)
{

}

//iterating over the container
bst_iter_ty BST::begin() //equal to end() if empty
{

}

bst_iter_ty BST::end() //one after the last real node
{

}

bst_iter_ty BST::next(bst_iter_ty curr)//next from the last gives end()
{

}

bst_iter_ty BST::prev(bst_iter_ty curr) //throws if first ? end if first?
{

}

bool BST::isEqual(bst_iter_ty lhd, bst_iter_ty rhd) // use operator== overload?
{

}

bst_iter_ty BST::find(int data) //end if not found
{

}

int BST::getData(bst_iter_ty curr)
{

}