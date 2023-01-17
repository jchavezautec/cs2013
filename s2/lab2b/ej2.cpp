#include <iostream>
#include <random>

using namespace std;

class matrix{
    public:
        matrix(int rows, int cols);             // Conctructor
        matrix(const matrix &M);                // Permite realizar la copia
        
        matrix operator+(const matrix &M)const; // Sobrecarga al operador +
        int operator()(int row, int col);       // Sobrecarga al operador ()

        ~matrix();          // Destructor
        int get_rows();      // filas
        int get_cols();      // columnas

        void random();      // Rellenar con numeros aleatorios

        // Sobrecarga al operador <<
        friend std::ostream& operator<<(std::ostream& os, matrix &M);
    private:
        int _rows;
        int _cols;
        int **_m;
};

matrix::matrix(int rows, int cols){
    _rows = rows;
    _cols = cols;
    
    _m = new int*[rows];
    for(int i=0; i < rows; i++)
        _m[i] = new int[cols];

    this->random();

}

matrix::matrix(const matrix &M){
    _rows = M._rows;
    _cols = M._cols;
    
    _m = new int*[_rows];
    for(int i=0; i < _rows; i++){
        _m[i] = new int[_cols];
        for(int j=0; j < _cols; j++)
            _m[i][j] = M._m[i][j];
    }
}

matrix::~matrix(){
    for(int i=0; i<_rows; i++)
        delete[] _m[i];
    delete[] _m;
}

int matrix::get_rows(){
    return _rows;
}
int matrix::get_cols(){
    return _cols;
}
int matrix::operator()(int i, int j){
    return _m[i][j];
}

void matrix::random(){
    random_device rd;

    for (int i=0; i < _rows; i++){
        for (int j=0; j < _cols; j++){
            _m[i][j] = static_cast<int>(rd()) % 100;
        }
    }
}

std::ostream& operator<<(std::ostream& os, matrix &M){
    os << endl;
    for (int i=0; i < M.get_rows(); i++){
        os << "| ";
        for (int j=0; j < M.get_cols(); j++){
            os.width(4);
            os << M(i,j) << " ";
        }
        os << "|"<< endl;
    }   
    return os;
}
matrix matrix::operator +(const matrix &M) const{
    if (_rows != M._rows || _cols != M._cols){
        cout << "Las dimensiones no coinciden!" << std::endl;
    }

    matrix res(_rows, _cols);

    for (int i=0; i < _rows; i++){
        for (int j=0; j < _cols; j++){
            res._m[i][j] = _m[i][j] + M._m[i][j];
        }
    }
         

    return res;
}

int main(){   
    matrix m1(4,3);
    cout << m1;
  
    // Copia
    matrix m2 = m1;

    cout << m2;

    matrix m3 = m1 + m2;

    cout << m3;
    return 0;
}