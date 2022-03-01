// implementation of the DLList class

#include "DLList.h"
#include <iostream>
using std::cout;
using std::endl;
#include <stdexcept>
using std::invalid_argument;

DLList::DLList(){
    // possibly done 
	header.next = &trailer;
	trailer.prev = &header;
}

void DLList::clear() {
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

DLList::DLList(const DLList& dll){ // copy constructor 
	header.next = &trailer;
	trailer.prev = &header;
	DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){
		insert_last(traveler->obj);
		traveler = traveler->next;
	}
	
}

DLList& DLList::operator=(const DLList& dll){ // copy assignment operator
	// cout << "in0" << endl;
	if(dll.header.next == &dll.trailer){ // empty list case
		// check to see if it works 
		//cout << "in0.5" << endl;
		return *this;
	}
	this->clear();
	DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){
		this->insert_last(traveler->obj);
		traveler = traveler->next;
	}
	return *this;
}

DLList::DLList(DLList&& dll){ // move constructor
	
	header.next = dll.header.next;
	(dll.header.next)->prev = &header;
	(dll.trailer.prev)->next = &trailer;
	trailer.prev = dll.trailer.prev;
	dll.header.next = &dll.trailer;
	dll.trailer.prev = &dll.header;
}

DLList& DLList::operator=(DLList&& dll){ // move assignment operator

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
	return *this;
}



DLList::DLListNode* DLList::first_node() const{
	return header.next;
}

const DLList::DLListNode* DLList::after_last_node() const{
	return &trailer;
}

bool DLList::is_empty() const{
	bool bool1 = (header.next == &trailer);
	bool bool2 = (trailer.prev == &header);
	if(bool1 && bool2){
		return true;
	}
	else{
		return false;
	}

}

int DLList::first() const{ // return the first object
	if (this->is_empty()){
		throw invalid_argument("Empty Doubly Linked List");
	}
	return header.next->obj;

}
int DLList::last() const{ // return the last object
	if (this->is_empty()){throw invalid_argument("Empty Doubly Linked List");}
	return trailer.prev->obj;
}

void DLList::insert_first(const int obj){
	DLListNode* new_Node = new DLListNode(obj, &header,header.next);
	header.next->prev = new_Node;
	header.next = new_Node;
}

int DLList::remove_first(){
	if(this->is_empty()){
        throw std::invalid_argument("Empty list");
    }
    if(header.next == &trailer){
        throw std::invalid_argument("Deleting trailer");
    }
	int return_value = header.next->obj;
	DLListNode* to_delete =  header.next;
	header.next = to_delete->next;
	header.next->prev = &header;
	delete to_delete;
	return return_value;

}

void DLList::insert_last(const int obj){

	DLListNode* new_Node = new DLListNode(obj,trailer.prev,&trailer);
	trailer.prev->next = new_Node;
	trailer.prev = new_Node;

}

int DLList::remove_last(){
	if(this->is_empty()){
        throw std::invalid_argument("Empty list");
    }
    if(trailer.prev == &header){
        throw std::invalid_argument("Deleting trailer");
    }
	int return_value = trailer.prev->obj;
	DLListNode* to_delete =  trailer.prev;
	to_delete->prev->next = &trailer;
	trailer.prev = to_delete->prev;
	delete to_delete;
	return return_value;
}



void DLList::make_empty(void){
	this->clear();
}

void DLList::insert_after(DLListNode &p, const int obj){
	DLListNode* new_Node = new DLListNode(obj,&p,p.next);
	p.next = new_Node;
	(p.next->next)->prev = new_Node;
}

void DLList::insert_before(DLListNode &p, const int obj){
	DLListNode* new_Node = new DLListNode(obj,p.prev,&p);
	(p.prev)->next = new_Node;
	p.prev = new_Node;
}

int DLList::remove_after(DLListNode &p){
	if(this->is_empty() == true){
        throw std::invalid_argument("Empty list");
    }
    if(p.next == &trailer){
        throw std::invalid_argument("Deleting trailer");
    }
	DLListNode* temp = p.next;
	int return_value = temp->obj;
	DLListNode* before = &p;
	DLListNode* next_next = (p.next)->next;
	before->next = next_next;
	next_next->prev = before;
	delete temp;
	return return_value;
}

int DLList::remove_before(DLListNode &p){
	if(this->is_empty() == true){
        throw std::invalid_argument("Empty list");
    }
    if(p.prev == &header){
        throw std::invalid_argument("Deleting header");
    }
	DLListNode* temp = p.prev;
	int return_value = temp->obj;
	DLListNode* present = &p;
	DLListNode* before_before = (p.prev)->prev;
	before_before->next = present;
	present->prev = before_before;
	delete temp;
	return return_value;
}


std::ostream& operator<<(std::ostream& out, const DLList& dll){
	DLList::DLListNode *traveler = dll.first_node();
	while(traveler != dll.after_last_node()){
		out << traveler->obj << ", ";
		traveler = traveler->next;
	}
	//out << (dll.getAfterLast().prev)->obj << endl;
	return out;
}

DLList::~DLList(){
	this->clear();
}


