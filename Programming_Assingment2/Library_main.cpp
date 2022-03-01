#include "Library.h"

int main(){
    Library myLib;
    
    myLib.import_database("Book.txt");
    myLib.export_database("Book2.txt");
}