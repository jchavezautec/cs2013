#include "emailbuilder.h"

EmailBuilder&  EmailBuilder::header() { return *this; }
EmailBuilder&  EmailBuilder::body() { return *this; }

EmailBuilder&  EmailBuilder::from(string s) {
    email._from = s; 
    return *this;
}

EmailBuilder&  EmailBuilder::to(string s) {
    email._to = s; 
    return *this;
}

EmailBuilder&  EmailBuilder::subject(string s) {
    email._subject = s; 
    return *this;
}

EmailBuilder&  EmailBuilder::body(std::string s) {
    email._body = s; 
    return *this;
}