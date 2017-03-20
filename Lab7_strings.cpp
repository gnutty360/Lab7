// Lab7_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++11
//      or:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard. 

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	cin.ignore();	// to consume the '\n' character. Otherwise, you may get issues with
					// the getline() below. Try commenting this out. Any issues?
	
	string s4(s1);
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
	
	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************
	string string1, string2,string3;
	string1 = "ABCDEF";
	string2 = "ghijkl";
	//1 and 2
	cout<<"\nEnter a string:"<<endl;
	cin>>string3;
	cout<<string3;
	//3
	cin.ignore();
	cout<<"\nEnter a string:"<<endl;
	getline(cin, string3);
	cout<<string3;
	//4
	if(!string3.empty()){
		cout<<"\nString3 is not empty"<<endl;
	}else{
		cout<<"\nString3 is empty"<<endl;
	}
	//5
	cout<<"The number of characters in "<<string1<<" is: "<<string1.size()<<endl;
	//6
	cout<<"The 2nd character of "<<string2<<" is: "<<string2[1]<<endl;
	//7
	cout<<string1<<" + "<<string2<< " = "<<string1 + string2<<endl;
	//8
	
	cout<<"String1 = "<<string1<<"."<<"\nString2 = "<<string2<<"."<<endl;
	string1 = string2;
	cout<<"After 'string1 = string2', String1 = "<<string1<<endl;
	//9
	if(string1 == string2){
		cout<<"String1: '"<<string1<<"' = String2: '"<<string2<<"'"<<endl;
	}
	//10
	cout<<"\nEnter a string: "<<endl;
	getline(cin, string1);
	cout<<"\nEnter another string: "<<endl;
	getline(cin, string2);
	if(string1 != string2){
		cout<<"String1: '"<<string1<<"' != String2: '"<<string2<<"'"<<endl;
	}else{
		cout<<"String1: '"<<string1<<"' = String2: '"<<string2<<"'"<<endl;
	}
	
	//11
	
	string1 = "ABCDEF";
	string2 = "ghijkl";
	string3 = "abcdef";
	cout<<"String1: "<<string1<<endl;
	cout<<"String2: "<<string2<<endl;
	cout<<"String3: "<<string3<<endl;
	
	if(string1 > string2){
		cout<<"string1 > string2"<<endl;
	}else if(string1 < string2){
		cout<<"string1 < string2"<<endl;
	}
	if(string1 > string3){
		cout<<"string1 > string3"<<endl;
	}else if(string1 < string3){
		cout<<"string1 < string3"<<endl;
	}
	if(string2 > string1){
		cout<<"string2 > string1"<<endl;
	}else if(string2 < string1){
		cout<<"string2 < string1"<<endl;
	}
	if(string2 > string3){
		cout<<"string2 > string3"<<endl;
	}else if(string2 < string3){
		cout<<"string2 < string3"<<endl;
	}
	/***********************************/
	if(string1 >= string2){
		cout<<"string1 >= string2"<<endl;
	}else if(string1 <= string2){
		cout<<"string1 <= string2"<<endl;
	}
	if(string1 >= string3){
		cout<<"string1 >= string3"<<endl;
	}else if(string1 <= string3){
		cout<<"string1 <= string3"<<endl;
	}
	if(string2 >= string1){
		cout<<"string2 >= string1"<<endl;
	}else if(string2 <= string1){
		cout<<"string2 <= string1"<<endl;
	}
	if(string2 >= string3){
		cout<<"string2 >= string3"<<endl;
	}else if(string2 <= string3){
		cout<<"string2 <= string3"<<endl;
	}
	
	
// -----------------------------------------------------------------------


// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************

	string line;
	cout << "\nEnter some text:" << endl;
	getline(cin, line);
	cout << line << endl;
	
	for(auto &c : line){
		c = toupper(c);
	}
	cout<<"After toupper: "<<line<<endl;
	for(auto &c : line){
		c = tolower(c);
	}
	cout<<"After tolower: "<<line<<endl;
	
	for(auto &c : line){
		if(isspace(c)){
			c = '.';
		}
	}
	cout<< "After whitespace conversion: "<<line<<endl;
	cout << "\nEnter some text, finish it with an &:" << endl;
	getline(cin, line, '&');	// the delimiter can be any character
	cout << line << endl;

	return 0;
}