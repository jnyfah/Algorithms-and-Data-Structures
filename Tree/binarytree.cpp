#include "binarytree.h"
#include<iostream>

template <class T>
void binarytree<T>::insert(node *&nodePtr, node *&newNode)
 {
    if (nodePtr == nullptr)
    {
         nodePtr = newNode;    // Insert the node
    }
    else if (newNode->value < nodePtr->value)
    {
        insert(nodePtr->left, newNode); // Search the left branch
    }else
    {
        insert(nodePtr->right, newNode); // Search the right branch
    }

}


template <class T>
void binarytree<T>::insertNode(T item)
{
    node *newNode = nullptr;  // Pointer to a new node

    newNode = new node;

    newNode->value = item;

    newNode->left = newNode->right = nullptr;

    // Insert the node.

    insert(root, newNode);
}

template <class T>
bool binarytree<T>::searchNode(T item)
{
    node *nodePtr = root;
    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;

        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}

template <class T>
void binarytree<T>::remove(T item)
{
    deleteNode(item, root);
}

template <class T>
void binarytree<T>::deleteNode(T item, node *&nodePtr)
{
    if (item < nodePtr->value)

        deleteNode(item, nodePtr->left);

    else if (item > nodePtr->value)

        deleteNode(item, nodePtr->right);

    else

        makeDeletion(nodePtr);
}



template <class T>
void binarytree<T>::makeDeletion(node *&nodePtr)
{
   node *tempNodePtr = nullptr;
   if (nodePtr == nullptr)

       std::cout << "Cannot delete empty node.\n";

   else if (nodePtr->right == nullptr)
   {
       tempNodePtr = nodePtr;

       nodePtr = nodePtr->left;  // Reattach the left child

       delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
       tempNodePtr = nodePtr;
       nodePtr = nodePtr->right;  // Reattach the right child

       delete tempNodePtr;
   }
   // If the node has two children.

   else
   {
      // Move one node to the right.

       tempNodePtr = nodePtr->right;

       // Go to the end left node.

       while (tempNodePtr->left)

           tempNodePtr = tempNodePtr->left;

       tempNodePtr->left = nodePtr->left;

       tempNodePtr = nodePtr;   // Reattach the right subtree.

       nodePtr = nodePtr->right;
       delete tempNodePtr;
   }

    }


template <class T>
void binarytree<T>::displayInOrder(node *nodePtr) const
{
    if (nodePtr)
    {
            displayInOrder(nodePtr->left);
            std::cout << nodePtr->value << std::endl;
            displayInOrder(nodePtr->right);
}
}


template <class T>
void binarytree<T>::displayPreOrder(node *nodePtr) const
{
    if (nodePtr)
    {
            std::cout << nodePtr->value << std::endl;

            displayInOrder(nodePtr->left);

            displayInOrder(nodePtr->right);
}
}


template <class T>
void binarytree<T>::displayPostOrder(node *nodePtr) const
{
    if (nodePtr)
    {


            displayInOrder(nodePtr->left);

            displayInOrder(nodePtr->right);

            std::cout << nodePtr->value << std::endl;
}
}

template <class T>
void binarytree<T>::destroySubTree(node *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)

            destroySubTree(nodePtr->left);

        if (nodePtr->right)

            destroySubTree(nodePtr->right);

        delete nodePtr;
    }
}


