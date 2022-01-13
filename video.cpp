// video.cpp
// Saephan, Sean
// sksaephan
#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"
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

bool Sorting()
{
	  if(videoSort=="length") //This is the sorting for length
     {
             for(int forLength=0;forLength<increment-1;forLength++) //Uses the increment variable for the confition
             {
                     for(int nestLength=0;nestLength<increment-forLength-1;nestLength++) //Referenced the example from the project pdf for the body of the loops
                     {
                             if(videoObj[nestLength]->longer(videoObj[nestLength+1]))
                             {
                                     swap(videoObj[nestLength], videoObj[nestLength+1]);
                             }
                     }
             }
     }
     else if(videoSort=="title") //This is sorting by title
     {
             for(int forTitle=0;forTitle<increment-1;forTitle++)
             {
                     for(int nestTitle=0;nestTitle<increment-forTitle-1;nestTitle++)
                     {
                             if(videoObj[nestTitle]->g_title(videoObj[nestTitle+1]))
                               {
                                     swap(videoObj[nestTitle], videoObj[nestTitle+1]);
                               }
                     }
             }
     }
     else if(videoSort=="rating") //his is sorting by rating
     {
             for(int forRating=0;forRating<increment-1;forRating++)
             {
                     for(int nestRating=0;nestRating<increment-forRating-1;nestRating++)
                     {
                             if(videoObj[nestRating+1]->g_rating(videoObj[nestRating]))
                             {
                                     swap(videoObj[nestRating], videoObj[nestRating+1]);
                             }
                     }
             }
     }
}

int videoTest()
{
	if(videoSort != "rating" && videoSort != "length" && videoSort != "title") //This is to test the user input if it is not
     {                                                                              //rating, length, or title.
             cerr << videoSort << " is not a legal sorting method, giving up." << endl;
             return 1;

     }
}
