#ifndef BST_H 
#define BST_H 

#include "../../includes/bst_functions/bst_functions.h"

template <typename T>
class BST{
public:
    BST(){
        _root = NULL; 
        cout<<"constructed tree: \n"; 
        tree_print(_root); 
    }

    BST(const T *sorted_list, int size = -1){
        _root = tree_from_sorted_list(sorted_list, size);
        cout<<"constructed tree from list: \n"; 
        tree_print(_root);  
    }
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    BST(const BST<T> &copy_me){ //don't need to
        _root = tree_copy(copy_me._root); 
        cout<<"constructed tree from copy ctor: \n"; 
        tree_print(_root); 
    } 

    //need to check for self assignment before delete 
    BST<T> &operator=(const BST<T> &rhs){
        if(this == &rhs){
            return *this; 
        }
        delete this; 
        _root = tree_copy(rhs._root);  
        return *this; 
    }

    ~BST(){
        tree_clear(_root); 
        _root = NULL; //doing this just for my peace of mind 
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    void insert(const T &insert_me){
        tree_insert(_root, insert_me); 
    }

    void erase(const T &target){
        bool success = tree_erase(_root, target); 
        cout<<target<<" erased successful: "<<boolalpha<<success<<endl; 
    }

    //const so can't change obj
    bool contains(const T &target)const{
        return tree_search(_root, target); 
    }

    //assuming this just clear again? 
    void clear_all(){
        tree_clear(_root); 
        _root = NULL; //for my sanity
    }

    bool empty()const{
        return (_root == NULL); 
    }
    
    friend ostream &operator<<(ostream &outs, const BST<T> &tree)
    {
        const bool debug = false;
        if (debug){
            cout<<"-------------------------------"<<endl;
            tree_print_debug(tree._root, 0, outs);
            cout<<". . . . . . . . . . . . . . . ."<<endl;
        }
        tree_print(tree._root, 0, outs);
        return outs;
    }

    //assuming this is add?
    BST<T> operator+=(const BST<T> &rhs){
        tree_add(_root, rhs._root); 
        return *this; 
    }

    string pre_order(){
        return pre_order_string(_root); 
    }

    string in_order(){
        return in_order_string(_root); 
    }

    string post_order(){
        return post_order_string(_root); 
    }

private:
    tree_node<T>* _root;
};


#endif 