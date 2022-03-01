#include "BSTree.h"

#include <iostream>
#include <exception>
#include <queue>
#include <vector>
#include <string> 



using namespace std;
using std::invalid_argument;
using std::queue;
///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 


// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
// If you try to use it without care, you will get a memory leak.
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}


void BSTree::clear_helper(Node* node){//destructor helper and clear function 
  //Don't delete if the node is nullptr
  if(node == nullptr)
  {
    return;
  }
  if (node->left != nullptr){
    clear_helper(node->left);
  }
  if (node->right != nullptr){
    clear_helper(node->right);
  }
  //cout<<"clearing"<<endl;
  //int value = node->value;
  delete node;
  //cout<<"deleted node with value :" << value <<endl;
}


// Recursive function to insert a key into a BST
//void BSTree::insert_helper(Node* newNode,Node* sourceNode ,int num, int depth)
Node* BSTree::insert_helper(Node* newNode, Node* sourceNode, int x)
{
  // static int comps = 1;
  // if(size == 0){
  //   root = newNode;
  //   root->search_time = 1;
  //   size++;
  //   return;
  // }
  // if ((sourceNode == nullptr)){
  //   sourceNode = newNode;
  //   sourceNode->search_time = comps;
  //   cout << sourceNode->value << endl;
  //   size++;
  //   return;
  // }
  // else if (x < sourceNode->value){
  //   comps++;
  //   // sourceNode = sourceNode->left;
  //   insert_helper(newNode,sourceNode->left, x);
  // }
  // else if (x > sourceNode->value){
  //   comps++;
  //   //sourceNode = sourceNode->right;
  //   insert_helper(newNode,sourceNode->right, x);
  // }
  
  // comps = 1;
  static int comps = 1;
  
  if (sourceNode == nullptr){
    sourceNode = newNode;
    
    if(size == 0){
      root = sourceNode;
      root->search_time = 1;
    }
    size++;
    sourceNode->search_time = comps;
    comps = 1;

  }
  if (x < sourceNode->value){
    comps++;
    sourceNode->left = insert_helper(newNode, sourceNode->left,x);
  }
  else if (x > sourceNode->value){
    comps++;
    sourceNode->right = insert_helper(newNode, sourceNode->right,x);
  }
  
  return sourceNode;
  
  
    
}

void BSTree::inorder_helper(Node* node, ostream& out){
  if (node->left != nullptr)
    inorder_helper(node->left, out);
  out << node->value << "[" << node->search_time << "]" << " ";
  if(node->right != nullptr)
    inorder_helper(node->right, out);
} 

// recursive function
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}

void BSTree::update_search_times_helper( Node* node, int depth){
    if(node) {
        update_search_times_helper(node->right, depth + 1);
        node->search_time=depth;
        update_search_times_helper(node->left, depth + 1);
    }
}

void BSTree::depth_helper( Node* node, int depth, int &save_value){
    static int max = 0;
    if(node) {
        depth_helper(node->right, depth + 1, save_value);
        //node->search_time=depth;
        if(depth > max){
          max = depth;
        }
        save_value = max;
        depth_helper(node->left, depth + 1, save_value);
    }
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other)
{ 
  if(other.root == nullptr){
    root = nullptr;
    size = 0;
    
  }
  else{
    Node* newNode;
    copy_helper(newNode,other.root);
    root = newNode;
    size = other.size;

  }
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
  root = other.root;
  size = other.size;
  other.root = nullptr;
  other.size = 0;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  if(other.root == root){
    return *this;
  }
  if(other.root == nullptr){
    clear_helper(root);
    root = nullptr;
    size = 0;
    return *this;
  }
  clear_helper(root);
  size = 0;
  root = nullptr;

  
  copy_helper(root, other.get_root());
  size = other.size;
  return *this;
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other)
{
  if(this == &other){
    return *this;
  }
  if(other.root == nullptr){
    clear_helper(root);
    root = nullptr;
    size = 0;
    return *this;
  }
  clear_helper(root);
  this->size = 0;
  this->root = nullptr;
  root = other.root;
  size = other.size;
  other.root = nullptr;
  other.size = 0;
  return *this;
}

void BSTree::clear(){
  clear_helper(root);
    size = 0;
    root = nullptr;
}

// destructor
BSTree::~BSTree()
{
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
    clear_helper(root);
    size = 0;
    root = nullptr;
}

Node* BSTree::insert(int obj)
{
  /* insert a node into the tree
  first find where the node should go
  then modify pointers to connect your new node */
  // Node* return_value = nullptr; 
  //insert_helper(obj, root, return_value);
  //return return_value;
  Node* newNode = new Node(obj);
  insert_helper(newNode, root, obj);
  return newNode;
  
}

Node* BSTree::search(int obj)
{
    /* recursively search down the tree to find the node that contains obj
    if you don't find anything return nullptr */
  Node* node = root;
  while (node != nullptr){
    if (obj < node->value){ node = node->left;}
    else if (obj > node->value){ node = node->right;}
    else if (obj == node->value){return node;}
    // else{ return nullptr;} //found
  }
  //throw invalid_argument("not found");
  return nullptr;//not found so nullptr is returned 
}
int BSTree::depth(){
  int save = 0;
  depth_helper(root,1,save);
  return save;
}


void BSTree::update_search_times()
{
    /* do a BFS or DFS of your tree and update the search times of all nodes at once
      The root has a search time of 1, and each child is 1 more than its parent */
      update_search_times_helper(root,1);
}

void BSTree::inorder(ostream& out)
{
    /* print your nodes in infix order
    If our tree looks like this:

       4
     2   6
    1 3 5 7

    It should output:
    1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]
    You can use the << operator to print the nodes in the format shown */
    inorder_helper(root, out);


}

void BSTree::print_level_by_level(ostream& out)
{
    /* Print the tree using a BFS so that each level contains the values for a level of the tree.
    Use X to mark empty positions. 
    
      if our tree looks like this:

       4
     2   6
    1   5 7


    it should output:

    4[1]
    2[2] 6[2]
    1[3] X 5[3] 7[3]

    it might be helpful to do this part with the std::queue data structure.
    Hint: the Nth level contains 2^(N-1) nodes (with a value or with an X). Watch out
    for nodes like the left child of 6 above, and print the descendents of an empty
    node as also empty
    You can use the << operator to print nodes in the format shown */
    int num_of_qs = this->depth();
    vector<queue<string>> vector_q; // vector of queues
    vector<vector<Node*>> vector_n;
  // vec.push_back(queue<int>()); // add a queue
  // vec[0].push(1); // push 1 into queue number 0.
  if(root){
      for(int i = 0; i < num_of_qs;i++){
      vector_q.push_back(queue<string>());
      vector_n.push_back(vector<Node*>());
    }
    // vector_q[0].push(to_string(root->value) + "[" + to_string(1) + "]");//first q
    vector_n[0].push_back(root);
    int leaves = 1;
    // int num = 0;
    for(int i = 1; i < (num_of_qs);i++){
      for(int j = 0; j < leaves; j++){
        if(vector_n[i-1][j] == nullptr){
          //out << " null subchild case" << endl;
          vector_n[i].push_back(nullptr);
          vector_n[i].push_back(nullptr);
          // num++;
          // num++;
          continue;
        }
        else{
          Node* right = vector_n[i-1][j]->right; 
          
          Node* left =  vector_n[i-1][j]->left;
          // out << vector_n[i-1][j]->left << endl;
          // out << vector_n[i-1][j]->right << endl;
          vector_n[i].push_back(left);
          vector_n[i].push_back(right);
          // num++;
          // num++;
        }
        // else if(vector_n[i-1][j]->left == nullptr){
        //   vector_n[i].push_back(nullptr);
        //   if(vector_n[i-1][j]->right == nullptr){
        //     vector_n[i].push_back(nullptr);
        //   }
        //   else{

        //     vector_n[i].push_back(vector_n[i-1][j]->right);
        //   }
        //   continue;
        // }
          

        
      }
      // out << endl;

      leaves *= 2;
    }
    // out << (num + 1) << endl;
    // out << vector_n[2][0]<< " " << vector_n[2][1]<< " " <<vector_n[2][2]<< " " <<vector_n[2][3] <<endl;
    leaves = 1;
    for(int i = 0; i < (num_of_qs);i++){
      for(int j = 0; j < leaves; j++){
        string value;
        string search;
        if(vector_n[i][j] == nullptr){
          
          value = "X ";
        }
        else{
          
          value = to_string(vector_n[i][j]->value);
        }
        if(value == "X "){
          search = "";

        }
        else{
          search = "[" + to_string(vector_n[i][j]->search_time) + "] ";
        }
        vector_q[i].push(value + search);
        
      }
      leaves *= 2;
    }
    for(int i = 0; i < num_of_qs;i++){
      while(!vector_q[i].empty()){
        out << vector_q[i].front();
        vector_q[i].pop();
      }
      out << endl;
    }
  }
  else{
    out << "X" << endl;
  }
   //root only edge case


}

void BSTree::inorder_counter(Node* node, int &counter){
  if (node->left != nullptr)
    inorder_counter(node->left, counter);
  counter++;
  if(node->right != nullptr)
    inorder_counter(node->right, counter);
} 

void BSTree::counter(){
  int counter = 0;
  inorder_counter(root, counter);
  cout << counter << endl;
} 


void BSTree::inorder_counter2(Node* node, int &counter){
  if (node->left != nullptr)
    inorder_counter2(node->left, counter);
  if((node->right != nullptr)&&(node->left != nullptr)){
    counter++;
  }
  if(node->right != nullptr)
    inorder_counter2(node->right, counter);
} 

int BSTree::counter2(){
    if(root == nullptr){
        return 0;
    }
    int counter = 0;
    inorder_counter2(root, counter);
    return counter;
} 

