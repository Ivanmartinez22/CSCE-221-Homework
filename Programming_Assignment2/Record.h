#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>
using std::string;
class Record {
private:
    //member variables
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    std::string edition;
public:
    //accessor/mutator functions
    // std::string get_title(void) const;
    // ... for all 5 fields
    string get_title(void) const;
    string get_author(void) const;
    string get_ISBN(void) const;
    string get_year(void) const;
    string get_edition(void) const;

    void set_title(string in);
    void set_author(string in);
    void set_ISBN(string in);
    void set_year(string in);
    void set_edition(string in);
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, const Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
bool operator<(const Record& lhs, const Record& rhs);
#endif