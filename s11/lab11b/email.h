#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
using namespace std;

class EmailBuilder;

class Email{
    private:
        string _from;
        string _to;
        string _subject;
        string _body; 
    public:
        friend class EmailBuilder;
        friend ostream& operator<<(ostream&  os, const Email& obj);
        static EmailBuilder create();
};

#endif