#ifndef BST_H 
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
        T key;
        // pointers:
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;

    public:
        //constructor:
        BinarySearchTree<T>(T value);


};

template <typename t>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr
}

template <typename T>
void BinarySearchTree<T>::insert(T value){
    if(value < key){
        //do something
        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        }else{
            left->insert(value);
        }
    }
    else if (value > key ){
        if(right == nullptr){
            right = new BinarySearchTree<T>(value);
        }else{
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout<<key"";
    if(left !=nullptr){
        left->preOrder();
}

 
