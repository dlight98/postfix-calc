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
    /*this is the default constructor
    it is needed to call the methods*/
    bool makeStack(float &ans, stack<float> &s, string line);
    /*This goes through each space on list
    and makes it a float or an operator
    then it does the math
    it returns true if it works and false if it doesn't*/
    bool checkEmpty(stack<float> &s);
    /*checks if the stack is empty and prints out what is needed
    probably not as useful as I thought it would be*/
};

Postfix::Postfix(){}  //Default constructor -- needed to call makeStack

bool Postfix::checkEmpty(stack<float> &s){
  if(s.empty()){  //checks if the stack is empty; if it is return false
    cout<<"Invalid Expression!"<<endl;
    return true;
  }else{
    return false;
  }
}

bool Postfix::makeStack(float &ans, stack<float> &s, string line){
  float var =0; //for the solution -- to be made into ans at the end
  float var1; //becomes the first value on the stack
  float var2; //becomes the second value on the stack
  ans = 0;
  while(true){
    int index = line.find(" ");	//finds a space
    if(line.substr(0, index) != " " && line.substr(0, index) != "  " && line.substr(0, index)!=""){ //skips to end if the string is only a space 
      string temp = line.substr(0, index);  //makes temp become the first part of line, before the space
      char tempc = temp.at(0);  //gets the first character from temp
      if(isdigit(tempc)){ //if the first character is a digit
        var = stof(temp); //convert temp to a float and push it to the stack
        s.push(var);
      }else if(tempc == '^'){  //if the first character is a ^
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var1 = s.top(); //makes var1 the first item on stack
        s.pop();
        if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
          return false; 
        }
        var2 = s.top(); //makes var2 the second item on stack
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
        if(tempc == '*'){ //if tempc is *, multiplies the two
          var = var1*var2;
        }else{
          var = var2/var1;
        }
        s.push(var);
      }else if(tempc == '+' || tempc == '-'){ //checks if tempc is a + or -
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
        }else{
          var = var2-var1;
        }
        s.push(var);
      }else{  //if the input isn't any of the above it returns false
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
  if(checkEmpty(s) == true){  //sees if the stack is empty; quits if it is
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
    if(line == "quit" || line == "exit"){ //quits the loop "quit" or "exit" is types
      break;
    }else{
      if(calc.makeStack(ans, s, line) == true){ //prints the answer if it makes the answer correctly
        cout<<ans<<endl;
      }
    }
  }
  return 0;
}
