#include "menucivilizacion.h"
using namespace std;

Mapa<string> mapa(9,9, "-");

void respaldar(Lista<Civilizacion<Aldeano>*> &civilizaciones){
    if (civilizaciones.tamano()==0) {//Si no se han creado civilizaciones se manda mensaje y se termina la accion
        cout << endl << "\t\t    -=ERROR: NO EXISTEN DATOS PARA GUARDAR=-" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
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
    ofstream archivo("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\Civilizaciones.txt", ios::out);//< Escuela
    //ofstream archivo("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\Civilizaciones.txt", ios::out);//< Casa

    if(archivo.is_open()){
        for (int i = 0; i < civilizaciones.tamano(); ++i) {
            archivo << civilizaciones[i]->getNombreC() << endl;
            archivo << civilizaciones[i]->getColumnaMapa() << endl;
            archivo << civilizaciones[i]->getFilaMapa() << endl;

            ofstream aldeanos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + ".txt", ios::out); //< Escuela
            //ofstream aldeanos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + ".txt", ios::out); //< Casa

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

            ofstream guerreros("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "_G.txt", ios::out); //< Escuela
            //ofstream guerreros("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "_G.txt", ios::out); //< Casa

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

            ofstream recursos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "_R.txt", ios::out); //< Escuela
            //ofstream recursos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizaciones[i]->getNombreC() + "_R.txt", ios::out); //< Casa

            if(recursos.is_open()){
                for (int j = 0; j < civilizaciones[i]->colaSize(); ++j) {
                    //Obtengo el puntero de la civilizacion
                    Civilizacion<Aldeano> *c = civilizaciones[i];
                    //Salto a la civilizacion y obtengo la referencia
                    //del aldeano "j"
                    Recurso &re = (*c).retrieveRecurso(j);
                    recursos << re.getIdRecurso() << endl;
                    recursos << re.getCantidadRecurso() << endl;
                    recursos << re.getTipoRecurso() << endl;
                }
            }
            recursos.close();
        }
    }
    archivo.close();
    cout << endl << "\t\t    -=LOS DATOS HAN SIDO GUARDADOS CON EXITO=-" << endl << endl;
    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
    return;
}

void recuperar(Lista<Civilizacion<Aldeano>*> &civilizaciones){
    //Se lee el archivo con las civilizaciones
    ifstream archivo("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\Civilizaciones.txt", ios::in);//< Escuela
    //ifstream archivo("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\Civilizaciones.txt", ios::in);//< Casa
    if(!archivo.is_open()){//< Si no se ha leido nada el archivo no existe, mensaje y se regresa
        cout << endl << "\t\t\t-=ERROR: NO EXISTEN DATOS PARA CARGAR=-" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
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
        string civilizacionN;
        string aldeanoS;

        int myInt;
        int columna;
        int fila;

        stringstream ss;

        while (!archivo.eof()) {
            getline(archivo, civilizacionN);

            if (archivo.eof())
                break;

            Civilizacion<Aldeano> *c = new Civilizacion<Aldeano>;
            c->setNombreC(civilizacionN);
            civilizaciones.insertarIn(c);

            getline(archivo, civilizacionS);
            ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
            ss << civilizacionS;
            ss >> columna;
            c->setColumnaMapa(columna);

            getline(archivo, civilizacionS);
            ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
            ss << civilizacionS;
            ss >> fila;
            c->setFilaMapa(fila);

            mapa[fila][columna] = c->getNombreC();

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

            ifstream aldeanos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizacionN + ".txt", ios::in);//< Escuela
            //ifstream aldeanos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizacionN + ".txt", ios::in);//< Casa
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

            ifstream guerreros("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizacionN + "_G.txt", ios::in);//< Escuela
            //ifstream guerreros("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizacionN + "_G.txt", ios::in);//< Casa
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

            ifstream recursos("C:\\Users\\Usuario\\Desktop\\Game_ID5\\Data\\" + civilizacionN + "_R.txt", ios::in);//< Escuela
            //ifstream recursos("C:\\Users\\Oscar Diaz\\Desktop\\Gameid5\\Game_ID5\\Data\\" + civilizacionN + "_R.txt", ios::in);//< Casa

            int iD, cantidad;
            string recursoS;

            if (recursos.is_open()) {
                while (!recursos.eof()) {

                    Recurso re;

                    getline(recursos, recursoS);
                    if (recursos.eof())
                        break;

                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << recursoS;
                    ss >> iD;
                    re.setIdRecurso(iD);

                    getline(recursos, recursoS);
                    ss.clear(); //< Limpio el ss para poder usarlo con un entero y que no lo utilice la basura
                    ss << recursoS;
                    ss >> cantidad;
                    re.setCantidadRecurso(cantidad);

                    getline(recursos, recursoS);
                    re.setTipoRecurso(recursoS);

                    c->agregarRecurso(re);
                }
            }
            recursos.close();

        }
    }
    archivo.close();
    cout << endl << "\t\t    -=LOS DATOS HAN SIDO CARGADOS CON EXITO=-" << endl << endl;
    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
    return;
}

MenuCivilizacion::MenuCivilizacion()
{
    bool dataLoaded = false; //Para no poder sobrecargar los datos dos veces

    string myStr;

    Lista<Civilizacion<Aldeano>*> list;

    Civilizacion<Aldeano>* pos;

    string GameText = R"(
                           __                         __
                          /                        /|/  |
                         ( __  ___  _ _  ___      ( |   |
                         |   )|   )| | )|___)     | |   )
                         |__/ |__/||  / |__       | |__/
                                              ---
                     _______________________________________
                    |             AGE OF EMPIRES            |
                    '------------------' '------------------'
                      )";


    while (true) {
        //Opciones del menu
        system("cls");
        cout << GameText << endl;

        cout << "\t\t1) Agregar nueva civilizacion" << endl;
        cout << "\t\t2) Buscar civilizacion" << endl;
        cout << "\t\t3) Eliminar civilizacion" << endl;
        cout << "\t\t4) Mostrar civilizaciones" << endl;
        cout << "\t\t5) Guardar partida" << endl;
        cout << "\t\t6) Cargar partida" << endl;
        cout << "\t\t0) Cerrar" << endl;
        cout << "\t\tOpcion: "; getline(cin, myStr);
        system("cls");

        if (myStr=="1") {
            /* Agregar civilizacion
             * Creara un objeto apuntador de la clase "civilizacion"
             */
            cout << GameText << endl;

            cout << "\t\t> Ingresa el nombre de la nueva civilizacion: ";
            getline(cin, myStr);
            if (list.posValida(myStr)) {
                cout << endl << "\t\t-=ERROR: YA EXISTE UNA CIVILIZACION CON EL NOMBRE=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

            //Si la civ no existe pido las coordenadas
            string coordX, coordY;
            cout << "\t\t> Ingresa las coordenadas de la civilizacion" << '\n';
            cout << "\t\t - Coordenada en x: ";
            getline(cin, coordX);
            cout << "\t\t - Coordenada en y: ";
            getline(cin, coordY);

            int fila = stoi(coordY);
            int columna = stoi(coordX);

            if (fila > 8 or columna > 8) {
                cout << endl << "\t\t-=ERROR: NO EXISTE ESA COORDENADA=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

            if (mapa[fila][columna] == "-") {

                Civilizacion<Aldeano> *c = new Civilizacion<Aldeano>;
                c->setNombreC(myStr);
                list.insertarIn(c);

                mapa[fila][columna] = c->getNombreC();

                c->setFilaMapa(fila);
                c->setColumnaMapa(columna);

                cout << endl << "\t\t\t-=MENSAJE: CIVILIZACION CREADA=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else {
                cout << endl << "\t\t-=ERROR: YA EXISTE UNA CIVILIZACION EN LA COORDENADA=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        }else if(myStr=="2"){
            /*
             * Buscar civilizacion
             * pedira el nombre de una civilizacíon, si la civilizacion no
             * existe, mostrar un mensaje. Si existe la civilizacion,
             * mostrar el menu de la actividad 01
             */
            cout << GameText << endl;
            if(!list.listaVacia()){
                cout << "\t\t> Nombre de la civilizacion a buscar: ";
                getline(cin, myStr);

                if (list.posValida(myStr)) {//Que hacer si existe la civilizacion
                    pos = list.findData(myStr);
                    system("cls");
                    Menu m(pos);
                }else{
                    cout << endl << "\t\t\t-=ERROR: LA CIVILIZACION NO EXISTE=-" << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else{
                cout << endl << "\t\t\t-=ERROR: NO HAY CIVILIZACIONES=-"<< endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        }else if (myStr=="3") {
            /*Eliminar civilizacion
             * Pedira el nombre de la civilizacion y eliminara el nodo de la lista
             * simplemente ligada que corresponda a la civilizacion con ese nombre
             */
            cout << GameText << endl;
            string op;
            if (!list.listaVacia()) {
                cout << "\t\t> Nombre de la civilizacion a eliminar: ";
                getline(cin, myStr);
                if (list.posValida(myStr)) {
                    cout << "\t\t> Estas seguro de eliminar la civilizacion '" << myStr << "' ? S|N: ";
                    getline(cin, op);
                    if (op == "S" or op == "s") {
                        list.eliminarCiv(myStr);
                        cout << endl << "\t\t\t-=MENSAJE: CIVILIZACION ELIMINADA=-" << endl;
                        cout << endl << "\t\t\t-=MENSAJE: CIVILIZACIONES RESTANTES: " << list.tamano() << " =-" << endl<< endl;
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }else{
                        cout << endl << "\t\t-=MENSAJE: LA CIVILIZACION SOBREVIVIO AL ATENTADO=-" << endl << endl;
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }
                }else{
                    cout << endl << "\t\t\t-=ERROR: LA CIVILIZACION NO EXISTE=-"<< endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else{
                cout << endl << "\t\t\t-=ERROR: NO HAY CIVILIZACIONES=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        }else if (myStr=="4") {
            /*Mostrar civilizaciones
             * Muestra en pantalla el nombre de la civilizacion y su población
             */
            cout << GameText << endl;
            if(!list.listaVacia()){
                cout << endl << "\t\t\t\t   -=RESUMEN=-"<< endl;
                for(int i (0); i < list.tamano(); ++i){
                    list[i]->toString();
                }
                cout << '\n' << '\n';
                cout << endl << "\t\t\t\t    -=MAPA=-" << '\n';
                mapa.mostrarMatriz(mapa.getMatriz());
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{
                cout << endl << "\t\t\t-=ERROR: NO HAY CIVILIZACIONES=-"<< endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        }else if(myStr == "5"){
            cout << GameText << endl;
            respaldar(list);

        }else if(myStr == "6"){
            cout << GameText << endl;
            if (dataLoaded == false) {
                recuperar(list);
                dataLoaded = true;
                continue;
            }
            cout << endl << "\t\t-=LOS DATOS YA HAN SIDO CARGADOS ANTERIORMENTE=-" << endl << endl;
            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
            continue;
        }else if(myStr == "0"){
            cout << GameText << endl;
            cout << endl <<"\t\t\t\t-=HASTA LUEGO=-"<< endl << endl;
            break;
        }else if (myStr == "5"){ }///To debug
    }
}
