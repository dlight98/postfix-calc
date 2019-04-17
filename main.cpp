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
    bool checkEmpty(stack<float> &s);
};

Postfix::Postfix(){}  //Default constructor -- needed to call makeStack

bool Postfix::checkEmpty(stack<float> &s){
  if(s.empty()){  //checks if the stack is empty; if it is return false
    cout<<"Invalid Expression!"<<endl;
    return true;
  } else {
    return false;
  }

}

bool Postfix::makeStack(float &ans, stack<float> &s, string line){
  float var =0;
  float var1;
  float var2;
  ans = 0;
  while(true){
    int index = line.find(" ");	//finds a space
    if(line.substr(0, index) != " " && line.substr(0, index) != "  " && line.substr(0, index)!=""){ //skips to end if the string is only a space 
      string temp = line.substr(0, index);  //makes temp become the first part of line, before the space
      char tempc = temp.at(0);  //gets the first character from temp
      if(isdigit(tempc)){ //if the first character is a digit
        var = stof(temp); //convert temp to a float and push it to the stack
        s.push(var);
      } else if(tempc == '^'){  //if the first character is a ^
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var1 = s.top();
        s.pop();
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var2 = s.top();
        s.pop();
        var = var1;
        var = pow(var2,var1); //takes the top 2 items on stack and raise the 2nd item to the 1st item power
        s.push(var);
      }else if(temp.at(0) == '*' || temp.at(0) == '/') {		//checks if tempc is a * or /
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }

        var1 = s.top();
        s.pop();
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var2 = s.top();
        s.pop();
        if(tempc == '*'){
          var = var1*var2;
        } else {
          var = var2/var1;
        }
        s.push(var);
      } else if(tempc == '+' || tempc == '-'){
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var1 = s.top();
        s.pop();
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var2 = s.top();
        s.pop();
        if(tempc == '+'){
          var = var1+var2;
        } else {
          var = var2-var1;
        }
        s.push(var);
      } else {
        cout<<"Invalid Expression!"<<endl;
        return false;
      }
    }  
    if(line.size() <= 1){
      break;
    }
    line.erase(0,index+1);	//needs the +1 or else it won’t erase the space
    var = 0;
  }
  var = s.top();
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
  float ans = 0.0;	//need to initialize for the pass through
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
      }
    }
  }
  return 0;
}
