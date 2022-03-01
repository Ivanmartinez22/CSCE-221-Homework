// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>

using std::cout;
using std::endl;
#include <stdexcept>
using std::invalid_argument;

//Conceptual question 7 singly linked list functions remove first and last should still have constant run times due to no iteration 

// doubly linked list class
template <typename T>
class TemplatedDLList {
public:
// doubly linked list node
  struct DLListNode {
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
  };
private:
  DLListNode header, trailer;
public:
  TemplatedDLList(void); // default constructor  
  TemplatedDLList(const TemplatedDLList<T>& dll); // copy constructor
  TemplatedDLList(TemplatedDLList<T>&& dll); // move constructor
  ~TemplatedDLList(); // destructor
  TemplatedDLList<T>& operator=(const TemplatedDLList<T>& dll); // copy assignment operator
  TemplatedDLList<T>& operator=(TemplatedDLList<T>&& dll); // move assignment operator

  // return the pointer to the first node
  DLListNode *first_node(void) const;

  // return the pointer to the trailer
  const DLListNode *after_last_node(void) const;

  // return true if the list is empty
  bool is_empty(void) const;
  void clear();
  T first(void) const; // return the first object
  T last(void) const; // return the last object
  void insert_first(const T obj); // insert to the first node
  T remove_first(); // remove the first node
  void insert_last(const T obj); // insert to the last node
  T remove_last();
  void insert_after(DLListNode &p, const T obj);
  void insert_before(DLListNode &p, const T obj);
  T remove_after(DLListNode &p);
  T remove_before(DLListNode &p);
  void make_empty(void);
};

// output operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const TemplatedDLList<T>& dll);

template <typename T>
TemplatedDLList<T>::TemplatedDLList(){
    // possibly done 
	header.next = &trailer;
	trailer.prev = &header;
} //O(constant)

template <typename T>
void TemplatedDLList<T>::clear() { //O(n)
	// Implement this function
	DLListNode*prev_node,*node = header.next;
	while (node != &trailer) {
		
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	
	header.next = &trailer;
	trailer.prev = &header;
	
	// probably good
}

template <typename T>
TemplatedDLList<T>::TemplatedDLList(const TemplatedDLList& dll){ // copy constructor 
	header.next = &trailer;
	trailer.prev = &header;
	DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){
		insert_last(traveler->obj);
		traveler = traveler->next;
	}  //O(n)
	
}
template <typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(const TemplatedDLList& dll){ // copy assignment operator
	// cout << "in0" << endl;
	if(dll.header.next == &dll.trailer){ // empty list case
		// check to see if it works 
		//cout << "in0.5" << endl;
		return *this;
	}
	this->clear();//O(n)
	DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){//i iterations 
		this->insert_last(traveler->obj);
		traveler = traveler->next;
	}
	return *this; //O(n + i)
}
template <typename T>
TemplatedDLList<T>::TemplatedDLList(TemplatedDLList&& dll){ // move constructor
	
	header.next = dll.header.next;
	(dll.header.next)->prev = &header;
	(dll.trailer.prev)->next = &trailer;
	trailer.prev = dll.trailer.prev;
	dll.header.next = &dll.trailer;
	dll.trailer.prev = &dll.header; //O(constants)
}
template <typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(TemplatedDLList&& dll){ // move assignment operator

	if(this == &dll){
        return *this;
    }
    this->clear();
	// this->header.next = dll.header.next;
	// this->trailer.prev = dll.header.prev;
	// dll.header.next = &dll.trailer;
	// dll.trailer.prev = &dll.header;
	header.next = dll.header.next;
	(dll.header.next)->prev = &header;
	(dll.trailer.prev)->next = &trailer;
	trailer.prev = dll.trailer.prev;

	dll.header.next = &dll.trailer;
	dll.trailer.prev = &dll.header;
	return *this; //O(n)
}


template <typename T>
typename TemplatedDLList<T>::DLListNode* TemplatedDLList<T>::first_node() const{
	return header.next; //O(1)
}

template <typename T>
const typename TemplatedDLList<T>::DLListNode* TemplatedDLList<T>::after_last_node() const{
	return &trailer; //O(1)
}

template <typename T>
bool TemplatedDLList<T>::is_empty() const{
	bool bool1 = (header.next == &trailer);
	bool bool2 = (trailer.prev == &header);
	if(bool1 && bool2){
		return true;
	}
	else{
		return false;
	} //O(constant)

}
template <typename T>
T TemplatedDLList<T>::first() const{ // return the first object
	if (this->is_empty()){
		throw invalid_argument("Empty Doubly Linked List");
	}
	return header.next->obj; // O(constant)

}

template <typename T>
T TemplatedDLList<T>::last() const{ // return the last object
	if (this->is_empty()){throw invalid_argument("Empty Doubly Linked List");}
	return trailer.prev->obj; //O(constants)
}

template <typename T>
void TemplatedDLList<T>::insert_first(const T obj){
	DLListNode* new_Node = new DLListNode(obj, &header,header.next);
	header.next->prev = new_Node;
	header.next = new_Node; // O(constants)
}

template <typename T>
T TemplatedDLList<T>::remove_first(){
	if(this->is_empty()){
        throw std::invalid_argument("Empty list");
    }
    if(header.next == &trailer){
        throw std::invalid_argument("Deleting trailer");
    }
	T return_value = header.next->obj;
	DLListNode* to_delete =  header.next;
	header.next = to_delete->next;
	header.next->prev = &header;
	delete to_delete;
	return return_value; // O(constants)

}

template <typename T>
void TemplatedDLList<T>::insert_last(const T obj){

	DLListNode* new_Node = new DLListNode(obj,trailer.prev,&trailer);
	trailer.prev->next = new_Node;
	trailer.prev = new_Node;
	//O(constants)

}

template <typename T>
T TemplatedDLList<T>::remove_last(){
	if(this->is_empty()){
        throw std::invalid_argument("Empty list");
    }
    if(trailer.prev == &header){
        throw std::invalid_argument("Deleting trailer");
    }
	T return_value = trailer.prev->obj;
	DLListNode* to_delete =  trailer.prev;
	to_delete->prev->next = &trailer;
	trailer.prev = to_delete->prev;
	delete to_delete;
	return return_value; //O(constant)
}


template <typename T>
void TemplatedDLList<T>::make_empty(void){
	this->clear();//O(n)
}
template <typename T>
void TemplatedDLList<T>::insert_after(DLListNode &p, const T obj){
	DLListNode* new_Node = new DLListNode(obj,&p,p.next);
	p.next = new_Node;
	(p.next->next)->prev = new_Node; //O(constants)
}
template <typename T>
void TemplatedDLList<T>::insert_before(DLListNode &p, const T obj){
	DLListNode* new_Node = new DLListNode(obj,p.prev,&p);
	(p.prev)->next = new_Node;
	p.prev = new_Node;//O(constants)
}
template <typename T>
T TemplatedDLList<T>::remove_after(DLListNode &p){
	if(this->is_empty() == true){
        throw std::invalid_argument("Empty list");
    }
    if(p.next == &trailer){
        throw std::invalid_argument("Deleting trailer");
    }
	DLListNode* temp = p.next;
	T return_value = temp->obj;
	DLListNode* before = &p;
	DLListNode* next_next = (p.next)->next;
	before->next = next_next;
	next_next->prev = before;
	delete temp;
	return return_value;//O(constants)
}
template <typename T>
T TemplatedDLList<T>::remove_before(DLListNode &p){
	if(this->is_empty() == true){
        throw std::invalid_argument("Empty list");
    }
    if(p.prev == &header){
        throw std::invalid_argument("Deleting header");
    }
	DLListNode* temp = p.prev;
	T return_value = temp->obj;
	DLListNode* present = &p;
	DLListNode* before_before = (p.prev)->prev;
	before_before->next = present;
	present->prev = before_before;
	delete temp;
	return return_value;//O(constants)
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const TemplatedDLList<T>& dll){
	const typename TemplatedDLList<T>::DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){
		out << traveler->obj << ", ";
		traveler = traveler->next;
	}
	//out << (dll.getAfterLast().prev)->obj << endl;
	return out;//O(n)
}

template <typename T>
TemplatedDLList<T>::~TemplatedDLList(){
	this->clear();//O(n)
}
#endif
