#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

struct Pixel{
    int r, g, b;
};

void procesar_imagen(vector<Pixel> input, int inicio, int fin){
    for (int i=inicio; i < fin; i++){
        int gray = (input[i].r + input[i].g + input[i].b) / 3;
        input[i].r = gray;
        input[i].g = gray;
        input[i].b = gray;
    }
}

void generar_imagen(vector<Pixel>& img){
    for (int i=0; i < img.size(); i++){
        img[i].r = rand() % 256;
        img[i].g = rand() % 256;
        img[i].b = rand() % 256;
    }
}

void imprimir_imagen(vector<Pixel> img){
    for (int i=0; i < img.size(); i++)
        cout << img[i].r << " " << img[i].g << " " << img[i].b << endl;
}

void procesamiento_1thread(int N){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    vector<Pixel> img1(N);

    generar_imagen(img1);

    t_inicio = chrono::system_clock::now();
    procesar_imagen(img1, 0, img1.size());
    t_final = chrono::system_clock::now();

    chrono::duration<double, milli> elapsed_seconds = t_final - t_inicio;
    cout << "Tiempo de procesamiento: " << elapsed_seconds.count() << "ms" << endl;

    //imprimir_imagen(img2);
}

void procesamiento_paralelo(int N, int n_threads){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    vector<Pixel> img1(N);

    generar_imagen(img1);

    t_inicio = chrono::system_clock::now();
    vector<thread> vthreads;

    for (int i=0; i < n_threads; i++)
        vthreads.push_back(thread(&procesar_imagen, ref(img1), i*N/n_threads, (i+1)*N/n_threads));
    
    for (int i=0; i < n_threads; i++)
        vthreads[i].join();

    t_final = chrono::system_clock::now();

    chrono::duration<double, milli> elapsed_seconds = t_final - t_inicio;
    cout << "Tiempo de procesamiento: " << elapsed_seconds.count() << "ms" << endl;

    //imprimir_imagen(img2);
}

int main(){
    procesamiento_1thread(1000000);
    //procesamiento_paralelo(1000000, 2);
}   