//sim.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include<string>
#include<fstream>
#include<sstream> 
#include<cstring>
#include "cust.h"
#include "pqueue.h"
using namespace std;

struct Checker //Checker struct from the project instructions
{
        int registerMoney;
        int done_time;
        Cust *cust;

}checker;

void print_time(ostream &os, int clock)//function to print out the time at the end
{
        os << "time = " << clock << endl;
}

void run_simulation(Pqueue &arrival_queue, int num_checkers, int break_duration, ostream &os) 
{
        Pqueue shopping;
        Pqueue checkout; //initialized the pqueue functions
        int clock; //initialized clock here
        const int item_cost = 3; //made a const variable for item cost
        int num_customers = arrival_queue.length(); //initialized num_customers to length of customers
        Checker *checker_array = (Checker*) malloc(num_checkers*sizeof(Checker)); //checker array using malloc        
        for(int i=0;i < num_checkers; i++) //for loop to initialize Checker structs
        {
                checker_array[i].registerMoney = 250;
                checker_array[i].done_time = 0;
                checker_array[i].cust = NULL;
        }
        for(clock = 1; 0<num_customers; clock++) //Clock for loop
        {
               while(arrival_queue.first_priority() == clock) //While loop for printing when they enter
               {
                    Cust *cust = arrival_queue.dequeue();
                    cust->print_entered(os, clock); //dequeues, then prints
                    int time_done = (clock +(cust->numItems() * 2)); //setting time done.
                    shopping.enqueue(cust, time_done);
               } 
               while(shopping.first_priority() == clock) //While loop to print when they are dont shopping 
               {
                    Cust *cust = shopping.dequeue();
                    cust->print_done_shopping(os, clock); //dequeues, prints
                    checkout.enqueue(cust, 0);
               } 
               for (int check=0;check<num_checkers;check++) //For loop for printint when the customer checks out
               {
                       if (checker_array[check].done_time == clock && checker_array[check].cust != NULL) //Checks if there are no customers, and if clock = checker break time
                       {
                               if (checker_array[check].cust->get_Robber() == 1) //Checks if they are a robber
                               {
	                                   checker_array[check].cust->print_paid(os, clock, check, checker_array[check].registerMoney); //Prints checkout of shopper
                                       checker_array[check].registerMoney = 0; //Resets money at 0
                                       checker_array[check].done_time = break_duration + clock;
                               }                        
                               else 
                               {
				                       checker_array[check].cust->print_paid(os, clock, check, checker_array[check].registerMoney);
                                       checker_array[check].registerMoney += (checker_array[check].cust->numItems() * item_cost); //Adds money to the register

                               } 
                       --num_customers; //Deincrements number of customers
                       delete checker_array[check].cust; //Deletes customers in the struct
                       checker_array[check].cust = NULL; //Sets customers to Null;
                       }
               }
               for (int done=0; done<num_checkers;done++) //For loop for printing when they are starting checkout
               {
                       if(checker_array[done].cust == NULL && !checkout.empty() && checker_array[done].done_time <= clock)
                       {
                               checker_array[done].cust = checkout.dequeue(); //Dequeues
                               if(checker_array[done].cust->get_Robber() == 1) 
                               {  
                                       checker_array[done].done_time = clock + 7; //Adds 7 seconds to the robbers clock
                                       checker_array[done].cust->print_started_check(os, clock, done);
                               }
                               else 
                               {
                                       checker_array[done].done_time = (clock + checker_array[done].cust->numItems()); 
                                       checker_array[done].cust->print_started_check(os, clock, done);  //Prints they started shopping
                               }
                      }
               }
        }
        for(int i=0;i<num_checkers;i++)
        {
                os << "registers[" << i << "] = $" << checker_array[i].registerMoney << endl;//prints out the register totals
        }
        print_time(os, clock);//prints the total time
        free(checker_array);//frees malloc
}
int main(int argc, char* argv[])
{
        if(argc < 5 || argc > 5){//if statement to catch cerr
                cerr << "Error: invalid number of command line arguments." << endl;
                exit(1);
        }
        int checkers = atoi(argv[1]);//number of checkers
        int breaks = atoi(argv[2]);;//number of breaks
        Pqueue queue;//initialize pqueue function
        string name, ifRobber, str;//holds name, if customer was robber, and stringstream variable
        int arrival, numItems;//arrival time and number of items customer has
        string in_filename = (argv[3]);//command line input file
        string out_filename = (argv[4]);//command line output file
        string check_dig = argv[1];//checks if digit
	    ifstream in_file(in_filename);

        if(!in_file){//if statement if the program could not open the file
                cerr << "Error: could not open input file <" << in_filename << ">." << endl;
                exit(1);
        }
        ofstream out_file(out_filename);
        if(!out_file){//if cant open output file
                cerr << "Error: coult not open output file <" << out_filename << ">." << endl;
                exit(1);
        }
        for(int i=0; i<strlen(argv[1]);i++){ //checks if checkers are digits
                if(!isdigit(check_dig[i])){
                        cerr << "Error: invalid number of checkers specified." << endl;
                        exit(1);
                }
        }
        if(checkers < 1){//checks to see if there are less than one checker
                cerr << "Error: invalid number of checkers specified." << endl;
                exit(1);
        }
        if(breaks < 0){//checks to see if there are less than zero breaks
                cerr << "Error: invalid checker break duration specified." << endl;
                exit(1);
        }
        while(getline(in_file, str, '\n')){//while loop to get input for file contents
                stringstream ss(str);//Used stringstreams to input the variables into the files
                ss >> name >> ifRobber >> arrival >> numItems;
                queue.enqueue(new Cust(name,(ifRobber == "robber" ? 1 : 0), arrival, numItems), arrival);//queues in the cust object
        }
        in_file.close(); //closes the file
        run_simulation(queue, checkers, breaks, out_file);//runs the simulation
        return 0;
}
