use std::collections::HashMap;

struct Equipo {
    nombre: String,
    suerte: i32,
    cabala: bool,
}

#[derive(Debug)]
struct Derrotero{
    partidos_ganados: u32,
    partidos_perdidos: u32,
    partidos_empatados: u32,
    puntos: u32
}

struct Torneo {
    tabla_posiciones: HashMap<String, Derrotero>,
}

impl Derrotero {
    fn new() -> Derrotero { Derrotero { partidos_ganados: 0, partidos_perdidos: 0, partidos_empatados: 0, puntos: 0 } }
    fn gana(&mut self)   { self.partidos_ganados+=1 ;  self.puntos+=3; }
    fn empata(&mut self) { self.partidos_empatados+=1; self.puntos+= 1; }
    fn pierde(&mut self) { self.partidos_perdidos+=1 }
}

impl Torneo {

    fn get_derrotero_equipo(&mut self, nombre: &str) -> &mut Derrotero  { self.tabla_posiciones.entry(nombre.to_owned()).or_insert(Derrotero::new()) }
    fn es_empate(&self, equipo_a: &Equipo, equipo_b: &Equipo) -> bool   { (equipo_a.suerte - equipo_b.suerte).abs() <= 2 && !equipo_a.cabala && !equipo_b.cabala }
    fn ventaja_local(&self, local: &Equipo, visitante: &Equipo) -> bool { !(visitante.suerte > 99 || local.cabala == false) }

    fn anunciar_ganador(&mut self, ganador: &Equipo, perdedor: &Equipo) {
        println!("\t [+] Gana {}, más suerte la proxima {} !! ",  ganador.nombre, perdedor.nombre);
        self.get_derrotero_equipo(&ganador.nombre).gana();
        self.get_derrotero_equipo(&perdedor.nombre).pierde();
    }

    fn anunciar_empate(&mut self, local: &Equipo, visitante: &Equipo) {
        println!("\t [=] Empate chiques, se lleva un punto cada uno !! ");
        self.get_derrotero_equipo(&local.nombre).empata();        
        self.get_derrotero_equipo(&visitante.nombre).empata();
    }

    pub fn jugar(&mut self, local: &Equipo, visitante: &Equipo) {
        println!("El equipo local {} se enfrenta a {}", local.nombre, visitante.nombre);

        match self.es_empate(&local, &visitante) {
            true => self.anunciar_empate(&local, &visitante),
            false => match self.ventaja_local(&local, &visitante) {
                true => self.anunciar_ganador(&local, &visitante),
                false => self.anunciar_ganador(&visitante, &local)
            }
        }
    }

    pub fn imprimir_puntajes(&self) {
        println!("\n------ [Tabla de posiciones] ------");
        self.tabla_posiciones.iter().for_each(|p| println!("[+] {} = {:?} puntos", p.0, p.1));
        println!("------------------------------------\n");
    }
}

fn main() {
    let carmen_sandiego = Equipo { nombre: "Carmen Sandiego".to_owned(), suerte: 100, cabala: false };
    let sacachispas     = Equipo { nombre: "Sacachispas"    .to_owned(), suerte: 14, cabala: false, };
    let sanjusto_fc     = Equipo { nombre: "San Justo FC"   .to_owned(), suerte: 12, cabala: false };
    let deportivo_moron = Equipo { nombre: "Deportivo Morón".to_owned(), suerte: 1, cabala: true };

    // Let's rock&roll
    let mut torneo_fabuloso = Torneo { tabla_posiciones: HashMap::new() };

    torneo_fabuloso.jugar(&deportivo_moron, &sanjusto_fc);
    torneo_fabuloso.jugar(&carmen_sandiego, &sacachispas);
    torneo_fabuloso.jugar(&sacachispas, &sanjusto_fc);

    torneo_fabuloso.imprimir_puntajes();
}
