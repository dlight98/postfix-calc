/*
Author: Nick Turner
Date: 2019.4.12
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Function declarations
//void makeStack(stack<float> &stack, string line){};

//main function
int main(){
	stack<float> stack;
	string line = "";
	while(true){
		cout<<"Enter a postfix expression or quite to exit:";
		getline(cin, line);
		if(line == "quit"){
			break;
		} else {
			cout<<line<<endl;	//temp
		}
	}
	return 0;
}

void makeStack(stack<float> &stack, string line){

}
