#pragma once

/*
  Dr. Leyk has a problem: devious students tend to break into her office and 
  steal her cookies. To prevent these high crimes, Dr. Leyk wants to implement 
  an access control system where only authorized persons (as determined by their 
  UINs) can enter the office.  Because this list may get quite large, Dr. Leyk 
  wants to store these persons in a hash table.  Implement the “insert” and “at” 
  methods of the hash table below. The “insert” method should insert an entry into 
  the table with the key “uin” and value “name”. If a collision occurs, resolve 
  it using linear probing.  Because two entries hashes may collide, we save both 
  the "uin" and "name" in an std::pair where _tab[0].first represents the uin at 
  the first index and _tab[0].second represents the name at the first index. The 
  “at” method should lookup an entry in the table and return the name of the person. 
  If the “at” method cannot find the person, return an empty string. You may assume 
  that the table will never fill completely.
  
  References:
  - https://en.cppreference.com/w/cpp/utility/pair
*/
#include <utility>    // std::pair
#include <vector>
#include <string>
#include <ostream>

/*
 * This is a simple hash function which takes
 * a string and returns a 64-bit number. In real
 * programs, you may consider using std::hash. We're
 * not using it here because it doesn't guarantee the
 * same values across different implementations of the
 * standard library and we want to test your implementation
 * internally for correctness.
 *
 * Example:
 * - hash("Hello World") = 17550223351478917048
 * - hash("Go Aggies!!") = 04406657511517237013
 *
 * If you're curious how it works, it's roughly based on a 
 * linear congruential generator and multiplicative hashing.
 */
static uint64_t hash(const std::string & str) {
  char const * s = str.c_str();

  uint64_t h = 5381;
  char c;

  while(c = *s++)
    h = ((h << 5) + h) ^ c;

  h ^= h >> 33;
  h *= 0xff51afd7ed558ccdL;
  h ^= h >> 33;
  h *= 0xc4ceb9fe1a85ec53L;
  h ^= h >> 33;

  return h; 
}


class HashTable {
  // an entry is a pair in the form (uin, name)
  typedef std::pair<std::string, std::string> entry;

  // entries of the hash table
  std::vector<entry> _tab;

  public:
  

  // construct a hash table with n_entries
  // both the UIN and name are initialized to empty strings
  HashTable(size_t n_entries)
    : _tab(n_entries, entry("", ""))
  { }

  // Inserts an item into the hash table
  void insert(const std::string & uin, const std::string & name) {
    // Complete:
    //
    // 1. Hash the UIN to determine the location at which you should insert
    // using mod(hash_code, table_size)
    int max_index = _tab.size() - 1;
    int index = hash(uin) % _tab.size();
    int counter = 0;
    //
    // 2. If a collision occurs, resolve it via open addressing
    //
    while(true){
      if(index == _tab.size()){
        index = 0;
      }
      if(counter == _tab.size()){
        return;
      }
      else if((_tab[index].first == "") && (_tab[index].second == "")){
        break;
      }
      index++;
      counter++;
      
    }
    // 3. Place the new entry in the table. You can construct an entry as:
    entry e = entry(uin, name);
    _tab[index] = e;
  }

  // Returns the name of the person with the provided uin
  // If the person doesn't exist, returns ""
  std::string at(const std::string & uin) const {
    // Complete
    int index = hash(uin) % _tab.size();
    int counter = 0;
    while(true){
      if(index == _tab.size()){
        index = 0;
      }
      if(counter == _tab.size()){
        return "";
      }
      else if(_tab[index].first == uin){
        return _tab[index].second;
      }
      index++;
      counter++;
      
    }
    return "";
  }

  // For our internal testing
  friend std::ostream & operator<<(std::ostream & ss, const HashTable & htab);
};

// Vector of example entries and insertion locations
static std::vector<std::pair<std::string, std::string> > testvec = {
  /* UIN          Name                     */
  { "764687365", "Mariel Lopez" },        // 39
  { "993402464", "Spencer Gautreaux" },   // 17
  { "358494685", "Alex" },                // Collides with Spencer
  { "954790063", "Dante Barbieri" },      // 50
  { "164398712", "Carlos Alvarez" },      // Collides with Dante
  { "666864646", "Evelyn Crowe" },        // 57
  { "879095317", "Furkan Sahin" },        // Collides with Mari
  { "174974284", "Ajay Hernandez" },      // 23
  { "679855933", "Clayton Stuhrenberg" }, // 77
  { "740348738", "Scott" },               // 78
  { "797584305", "Thomas Goodwin" },      // Collides with Clayton
  { "944486508", "Anjali Segu" },         // Also collides with Clayton
};
