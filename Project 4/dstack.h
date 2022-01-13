//dstack.h
//Saephan, Sean
//sksaephan
#ifndef DSTACK_H
#define DSTACK_H
class Dstack{
        public:
                Dstack(); //Constructor 
                ~Dstack();//De-constructor
                void push(double value); //Push numbers to the stack
                bool pop(double &value); //Pops numbers to the stack
                int size(); //Returns size of the stack.
                bool empty();//Checks if stack is empty.
        private:
                class Node{
                        public:
                                double m_value; //Double variable for the node
                                Node *m_next;
                                Node(double value, Node *next)
                                {
                                        m_value = value; m_next = next;
                                }
                };
                Node *m_head; //Start of the node
                int m_size = 0; //made m_size equal to 0 so it wont be a random number
};
#endif
