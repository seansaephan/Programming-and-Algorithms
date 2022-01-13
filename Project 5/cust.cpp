//cust.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include "cust.h"
#include<string>
#include<assert.h>
using namespace std;

Cust::Cust(string name, bool ifRobber, int time, int numItems)
{
        m_name = name;
        m_ifRobber = ifRobber;
        m_time = time;
        m_numItems = numItems;
}

int Cust::time()
{
        return m_time;
}
int Cust::numItems()
{
        return m_numItems;
}
bool Cust::get_Robber()
{
        return m_ifRobber;
}

void Cust::print_entered(ostream &os, int clock)//prints out when customer enters store
{
        assert(clock == m_time);
        os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_done_shopping(ostream &os, int clock)//prints when customer is done shopping
{
        os << clock << ": " << m_name << " done shopping" << endl;
}

void Cust::print_started_check(ostream &os, int clock, int numChecker)//prints when customer is started to check out
{
        os << clock << ": " << m_name << " started checkout with checker " << numChecker << endl;
}

void Cust::print_paid(ostream &os, int clock, int numChecker, int money)//prints the paid and stole from checker
{
        if(m_ifRobber == false)
        {
                os << clock << ": " << m_name << " paid $" << (m_numItems*3) << " for " << m_numItems << (m_numItems > 1 ? " items ": " item ")
                        << "to checker "  << numChecker << endl;
        }
        else
        {
                 os << clock << ": " << m_name << " stole $" << money << " and " << m_numItems << (m_numItems > 1 ? " items ": " item ") 
                        << "from checker " << numChecker << endl;
        }
}      
