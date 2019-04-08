#include <iostream>
#include <cmath>
#include <map>

using namespace std;


/**
  * ==== Ejercicio 2: Modelado de equipos =====
  */
class Equipo {
    protected:
        float   nivel_suerte;
        bool    tiene_cabala;
        string  nombre_equipo;
    public:
        bool    cabala(){ return tiene_cabala;}
        float   suerte(){ return nivel_suerte; }
        string  nombre(){ return nombre_equipo.substr(); }
};


class Sacachispas: public Equipo{
    public:
        Sacachispas() {
            nivel_suerte = 14;
            tiene_cabala = false;
            nombre_equipo = "Sacachispas";
        }
};

class DeportivoMoron: public Equipo{
    public:
        DeportivoMoron(){
            nivel_suerte = 1;
            tiene_cabala = true;
            nombre_equipo = "Deportivo Moron";
        }
};

class CarmenSanDiego: public Equipo{
    public:
        CarmenSanDiego(){
            nivel_suerte = 100;
            tiene_cabala = false;
            nombre_equipo = "Carmen San Diego";
        }
};


class SanJustoFC: public Equipo{
    public:
        SanJustoFC(){
            nivel_suerte = 12;
            tiene_cabala = false;
            nombre_equipo = "San Justo FC";
        }
};
/**
  * ==== / Ejercicio 2: Modelado de equipos =====
*/

int main(int argc, char* argv[]){
}
