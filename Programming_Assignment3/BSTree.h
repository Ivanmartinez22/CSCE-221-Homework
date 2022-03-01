#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;
struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_time; //see the problem description

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_time(0) {}
};

struct BSTree
{
public:
  BSTree();
  BSTree(const BSTree& other);
  // move constructor
  BSTree(BSTree&& other);
  // copy assignment
  BSTree& operator=(const BSTree& other);
  // move assignment
  BSTree& operator=(BSTree&& other);
  ~BSTree();
  inline const Node* get_root() const { return root; }
  inline const int get_size() const { return size; }
  Node* insert(int obj);
  Node* search(int obj);
  void update_search_times();
  float get_average_search_time();
  void inorder(std::ostream& out);
  void print_level_by_level(std::ostream& out);
  void clear_helper(Node* node);
  Node* insert_helper(Node* newNode, Node* sourceNode, int x);
  // Node* insert_helper(Node* node, int x);
  void inorder_helper(Node* node, ostream& out);
  void update_search_times_helper(Node* node, int depth);
  void clear();
  void depth_helper( Node* node, int depth, int &save_value);
  int depth();
  void inorder_counter(Node* node, int &counter);
  void counter();
  void inorder_counter2(Node* node, int &counter);
  int counter2();
  //int size_helper(Node*t);
  //Node* search_helper(int x,Node*node);
  std::ostream& print(std::ostream& o=std::cout) const {
    return print_helper(o, root, 0);
  }

private:
  int size;
  Node* root;
  std::ostream& print_helper(std::ostream& o, Node* node, int depth) const {
    if(node) {
        print_helper(o, node->right, depth + 1);
        for(int i = 0; i < depth; ++i) o << '\t';
        o << node->value <<"[" << (depth + 1) << "]" << "[" << node->search_time << "]"<<'\n';
        print_helper(o, node->left, depth + 1);
    }
    return o;
  }
  int get_total_search_time(Node* node);
  // you can add recursive helper functions to help you
  // this is one is implemented for you:
  void copy_helper(Node*& newNode, const Node* sourceNode);

};

// print a node
std::ostream& operator<<(std::ostream& out, Node& node);

// print a BSTree
std::ostream& operator<<(std::ostream& out, BSTree& tree);

// read in a tree from a file
std::istream& operator>>(std::istream& in, BSTree& tree);


#endif