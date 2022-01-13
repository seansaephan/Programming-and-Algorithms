//pqueue.h
//Saephan, Sean
//sksaephan
#ifndef PQUEUE_H
#define PQUEUE_H
#include<iostream>
#include "cust.h"
using namespace std;

class Pqueue{
        public:
                Pqueue();
                ~Pqueue();
                void enqueue(Cust *cust, int priority);
                Cust *dequeue();
                bool empty();
                int length();
                int first_priority();
        private:
                class Node{
                        public:
                                int m_priority;
                                Node *m_next;
                                Cust *m_cust;
                                Node(Cust *cust, int priority, Node *next)
                                {m_cust = cust; m_priority = priority; m_next = next;}
                          };
                Node *m_head;
               
};
#endif
