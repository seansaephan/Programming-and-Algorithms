//cust.h
//Saephan, Sean
//sksaephan
#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <string>
using namespace std;

class Cust{
        public:
                Cust(string name, bool ifRobber, int time, int numItems);
                int time();//returns time
                int numItems();//returns number of items
                bool get_Robber(); //returns if robber 
                void print_entered(ostream &os, int clock); //prints entered store
                void print_done_shopping(ostream &os, int clock);//prints when done shopping
                void print_started_check(ostream &os, int clock, int numChecker);//prints when started checkout
                void print_paid(ostream &os, int clock, int numChecker, int money);//prints paid or stole
        private:
                string m_name;
                bool m_ifRobber;
                int m_time;
                int m_numItems;
};
#endif

