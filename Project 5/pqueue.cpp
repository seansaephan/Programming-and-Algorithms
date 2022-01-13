//pqueue.cpp
//Saephan, Sean
//skssaephan
#include<iostream>
#include<string>
#include "cust.h"
#include "pqueue.h"
using namespace std;

Pqueue::Pqueue()//default constructor
{
        m_head = NULL;
}

Pqueue::~Pqueue()//deconstructor
{
        while(!empty())
        {
                Node *temp = m_head;
                m_head = m_head->m_next;
                delete temp;
        }
                        
}

bool Pqueue::empty()//function to check if pqueue is empty
{
       return(m_head==NULL);
}

void Pqueue::enqueue(Cust *cust, int priority)//function to queue in objects
{
        if(empty())
        {
                m_head = new Node(cust, priority, NULL);
        }
        else
        {
                if(priority < m_head->m_priority)
                {
                        m_head = new Node(cust, priority, m_head);
                }
                else
                {
                        Node *node = m_head;
                        while(node->m_next != NULL && node->m_next->m_priority <= priority)
                        {
                                node = node->m_next;
                        }
                        node->m_next = new Node(cust, priority, node->m_next);
                }
        }
}

Cust *Pqueue::dequeue()//function that dequeues objects
{
        Cust *var = NULL;
        Node *temp;
        if(!empty())
        {
                temp = m_head;
                var = m_head->m_cust;
                m_head = m_head->m_next;
        }
        delete temp;
        return var;
}

int Pqueue::length()//returns the length of the pqueue
{
        Node *temp = m_head;
        int custLength = 0;
        while(temp != NULL)
        {
                custLength++;
                temp = temp->m_next;
        }
        return custLength;
}

int Pqueue::first_priority()//returns the first priority of the pqueue
{
        if(!empty())
        {
                return m_head->m_priority;
        }
        else
        {
                return -1;
        }
}
