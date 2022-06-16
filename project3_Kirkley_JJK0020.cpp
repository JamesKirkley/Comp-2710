/* FILE NAME: project3_Kirkley_JJK0020.cpp.
* AUTHOR: James Kirkley
* implement and learn streams, I/O, data elements, functions, unit testing, and alogrithms in C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/* declare your user-defined functions */
bool check_file(string);
/* do not forget to describe each function */
vector<int> read_file(string);
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);
/*
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string(string, vector<int>);
/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
/* declare your variables */
   string file1;
   string file2;
   string file3;
   vector<int> numbers1;
   vector<int> numbers2;
   vector<int> numbers3;
 
   cout << "*** Welcome to James Kirkley's sorting program ***\n";
/* Get name of file one. */
   do {
      cout << "Enter the first input file name: ";
      cin >> file1;
      cout << "";
   } while (cin.fail() || !check_file(file1));
/* Get and display numbers from file one. */
   numbers1 = read_file(file1);
   to_string(file1, numbers1);
/* Get name of file two. */
   do {
      cout << "Enter the second input file name: ";
      cin >> file2;
      cout << "";
   } while (cin.fail() || !check_file(file2));
/* Get and display numbers from file two. */
   numbers2 = read_file(file2);
   to_string(file2, numbers2);
/* Combine vectors and display the sorted result. */
   numbers3 = merge(numbers1, numbers2);
   cout << "The sorted list of " << numbers3.size() << ""
      << "numbers is: ";
     
   for (int i = 0; i < numbers3.size() - 1; i++) {
      cout << numbers3.at(i) << " ";
   }
   cout << numbers3.at(numbers3.size() - 1) << "\n";
/* Get name of output file. */
   do {
      cout << "Enter the output file name: ";
      cin >> file3;
      cout << "";
   } while (cin.fail());
/* Write combined vector to output file. */
   write_file(file3, numbers3);
   cout << "*** Please check the new file - " << file3 << " ***\n";
   cout << "*** Goodbye. ***\n";
   return 1;
}
bool check_file(string file) {
/* Input file stream. (ifstream) */
   ifstream stream;
/* Check whether file exists. */
   stream.open(file.c_str());
   if (stream.fail()) {
      cerr << "File not found.\n\n";
      return false;
   }
   stream.close();
   return true;
}
vector<int> read_file(string file) {
/* Input file stream. (ifstream) */
   ifstream stream;
/* Vector containing numbers from file. (vector<int>) */
   vector<int> v;
/* Integer read from file. (int) */
   int i;
/* Add each number in the file to a vector. */
   stream.open(file.c_str());
   while (stream.good()) {
      stream >> i;
      v.push_back(i);
   }
   v.pop_back();
   stream.close();
   return v;
}
void write_file(string file, vector<int> v) {
/* Output file stream. (ofstream) */
   ofstream stream;
   unsigned short i;

   stream.open(file.c_str());
   for (i = 0; i < v.size() - 1; i++) {
      stream << v.at(i) << "\n";
   }
   stream << v.at(v.size() - 1);
   stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
   vector<int> v3;

   unsigned short i;

   unsigned short s;
/* Compare both vectors. */
   while (v1.size() > 0 && v2.size() > 0) {
      if (v1.at(0) < v2.at(0)) {
         v3.push_back(v1.at(0));
         v1.erase(v1.begin());
      } 
      else {
         v3.push_back(v2.at(0));
         v2.erase(v2.begin());
      }
   }
/* Add any remaining numbers from vector one. */
   if (v1.size() > 0) {
      s = v1.size();
      for (i = 0; i < s; i++) {
         v3.push_back(v1.at(0));
         v1.erase(v1.begin());
      }
   }
/* Add any remaining numbers from vector two. */
   if (v2.size() > 0) {
      s = v2.size();
      for (i = 0; i < s; i++) {
         v3.push_back(v2.at(0));
         v2.erase(v2.begin());
      }
   }
			
   return v3;
}
void to_string(string file, vector<int> v) {
/* Vector interator number. (unsigned short) */
   unsigned short i;
/* Display the numbers contained in a vector. */
   cout << "The list of " << v.size() << " numbers "
       << "in file " << file << "is:\n";

   for (i = 0; i < v.size(); i++) {
      cout << v.at(i) << "\n";
   }

   cout << "\n";
}