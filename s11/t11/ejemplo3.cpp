// PROXY

#include <iostream>
using namespace std;

// Interfaz del video
class Video {
public:
    virtual void reproducir() = 0;
};

// Video real
class VideoReal : public Video {
private:
    std::string titulo;
    std::string url;
public:
    VideoReal(const string& titulo, const string& url):titulo(titulo), url(url) {}

    void reproducir() override {
        std::cout << "Reproduciendo el video: " << titulo << std::endl;
        std::cout << "URL: " << url << std::endl;
    }
};

// Proxy de video
class ProxyVideo : public Video {
private:
    VideoReal videoReal;
    bool tienePermiso;
    bool regionPermitida;

public:
    ProxyVideo(const string& titulo, const std::string& url, bool tienePermiso, bool regionPermitida)
        : videoReal(titulo, url), tienePermiso(tienePermiso), regionPermitida(regionPermitida) {}

    void reproducir() override {
        if (tienePermiso && regionPermitida) {
            videoReal.reproducir();
        } else {
            std::cout << "No se puede reproducir el video. Permiso o region no validos." << std::endl;
        }
    }
};

int main() {
    // Crear instancias de videos
    Video* video1 = new ProxyVideo("Video 1", "https://ejemplo.com/video1.mp4", true, true);
    Video* video2 = new ProxyVideo("Video 2", "https://ejemplo.com/video2.mp4", false, true);
    Video* video3 = new ProxyVideo("Video 3", "https://ejemplo.com/video3.mp4", true, false);

    // Reproducir videos a través del proxy
    video1->reproducir(); // Resultado esperado: Reproduciendo el video: Video 1
    video2->reproducir(); // Resultado esperado: No se puede reproducir el video.
    video3->reproducir(); // Resultado esperado: No se puede reproducir el video.

    // Liberar memoria

    return 0;
}
