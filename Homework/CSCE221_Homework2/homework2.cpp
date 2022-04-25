#include <iostream>
#include <vector>
#include <math.h>
#include <vector>
#include "homework2.h"


using namespace std;
using std::vector;
using std::cout;
using std::endl;
// Question 1 Declarations 
#include <list>
void printList(list<int> in)
{
    list<int> :: iterator i;
    for(i = in.begin(); i != in.end(); ++i)
        cout << '\t' << *i;
    cout << '\n';
}


std::list<int> intersection ( const std:: list<int> & l1 , const std::list<int> & l2) {
// i n s e r t code h e r e
    list<int> l1c = l1; //1 operation 
    list<int> l2c = l2; //1 operation
    list<int> return_value;
    if(l1.empty()){
        return return_value; // 1 operation
    }
    if(l2.empty()){
        return return_value; // 1 operation 
    }
    list<int> :: iterator i = l1c.begin(); 
    list<int> :: iterator j = l2c.begin();
    while((i != l1c.end()) && (j != l2c.end())){
        if(*i > *j){
            ++j;

        }
        else if(*i < *j){
            ++i;
        }
        else if(*i == *j){
            return_value.push_back(*i);
            ++j;
            ++i;
        }

    }
    // for(i = l1c.begin(); i != l1c.end(); ++i){ //i iterations 
    //     for(j = l2c.begin(); j != l2c.end(); ++j){//j iterations 
    //         if(*i == *j){
    //             return_value.push_back(*i); // 1 operation
    //         }
    //     }
    // }
    //running time function f(n) = n^2 + 4
    //Big O(n^2)
    return return_value;
}

// Quiestion 2
//Make into templated 
//Solve recurrence relation
//template<typename T> 
// struct Node {
//     int obj;
//     Node *next;
//     // constructor
//     Node(int obj, Node* next = nullptr): obj(obj),next(next){}
// };
// template<typename T> 
// int count_nodes(Node* node, int &num_nodes){
//     if(node == nullptr){//base case
//     //Non recursive
//         return 0;
//     }
//     if(num_nodes == 0){ //count first node
//     //Non recursive 
//         if(node != nullptr){
//             num_nodes++;
//         }
//     }
//     if(node->next != nullptr){ // Recursive case 
//     //Recursive case is executed T(n-1) times 
//         num_nodes++;
//         count_nodes(node->next, num_nodes);
//     }
//     return num_nodes;
// }

//Question 3
//No static version
int find_max_value(int &max, int current, vector<int> int_vec){
    int max_index = int_vec.size() - 1;
    int value = int_vec.at(current);
    if((max_index + 1) == 1){ //Base case
        max = value;
        return max; //Returns value at vec[0]
    }
    if(value > max){ // changes max
        max = value;
    }
    if(current != max_index){ // Recursive case
        find_max_value(max, current + 1, int_vec);
    }
    return max; //End returns max value
}
//Static version
// int find_max_value(int &max, vector<int> int_vec){
//     int max_index = int_vec.size() - 1;
//     static int current = 0;
//     // cout << vec_size << endl;
    
//     int value = int_vec.at(current);
//     if((max_index + 1) == 1){
//         max = value;
//         return max;
//     }
//     if(value > max){
//         max = value;
//     //    cout << current<<"here" << " " << max << endl;
//     }
//     if(current != max_index){
//         current++;
//         find_max_value(max, int_vec);
//     }
//     // int return_value = max;
//     current = 0;
//     return max;
// }

//Question 5

//template<typename T> 
// struct Node {
//     int obj;
//     Node *left, *right;
//     // constructor
//     Node(int obj, Node* left = nullptr, Node* right = nullptr): obj(obj),left(left),right(right)
//     {}
// };

//Template function and create driver code
//Already tested on binary search tree assignment works 

// void inorder_counter(const Node* node, int &counter){
//   if (node->left != nullptr)//Recursive portion/sub problem
//     inorder_counter(node->left, counter);
//   if((node->right != nullptr)&&(node->left != nullptr)){ // Processing node not recursive
//     counter++;
//   }
//   if(node->right != nullptr) //Recursive portion/sub problem
//     inorder_counter(node->right, counter);
// } 

// int counter(const Node* node){
//     if(node == nullptr){ // Base case time of 1
//         return 0;
//     }
//     int counter = 0;
//     inorder_counter(node, counter);//Calls recursive helper
//     return counter;
// } 

//T(n) = T(n-1) + 1



int main(){
    //Question 1 driver code 
    // list<int> l1i;
    // list<int> l2i;
    // list<int> l1j;
    // list<int> l2j;
    // list<int> empty;
    // //Test Case 1 
    // l1i.push_back(1);
    // l1i.push_back(2);
    // l1i.push_back(3);
    // l1i.push_back(4);
    // l2i.push_back(2);
    // l2i.push_back(3);
    // list<int> printthis = intersection(l1i,l2i);
    // printList(printthis);
    // //Test Case 2
    // printthis = intersection(empty,l2i);
    // printList(printthis);


    // //Test Case 3 
    // l1j.push_back(2);
    // l1j.push_back(9);
    // l2j.push_back(14);

    // l2j.push_back(1);
    // l2j.push_back(7);
    // l2j.push_back(15);
    // printthis = intersection(l1j,l2j);
    // printList(printthis);

    //Driver code for question 2
    
    // Node<int> first = Node<int>(1);
    // Node<int> first = Node<int>(2);
    // Node<int> second = Node<int>(4);
    // Node<int> third = Node<int>(3);
    
    // first.next = &second;
    // second.next = &third;
    // int counter = 0;
    // cout << count_nodes(&first, counter) << endl;
    // //Empty list case
    // Node<int>* ptr = nullptr;
    // counter = 0;
    // cout << count_nodes(ptr, counter) << endl;

    //Driver Code for Question 3

    vector<int> myvec;
    myvec.push_back(11);
    myvec.push_back(0);
    myvec.push_back(9);
    myvec.push_back(2);
    myvec.push_back(3);
    myvec.push_back(8);
    myvec.push_back(10);
    int max = 0;
    cout << find_max_value(max,0,myvec) << endl;
    // cout << find_max_value(max,myvec) << endl;
    // cout << max << endl;
    max = 0;
    vector<int> myvec2;
    myvec2.push_back(1);
    myvec2.push_back(0);
    myvec2.push_back(2);
    myvec2.push_back(2);
    myvec2.push_back(3);
    myvec2.push_back(8);
    myvec2.push_back(5);
    cout << find_max_value(max,0,myvec2) << endl;
    // cout << find_max_value(max,myvec2) << endl;
    // cout << max << endl;
    max = 0;
    vector<int> myvec3;
    myvec3.push_back(1);
    cout << find_max_value(max,0,myvec3) << endl;
}

