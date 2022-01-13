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

void calcOperation(char &inputOp, double num, Dstack &calc)
{
	double leftNum, rightNum;                     
  	bool rightN = calc.pop(rightNum);
    	bool leftN = calc.pop(leftNum);
        if(rightN == false || leftN == false){
        	cerr << "Error: Invalid expression." << endl;;
                exit(1);
        }
  	if(inputOp == '-'){
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
			cerr << "Error: Invalid expression." << endl;
			}
	}
	if(inputOp == '^'){
         	num = pow(leftNum, rightNum);
                if(rightNum == 1){
                	num = 1;    
                }
	}	
	calc.push(num);
}

int main(){
        double num;
        Dstack calc;
        while(cin.peek()!=EOF){                                             
                char var = cin.peek();
		        char inputOp;
                if((isspace(var))){
                        cin.ignore();
                }
		        else if(isdigit(var) || var == '.'){
                        cin >> num;
                        if(cin.peek() == '.'){
                                cerr << "Error: Invalid expression." << endl;
                                exit(1);
                        }
                        calc.push(num);
		        }
		        else if(isOp(var)){
			        cin >> inputOp;	
				calcOperation(var, num, calc);
                	}
                else{
                        cerr << "Error: Invalid expression." << endl;
                        exit(1);
                }
        }
        if(calc.size()==1){
		    calc.pop(num);
		    cout << num << endl;
        }
        else{
            cerr << "Error: Invalid expression." << endl;
		    exit(1);
        }  
        return 0;
}
