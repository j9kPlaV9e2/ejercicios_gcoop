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



class Cancha {

    public:

        /**
         * Descripción: Retorna true si ambos equipos empatan (diferencia suerte < 2 y ambos no tienen cabala). No modifica los parámetros
         * Este es el Ejercicio [3]
         */
        bool esEmpate(Equipo& equipo_a, Equipo& equipo_b){
            auto diferencia_suerte = abs(equipo_a.suerte() - equipo_b.suerte());

            if ( diferencia_suerte <= 2 &&
                !equipo_a.cabala() && !equipo_b.cabala() )
                return true;

            return false;
        }
};


int main(int argc, char* argv[]){
}
