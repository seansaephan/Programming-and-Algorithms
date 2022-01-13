//bst.cpp
//Saephan, Sean
//sksaephan
#include<iostream>
#include "bst.h"
#include<queue>
using namespace std;

Bst::Bst()
{
        m_root = NULL;
}

bool Bst::insert(string str)
{
        bool result = false;
        if(m_root == NULL)
        {
                m_root = new Node(str);
                result = true;
        }
        else
        {
                result = insert(str, m_root);
        }
        return result;
}

bool Bst::find(string value)
{
        return find(value, m_root);
}

void Bst::dft(vector<string> &values)
{
        return dft(values, m_root);
}

void Bst::bft(vector<string> &values)
{
        if(m_root == NULL)
        {
                return;
        }
        queue<Node*> bft_queue;
        bft_queue.push(m_root);
        while(!bft_queue.empty())
        {
                Node *root = bft_queue.front();
                bft_queue.pop();
                values.push_back(root->m_str);
                if(root->m_left != NULL)
                {
                        bft_queue.push(root->m_left);
                }
                if(root->m_right != NULL)
                {
                        bft_queue.push(root->m_right);
                }
        }

}

int Bst::size()
{
        return size(m_root);
}

bool Bst::balanced()
{
        bool result = false;
        if(balanced(m_root) == -1)
        {
                result = true;
        }
        return result;
}

void Bst::rebalance()
{
        vector<string> rebalance;
        dft(rebalance, m_root);
        delete m_root;
        m_root = NULL;
        insert_from_vector(rebalance, 0, rebalance.size()-1);
}

double Bst::average_distance_to_root()
{
        double result = 0.0;
        if(size() != 0)
        {
                int cur_distance = 0;
                int node_count = 0;
                int distances_sum = 0;
                average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_left);
                average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_right);
        }
        result = average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_left) +
                    average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_right);
        return result;
        
}

bool Bst::insert(string str, Node *root)
{
        bool result = false;
        if(str == root->m_str)
        {
                result = false;
        }
        if(str < root->m_str)
        {
                if(root->m_left == NULL)
                {
                        root->m_left = new Node(str);
                        result = true;
                }
                else
                {
                        result = insert(str, root->m_left);
                }
        }
        else
        {
                if(root->m_right == NULL)
                {
                        root->m_right = new Node(str);
                        result = true;
                }
                else
                {
                        result = insert(str, root->m_right);
                }
        }
        return result;
}

bool Bst::find(string str, Node *root)
{
        bool result = false;
        if(root == NULL)
        {
                result = false;
        }
        if(str == root->m_str)
        {
                result = true;
        }
        if(str < root->m_str)
        {
                result = find(str, root->m_left);
        }
        else
        {
                return find(str, root->m_right);
        }

}

void Bst::dft(vector<string> &values, Node *root)
{
        if(root != NULL)
        {
                dft(values, root->m_left);
                values.push_back(root->m_str);
                dft(values, root->m_right);
        }
}

int Bst::balanced(Node *root)
{
        int left = balanced(root->m_left);
        int right = balanced(root->m_right);
        if(left == -1 || right == -1)
        {
                return -1;
        }
        if(root == NULL)
        {
                return = 0;
        }
        int result = -1;
        if((left - right) <= 1)
        {
                result = max(left, right)+1;
        }
        return result;
}

void Bst::insert_from_vector(vector<string> &elements, int start, int end)
{
        if(start <= end)
        {
            if(start == end)
            {
                insert(elements[start]);
            }
            else
            {
                int mid = ((start+end)/2);
                insert(elements[start]);
                insert_from_vector(elements, start, mid-1);
                insert_from_vector(elements, mid+1, end);
            }
       }
}

int Bst::size(Node *root)
{
        int result = 1 + size(root->m_left) + size(root->m_right);
        if(m_root == NULL)
        {
                result = 0;
        }
        return result;
}

void Bst::average_distance_to_root(int cur_distance, int&node_count, int &distances_sum, Node *root)
{
        if(m_root != NULL)
        {
                node_count++;
                int sum = (cur_distance + distances_sum);
                average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_left);
                average_distance_to_root(cur_distance+1, node_count, distances_sum, root->m_right);
        }
       
}
