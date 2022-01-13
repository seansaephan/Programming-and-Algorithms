// calc.cpp
// Saephan, Sean
// sksaephan
#include <iostream>
#include "dstack.h"
#include <string>
#include <cctype>
#include <cmath>
using namespace std; 


bool isOp(char &inputOp) //Checks the char to see if it is a valid operator 
{
        bool result = false;
        char op[] = {'+', '-', '*', '/', '^'};

        for(int i=0; i<5; i++){ //Loop to check if operators are true
                if(inputOp==op[i])
                {
                        result = true;
                }
        }
        return result;
}

void calcOperation(char &inputOp, double num, Dstack &calc) //Function to calculate the numbers on the stack.
{
	double leftNum, rightNum; //Declared double functions
  	bool rightN = calc.pop(rightNum); //Created bool variables for pop
    bool leftN = calc.pop(leftNum);
    if(rightN == false || leftN == false){ //Checks if either bool variables are true or false
        	cerr << "Error: Invalid expression." << endl;;
            exit(1);
    }
  	if(inputOp == '-'){ //Checks to see if the char is - and so on for the other if statements. 
        	num = leftNum - rightNum;
	}
  	if(inputOp == '+'){ 
        	num = leftNum + rightNum;
	}
    	if(inputOp == '*'){
              	num = leftNum * rightNum;
	}	
   	if(inputOp == '/'){
               	num = leftNum / rightNum;
		if(rightNum == 0){
			cerr << "Error: Invalid expression." << endl; //Anything divided by zero is 0
			}
	}
	if(inputOp == '^'){
         	num = pow(leftNum, rightNum);
                if(rightNum == 0){ //Anything to the power of zero is 1
                	num = 1;    
                }
	}	
	calc.push(num); //Pushes all of the numbers on the stack.
}

int main(){
        double num; //Declared the double variable
        Dstack calc; //Declared the Dstack variable
        while(cin.peek()!=EOF){ //While loop to stop when EOF                         
                char peek = cin.peek(); //Made a variable to be used like cin.peek()
		        char inputOp; //A char variable to input the operator.
                if((isspace(peek))){ //variable for whitespace
                        cin.ignore();
                }
		        else if(isdigit(peek) || peek == '.'){ //Check if var is a digit and if var is a decimal
                        cin >> num; //User inserts num variable.
                        if(cin.peek() == '.'){ //If the user inputs 1.2.3 it's illegal
                                cerr << "Error: Invalid expression." << endl;
                                exit(1);
                        }
                        calc.push(num); //Pushes the numbers to the stack. 
		        }
		        else if(isOp(peek)){ //Check var to see if it is an legal operator
			        cin >> inputOp;	
				    calcOperation(peek, num, calc); //Function to calculate the numbers on the stack.
                	}
                else{
                        cerr << "Error: Invalid expression." << endl; //If user input is illegal
                        exit(1);
                }
        }
        if(calc.size()==1){ //Checks the size of the stack
		    calc.pop(num); //Pops the numbers and prints them
		    cout << num << endl;
        }
        else{
            cerr << "Error: Invalid expression." << endl; //If no numbers, error
		    exit(1);
        }  
        return 0;
}
