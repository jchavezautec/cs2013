#include <iostream>

using namespace std;

// Clase abstracta Character
class Character {
public:
    virtual std::string getInfo() = 0;
};

// Clase concreta PlayerCharacter
class PlayerCharacter : public Character {
public:
    std::string getInfo() override {
        return "Personaje del jugador";
    }
};

// Clase concreta NonPlayerCharacter
class NonPlayerCharacter : public Character {
public:
    std::string getInfo() override {
        return "Personaje no jugador";
    }
};

// Clase abstracta CharacterCreator
class CharacterCreator {
public:
    virtual Character* createCharacter() = 0;
};

// Clase concreta PlayerCharacterCreator
class PlayerCharacterCreator : public CharacterCreator {
public:
    Character* createCharacter() override {
        // Completa el código para crear y retornar una instancia de PlayerCharacter
        return new PlayerCharacter();
    }
};

// Clase concreta NonPlayerCharacterCreator
class NonPlayerCharacterCreator : public CharacterCreator {
public:
    Character* createCharacter() override {
        // Completa el código para crear y retornar una instancia de NonPlayerCharacter
        return new NonPlayerCharacter();
    }
};

int main() {
    CharacterCreator* creator = new PlayerCharacterCreator();
    Character* character = creator->createCharacter();

    // Completa el código para mostrar la información del personaje
    cout << character->getInfo() << endl;
    
    // Resultado esperado en la consola:
    // Información del personaje: Personaje del jugador

    delete character;
    delete creator;

    return 0;
}
