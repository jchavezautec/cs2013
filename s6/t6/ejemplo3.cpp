#include <iostream>
#include <forward_list>

using namespace std;

int main(){
    forward_list<int> lista = {1,4,5};

    cout << "Lista Original:" << endl;
    cout << "================" << endl;

    forward_list<int>::iterator i;
    for (i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

	lista.insert_after(lista.begin(),2);
    cout << "\nLista Modificada (insert):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << " ";   
    cout<< endl;

	forward_list<int>::iterator it = lista.begin();
	it = next(it);
	lista.insert_after(it, 3);
    //lista.insert_after(next(lista.begin()),3);

    cout << "\nLista Modificada (insert):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl;
        
	lista.push_front(0);

    cout << "\nLista Modificada (push_front):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl;

    lista.pop_front();

    cout << "\nLista Modificada (pop_front):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl; 

    lista.push_front(3);

    cout << "\nLista Modificada (push_front):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl;  

    lista.remove(3);

    cout << "\nLista Modificada (remove):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl;  

    lista.remove_if([](int x){return x % 2 == 0;});

    cout << "\nLista Modificada (remove_if):" << endl;
    cout << "================================" << endl;
   
    for (int e: lista)
        cout << e << endl;  

    return 0;

}
