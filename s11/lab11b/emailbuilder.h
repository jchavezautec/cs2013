#ifndef EMAILBUILDER_H
#define EMAILBUILDER_H

#include <string>
#include <sstream>
#include "email.h"

using namespace std;

class EmailBuilder
{
    private:
        Email email;
    public:
        operator Email() const { return move(email);}

        EmailBuilder& header();
        EmailBuilder& from(string s);
        EmailBuilder& to(string s);
        EmailBuilder& subject(string s);

        EmailBuilder& body();
        EmailBuilder& body(string s);

        friend std::ostream &operator<<(std::ostream &os, const Email &obj);
};

#endif