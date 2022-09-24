//Clases en c++
#include <iostream>

using namespace std;

//Clase padre o superclase
class Persona {
private: //Atributos que son las caracteristicas, deben ir encapsulados en private para que no se tenga acceso a modificarlos desde fuera
    int edad;
    string nombre;
public: //Metodos que son las acciones que puede generar la clase
    Persona(int, string); //Constructor de la clase padre
   // ~Persona(); //Destructor
    void leer();
    void correr();
    void MostrarDatos();
    virtual void mostrar();//Polimorfismo, se usa la palabra reservada virtual y sirve para reusar la funcion pero con distintos resultados en cada clase
};

//Clase hijo
class Alumno : public Persona {
private: //Atributos de la clase hijo
    string matricula;
    float notaFinal;
public:
    Alumno(int, string, string, float); //Constructor de la clase hijo, se toma en orden en que se fueron poniendo incluyendo las que hereda: int edad, string nombre, string matricula, float notaFinal
    void mostrarAlumno();
    void mostrar();
};

class Profesor : public Persona {
private://Atriburos encapsulados
    string nombreClase;
public:
    Profesor(int, string, string);
    void mostrar();
};

//Constructor de la clase padre, sirve para inicializar los tributos de la clase
//Existe la sobrecarga de constructores, tiende a ser para cuando se quiera meter los atributos de forma distinta, por ejemplo en este caso int, string
Persona::Persona(int _edad, string _nombre) {
    edad = _edad;
    nombre = _nombre;
}
//Destructor
//Persona::~Persona(){}
void Persona::leer() {
    cout << "Soy " << nombre << " y estoy leyendo un libro" << endl;
}

void Persona::correr() {
    cout << "Soy " << nombre << " y estoy corriendo una maraton" << endl;
}

void Persona::MostrarDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

void Persona::mostrar(){
    cout << "Utilizando polimorfismo" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
//Constructor clase hijo
Alumno::Alumno(int _edad, string _nombre, string _matricula, float _notaFinal) : Persona(_edad, _nombre) {
    matricula = _matricula;
    notaFinal = _notaFinal;
}

void Alumno::mostrarAlumno() {
    MostrarDatos();
    cout << "Matricula: " << matricula << endl;
    cout << "Nota Final: " << notaFinal << endl;
}

void Alumno::mostrar(){
    Persona::mostrar();
    cout << "Matricula: " << matricula << endl;
    cout << "Nota Final: " << notaFinal << endl;
}

Profesor::Profesor(int _edad, string _nombre, string _nombreClase): Persona(_edad, _nombre){
    nombreClase = _nombreClase;
}

void Profesor::mostrar() {
    Persona::mostrar();
    cout << "La clase que da es: " << nombreClase << endl;
}

int main()
{
    Persona* vec[3];

    vec[0]= new Alumno(23, "Albertinino", "342213", 8.3);
    vec[0]->mostrar();

    vec[1] = new Alumno(33, "Ainino", "340923", 9.1);
    vec[1]->mostrar();

    vec[2] = new Profesor(23, "Liz", "C++");
    vec[2]->mostrar();


    Persona p1 = Persona(1, "Cacerolo");//Forma 1 de llamar a una clase
    Persona p2(2, "Pituko");//Forma 2 de llamar a una clase
    p1.correr();
    p2.leer();
    p1.mostrar();
    Alumno a1 = Alumno(27, "Rosita", "123456789", 9.7);
    a1.mostrar();
    return 0;
}
//Esto es un comentario de prueba

