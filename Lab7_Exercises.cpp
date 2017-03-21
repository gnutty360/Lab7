/*
	Marshall Lindsay
	3/20/17
	Lab7
	Excersizes 3.14 and 3.15
	
	3.14 - Write a program to read a sequence of ints from cin and store those
	values in a vector;
	3.15 - Repeat the previous program but read strings this timee;
	
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	
	int input;
	string input2;
	int i;
	vector<int> integers;
	vector<string> strings;
	
	cout<<"Please enter 10 integers: "<<endl;
	
	for(int i = 0; i < 10; i++){
		cin>> input;
		integers.push_back(input);
	}
	
	for(auto i:integers){
		cout<< i << " ";
	}
	cout<<endl;
	
	cout<<"Please enter 5 strings: "<<endl;
	cin.ignore();
	for(int i = 0; i < 5; i++){
		getline(cin, input2);
		strings.push_back(input2);
	}
	
	for(auto i:strings){
		cout<< i << " ";
	}
	
	
	return(0);
}