#include <iostream>
using namespace std;

class Email{
    private:
        string _from;
        string _to;
        string _subject;
        string _body; 
    public:
        Email(string from, string to, string subject, string body){
            _from    = from;
            _to      = to;
            _subject = subject;
            _body    = body;
        }
        friend ostream& operator<<(ostream& os, const Email& obj);
};

ostream& operator<<(ostream& os, const Email& obj){
    return os 
        << "from\t: " << obj._from << endl
        << "to  \t: " << obj._to << endl
        << "subject\t: " << obj._subject << endl
        << "body\t: " << obj._body << endl;
}

int main(){
    Email obj("jchaveza@utec.edu.pe", "alumno@utec.edu.pe", "PC2 Notas", "Su nota es ...");

    cout << obj << endl;

    return 0;
}