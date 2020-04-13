#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
class binarytree
 {
private:
    struct node
    {
        T value;          // The value in the node
        node *left;   // Pointer to left child node
        node *right;  // Pointer to right child node
    };

    node *root; // Pointer to the root node

    // Private member functions
    void insert(node *&, node *&);

    void destroySubTree(node *);
    void deleteNode(T, node *&);
    void makeDeletion(node *&);
    void displayInOrder(node *) const;
    void displayPreOrder(node *) const;
    void displayPostOrder(node *) const;

public:

    // Constructor
    binarytree()
    {
        root = nullptr;
    }

    // Binary tree operations
    void insertNode(T);

    bool searchNode(T);

    void remove(T);

    void displayInOrder() const
    {
        displayInOrder(root);
    }

    void displayPreOrder() const
    {
        displayPreOrder(root);
    }

   void displayPostOrder() const
   {
       displayPostOrder(root);
   }

   // Destructor
   ~binarytree()
   {

       destroySubTree(root);
   }
};

#include"binarytree.cpp"
#endif
