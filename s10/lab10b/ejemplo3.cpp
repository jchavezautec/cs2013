#include "email.h"
#include "emailbuilder.h"

using namespace std;
int main(){
    Email mail = Email::create()
                     .header()
                         .from("jchaveza@utec.edu.pe")
                         .to("alumno@utec.edu.pe")
                         .subject("PC2 Nota")
                     .body()
                         .body("Su nota es ...");
    std::cout << mail << std::endl;
}