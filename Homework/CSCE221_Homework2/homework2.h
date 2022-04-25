#ifndef HOMEWORK2_H
#define HOMEWORK2_H
// Quiestion 2
//Make into templated 
//Solve recurrence relation
template<typename T> 
struct Node {
    T obj;
    Node *next;
    // constructor
    Node(T obj, Node* next = nullptr): obj(obj),next(next){}
};
template<typename T> 
int count_nodes(Node<T>* node, int &num_nodes){
    if(node == nullptr){//base case
    //Non recursive
        return 0;
    }
    if(num_nodes == 0){ //count first node
    //Non recursive 
        if(node != nullptr){
            num_nodes++;
        }
    }
    if(node->next != nullptr){ // Recursive case 
    //Recursive case is executed T(n-1) times 
        num_nodes++;
        count_nodes(node->next, num_nodes);
    }
    return num_nodes;
}

//Question 5

// template<typename T> 
// struct Node {
//     T obj;
//     Node *left, *right;
//     // constructor
//     Node(T obj, Node* left = nullptr, Node* right = nullptr): obj(obj),left(left),right(right)
//     {}
// };

// //Template function and create driver code
// //Already tested on binary search tree assignment works 
// template<typename T> 
// void inorder_counter(const Node<T>* node, int &counter){
//   if (node->left != nullptr)//Recursive portion/sub problem
//     inorder_counter(node->left, counter);
//   if((node->right != nullptr)&&(node->left != nullptr)){ // Processing node not recursive
//     counter++;
//   }
//   if(node->right != nullptr) //Recursive portion/sub problem
//     inorder_counter(node->right, counter);
// } 


// template<typename T> 
// int counter_nodes(const Node<T>* node){
//     if(node == nullptr){ // Base case time of 1
//         return 0;
//     }
//     int counter = 0;
//     inorder_counter(node, counter);//Calls recursive helper
//     return counter;
// } 


#endif

