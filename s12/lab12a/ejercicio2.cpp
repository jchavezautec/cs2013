#include <iostream>

using namespace std;

class WindowImp{
    public:
        virtual void DrawOnDesktop() = 0;
};
 
class Window{
    protected:
        WindowImp* _imp; // pueden acceder subclases
    public:
        Window(WindowImp* w){_imp = w;}
        virtual ~Window(){}
        virtual void Draw() = 0;
};
 
class DesktopWindow:public Window{
    public:
        DesktopWindow(WindowImp* w): Window(w){
            std::cout<<"Se necesita una PC con Windows"<<std::endl;
        }
        ~DesktopWindow(){}
        void Draw(){
            _imp->DrawOnDesktop();
        }
};
 
class LinuxImp: public WindowImp{
    public:
        LinuxImp(){
            std::cout<<"Linux seleccionado"<<std::endl;
        }
        ~LinuxImp(){}
        void DrawOnDesktop(){
            std::cout<<"Linux OS para PC configurado..."<<std::endl;
        }
};
 
int main(){
    WindowImp* imp = new LinuxImp;
    
    DesktopWindow app(imp);
    app.Draw();

    delete imp;
    return 0;
};