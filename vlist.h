// vlist.h
// Saephan, Sean
// sksaephan
#ifndef VLIST_H
#define VLIST_H

#include <iostream>
#include <string>
#include "video.h"
using namespace std;

class Vlist{
        public:
                Vlist(){m_head = nullptr;}
                void insert(Video *other);
                void print();
                int length();
                void lookup();
                bool remove(Video *other);
        private: 
                class Node{
                    public: 
                           Node(Video *other, Node *next) {m_video = video; m_next = next;}
                           Video *m_video;
                           Node *m_next;
                }
                Node *m_head;
};
#endif
