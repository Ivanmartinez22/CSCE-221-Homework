#include "Library.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
//Searches for a title in the database and returns vector of matching records
std::vector<Record> Library::search(const std::string title) const{
    std::vector<Record> found_records;
    for(int i = 0; i < 26; i++){
        TemplatedDLList<Record> iteration = book_db[i];
        TemplatedDLList<Record>::DLListNode*prev_node;
        TemplatedDLList<Record>::DLListNode*node = iteration.first_node();
        while (node != iteration.after_last_node()) {
            prev_node = node;
            node = node->next;
            if((prev_node->obj).get_title() == title){
                found_records.push_back(prev_node->obj);
            }
        }
    }
    
    return found_records;

}


//Imports records from a file.  Does not import duplicates.
// Return the number of records added to the database
int Library::import_database(const std::string filename){
    int num = 0;
    ifstream data(filename);
    if(!data){
        cout << __LINE__ << " Error opening data file" << endl;
        return 0;
    }
    Record rec;
    while(data>>rec){
        // int place = rec.get_title()[0];
        // book_db[place].insert_first(rec);
        add_record(rec);
        num++;
    }
    return num;

}

//Exports the current database to a file
//Return the number of records exported
int Library::export_database(const std::string filename) const{
    int num = 0;
    ofstream write(filename);
    if(!write){
        cout << __LINE__ << " Error opening data file" << endl;
        return 0;
    }
    for(int i = 0; i < 26; i++){
        TemplatedDLList<Record> iteration = book_db[i];
        TemplatedDLList<Record>::DLListNode*prev_node;
        TemplatedDLList<Record>::DLListNode*node = iteration.first_node();
        while (node != iteration.after_last_node()) {
            prev_node = node;
            node = node->next;
            write << prev_node->obj << endl;
            num++;
        }
        
    }
    return num;

}

void Library::print_database() const{
    for(int i = 0; i < 26; i++){
        TemplatedDLList<Record> iteration = book_db[i];
        TemplatedDLList<Record>::DLListNode*prev_node;
        TemplatedDLList<Record>::DLListNode*node = iteration.first_node();
        while (node != iteration.after_last_node()) {
            prev_node = node;
            node = node->next;
            cout << prev_node->obj << endl;
        }
    }

}

//add record to database, avoid complete duplicates
//  return true if unique
bool Library::add_record(const Record r){
    std::vector<Record> found_records = search(r.get_title());
    std::vector<Record> refined;
    for(int i = 0; i < found_records.size();i++){
        if(found_records.at(i) == r){
            refined.push_back(found_records.at(i));
        }
    }
    if(refined.size() == 0){
        int place = r.get_title()[0] - 'A';
        book_db[place].insert_first(r);
        return true;
    }
    bool unique = true;
    for(int i = 0; i < refined.size(); i++){
        if(refined.at(i) == r){
            unique = false;
        }
    }
    if(unique){
        int place = r.get_title()[0] - 'A';
        book_db[place].insert_first(r);
        return true;
    }
    return false;

}

//Deletes a record from the database
void Library::remove_record(const Record r){
    int place = r.get_title()[0] - 'A';
    TemplatedDLList<Record>::DLListNode*prev_node;
    TemplatedDLList<Record>::DLListNode*node = book_db[place].first_node();
    while (node != book_db[place].after_last_node()) {
        prev_node = node;
        node = node->next;
        if(prev_node->obj == r){
            book_db[place].remove_before(*node);
        }
    }



}
