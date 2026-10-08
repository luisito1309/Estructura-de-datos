#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// ===================== CLASE BASE =====================
class Vehiculo
{
private:
    string marca;
    string modelo;
    string color;
    int anio;

protected:
    // Imprime los datos comunes (reutilizable por las clases derivadas)
    void mostrarDatosBase() const
    {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Color: " << color << endl;
        cout << "Anio: " << anio << endl;
    }

public:
    // Constructor
    Vehiculo(string marca, string modelo, string color, int anio)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->color = color;
        this->anio = anio;
    }

    virtual ~Vehiculo() {}

    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    string getColor() const { return color; }
    int getAnio() const { return anio; }

    // Setters
    void setMarca(string marca) { this->marca = marca; }
    void setModelo(string modelo) { this->modelo = modelo; }
    void setColor(string color) { this->color = color; }
    void setAnio(int anio) { this->anio = anio; }

    // Calcula la antigüedad según el año actual del sistema
    int calcularAntiguedad() const
    {
        time_t t = time(nullptr);
        int anioActual = localtime(&t)->tm_year + 1900;
        return anioActual - anio;
    }

    // Método que será sobrescrito en la clase derivada
    virtual void mostrarDatos() const
    {
        cout << "=== DATOS DEL VEHICULO ===" << endl;
        mostrarDatosBase();
        cout << "Antiguedad: " << calcularAntiguedad() << " anios" << endl;
    }
};

// ===================== CLASE DERIVADA =====================
class Motocicleta : public Vehiculo
{
private:
    int cilindrada;

public:
    // Constructor: reutiliza el constructor de la clase base
    Motocicleta(string marca, string modelo, string color, int anio, int cilindrada)
        : Vehiculo(marca, modelo, color, anio)
    {
        this->cilindrada = cilindrada;
    }

    int getCilindrada() const { return cilindrada; }
    void setCilindrada(int cilindrada) { this->cilindrada = cilindrada; }

    // Sobreescritura de mostrarDatos()
    void mostrarDatos() const override
    {
        cout << "=== DATOS DE LA MOTOCICLETA ===" << endl;
        mostrarDatosBase(); // código reutilizado de Vehiculo
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "Antiguedad: " << calcularAntiguedad() << " anios" << endl;
    }
};

// ===================== PROGRAMA PRINCIPAL =====================
int main()
{
    // 1. Crear objeto Vehiculo
    Vehiculo auto1("Toyota", "Corolla", "Azul", 2024);

    // 2. Crear objeto Motocicleta
    Motocicleta moto1("Yamaha", "R15", "Gris", 2021, 250);

    // 3 y 4. Calcular antigüedad y mostrar información completa
    auto1.mostrarDatos();
    cout << endl;
    moto1.mostrarDatos();

    // 5. Demostrar herencia y reutilización de código
    cout << endl
         << "--- Demostracion de herencia ---" << endl;
    cout << "Marca de la moto (getter heredado): " << moto1.getMarca() << endl;
    cout << "Antiguedad de la moto (metodo heredado): "
         << moto1.calcularAntiguedad() << " anios" << endl;

    return 0;
}