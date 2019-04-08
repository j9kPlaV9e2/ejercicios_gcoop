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

        /**
         * Descripción: Devuelve el ganador del partido. Retorna el equipo local, salvo que:
         *              el de visitante tenga 100 o más de suerte o falle (sea false) la cábala del equipo local.
         *              creo que faltaba esto del ejercicio [1]
         */
        Equipo& ponderarSuerte(Equipo& local, Equipo& visitante) {
            if (visitante.suerte() > 99 || !local.cabala() ) return visitante;
            else return local;
        }

        /**
         * Descripción: Presenta los equipos y da el resultado. Modifica variables, escribe en stdout
         */
        void jugar(Equipo& local, Equipo& visitante)
        {
            // Presento equipos
            cout << "El equipo local " << local.nombre() <<
                    " se enfrenta a " << visitante.nombre() << ". Mucha suerte a todos !!!" << endl;

            // Si hay empate, ambos se llevan 1 punto
            if ( esEmpate(local, visitante) ) {
                cout << "\t[=] Es empate !" << endl;
            }
            else {
                // El ganador se lleva 3 puntos
                auto equipo_ganador = ponderarSuerte(local, visitante);
                cout << "\t[+] Gana: " << equipo_ganador.nombre() << " !!!" << endl;
            }
        }


};


int main(int argc, char* argv[]){
    /**
    * [4] indicá quien sería el ganador en cada caso:
    *
    * Local               Visitante
    * Deportivo Moron     San Justo FC
    * Carmen Sandiego     Sacachispas
    * Sacachispas         San Justo FC
    * */    

   DeportivoMoron deportivo_moron;
   SanJustoFC     san_justo_fc;
   CarmenSanDiego carmen_san_diego;
   Sacachispas    sacachispas;

   Cancha         cancha_fabulosa;

   cancha_fabulosa.jugar(deportivo_moron,  san_justo_fc); // Gana Moron
   cancha_fabulosa.jugar(carmen_san_diego, sacachispas);  // Gana Sacachispas, San Diego está flojo de cábala :c
   cancha_fabulosa.jugar(sacachispas,      san_justo_fc); // Es empate
}
