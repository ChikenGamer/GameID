#include "menucivilizacion.h"
using namespace std;

void respaldar(Lista<Civilizacion<Aldeano>*> &civilizaciones){
    if (civilizaciones.tamano()==0) {//Si no se han creado civilizaciones se manda mensaje y se termina la accion
        cout << "-=ERROR: NO EXISTEN DATOS PARA GUARDAR=-" << endl << endl;
        return;
    }
    /*
     * Se crea el archivo para guardar las civilizaciones
     * 'for' hasta el numero total de civilizaciones
     * Se introduce en el archivo el nombre de cada civ.
     * Se crea el archivo con el nombre de cada civilizacion y se guardan los aldeanos correspondientes
     * Se cierra el archivo aldeanos
     * Se cierra el archivo de civilizacion
     * Se manda mensaje de operacion realizada con exito
     */
    //ofstream archivo("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\Civilizaciones.txt", ios::out);//< Escuela
    ofstream archivo("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\Civilizaciones.txt", ios::out);//< Casa

    if(archivo.is_open()){
        for (int i = 0; i < civilizaciones.tamano(); ++i) {
            archivo << civilizaciones[i]->getNombreC() << endl;

            //ofstream aldeanos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + ".txt", ios::out); //< Escuela
            ofstream aldeanos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + ".txt", ios::out); //< Casa

            if(aldeanos.is_open()){
                for (int j = 0; j < civilizaciones[i]->poblacionT(); ++j) {
                    //Obtengo el puntero de la civilizacion
                    Civilizacion<Aldeano> *c = civilizaciones[i];
                    //Salto a la civilizacion y obtengo la referencia
                    //del aldeano "j"
                    Aldeano &aldeano = (*c)[j];
                    aldeanos << aldeano.getNombreA() << endl;
                    aldeanos << aldeano.getEdadA() << endl;
                    aldeanos << aldeano.getGeneroA() << endl;
                    aldeanos << aldeano.getSaludA() << endl;
                }
            }
            aldeanos.close();

            //ofstream guerreros("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "G.txt", ios::out); //< Escuela
            ofstream guerreros("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "G.txt", ios::out); //< Casa

            if(guerreros.is_open()){
                for (int j = 0; j < civilizaciones[i]->guerrerosSize(); ++j) {
                    //Obtengo el puntero de la civilizacion
                    Civilizacion<Aldeano> *c = civilizaciones[i];
                    //Salto a la civilizacion y obtengo la referencia
                    //del aldeano "j"
                    Guerrero &war = (*c).datosG(j);
                    guerreros << war.getTipoGuerrero() << endl;
                    guerreros << war.getIdGuerrero() << endl;
                    guerreros << war.getEscudoGuerrero() << endl;
                    guerreros << war.getFuerzaGuerrero() << endl;
                    guerreros << war.getSaludGuerrero() << endl;
                }
            }
            guerreros.close();
        }
    }
    archivo.close();
    cout << endl << "-=LOS DATOS SE HAN GUARDADO CON EXITO=-" << endl << endl;
}

void recuperar(Lista<Civilizacion<Aldeano>*> &civilizaciones){
    //Se lee el archivo con las civilizaciones
    //ifstream archivo("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\Civilizaciones.txt", ios::in);//< Escuela
    ifstream archivo("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\Civilizaciones.txt", ios::in);//< Casa
    if(!archivo.is_open()){//< Si no se ha leido nada el archivo no existe, mensaje y se regresa
        cout << "-=ERROR: NO EXISTEN DATOS PARA CARGAR=-" << endl << endl;
        return;
    }
    /*
     * Si el archivo se abrio
     * Declaro variables a usar (Posible exceso)
     * 'while' hasta que el archivo termine, consigo primer linea
     * Si el archivo termino rompo el ciclo
     * Creo punteros para añadir nuevas civilizaciones y añado con el nombre que viene en el archivo y se inserta en la lista ligada
     */
    if(archivo.is_open()){

        string civilizacionS;
        string aldeanoS;

        int myInt;

        stringstream ss;

        while (!archivo.eof()) {
            getline(archivo, civilizacionS);

            if (archivo.eof())
                break;

            Civilizacion<Aldeano> *c = new Civilizacion<Aldeano>;
            c->setNombreC(civilizacionS);
            civilizaciones.insertarIn(c);

            /*
             * Leo el archivo con el nombre de la civilizacion
             * Existe, dado que arriba comprobe eso
             * 'while' hasta el final del archivo
             * Creo objeto 'Aldeano'
             * Consigo la primer linea, miro si el archivo termino, si es así, cierro ese ciclo
             * si no, añado los atributos a mi aldeano (nombre,edad,genero,salud) y lo añado a su civilizacion
             * Cierro el archivo aldeanos
             * Regreso al ciclo, si he terminado cierro el archivo de las civilizaciones y mando mensaje de carga exitosa
             */

            //ifstream aldeanos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizacionS + ".txt", ios::in);//< Escuela
            ifstream aldeanos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizacionS + ".txt", ios::in);//< Casa
            if (aldeanos.is_open()) {
                while (!aldeanos.eof()) {

                    Aldeano aldeano;

                    getline(aldeanos, aldeanoS);
                    if (aldeanos.eof())
                        break;
                    aldeano.setNombreA(aldeanoS);//< Añado directamente el string a un dato string, en este caso el nombre

                    getline(aldeanos, aldeanoS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << aldeanoS;
                    ss >> myInt;
                    aldeano.setEdadA(myInt);

                    getline(aldeanos, aldeanoS);
                    aldeano.setGeneroA(aldeanoS);

                    getline(aldeanos, aldeanoS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << aldeanoS;
                    ss >> myInt;
                    aldeano.setSaludA(myInt);

                    c->agregarA(aldeano);
                }
            }
            aldeanos.close();

            //ifstream guerreros("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizacionS + ".txt", ios::in);//< Escuela
            ifstream guerreros("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizacionS + "G.txt", ios::in);//< Casa
            double fuerza, escudo;
            int id, vida;
            string guerreroS;
            if (guerreros.is_open()) {
                while (!guerreros.eof()) {

                    Guerrero guerrero;

                    getline(guerreros, guerreroS);
                    if (guerreros.eof())
                        break;

                    guerrero.setTipoGuerrero(guerreroS);//< Añado directamente el string a un dato string, en este caso el nombre

                    getline(guerreros, guerreroS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << guerreroS;
                    ss >> id;
                    guerrero.setIdGuerrero(id);

                    getline(guerreros, guerreroS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << guerreroS;
                    ss >> escudo;
                    guerrero.setEscudoGuerrero(escudo);

                    getline(guerreros, guerreroS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << guerreroS;
                    ss >> fuerza;
                    guerrero.setFuerzaGuerrero(fuerza);

                    getline(guerreros, guerreroS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << guerreroS;
                    ss >> vida;
                    guerrero.setSaludGuerrero(vida);

                    c->agregarGuerrero(guerrero);
                }
            }
            guerreros.close();
        }
    }
    archivo.close();
    cout << endl << "-=LOS DATOS SE HAN CARGADO CON EXITO=-" << endl << endl;
}


MenuCivilizacion::MenuCivilizacion()
{
    string myStr;

    Lista<Civilizacion<Aldeano>*> list;

    Civilizacion<Aldeano>* pos;

    while (true) {
        //Opciones del menu

        //http://www.kammerl.de/ascii/AsciiSignature.php
        cout << "  __                         __ " << endl;
        cout << " /                        /|/  |" << endl;
        cout << "( __  ___  _ _  ___      ( |   |" << endl;
        cout << "|   )|   )| | )|___)     | |   )"  << endl;
        cout << "|__/ |__/||  / |__       | |__/ "  << endl;
        cout << "                     ---        " << endl;
        //cout << "\t-=Game_ID=-" << endl << endl;
        cout << "1) Agregar nueva civilizacion" << endl;
        cout << "2) Buscar civilizacion" << endl;
        cout << "3) Eliminar civilizacion" << endl;
        cout << "4) Mostrar civilizaciones" << endl;
        cout << "5) Guardar partida" << endl;
        cout << "6) Cargar partida" << endl;
        cout << "0) Cerrar" << endl;
        cout << "Opcion: "; getline(cin, myStr);
        system("cls");

        if (myStr=="1") {
            /* Agregar civilizacion
             * Creara un objeto apuntador de la clase "civilizacion"
             */

            cout << "Ingresa el nombre de la nueva civilizacion: ";
            getline(cin, myStr);
            if (list.posValida(myStr)) {
                cout << endl << "-=ERROR: YA EXISTE UNA CIVILIZACION CON EL NOMBRE=-" << endl << endl;
                continue;
            }
            Civilizacion<Aldeano> *c = new Civilizacion<Aldeano>;
            c->setNombreC(myStr);
            list.insertarIn(c);

            cout << endl << "-=CIVILIZACION CREADA=-" << endl << endl;


        }else if(myStr=="2"){
            /*
             * Buscar civilizacion
             * pedira el nombre de una civilizacíon, si la civilizacion no
             * existe, mostrar un mensaje. Si existe la civilizacion,
             * mostrar el menu de la actividad 01
             */
            if(!list.listaVacia()){
                cout << "Nombre de la civilizacion a buscar: ";
                getline(cin, myStr);

                if (list.posValida(myStr)) {//Que hacer si existe la civilizacion
                    pos = list.findData(myStr);
                    Menu m(pos);
                }else{
                    cout << endl<< "-=ERROR: LA CIVILIZACION NO EXISTE=-" << endl << endl;
                }
            }else{
                cout << endl << "-=ERROR: NO HAY CIVILIZACIONES=-"<< endl << endl;
            }

        }else if (myStr=="3") {
            /*Eliminar civilizacion
             * Pedira el nombre de la civilizacion y eliminara el nodo de la lista
             * simplemente ligada que corresponda a la civilizacion con ese nombre
             */
            string op;
            if (!list.listaVacia()) {
                cout << "Nombre de la civilizacion a eliminar: ";
                getline(cin, myStr);
                if (list.posValida(myStr)) {
                    cout << "Estas seguro de eliminar la civilizacion '" << myStr << "' ? S/N: ";
                    getline(cin, op);
                    if (op == "S" or op == "s") {
                        list.eliminarCiv(myStr);
                        cout << endl << "-=CIVILIZACION ELIMINADA=-" << endl;
                        cout << endl << "-=CIVILIZACIONES RESTANTES: " << list.tamano() << " =-" << endl<< endl;
                    }else{
                        cout << endl << "-=LA CIVILIZACION SOBREVIVIO AL ATENTADO=-" << endl << endl;
                    }
                }else{
                    cout << endl << "-=ERROR: LA CIVILIZACION NO EXISTE=-"<< endl << endl;
                }
            }else{
                cout << endl << "-=ERROR: NO HAY CIVILIZACIONES=-"<< endl << endl;
            }

        }else if (myStr=="4") {
            /*Mostrar civilizaciones
             * Muestra en pantalla el nombre de la civilizacion y su población
             */
            if(!list.listaVacia()){
                cout << "\t-=RESUMEN=- \n";
                for(int i (0); i < list.tamano(); ++i){
                    list[i]->toString();
                }
            }else{
                cout << endl <<"-=ERROR: NO HAY CIVILIZACIONES=-"<< endl << endl;
            }

        }else if(myStr == "5"){
            respaldar(list);
        }else if(myStr == "6"){
            recuperar(list);
        }else if(myStr == "0"){
            cout << endl <<"\t-=SEE YOU LATER=-"<< endl << endl;
            break;
        }else if (myStr == "5"){ }///To debug
    }
}
