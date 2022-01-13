// video.h
// Saephan, Sean
// sksaephan
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;

class Video
{
        public: //Decalred the variables
                Video(string title, string link, string comment, float length, int rating);
                void print(); //This function is to print out the sentence
                bool longer(Video *other); //To sort videos by length
                bool g_title(Video *greater);//Declared sorting by title
                bool g_rating(Video *rate);//Declared sorting by rating
                string getTitle()
                {
                        return pri_title;
                }
                
        private:
                string pri_title; //Added private variables so it could be used in main.
                string pri_link;
                string pri_comment;
                float pri_length;
                int pri_rating;




};
#endif
