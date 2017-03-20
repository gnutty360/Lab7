// Lab7_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++11
//      or:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	int i;
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
// ***********************************************************************
// Try all the ways to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	vector<int> scores(10);//1
	for( i = 0; i < scores.size(); i++ ){
		scores[i] = i;
	}
		
	for(i = 0; i < scores.size(); i++){
		cout<< scores[i] <<" ";
	}
	cout<<endl;
	
	vector<int> copy(scores);//2
	
	for(i = 0; i < copy.size(); i++){
		cout<< copy[i] <<" ";
	}
	cout<<endl;
	
	vector<int> copy2 = scores;//3
	
	
	for(i = 0; i < copy2.size(); i++){
		cout<< copy2[i] <<" ";
	}
	cout<<endl;
	
	vector<double> percentages(10,50.5);//4
	
	for(auto i:percentages){
		cout<< i <<" ";
	}
	cout<<endl;
	
	int number = 8;
	
	vector<int> foo(number);//5
	for(auto i:foo){
		cout<< i <<" ";
	}
	cout<<endl;
	
	vector<string> sentence{"This", "is", "a", "sentence that I wrote"};//6 and 7
	for(auto i:sentence){
		cout<< i <<" ";
	}
	cout<<endl;
	
	
	return 0;
}