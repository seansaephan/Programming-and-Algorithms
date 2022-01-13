// video.cpp
// Saephan, Sean
// sksaephan
#include <iostream>
#include <string>
#include "video.h"
using namespace std;

Video::Video(string title, string link, string comment, float length, int rating)
{       //Assigns all of the variables
        pri_title = title;
        pri_link = link;
        pri_comment = comment;
        pri_length = length;
        pri_rating = rating;
}

void Video::print()
{
       //prints the outcome, pulled from lab3 
       cout << pri_title << ", " << pri_link << ", " << pri_comment
               << ", " << pri_length << ", ";

       for(int i=0; i<pri_rating; i++) //This for loop is to print out the ratings
       {
               cout << "*";
       }
       cout << endl;
       
}

bool Video::longer(Video *other) //This is to sort by length
{
        if(pri_length > other -> pri_length)
        {
                return true;
        }
        else
        {
                return false;
        }
}

bool Video::g_title(Video *greater) //This is to sort by title
{
        if(pri_title>greater->pri_title)
        {
                return true;
        }
        else
        {
                return false;
        }
}

bool Video::g_rating(Video *rate) //This is the sort by rating definition.
{
        if(pri_rating>rate->pri_rating)
        {
                return true;
        }
        else
        {
                return false;
        }
}
