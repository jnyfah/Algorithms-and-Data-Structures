#include <iostream>
#include <queue>
template <class T>


class BST{
    public:

    // Constructor
    BST()
    {
        root = nullptr;
    }

    // Binary tree operations
    void insert(T value){
         node *newnode = makenode(value);
         insertNode(root, newnode);
    }

    bool searchNode(T value) {
        node* nodeptr = root;
        while(nodeptr){
            if(nodeptr->value == value) {
                return true;
            } else if(nodeptr->value <= value){
                nodeptr = nodeptr->left;
            }else {
                nodeptr = nodeptr->right;
            }
        }
    }

    void remove(T value){
        deleteNode(value, root);
    }

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

   void levelOrder() const{
       BFS(root);
   }

   // Destructor
  /* ~BST()
   {

       destroySubTree(root);
   }*/


/* Private Functions*/

    private:

      struct node{
        T value;
        node *left;
        node *right;
      };

      node *root; // Pointer to the root node

    // Private member functions

    node* makenode(T value){
        node *nodeptr = new node;
        nodeptr->value = value;
        nodeptr->left = nodeptr->right = nullptr;

        return nodeptr;
    }

    void insertNode(node *&nodeptr, node *&newnode){
        if(nodeptr == nullptr){
            nodeptr = newnode;
        }else if(newnode->value <= nodeptr->value){
            insertNode(nodeptr->left, newnode);
        }else{
            insertNode(nodeptr->right, newnode);
        }
    }

    void destroySubTree(node *);

    void deleteNode(T value, node *&nodeptr) {  //find node
          if(value < nodeptr->value) {
              deleteNode(value, nodeptr->left);
          }else if(value > nodeptr->value) {
              deleteNode(value, nodeptr->right);
          }else{
              makeDeletion(nodeptr);
          }
        
    }
    void makeDeletion(node *&nodeptr){
        node *temp = nullptr;
        if(nodeptr == nullptr){
            //cannot delete
        }else if(nodeptr->left == nullptr){
            temp = nodeptr;
            nodeptr = nodeptr->right;
            delete temp;
        }else if(nodeptr->right == nullptr){
            temp = nodeptr;
            nodeptr = nodeptr->left;
            delete temp;
        }else{
            temp = nodeptr->right;
            while(temp->left){
                temp = temp->left;
            }
            temp->left = nodeptr->left;
            temp = nodeptr;
            nodeptr= nodeptr->right;
        }
    }
    void displayInOrder(node *nodeptr) const {
        if(nodeptr){
            displayInOrder(nodeptr->left);
            std::cout<<nodeptr->value<<std::endl;
            displayInOrder(nodeptr->right);
        }

    }
    void displayPreOrder(node *nodeptr) const{
          if(nodeptr){
              std::cout<<nodeptr->value <<std::endl;
              displayPreOrder(nodeptr->left);
              displayPreOrder(nodeptr->right);  
          }     
    }
    void displayPostOrder(node *nodeptr) const {
        if(nodeptr){
            displayPostOrder(nodeptr->left);
            displayPostOrder(nodeptr->right);
            std::cout<<nodeptr->value;
        }
    }

    void BFS(node* nodeptr) const{
       if(nodeptr == nullptr) {
           return;
       }

       std::queue<node*>Q;
       Q.push(nodeptr);

       while(!Q.empty()){
           node *current = Q.front();
           std::cout<<current->value<< " ";
           if(current->left != nullptr) {
               Q.push(current->left);
           }
           if(current->right != nullptr) {
               Q.push(current->right);
           }
           Q.pop();
       }
   }

};

int main() {
  BST<int>btree;
  btree.insert(5);
  btree.insert(3);
  btree.insert(6);
  btree.insert(9);
  btree.insert(1);
  btree.remove(3);
  btree.levelOrder();
}
