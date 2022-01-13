//dstack.h
//Saephan, Sean
//sksaephan
#ifndef DSTACK_H
#define DSTACK_H
class Dstack{
        public:
                Dstack();
                ~Dstack();
                void push(double value);
                bool pop(double &value);
                int size();
                bool empty();
        private:
                class Node{
                        public:
                                double m_value;
                                Node *m_next;
                                Node(double value, Node *next)
                                {
                                        m_value = value; m_next = next;
                                }
                };
                Node *m_head;
                int m_size = 0; //made m_size equal to 0 so it wont be a random number
};
#endif
