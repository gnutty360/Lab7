/*
	Marshall Lindsay
	Lab7
	3/20/17
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

#define DEFAULT_DATA_FILE "defaultData.txt"

//Signal Class
class Signal{
	private:
		string fileName;
		int length;
		double max_value;
		double average;
				vector<double> data;
		void calcAvg();
		double calcMaxValue();
		
	public:

		void operator*(double x);
		void operator+(double x);
		void center();
		void normalize();
		void Sig_info();
		void Save_file(string);
		Signal();
		Signal(string L);
		Signal(const char* fileName);
		~Signal();

};

Signal::Signal(){
	this -> fileName = "void";
	this -> length = 0;
	this -> max_value = 0;
	this -> average = 0;
	
}

Signal::Signal(string L){
	fstream dataFile;
	string fileName;
	
	//Declare a const char* to be used with the .open() on line 115
	//that points to the file name.
	const char* ptrFileName = fileName.c_str();
	
	
	//Append the integers into the file name template
	fileName = std::string("Raw_data_") + L + ".txt";
	
	this->fileName = fileName;
	//Open the correct file
	dataFile.open(ptrFileName);
	
	//Check that the file was opened correctly.
	//If not, set default values and return
	if(!dataFile.is_open()){
		cout<<"\nCould not open "<<fileName<<" setting default values!"<<endl;
		this -> length = 0;
		this -> max_value = 0;
		this -> average = 0;
		return;
	}
	
	//Read the number of integers in the datafile
	dataFile >>  this -> length;
	vector<double> copy(this -> length, 0);
	//Allocate memory for the data array.
	this -> data = copy;
	
	//Read the max value from the data file
	dataFile >> this -> max_value;
	
	//Read the data from the file and place in the data array.
	for(int i = 0; i < this -> data.size(); i++){
		dataFile >> this -> data[i];
	}
	
	dataFile.close();
	calcAvg();
	return;
}

Signal::Signal(const char* fileName){
	fstream dataFile;
	
	this->fileName = fileName;
	//Open the correct file
	dataFile.open(fileName);
	
	//Check that the file was opened correctly.
	//If not, set default values and return
	if(!dataFile.is_open()){
		cout<<"\nCould not open "<<fileName<<" setting default values!"<<endl;
		this -> length = 0;
		this -> max_value = 0;
		this -> average = 0;
		return;
	}
	
	//Read the number of integers in the datafile
	dataFile >>  this -> length;
	vector<double> copy(this -> length, 0);
	//Allocate memory for the data array.
	this -> data = copy;
	
	//Read the max value from the data file
	dataFile >> this -> max_value;
	
	//Read the data from the file and place in the data array.
	for(int i = 0; i < this -> data.size(); i++){
		dataFile >> this -> data[i];
	}
	
	dataFile.close();
	calcAvg();
	return;
}

Signal::~Signal(){
	cout<<"Destructor"<<endl;
}

double Signal::calcMaxValue(){
	double hold = 0;
	
	for(int i = 0; i < this -> data.size(); i++){
		if(this -> data[i] > hold)
			hold = this -> data[i];
	}
	
	return(hold);
	
}

void Signal::calcAvg(){
	
	double total = 0;
	
	for(int i = 0; i < this -> data.size(); i++){
		total += this -> data[i];
	}
	
	this -> average = (double)(total) / this -> length;
	
}

void Signal::operator*(double x){
	
	for(int i = 0; i < this -> length; i++){
		this -> data[i] = this -> data[i] * x;
	}
	this -> max_value = calcMaxValue();
	calcAvg();
}

void Signal::operator+(double x){
	
	for(int i = 0; i < this -> length; i++){
		this -> data[i] = this -> data[i] + x;
	}
	this -> max_value = calcMaxValue();
	calcAvg();
}

void Signal::center(){
	this -> operator+(-(this -> average));
	this -> max_value = calcMaxValue();
	calcAvg();
}

void Signal::normalize(){
	operator*(1/(this->max_value));
	this -> max_value = calcMaxValue();
	calcAvg();
	
}

void Signal::Sig_info(){
	cout<<"\nNumber of data points (length): "<<this->length
	<<"\nMaximum value (max_value): "<<this->max_value
	<<"\nAverage of data (average): "<<this->average<<"\n"<<endl;
}

void Signal::Save_file(string newFileName){
	newFileName = std::string(newFileName) + ".txt";
	const char* newFilePtr = newFileName.c_str();
	
	//open save file
	
	ofstream saveFile(newFilePtr);
	
	//Save the Length, Max Value, and the data to the save file
	saveFile << this->length<< " " << this->max_value<<endl;
	
	for(auto i:data){
		saveFile<< i <<endl;
	}
	
	//Close the file
	saveFile.close();
	return;
}

void optionMenu();
double scaling();
double offsetting();
string fileSave();

int main(){
	
	locale loc;
	string userInput;
	string fileName;
	const char* fileNamePtr = fileName.c_str();
	Signal* dataSignal;
	
	cout<<"\n****Lab7****"<<endl;
	while(1){
		
		cout<<"\nEnter 'F' to use the file name or 'N' to use the file number:"<<endl;
		getline(cin, userInput);
		//Convert input to upper case
		for(auto &c : userInput){
			c = toupper(c);
		}
		//Error check input
		while(userInput != "F" && userInput != "N"){
			cout<<"\nInvalid input!"<<endl;
			cout<<"\nEnter 'F' to use the file name or 'N' to use the file number:"<<endl;
			getline(cin, userInput);
			for(auto &c : userInput){
			c = toupper(c);
			}
		}
		//Logic on input
		if(userInput == "F"){
			cout<<"Please enter the file name to be opened:"<<endl;
			getline(cin, fileName);
			dataSignal = new Signal(fileNamePtr);
		}else{
			cout<<"\nPlease enter the file number to be opened:"<<endl;
			getline(cin, userInput);
			//Error check on file number input
			while(userInput.size() > 2 || (!isdigit(userInput[0],loc) && !isdigit(userInput[1],loc))){
				cout<<"\nInvalid file number!"<<endl;
				cout<<"\nPlease enter the file number to be opened:"<<endl;
				getline(cin, userInput);
			}
			if(userInput.size() == 1){
				string hold = userInput;
				userInput = "0";
				userInput = userInput + hold;
			}
			dataSignal = new Signal(userInput);
		}
		
		
		while(1){
			//Display option menu
			optionMenu();
			
			//Get user choice
			getline(cin, userInput);
			
			for(auto &c: userInput){
				c = toupper(c);
			}
			
			if(userInput == "S"){
				dataSignal->operator*(scaling());
			}else if(userInput == "O"){
				dataSignal->operator+(offsetting());
			}else if(userInput == "P"){
				dataSignal->Sig_info();
			}else if(userInput == "C"){
				dataSignal->Sig_info();
			}else if(userInput == "N"){
				dataSignal->normalize();
			}else if(userInput == "V"){
				dataSignal->Save_file(fileSave());
			}else if(userInput == "Q"){
				break;
			}else{
				cout<<"Invalid input!"<<endl;
			}
		}
		
		cout<<"Would you like to manipulate another signal?(Y N)"<<endl;
		getline(cin, userInput);
		for(auto &c: userInput){
			c = toupper(c);
		}
		while(userInput != "Y" && userInput != "N"){
			cout<<"\nInvalid input!"<<endl;
			cout<<"Would you like to manipulate another signal?(Y N)"<<endl;
			getline(cin, userInput);
			for(auto &c:userInput){
				c = toupper(c);
			}
		}
		if(userInput == "N"){
			delete dataSignal;
			break;
		}
		
		delete dataSignal;
		
	}
	
	return(0);
}

void optionMenu(){
	
	cout<<"What would you like to do with the signal?"<<endl;
	cout<<"(S) : Scale the data\n"
		<<"(O) : Offset the data\n"
		<<"(P) : Print statistics for the data\n"
		<<"(C) : Center the data\n"
		<<"(N) : Normalize the data\n"
		<<"(V) : Save data to file\n"
		<<"(Q) : Quit"<<endl;
	return;
}

double scaling(){
	double value;
	
	cout<<"Please enter the value you wish to scale the data by:"<<endl;
	cin >> value;
	
	//Check that the user input is a double type
	while(cin.fail()){
		cin.clear();
		fflush(stdin);
		cout<<"Invalid input! Please enter a number!"<<endl;
		cin >> value;
	}
	fflush(stdin);
	return(value);
	
}

double offsetting(){
	double value;
	
	cout<<"Please enter the value you wish to offset the data by:"<<endl;
	cin >> value;
	
	//Check that the user input is a double type
	while(cin.fail()){
		cin.clear();
		fflush(stdin);
		cout<<"Invalid input! Please enter a number!"<<endl;
		cin >> value;
	}
	fflush(stdin);
	return(value);
}

string fileSave(){
	
	string newFileName;
	
	cout<<"Please enter the name of the file to save the updated data to:"<<endl;
	getline(cin, newFileName);
	
	return(newFileName);
	
}