#include <iostream>
#include "BSTree.h"
using std::cout;
using std::endl;
#include <set>


int main(){
    BSTree tree1;
    // /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    // Use X to mark empty positions. 
    
    //   if our tree looks like this:

    //    4
    //  2   6
    // 1   5 7


    // it should output:

    // 4[1]
    // 2[2] 6[2]
    // 1[3] X 5[3] 7[3]

    // it might be helpful to do this part with the std::queue data structure.
    // Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    // for nodes like the left child of 6 above, and print the descendents of an empty
    // node as also empty
    // You can use the << operator to print nodes in the format shown */
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
    // tree1.insert(5);
    // tree1.insert(9);
    // tree1.insert(7);
    // tree1.insert(10);
    //cout << tree1.depth() << endl;
    tree1.print_level_by_level(cout);
    // int counter = 0;
    cout << tree1.get_average_search_time() << endl;



    
}

// tree1.insert(4);
    // cout << "-----------------" << endl;
    // tree1.insert(3);
    // cout << "-----------------" << endl;
    // tree1.insert(2);
    // cout << "-----------------" << endl;
    // tree1.insert(5);
    // cout << "-----------------" << endl;
    // tree1.insert(6);
    // cout << "-----------------" << endl;
    // cout << "size should be 5 is: "<<endl;
    // cout << tree1.get_size() << endl;
    // BSTree tree2;
    // tree2 = tree1;
    // cout << "-------------------------------------" << endl;
    // cout << "tree1 print out: " << endl;
    // tree1.print();
    // cout << "-------------------------------------" << endl;
    // cout << "tree2 print out should match tree1" << endl;
    // cout << "copy constructor test" << endl;
    // tree2.print();
    // cout << "-------------------------------------" << endl;
    // cout << "tree2 clearing" << endl;
    // tree2.~BSTree();
    // cout << "tree2 size" << endl;
    // cout << tree2.get_size() << endl;
    // const Node* test = tree2.get_root();
    // bool testb = (test == nullptr);
    // cout << "bool value" << endl;
    // cout << testb << endl;

    // tree2.print();
    // cout << "-------------------------------------" << endl;
    // cout << "tree2 insert 8 9 3 2 1" << endl;
    // tree2.insert(8);
    // tree2.insert(9);
    // tree2.insert(3);
    // tree2.insert(2);
    // tree2.insert(1);
    // tree2.print();
    // cout << "-------------------------------------" << endl;
    // cout << "copy assignment test" << endl;
    // cout << "tree1 = tree2" << endl;
    // tree1 = tree2;
    // tree1.print();
    // cout << "-------------------------------------" << endl;
    // tree1.insert(4);
    // tree1.insert(10);
    // tree1.insert(11);
    // tree1.update_search_times();
    // tree1.print();
    // tree1.clear();
    // cout << "-------------------------------------" << endl;
    // tree1.print();
    // cout << "-------------------------------------" << endl;
    // std::set<int> set;

    // srand(time(NULL));

    // for (int i = 0; i < 10; i++) {
    //     int num = rand() % 10000;
    //     if (set.count(num) == 0) {
    //         set.insert(num);
    //         //cout << num << endl;
    //         auto ptr = tree1.insert(num);
    //         if(ptr->value != num){
    //             cout << "mismatch !!!!! " << endl;
    //             cout<< " ptrvalue: " << ptr->value << " num: "<< num << endl;
    //         }
    //         // ASSERT_EQ(ptr->value, num);
        
    //     }
    // }
    // tree1.print();


