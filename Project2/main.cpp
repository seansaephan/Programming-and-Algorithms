// main.cpp
// Saephan, Sean
// sksaephan
#include <iostream>
#include <string>
#include "video.h"
using namespace std;

int main()
{
     //Declared variables
     string videoTitle, videoLink, videoComment, videoSort; 
     float videoLength;
     int videoRating;
     int increment = 0;
     int printI = 0;
     Video *videoObj[100]; //Declares the array
     

     //Determines which sorting the user wants to go by
     cin >> videoSort;
     cin.ignore(); // Added a cin ignore here because it was conflictiing with my loop below

     if(videoSort != "rating" && videoSort != "length" && videoSort != "title") //This is to test the user input if it is not
     {                                                                              //rating, length, or title.
             cerr << videoSort << " is not a legal sorting method, giving up." << endl;
             return 1;

     }

     while(getline(cin, videoTitle)) //Created a while loop so it will stop when end of file
     { 
             getline(cin, videoLink); //Only did a getline for string inputs
             getline(cin, videoComment);
             cin >> videoLength;
	         cin.ignore();
             cin >> videoRating;
             cin.ignore();

	     videoObj[increment] = new Video(videoTitle, videoLink, videoComment, videoLength, videoRating); //Implemented the array he so it can take inputs in a loop.
             increment++; //added an increment for the two functions for the loop below.
             printI++;
             if(increment>100) //If user input is more than 100 it will cerr
             {
                     cerr << "Too many videos, giving up." << endl;
                     return 1;
             }
     }

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


     for(int increment=0;increment<printI;increment++) //For loop to cout print
     {
             videoObj[increment]->print();
     }

     



    return 0;
}

