#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree = 0; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  Vertex(T l) : label(l) {top_num = 0;} //Part 1
  // You may include default constructor optionally.
  Vertex(){
    top_num = 0;
  }
};

// optional, but probably helpful
// template <class T>
// ostream& operator<<(ostream &o, Vertex<T> v){};

// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor follows
// Refer the instructions PDF last section for more information

template<class T>
class VertexCompare
{
public:
  bool operator()(Vertex<T> v1, Vertex<T> v2){
    //todo - implement here

    return v1.top_num > v2.top_num;
  }
};

template <class T>
class Graph {
private:
  //c++ stl hash table
  std::unordered_map<T, Vertex<T> > node_set;
  int size_of_graph = 0;
  vector<T> sorted_nodes;
  std::priority_queue< Vertex<T>,vector<Vertex<T> >, VertexCompare<T> > min_queue;
  // alternatively:
  //c++ balanced binary tree (probably red-black but may be compiler dependent)
  // std::map<T, Vertex<T> > node_set;
  //  using this may negatively impact your runtime

  //Use other data fields if needed
public:
  Graph() {};  //No modification needed to default constructor. Can be used optionally if needed.
  ~Graph() {}; //No modification needed to destructor. Can be used optionally if needed.

  // build a graph - refer the instructions PDF for more information.
  void buildGraph(istream &input){
    string line;
    while(getline(input, line)){
      stringstream ss(line);
      // vector<T> local_list;
      Vertex<T> local_vertex;
      T var;
      
      ss >> var;
      T label = var;
      local_vertex.label = var;
      while (ss >> var) local_vertex.adj_list.push_back(var);
      
      // local_vertex.adj_list = local_list;
      node_set[label] = local_vertex;
      size_of_graph++;
    }
    
  }

  // display the graph into o - refer the instructions PDF for more information.
  void displayGraph(ostream& o){
    for(auto &v : node_set){
      int size = v.second.adj_list.size();
      o << v.second.label << ": ";
      for(int i = 0; i < size;i++){
        o << (v.second.adj_list)[i] << ' ';
      }
      o << endl;
    }
    
  }

  vector<T> tester(){
    return sorted_nodes;
  }

  //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
  Vertex<T> at(T label){
    return node_set.at(label);
  }

  //return the graph size (number of verticies)
  int size(void){
    return size_of_graph;
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(void){
    queue<Vertex<T> > v_q;
    // this->displayGraph(cout);
    // this->compute_indegree();
    int counter = 0;
    cout << "before loop top sort" << endl;
    for(auto &v : node_set){
      if(v.second.indegree == 0){
        v_q.push(v.second);
        cout << "top queue pusher" << endl;
        sorted_nodes.push_back(v.second.label);
        // min_queue.push(v.second);
        //cout << v.second.label << "here" << endl;
      }
    }
    while(!v_q.empty()){
      cout << "top queue popper" << endl;
      Vertex<T> ver_loc = v_q.front();
      v_q.pop();
      ver_loc.top_num = counter;
      counter++;
      node_set.at(ver_loc.label) = ver_loc;
      for(int i = 0; i < ver_loc.adj_list.size();i++){
        Vertex<T> vertex_ = node_set.at(ver_loc.adj_list[i]);
        vertex_.indegree--;
        node_set.at(ver_loc.adj_list[i]) = vertex_;
        if(vertex_.indegree == 0){
          v_q.push(node_set.at(ver_loc.adj_list[i]));
          // min_queue.push(node_set.at(ver_loc.adj_list[i]));
          sorted_nodes.push_back(ver_loc.adj_list[i]);
        }
      }

    }
    
    cout << "completed sort" << endl;
    return counter == size_of_graph;
  }; // Part 2

  // find indegree
  void compute_indegree(void){
    // for(auto &v : node_set){
    //   v.second.indegree = 0;
    // }
    cout << "before loop indegree" << endl;
    for(auto &v : node_set){
      // cout << "indegree loop" << endl;
      for(int i = 0; i < v.second.adj_list.size();i++){
        Vertex<T> vertex_ = node_set.at(v.second.adj_list[i]);
        vertex_.indegree++;
        node_set.at(v.second.adj_list[i]) = vertex_;
      }
    }
    cout << "completed indegree" << endl;
  }; // Part 2


  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true)
  { 
    //TODO - implement things here
    // for(auto &v : node_set){
    //   min_queue.push(v.second);
    // }
    // while(!min_queue.empty()){
    //   o << min_queue.top().label << " ";
    //   min_queue.pop();
    // }
    // if(addNewline){o << '\n';}
    for(int i = 0; i < sorted_nodes.size();i++){
      o << sorted_nodes[i] << " ";
    }
    if(addNewline){o << '\n';};
  }; // Part 2
};

#endif
