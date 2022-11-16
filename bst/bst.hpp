#ifndef __BST_H__
#define __BST_H_

#include "iostream"

namespace bst
{
enum side{LEFT, RIGHT};

class BST; //declared here for the friend funcs

struct bst_iter_ty{
    BST::Node* node;
};

std::ostream& operator<<(std::ostream& os_, const BST& bst); // can i declare it below?

class BST
{
public:
    //creation 
    explicit BST();
    ~BST();
    BST(const BST& other) = delete; //copy constructor blocked
    BST& operator=(const BST& other) = delete; // copy assignment blocked
    friend bst_iter_ty;

    //basic functionality
    bst_iter_ty insert(int data); //throws on malloc failure
    void remove(bst_iter_ty target); //
    bool isEmpty();
    int count();
    bool isPresent(int data);

    //iterating over the container
    bst_iter_ty begin(); //equal to end() if empty
    bst_iter_ty end(); //one after the last real node
    bst_iter_ty next(bst_iter_ty curr);//next from the last gives end()
    bst_iter_ty prev(bst_iter_ty curr); //throws if first ? end if first?
    bool isEqual(bst_iter_ty lhd, bst_iter_ty rhd); // use operator== overload?
    bst_iter_ty find(int data); //end if not found
    int getData(bst_iter_ty curr);
    // TODO: for each()

    //friend std::ostream& operator<<(std::ostream& os_, const BST& bst);//must be friend?
    
    
private:
    
    class Node
    {
    public:   
        explicit Node(int data, Node* parent);
        ~Node();
        // ? block cctor and copy assignment?
        
        bool isLeaf();
        bool hasChild(side which);

        void setChild(int data, side where);
        void setChild(Node* child, side where);

        Node* getChild(side where);
    
    private:
        int data;
        Node* parent;
        Node* childs[2];
    };

    Node* root; //pointer for simpler construction and destruction


};


}//namespace bst

#endif