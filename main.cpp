/*
Author: Nick Turner
Date: 2019.4.12
 */
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <math.h>

using namespace std;

//Function declarations
class Postfix{
  public:
    Postfix();
    bool makeStack(float &ans, stack<float> &s, string line);
};

Postfix::Postfix(){}

bool Postfix::makeStack(float &ans, stack<float> &s, string line){
  int varInt;
  float var =0;
  float var1;
  float var2;
  string temp2;
  ans = 0;
  while(true){
    int index = line.find(" ");	//finds a space → should loop for 2 space
    if(line.substr(0, index) != " " && line.substr(0, index) != "  " && line.substr(0, index)!=""){
      //cout<<"Making temp into substring"<<endl; //DEBUG
      string temp = line.substr(0, index);
      //cout<<"Suceeded, temp is: '"<<temp<<"'"<<endl; //DEBUG
      char tempc = temp.at(0);
      //if(temp != " " && temp != "  "){
      //char tempc = temp.at(0);
      if(isdigit(tempc)){
        temp2 = temp.at(0);
        //varInt = stoi(temp);
        var = stof(temp);
        s.push(var);
      } else if(tempc == '^'){
        var1 = s.top();
        s.pop();
        if(s.empty()){
          cout<<"Invalid Expression!"<<endl;
          return false;
        }
        var2 = s.top();
        s.pop();
        var = var1;
        /*for(int i =0; i < var2; i++){
          var += var1 * var1;
          }*/
        var = pow(var2,var1);
        s.push(var);
      }else if(temp.at(0) == '*' || temp.at(0) == '/') {		//checks if operator
        var1 = s.top();
        //cout<<"var1 is: "<<var1<<endl;	//DEBUG
        s.pop();
        if(s.empty()){
          cout<<"Invalid Expression!"<<endl;
          return false;
        }
        var2 = s.top();
        //cout<<"var2 is: "<<var2<<endl;	//DEBUG
        s.pop();
        if(tempc == '*'){
          var = var1*var2;
          //cout<<"Added. var is: "<<var<<endl; //DEBUG
        } else {
          var = var2/var1;
          //cout<<"subtracted. var is: "<<var<<endl; //DEBUG
        }
        s.push(var);
      } else if(tempc == '+' || tempc == '-'){
        var1 = s.top();
        //cout<<"var1 is: "<<var1<<endl;	//DEBUG
        s.pop();
        if(s.empty()){
          cout<<"Invalid Expression!"<<endl;
          return false;
        }
        var2 = s.top();
        //cout<<"var2 is: "<<var2<<endl;	//DEBUG
        s.pop();
        if(tempc == '+'){
          var = var1+var2;
          //cout<<"Added. var is: "<<var<<endl; //DEBUG
        } else {
          var = var2-var1;
          //cout<<"subtracted. var is: "<<var<<endl; //DEBUG
        }
        s.push(var);
      } else {
        //TODO
        //cout<<"Not a valid entry"<<endl;	//DEBUG
        //cout<<"Should be if its a blank space?"<<endl;  //DEBUG
        cout<<"Invalid Expression!"<<endl;
        return false;

      }
    } //FIXME end of the new if statement
    if(line.size() <= 1){
      break;
    }
    line.erase(0,index+1);	//needs the +1 or else it won’t erase the space
    var = 0;
    }
    var = s.top();
    //cout<<"var is: "<<var<<endl; //DEBUG
    s.pop();
    if(!s.empty()){
      cout<<"Invalid Expression!"<<endl;
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
