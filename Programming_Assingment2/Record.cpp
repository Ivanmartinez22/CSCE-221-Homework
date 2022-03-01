//implementation of record class

#include "Record.h"
string Record::get_title(void) const{
    return title;
}
string Record::get_author(void) const{
    return author;
}
string Record::get_ISBN(void) const{
    return ISBN;
}
string Record::get_year(void) const{
    return year;
}
string Record::get_edition(void) const{
    return edition;
}

void Record::set_title(string in){
    title = in;
}
void Record::set_author(string in){
    author = in;
}
void Record::set_ISBN(string in){
    ISBN = in;
}
void Record::set_year(string in){
    year = in;
}
void Record::set_edition(string in){
    edition = in;
}

std::istream& operator>>(std::istream& is, Record& rec){
    string iteration;
    int counter = 0;
    while(getline(is,iteration)){
        if(iteration.empty()){
            getline(is, iteration);
        }
        if(counter == 0){
            rec.set_title(iteration);
            counter++;
        }
        else if(counter == 1){
            rec.set_author(iteration);
            counter++;
        }
        else if(counter == 2){
            rec.set_ISBN(iteration);
            counter++;
        }
        else if(counter == 3){
            rec.set_year(iteration);
            counter++;
        }
        else if(counter == 4){
            rec.set_edition(iteration);
            counter++;
        }
        if(counter == 5){
            break;
        }
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, const Record& rec){
    os << rec.get_title() << std::endl;
    os << rec.get_author() << std::endl;
    os << rec.get_ISBN() << std::endl;
    os << rec.get_year() << std::endl;
    os << rec.get_edition() << std::endl;
    return os;
}

bool operator==(const Record& r1, const Record& r2){
    string title_1 = r1.get_title();
    string author_1 = r1.get_author();
    string isbn_1 = r1.get_ISBN();
    string title_2 = r2.get_title();
    string author_2 = r2.get_author();
    string isbn_2 = r2.get_ISBN();
    bool return_value = (title_1 == title_2) && (author_1 == author_2) && (isbn_1 == isbn_2);
    return return_value;
}
bool operator<(const Record& lhs, const Record& rhs){
    string title_1 = lhs.get_title();
    string author_1 = lhs.get_author();
    string isbn_1 = lhs.get_ISBN();
    string title_2 = rhs.get_title();
    string author_2 = rhs.get_author();
    string isbn_2 = rhs.get_ISBN();
    if(title_1 < title_2){
        return true;
    }
    if(author_1 < author_2){
        return true;
    }
    if(isbn_1 < isbn_2){
        return true;
    }
    return false;
}