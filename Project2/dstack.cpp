//dstack.cpp
//Saephan, Sean
//sksaephan
#include "dstack.h"
#include <iostream>
#include <string>
using namespace std;

Dstack::Dstack() //initalizies the stack to null
{
        m_head = NULL;
}

Dstack::~Dstack() //deconstructs the stack
{
        double temp;
        while(pop(temp));
}

void Dstack::push(double value) //pushes the values into the stack
{
        m_head = new Node(value, m_head);
        m_size++;
}

bool Dstack::pop(double &value) //pops the values out of the stack. 
{
        bool result = false;
        if (m_head != NULL)
        {
                value = m_head->m_value;
                Node *nodeToDelete = m_head;
                m_head = m_head->m_next;
                delete nodeToDelete;
                result = true;
                m_size--;
        }
        return result; 
}

int Dstack::size() //gives the size of the stack.
{
        return m_size;
     
}

bool Dstack::empty() //checks if the stack is empty. 
{
    return(m_head == NULL);
}
