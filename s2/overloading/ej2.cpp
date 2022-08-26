#include <iostream>
#include <random>

class matrix{
    public:
        matrix(int rows, int cols);
        matrix(const matrix &M);
        matrix operator+(const matrix &M)const;

        ~matrix();
        int row_size();
        int col_size();

        void to_zeros();
        void fill_random();

        int operator()(int row, int col);
        
        friend std::ostream& operator<<(std::ostream& os, matrix &M);

    private:
        int _rows;
        int _cols;
        int *_m;
};

matrix::matrix(int rows, int cols){
    _rows = rows;
    _cols = cols;
    _m = new int[rows * cols];
}
matrix::matrix(const matrix &M){
    _rows = M._rows;
    _cols = M._cols;
    
    _m = new int[_rows * _cols];

    for (int i=0; i < _rows * _cols; i++){
        _m[i] = M._m[i];
    }
}

matrix::~matrix(){
    delete[] _m;
}

int matrix::row_size(){
    return _rows;
}
int matrix::col_size(){
    return _cols;
}
int matrix::operator()(int i, int j){
    return _m[i * _cols + j];
}

void matrix::to_zeros(){
    for (int i=0; i < _rows; i++){
        for (int j=0; j < _cols; j++){
            _m[i * _cols + j] = 0;
        }
    }
}
void matrix::fill_random(){
    std::random_device rd;

    for (int i=0; i < _rows; i++){
        for (int j=0; j < _cols; j++){
            _m[i * _cols + j] = static_cast<int>(rd()) % 100;
        }
    }
}

std::ostream& operator<<(std::ostream& os, matrix &M){
    for (int i=0; i < M.row_size(); i++){
        std::cout << "| ";
        for (int j=0; j < M.col_size(); j++){
            std::cout.width(3);
            std::cout << M(i,j) << " ";
        }
        std::cout.width(1);
        std::cout << "|"<< std::endl;
    }   
}
matrix matrix::operator +(const matrix &M) const{
    if (_rows != M._rows || _cols != M._cols){
        std::cout << "Las dimensiones no coinciden!" << std::endl;
    }

    matrix res(_rows, _cols);

    for (int i=0; i < _rows * _cols; i++)
        res._m[i] = _m[i] + M._m[i]; 

    return res;
}

int main(){   
    /* Ejercicio 1:
      a. Constructor
      b. Sobrecarga al operador '<<'
    */
    matrix m1(4,3);
    m1.fill_random(); // Inicializar con valores aleatorios
    std::cout << m1;
  
    // Ejercicio 2: Copy
    matrix m2 = m1;

    std::cout << m2;

    matrix m3 = m1 + m2;

    std::cout << m3;
    return 0;
}