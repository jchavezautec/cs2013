#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>

using namespace std;

mutex m;

struct Particula2D{
    int x, y;
};

void random_move(vector<Particula2D>& particulas, int height, int width){
    for(auto& p: particulas){
        p.x += rand() % 5 - 2;  // -1, 0, 1
        p.y += rand() % 5 - 2;  // -1, 0, 1

        if(p.x < 0) p.x = 0;                // Limites de la pantalla
        if(p.x >= width) p.x = width - 1; 
        if(p.y < 0) p.y = 0;
        if(p.y >= height) p.y = height - 1;
    }
}

void show(vector<Particula2D>& particulas, int height, int width){
    system("cls");

    char** window = new char*[height];
    for(int i=0; i<height; i++){
        window[i] = new char[width];
        for(int j=0; j<width; j++)
            window[i][j] = ' ';
    }

    for(auto& p: particulas)
        window[p.y][p.x] = '*';

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++)
            cout << window[i][j];
        cout << endl;
    }
    cout << endl;

    for(int i=0; i<height; i++)
        delete[] window[i];
    delete[] window;
}

void sum(vector<Particula2D> vec, int inicio, int fin, Particula2D& res){
    int x = 0, y = 0;
    for(int i=inicio; i<fin; i++){
        x += vec[i].x;
        y += vec[i].y;
    }
    m.lock();
    res.x += x;
    res.y += y;
    m.unlock();
}

int main(){
    int N = 50;
    vector<Particula2D> particulas(N);
    int h  = 10, w = 70;

    generate(particulas.begin(), particulas.end(), [&](){
        return Particula2D{w/2, h/2};
    });

    for(int i=0; i<1000000; i++){
        random_move(particulas, h, w);
        this_thread::sleep_for(chrono::milliseconds(500));
        show(particulas, h, w);

        Particula2D res{0, 0};
        thread t1(sum, particulas, 0, N/2, ref(res));
        thread t2(sum, particulas, N/2, N, ref(res));

        t1.join();
        t2.join();

        cout << "Centroide: " << res.x/particulas.size();
        cout << ", " << res.y/particulas.size() << endl;
    }  


}

