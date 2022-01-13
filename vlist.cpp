//vlist.cpp
//Saephan, Sean
//sksaephan
#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"
using namespace std;

Vlist::Vlist()
{
        m_head = nullptr;
}

void Vlist::insert(Video *other)
{
        if(m_head == NULL || m_head->m_video->getTitle() < m_head->m_next->getTitle())
        {
                m_head = new Node(other, m_head);
        }
        else
        {
                Node *node = m_head;
                while(node->m_next != NULL && node->m_next->m_video->getTitle() < m_head->m_next->getTitle())
                {
                        node = node->m_next;
                }
                node->m_next = new Node(other, node->m_next;);
        }
}
        
void Vlist::print()
{
        Node *ptr = m_head;
        while(ptr != NULL)
        {
                cout << ptr->m_video << ", ";
                ptr = ptr->m_next;
        }
        cout << endl;
}

void Vlist::length()
{

}

void Vlist::lookup()
{

}

bool Vlist::remove(Video *other)
{
        bool result = false;
        if(m_head != NULL)
        {
                if(m_head->m_video == video)
                {
                        Node *nodeToDelete = m_head;
                        m_head = m_head->m_next;
                        delete nodeToDelete;
                        result = true;
                }
                else 
                {
                        Node *node = m_head;
                        while(node->m_next != NULL && node0>m_next->m_value != value)
                        {
                                node = node->m_next;
                        }
                        if(node->m_next != NULL)
                        {
                                Node *nodeToDelete = node->m_next;
                                node->m_next = nodeToDelete->m_next;
                                delete nodeToDelete;
                                result = true;
                        }
                }
        }
        return result;
}

