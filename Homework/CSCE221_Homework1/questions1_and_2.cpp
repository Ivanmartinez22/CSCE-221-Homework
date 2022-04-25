#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using std::vector;
using std::cout;
using std::endl;

int two_to_the_k(int k){
  return pow(2,k);
}

int two_to_the_k_minus_one(int k){
  return pow(2,k)-1;
}

void vector_creation(vector<int> &v, int size){
  for(int i = 0; i < size; i++){
    v.push_back(i);
  }
}

// test data 
vector<int> v1;

vector<int> k;

vector<int> consecutive_ints;

vector<int> targets;
vector<int> num_comps;

int values [20] = {1,2,4,6,8};
int values_2 [20] = {2,1,4,5,6,3,8,9};
int values_3 [20] = {1,2,3,4};
int values_4 [20] = {1,2,3,4,5,6,7,8,10,12,13,15,16,17,18,19};
int num_comp = 0; // number of computations for question 2 

//Question 1
// an odd product can only be made by two odd numbers 
bool odd_detector_1(vector<int> v){ // test 
  int counter = 0; // 1 operation assignment
  for(int i = 0; i < v.size(); i++) { // n iterations 
    if(v.at(i) % 2 != 0){ // 2 operations modulus and comparison 
      counter++; // 1 operation
    }
    if(counter == 2){
      return true;
    }
  }
  
  return false; 
} // running time function f(n) = 3n + 1
// the algorithm is O(n)
//A best case would be the first two items being odd which would give the program a O(1) complexity because the program would find an odd pair 
// in a small number of iterations
//A worst case would be the case of there being no pairs of odd numbers because the algorithm would have iterate through all the data giving 
// it a complexity of O(n)

// best case input {1,3,6,8,9}
// worst case input {2,4,6,8,10,12}


bool odd_detector_2(vector<int> v){
  for(int i = 0; i < v.size(); i++) { // n iterations 
    for(int j = i + 1; j < v.size(); j++){ // n iterations 
      int product = v.at(i) * v.at(j); // 2 operations multiplication and assignment
      if(product % 2 != 0){ // 2 operations modulus and comparison 
        return true;
      }
    }
  }
  return false; 
} // running time function f(n) = 4n^2 
// the algorithm is O(n^2)
//A best case would be the first two items being odd which would give the program a O(1) complexity because the program would find an odd pair 
// in a small number of iterations
//A worst case would be the case of there being no pairs of odd numbers because the algorithm would have iterate through all the data giving 
// it a complexity of O(n^2)

// best case input {1,3,6,8,9}
// worst case input {2,4,6,8,10,12}

// Question 2
//part (a) 
template<typename T>
int Binary_Search(vector<T> &v, T x) {
  int mid, low = 0; // 2 ops assignment
  int high = v.size()-1; // 2 ops assignment and subtraction
  while (low < high) { // n iterations
    mid = (low+high)/2; // 3 ops assignment addition and division
    if (num_comp++, v[mid] < x){ // 3 ops overall
      low = mid+1; //2 ops assignment and adding
    }
    else{
      high = mid; // 1 op assignment
    }
  }
  if (num_comp++, x == v[low]){return low;}; //OK: found
  return -1; //exception: not found
}
//part (b)
// i. 5 for num_comp 
//ii. 5 for num_comp
//iii. 5  for num_comp
// My conclusuion from testing n = 16 is that the complexity is constant for this particular input. 

// part(c)
// csv copy and paste for part c
//Range [1,n],Target, # comp.
// [1,1],1,1
// [1,2],2,2
// [1,4],4,3
// [1,8],8,4
// [1,16],16,5
// [1,32],32,6
// [1,64],64,7
// [1,128],128,8
// [1,256],256,9
// [1,512],512,10
// [1,1024],1024,11
// [1,2048],2048,12

//part(d) plot the number of comparisons for the vector size n = 2^k,k= 1,2, . . . ,11. You can use a spreadsheet or any graphical package.

// essentialy size n = 2^k vs # of comps 

// part(e) formula of n = 2^k vs # of comps

//part(f)
// csv copy and paste for part f
// Range [1,n],Target, # comp.
// [1,1],1,1
// [1,3],3,2
// [1,7],7,3
// [1,15],15,4
// [1,31],31,5
// [1,63],63,6
// [1,127],127,7
// [1,255],255,8
// [1,511],511,9
// [1,1023],1023,10
// [1,2047],2047,11

// part(g)

// part(h)

//part(i)





int main(){
  





  // driver for part c
  // vector_creation(k,12);
  // for(int i = 0; i < k.size(); i++){
  //   targets.push_back(two_to_the_k(i));
  // }
  // for(int i = 0; i < targets.size(); i++){
  //   for(int j = 1; j <= targets.at(i); j++){
  //     consecutive_ints.push_back(j);
  //   }
    
  //   Binary_Search(consecutive_ints, targets.at(i));
  //   num_comps.push_back(num_comp);
  //   consecutive_ints.clear();
  //   num_comp = 0;
  // }
  // cout << "Range [1,n],Target, # comp." << endl;
  // for(int i = 0; i < targets.size(); i++){
  //   cout << "[1," << targets.at(i) << "]," << targets.at(i) << "," << num_comps.at(i) << endl;
  // }
  // cout << endl;
  // cout << " targets size "<< "  " << " num_comps size "<< endl;
  // cout << targets.size() << " " <<  num_comps.size() << endl;
  // vector_creation(consecutive_ints, two_to_the_k(1));




  //driver for part d
  // vector_creation(k,12);
  // for(int i = 1; i < k.size(); i++){
  //   targets.push_back(two_to_the_k_minus_one(i));
  // }
  // // for(int k = 0; k < targets.size(); k++){
  // //   cout << targets.at(k) << endl;
  // // }
  // // cout << endl;

  // for(int i = 0; i < targets.size(); i++){
  //   for(int j = 1; j <= targets.at(i); j++){
  //     consecutive_ints.push_back(j);
  //   }
  //   // for(int k = 0; k < targets.at(i); k++){
  //   //   cout << consecutive_ints.at(k) << endl;;
  //   // }
  //   Binary_Search(consecutive_ints, targets.at(i));
  //   num_comps.push_back(num_comp);
  //   consecutive_ints.clear();
  //   // cout << endl;
  //   num_comp = 0;
  // }
  // cout << "Range [1,n],Target, # comp." << endl;
  // for(int i = 0; i < targets.size(); i++){
  //   cout << "[1," << targets.at(i) << "]," << targets.at(i) << "," << num_comps.at(i) << endl;
  // }
  // cout << endl;
  // cout << " targets size "<< "  " << " num_comps size "<< endl;
  // cout << targets.size() << " " <<  num_comps.size() << endl;
  // vector_creation(consecutive_ints, two_to_the_k(1));
  int* ip = new int[3]{1,3,4};
  cout << *(ip+1);
  
}


// inner display code 
// for(int k = 0; k < targets.at(i); k++){
//   cout << consecutive_ints.at(k) << endl;;
// }
// cout << endl;

// correctness driver code
  // for(int i = 0; i < 5; i++) {
  //  v1.push_back(values[i]);
  // }
  // cout << odd_detector_2(v1);
  // for(int i = 0; i < 8; i++) {
  //   v1.push_back(values_2[i]);
  // }
  // for(int i = 0; i < 4; i++) {
  //   v1.push_back(values_3[i]);
  // }
  // for(int i = 0; i < 8; i++) {
  //   v1.push_back(values_4[i]);
  // }

  // cout<< "index: " << Binary_Search(v1, 3) << endl;
  // cout<<"num of comps: " << num_comp << endl;