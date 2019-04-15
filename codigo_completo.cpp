#include <iostream>
#include <cmath>
#include <map>

using namespace std;

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

// En el commit original me había olvidado de esto :P
class Derrotero {
    public:
    int partidos_ganados, partidos_perdidos, partidos_empatados, puntos;
    Derrotero() : partidos_ganados(0), partidos_empatados(0), partidos_perdidos(0), puntos(0){}
    void gana()   { partidos_ganados++; puntos+= 3; }
    void empata() { partidos_empatados++; puntos+= 1; }
    void pierde() { partidos_perdidos +=1; }
};

class Sacachispas: public Equipo{
    public: Sacachispas() { nivel_suerte = 14; tiene_cabala = false; nombre_equipo = "Sacachispas"; }
};

class DeportivoMoron: public Equipo{
    public: DeportivoMoron(){ nivel_suerte = 1; tiene_cabala = true; nombre_equipo = "Deportivo Moron"; }
};

class CarmenSanDiego: public Equipo{
    public: CarmenSanDiego(){ nivel_suerte = 100; tiene_cabala = false; nombre_equipo = "Carmen San Diego"; }
};

class SanJustoFC: public Equipo{
    public: SanJustoFC(){ nivel_suerte = 12; tiene_cabala = false; nombre_equipo = "San Justo FC"; }
};

class Torneo {
    private:
        // Acá se anotan los puntos, por nombre de equipo que haya jugado en la cancha
        map<string, Derrotero>    tabla_de_puntos;

        bool hay_empate(Equipo& equipo_a, Equipo& equipo_b) const {
            return ( abs(equipo_a.suerte() - equipo_b.suerte()) <= 2 && !equipo_a.cabala() && !equipo_b.cabala() );
        }

        bool hay_ventaja_local(Equipo& local, Equipo& visitante) const {
            return !(visitante.suerte() > 99 || !local.cabala());
        }

        void anunciar_ganador(Equipo& gana, Equipo& pierde) {
            tabla_de_puntos[ gana.nombre() ].gana();
            tabla_de_puntos[ pierde.nombre() ].pierde();
            cout << "\t[+] Gana: " << gana.nombre() << " !!!" << endl;            
        }

        void anunciar_empate(Equipo& local, Equipo& visitante) {
            tabla_de_puntos[ local.nombre() ].empata();
            tabla_de_puntos[ visitante.nombre() ].empata();
            cout << "\t[=] Empatan: " << endl;            
        }

    public:

        void jugar_partido(Equipo& local, Equipo& visitante) {
            cout << "El equipo local " << local.nombre() <<  " se enfrenta a " << visitante.nombre() << endl;

            if ( hay_empate(local, visitante) ) anunciar_empate(local, visitante);
            else hay_ventaja_local(local,visitante) ? anunciar_ganador(local, visitante): anunciar_ganador(visitante, local);
        }

        void imprimir_puntajes(){
            cout << endl << "------ [Tabla de posiciones] ------" << endl;
                for(auto equipo: tabla_de_puntos) cout << "[+] " << equipo.first << " = "
                        << "Gana: "   << equipo.second.partidos_ganados << ", "
                        << "Empata: " << equipo.second.partidos_empatados << ", " 
                        << "Pierde: " << equipo.second.partidos_perdidos << " => " 
                        << "Puntos: " << equipo.second.puntos << endl; 
            cout << "------------------------------------" << endl << endl;  
        }
};

int main(int argc, char* argv[]){
   DeportivoMoron deportivo_moron;
   SanJustoFC     san_justo_fc;
   CarmenSanDiego carmen_san_diego;
   Sacachispas    sacachispas;

   Torneo         torneo_fabuloso;

   torneo_fabuloso.jugar_partido(deportivo_moron,  san_justo_fc); 
   torneo_fabuloso.jugar_partido(carmen_san_diego, sacachispas);  
   torneo_fabuloso.jugar_partido(sacachispas,      san_justo_fc);

   torneo_fabuloso.imprimir_puntajes();
}
