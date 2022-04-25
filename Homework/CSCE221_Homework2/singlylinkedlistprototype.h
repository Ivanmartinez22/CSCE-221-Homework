#ifndef HOMEWORK2
#define HOMEWORK2
using namespace std;
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
using std::stringstream;

//Conceptual question 7 singly linked list functions remove first and last should still have constant run times due to no iteration 

// doubly linked list class
template <typename T>
class LinkedList {
public:
// doubly linked list node
  struct Node {
    T obj;
    Node *next;
    // constructor
     Node(T obj, next = nullptr): obj(obj),next(next){}
  };

public:
//   // Default constructor
// 	LinkedList();

// 	// Destructor
// 	~LinkedList();

// 	// Copy constructor
// 	LinkedList(const LinkedList& other);

// 	// Copy assignment
// 	LinkedList& operator=(const LinkedList& other);

// 	// Insert a record to the linked list
// 	void insert(std::string location, int year, int month, double temperature);

// 	// Clear the content of this linked list
// 	void clear();

// 	// The functions below are written already. Do not modify them.
// 	std::string print() const;

// 	Node* getHead() const;

    LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function good I think
    }

    LinkedList::~LinkedList() {
        // Implement this function
        this->clear();
    }

    LinkedList::LinkedList(const LinkedList& source) : head(new Node){
        // Implement this function
        // head = source.head;
        // tail = source.tail;
        // use insertion function
        this->clear();
        if(source.head == nullptr){ 
            head == nullptr;
            return;
        }
        Node* marker = source.head;
        // TemperatureData headData = marker->data;
        // this->insert(headData.id, headData.year, headData.month, headData.temperature);
        while(marker != nullptr){
            TemperatureData newData = marker->data;
            this->insert(newData.id, newData.year, newData.month, newData.temperature);
            Node* next_ptr = marker->next;
            marker = next_ptr;
        }
        marker = nullptr;
    }

    LinkedList& LinkedList::operator=(const LinkedList& source) {
        // Implement this function
        this->clear();
        if(source.head == nullptr && source.tail == nullptr){ 
            return *this;
        }
        Node* marker = source.head;
        // TemperatureData headData = marker->data;
        // this->insert(headData.id, headData.year, headData.month, headData.temperature);
        while(marker != nullptr){
            TemperatureData newData = marker->data;
            this->insert(newData.id, newData.year, newData.month, newData.temperature);
            Node* next_ptr = marker->next;
            marker = next_ptr;
        }
        marker = nullptr;
        return *this;

    } // good

    void LinkedList::insert(string location, int year, int month, double temperature) {
        // Implement this function			
        bool new_tail_needed = false; // new tails necessity from middle cases
        TemperatureData newData = TemperatureData(location, year, month, temperature);
        if(head == nullptr && tail == nullptr){ // empty list case
            head = new Node;
            head->data = TemperatureData(location, year, month, temperature);
            tail = head;
            head->next = nullptr;
            tail->next = nullptr;
        }
        else if(head == tail){// singleton case
            TemperatureData oldData = head->data;
            TemperatureData newData = TemperatureData(location, year, month, temperature);
            if(oldData < newData){
                // new tail
                tail = new Node;
                tail->data = newData;
                head->next = tail;
                tail->next = nullptr;
            }
            else if(newData < oldData){
                // new head
                Node* prev_Ptr = head; // needs to be tail
                head = new Node;
                head->data = newData;
                head->next = prev_Ptr;
                tail = prev_Ptr;
                tail->data = oldData;
                tail->next = nullptr;
            }
        }
        else if(newData <  head->data){ // new head from middle case
            Node* prev_Ptr = head;
            Node* link = head->next;
            head = new Node;
            head->data = newData;
            head->next = prev_Ptr;
            prev_Ptr->next = link;
        } 
        else if(head != nullptr && tail != nullptr){ // general middle cases 
            if(!(newData < tail->data)){ // new tail case
                Node* prev_Ptr = tail;
                prev_Ptr->data = tail->data;
                tail = new Node;
                tail->data = newData;
                tail->next = nullptr;
                prev_Ptr->next = tail;
                return;
            }
            Node* insertion = new Node; // node to be insterted in linked list
            Node* traveler = nullptr; // iterates through linked list
            Node* marker = nullptr;
            insertion->data = newData;
            traveler = head; // starting position
            while(traveler != nullptr){
                marker = traveler;
                Node* nextPtr = marker->next;
                if(newData < nextPtr->data){
                    marker->next = insertion;
                    insertion->next = nextPtr;
                    return;
                }
                traveler = marker->next;
            }
            new_tail_needed = true;

        }
        
    }

    void LinkedList::clear() {
        // Implement this function
        if(head != nullptr){
            Node* temporary_ptr = nullptr;
            while(head != nullptr){
                temporary_ptr = head;
                
                head = temporary_ptr->next;
                
                temporary_ptr->next = nullptr;

                delete temporary_ptr;
            }
            head = nullptr;
            tail = nullptr;
            temporary_ptr = nullptr;
        } // probably good
    }

    Node* LinkedList::getHead() const {
        // Implement this function it will be used to help grade other functions
        return head;

    }

    string LinkedList::print() const {
        string outputString;
        // Implement this function
        Node* temporary_ptr = nullptr;
        temporary_ptr = head;
        stringstream ss;
        while(temporary_ptr != nullptr){
            ss << temporary_ptr->data.id;
            ss << " ";
            ss << temporary_ptr->data.year;
            ss << " ";
            ss << temporary_ptr->data.month;
            ss << " ";
            ss << temporary_ptr->data.temperature;
            ss << '\n';
            temporary_ptr = temporary_ptr->next;
        }
        outputString = ss.str();
        return outputString;
    }

    ostream& operator<<(ostream& os, const LinkedList& ll) {
        /* Do not modify this function */
        os << ll.print();
        return os;
    }

};





#endif

