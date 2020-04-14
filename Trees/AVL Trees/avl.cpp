#include<iostream>
template<class T>
class Avl
{
private:
    struct node{
        T item;
        node *left;
        node *right;

        int height;    // height of nodes


    };

   node *root;   // root/head node

   int nodecount = 0;


node* insert(node *&nodeptr, node *&newnode)
   {
       if (nodeptr == nullptr)                //if no nodes exist
       {
            nodeptr = newnode;               // Insert the node as root//
       }

       else if (newnode->item < nodeptr->item )              // Search the left branch
       {

           insert(nodeptr->left, newnode);

           if(height(nodeptr->left) - height(nodeptr->right) >= 2)   //if balance factor is greater than 2

            {

               if(newnode->item < nodeptr->left->item)    //check where the new item belongs to decide rotation

                    nodeptr = singleRightRotate(nodeptr);
               else
                    nodeptr = RightLeftRotate(nodeptr);
             }
           }

       else if (newnode->item >= nodeptr->item )        // Search the right branch, less than or equal to for same items
       {

           insert(nodeptr->right, newnode); // Search the right branch


           if(height(nodeptr->right) - height(nodeptr->left) >= 2)

            {

               if(newnode->item <= nodeptr->right->item) //check where the new item belongs to decide rotation

                    nodeptr = singleLeftRotate(nodeptr);
               else
                    nodeptr = LeftRightRotate(nodeptr);
             }

       }

       nodeptr->height =std::max(height(nodeptr->left), height(nodeptr->right))+1;   //assign maximum height

              return nodeptr;
   }



node* singleRightRotate(node* &nodeptr)  //right-right rotation
    {
        node* newnode = nodeptr->left;

        nodeptr->left = newnode->right;

        newnode->right = nodeptr;  //swap left and right node

        nodeptr->height = std::max(height(nodeptr->left), height(nodeptr->right))+1;  //update node height

        newnode->height = std::max(height(newnode->left), nodeptr->height)+1;   //update node height

        return newnode;
    }

node* singleLeftRotate(node* &nodeptr)    //left-left rotation
    {
        node* newnode = nodeptr->right;

        nodeptr->right = newnode->left;

        newnode->left = nodeptr;         //swap left and right node

        nodeptr->height = std::max(height(nodeptr->left), height(nodeptr->right))+1;   //update node height

        newnode->height = std::max(height(nodeptr->right), nodeptr->height)+1 ;    //update node height

        return  newnode;
    }

node* LeftRightRotate(node* &nodeptr)
    {
        nodeptr->right = singleRightRotate(nodeptr->right);

        return singleLeftRotate(nodeptr);
    }


node* RightLeftRotate(node* &nodeptr)
    {
        nodeptr->left = singleLeftRotate(nodeptr->left);

        return singleRightRotate(nodeptr);
    }


int height(node* nodeptr)
   {
       return (nodeptr == nullptr ? -1 : nodeptr->height);
   }


int getBalance(node* nodeptr)
    {
        if(nodeptr == nullptr)
            return 0;
        else
            return height(nodeptr->left) - height(nodeptr->right);
    }


void inorder(node* nodeptr)               //inorder transversal
    {
        if(nodeptr == nullptr)
            return;
        inorder(nodeptr->left);

       std::cout << nodeptr->item << std::endl;

        inorder(nodeptr->right);
    }


node* getMin(node* nodeptr)
    {
        if(nodeptr == nullptr)

            return nullptr;
        else if(nodeptr->left == nullptr)

            return nodeptr;
        else
            return getMin(nodeptr->left);
    }


node* getMax(node* nodeptr)
    {
        if(nodeptr == nullptr)

            return nullptr;

        else if(nodeptr->right == nullptr)

            return nodeptr;
        else
            return getMax(nodeptr->right);
    }





node* remove(T num, node* nodeptr)
    {
        node* temp;


        if(nodeptr == nullptr)     // no root
        {
            return nullptr;
        } else if( num < nodeptr->item)   // Searching for element
        {
             nodeptr->left = remove(num , nodeptr->left);

        }  else if(num > nodeptr->item)
        {
             nodeptr->right = remove(num , nodeptr->right);
        }
        else if(nodeptr->left && nodeptr->right)
        {
            temp = getMin(nodeptr->right);

            nodeptr->item = temp->item;

            nodeptr->right = remove(num, nodeptr->right);
        }
        // With one or zero child
        else
        {
            temp = nodeptr;

            if(nodeptr->left == nullptr)

                nodeptr = nodeptr->right;

            else if(nodeptr->right == nullptr)

                nodeptr = nodeptr->left;
            delete temp;
        }
        if(nodeptr == nullptr)
            return nodeptr;

        nodeptr->height = std::max(height(nodeptr->left), height(nodeptr->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(nodeptr->left) - height(nodeptr->right) == 2)
        {

            if(height(nodeptr->left->left) - height(nodeptr->left->right) == 1)   // right right case

                return singleLeftRotate(nodeptr);

            else    // right left case

                return LeftRightRotate(nodeptr);
        }

        else if(height(nodeptr->right) - height(nodeptr->left) == 2)   // If right node is deleted, left case
        {

            if(height(nodeptr->right->right) - height(nodeptr->right->left) == 1)  // left left case

                return singleRightRotate(nodeptr);

            else    // left right case

                return RightLeftRotate(nodeptr);
        }
        return nodeptr;
    }



void Empty(node* nodeptr)
    {
        if(nodeptr == nullptr)

            return;
        else {
            Empty(nodeptr->left);

            Empty(nodeptr->right);

            delete nodeptr;
        }

    }

public:


Avl()
{
    root = nullptr;
}


void insert(T num)
{
    node *newNode = nullptr;  // Pointer to a new node

    newNode = new node;

    newNode->item = num;

    newNode->left = newNode->right = nullptr;

   root = insert(root, newNode);

    nodecount++;
}


void display()
    {
        inorder(root);
        std::cout << std::endl;
    }


bool search(T item)     //serach if a item exists in a tree
{
    node *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->item == item)

            return true;

        else if (item < nodePtr->item)

            nodePtr = nodePtr->left;

        else

            nodePtr = nodePtr->right;
    }

    return false;
}

void remove(T num)
{
    node *newnode = nullptr;  // Pointer to a new node

    newnode = new node;

    newnode->item = num;

    newnode->left = newnode->right = nullptr;

    root = remove(num, root);
}





~Avl()
{
Empty(root);
}
  };
