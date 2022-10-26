#include "email.h"
#include "emailbuilder.h"

EmailBuilder Email::create(){
    return EmailBuilder{};
}

std::ostream &operator<<(std::ostream& os, const Email& obj)
{
    return os
           << "from\t: " << obj._from << endl
           << "to  \t: " << obj._to << endl
           << "subject\t: " << obj._subject << endl
           << "body\t: " << obj._body << endl;
}