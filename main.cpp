// main.cpp
// Saephan, Sean
// sksaephan
#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"
using namespace std;

int main()
{
     //Declared variables
     string videoTitle, videoLink, videoComment, videoSort; 
     float videoLength;
     int videoRating;
     int increment = 0;
     int printI = 0;
      
     

     //Determines which sorting the user wants to go by
     cin >> videoSort;
     cin.ignore(); // Added a cin ignore here because it was conflictiing with my loop below

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
    return 0;
}

