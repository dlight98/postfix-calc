/*
Author: Nick Turner
Date: 2019.4.12
*/
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

//Function declarations
class Postfix{
public:
	Postfix();
	bool makeStack(float &ans, stack<float> &s, string line);
};

Postfix::Postfix(){}

bool Postfix::makeStack(float &ans, stack<float> &s, string line){
	int var;
	int var1;
	int var2;
	string temp2;
	ans = 0;
	/*FIXME
	This current algorithm will only work with single digit variables*/
	//for(int i = 0; i < line.size(); i++){	//Loops for the whole line
	while(true){
		int index = line.find(" ");	//finds a space → should loop for 2 space
		string temp = line.substr(0, index);
		char tempc = temp.at(0);
		if(isdigit(tempc)){
			temp2 = temp.at(0);
			var = stoi(temp);
			cout<<"Found digit: "<<var<<endl; //DEBUG
			s.push(var);
		} else if(temp.at(0) == '^'){
			//TODO insert algorithm here

		}else if(temp.at(0) == '*' || temp.at(0) == '/') {		//checks if operator
			//TODO insert algorithm here

		} else if(tempc == '+' || tempc == '-'){
			var1 = s.top();
			cout<<"var1 is: "<<var1<<endl;	//DEBUG
			s.pop();
			var2 = s.top();
			cout<<"var2 is: "<<var2<<endl;	//DEBUG
			s.pop();
			if(tempc == '+'){
				var = var1+var2;
				cout<<"Added. var is: "<<var<<endl; //DEBUG
			} else {
				var = var2-var1;
				cout<<"subtracted. var is: "<<var<<endl; //DEBUG
			}
			s.push(var);
		} else {
			//TODO
			cout<<"Not a valid entry"<<endl;	//DEBUG
		}
		if(line.size() <= 1){
			break;
		}
		line.erase(0,index+1);	//needs the +1 or else it won’t erase the space
	}
	var = s.top();
	cout<<"var is: "<<var<<endl; //DEBUG
	s.pop();
	if(!s.empty()){
		cout<<"Stack is not empty"<<endl;
		return false;
	}
	ans = var;
	return true;
}

//main function
int main(){
	Postfix calc;	//makes the calculator
	stack<float> s;
	float ans = 0.0;	//need to initialize for a later thing
	string line = "";
	string temp = "";
	while(true){
		cout<<"Enter a postfix expression or quit to exit:";
		getline(cin, line);
		if(line == "quit"){
			break;
		} else {
			if(calc.makeStack(ans, s, line) == true){
				cout<<ans<<endl;
			} else {

			}
			cout<<line<<endl;	//TEMP?
		}
	}
	return 0;
}

/*
int index = line.find(‘ ‘);	//finds a space → should loop for 2 space
string temp = line.substr(0, index…);
if(isdigit(temp.at(0))
var = atof(temp.at(0))
else if	+ * / ^ 		//checks if operator
//insert algorithm here
line.erase(0,index+1)	//needs the +1 or else it won’t erase the space
*/
