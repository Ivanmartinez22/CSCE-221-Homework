#include <iostream>

#include "HashTable.h"

using namespace std;

int main(){
  int starting_size;
  cout << "enter size: ";
  cin >> starting_size;
  
  HashTable theHash = HashTable(starting_size);
  for(int i = 0; i < testvec.size(); i++){
      theHash.insert(testvec[i].first, testvec[i].second);
  }
  // while(true){
  //   string input;
  //   cout << "Enter uin:";
  //   cin >> input;
  //   if(input == "q"){
  //       break;
  //   }
  //   cout << "name: " << theHash.at(input) << endl;
    
  // }
  for(int i = 0; i < testvec.size(); i++){
    cout << "uin: " << testvec[i].first << endl;
    cout << "name: " << theHash.at(testvec[i].first) << endl;
  }

  return 0;
}
