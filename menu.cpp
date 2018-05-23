#include <chrono>
#include <random>
#include <functional>
#include <iostream>
#include <math.h>
#include "menu.h"
#include <conio.h>

using namespace std;

Menu::Menu(Civilizacion<Aldeano> *arr)
{
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

    // Numeros random HD
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistribution(1111, 9999);
    auto intDice=bind(intDistribution, generator);
    int idGuerreroGenerador;
    int idRecurso;
    /////////////////////////////

    string myStr;
    int myInt;
    double myDouble;
    double myDouble2;
    Aldeano a;//< Objeto 'Aldeano'
    Guerrero g;
    Recurso r;

    while (true) {
        system("cls");
        cout << GameText << endl;
        //Nombre de la civ actual
        cout << "\n\t\t -Nombre de la civilizacion: " << arr->getNombreC() << endl<< endl;
        //Opciones del menu
        cout << "\t\t+> ALDEANOS" << '\n';
        cout << "\t\t  1) Agregar aldeano." << endl;
        cout << "\t\t  2) Eliminar aldeano." << endl;
        cout << "\n\t\t" << "+> GUERREROS" << '\n';
        cout << "\t\t  3) Agregar Guerrero." << endl;
        cout << "\t\t  4) Buscar Guerrero." << endl;
        cout << "\t\t  5) Modificar Guerrero." << endl;
        cout << "\t\t  6) Eliminar Guerrero." << endl;
        cout << "\n\t\t" << "+> RECURSOS" << '\n';
        cout << "\t\t  7) Agregar recursos." << endl;
        cout << "\t\t  8) Mostrar solo recursos." << endl;
        cout << "\t\t  9) Mostrar recursos por." << endl;
        cout << "\t\t 10) Modificar recurso." << endl;
        cout << "\n\t\t" << "+> MOSTRAR TODO" << '\n';
        cout << "\t\t 11) Mostrar poblacion y recursos." << endl << endl;
        cout << "\t\t  0) Regresar." << endl<< endl;
        cout << "\t\t> Opcion: "; getline(cin, myStr);
        system("cls");

        // ALDEANOS
        if (myStr == "1") { //< Agregar aldeano
            cout << GameText << endl;
            //Se piden los datos para el aldeano
            cout << "\t\t> Ingresa el nombre: ";
            getline(cin, myStr);
            a.setNombreA(myStr);

            cout << "\t\t> Ingresa la edad: ";
            cin >> myInt;
            a.setEdadA(myInt);

            cin.ignore();
            cout << "\t\t> Ingresa el genero (H|M): ";
            getline(cin, myStr);
            if (myStr == "H" or myStr == "M") {
                //Si se ingresa una H o una M se setea el genero
                a.setGeneroA(myStr);
            }else{
                //Si se ingresa algo diferente de H o M se cancela
                cout << endl << "\t\t-=ERROR: UTILIZA H O M" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;

            }

            cout << "\t\t> Ingresa la salud (HP): ";
            cin >> myInt;
            a.setSaludA(myInt);
            cin.ignore();
            /* Se agrega el aldeano al arreglo siempre y cuando no exista uno con el mismo nombre
             * Si 'linearFindData' regresa '-1' el aldeano no existe, así que lo agrego
             */
            myInt = arr->linearFindData(a);
            if(myInt != -1){
                cout << endl << "\t\t-=ERROR: EXISTE UN ALDEANO CON EL MISMO NOMBRE=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{
                arr->agregarA(a);
                cout << endl << "\t\t-=MENSAJE: ALDEANO AGREGADO CON EXITO=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        }else if (myStr == "2") { //< Eliminar aldeano
            cout << GameText << endl;
            if(arr->isEmpty()){
                //Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << endl << "\t\t-=ERROR: NO HAY ALDEANOS PARA ELIMINAR=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }
            //Si no esta vacío se pide el nombre del aldeano y se hace la busqueda
            cout << "\t\t> Ingresa el nombre del aldeano a eliminar: ";
            getline(cin, myStr);
            a.setNombreA(myStr);
            myInt = arr->linearFindData(a);
            if(myInt == -1){
                //Si la busqueda regresa -1 el adeano no existe
                cout << endl << "\t\t-=ERROR: EL ALDEANO NO EXISTE-=" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{
                //El aldeano existe, preguntar si desea eliminarlo
                cout << "\t\t> Estas seguro de eliminar a '" << myStr << "'? S/N: ";
                getline(cin, myStr);
                if(myStr == "S"){
                    //Si dice que sí se elimina al aldeano y se envia la confirmación
                    arr->eliminarA(myInt);
                    cout << endl << "\t\t-=MENSAJE: ALDEANO ELIMINADO=-" << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }else if(myStr == "N"){
                    //Si dice que no el aldeano vuelve "a su hogar" y se sigue con el menu
                    cout << endl << "\t\t-=MENSAJE:EL ALDEANO VOLVIO A SU HOGAR=-" << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }else{
                    //Si se usa una letra diferente de 'S' o 'N'
                    cout << endl << "\t\t-=ERROR: OPCION NO VALIDA=-" << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }

        // GUERREROS

        }else if (myStr == "3") { //< Agregar guerrero
            cout << GameText << endl;
            if (arr->isEmpty()) {
                cout << endl << "\t\t-=ERROR: NO PUEDEN EXISTIR GUERREROS SIN ALDEANOS=-"<<endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }
            //Se piden los datos para el guerrero
            idGuerreroGenerador = intDice();
            cout << "\t\t> ID del guerrero: " << idGuerreroGenerador << '\n';
            g.setIdGuerrero(idGuerreroGenerador);

            cout << "\t\t> Ingresa la salud (0 - 100): ";
            cin >> myInt;
            cin.ignore();
            if (myInt > 100) {
                cout << endl << "\t\t-=ERROR: LA SALUD NO PUEDE SER MAYOR A 100=-"<<endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else if (myInt == 0) {
                cout << endl << "\t\t-=ERROR: LA SALUD NO PUEDE SER 0 DE INICIO=-"<<endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{g.setSaludGuerrero(myInt);}

            cout << "\t\t> Ingresa la fuerza (0.0 - 60.0): ";
            cin >> myDouble;
            cin.ignore();
            if (myDouble > 60.0) {
                cout << endl << "\t\t-=ERROR: LA FUERZA NO PUEDE SER MAYOR A 60.0=-"<<endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{g.setFuerzaGuerrero(myDouble);}

            cout << "\t\t> Ingresa el escudo (0.0 - 30.0): ";
            cin >> myDouble2;
            cin.ignore();
            if (myDouble2 > 30.0) {
                cout << endl << "\t\t-=ERROR: EL ESCUDO NO PUEDE SER MAYOR A 30.0=-"<<endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{g.setEscudoGuerrero(myDouble2);}

            cout << "\t\t> Ingresa el tipo de guerrero" << endl;
            cout << "\t\t Arquero|Mago|Caballero|Heroe : ";
            getline(cin, myStr);
            if (myStr == "Arquero") {
                g.setTipoGuerrero("Arquero");
            }else if (myStr == "Mago") {
                g.setTipoGuerrero("Mago");
            }else if (myStr == "Caballero") {
                g.setTipoGuerrero("Caballero");
            }else if (myStr == "Heroe") {
                g.setTipoGuerrero("Heroe");
            }else{
                cout << endl << "\t\t-=ERROR: NO EXISTE ESE TIPO DE GUERRERO=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }
            arr->agregarGuerrero(g);
            cout << endl << "\t\t-=MENSAJE: GUERRERO AGREGADO CON EXITO=-" << endl << endl;
            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
            continue;

        }else if (myStr == "4") { //< Buscar guerrero
            cout << GameText << endl;
            cout << "\t\t> Deseas buscar por: \n";
            cout << "\t\t1) Salud mayor igual que.\n";
            cout << "\t\t2) Salud menor que.\n";
            cout << "\t\t3) Fuerza mayor igual que..\n";
            cout << "\t\t4) Fuerza menor que.\n";
            cout << "\t\t5) Clase de guerrero.\n";
            cout << "\t\tOpcion: ";
            getline(cin, myStr);
            system("cls");

            if (myStr == "1") {
                cout << GameText << endl;
                cout << "\t\t> Ingresa la salud a buscar: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->saludMayorIgual(myInt);
                } catch (...) {
                    cout << endl << "\t\t-=MENSAJE: GUERREROS IMPRESOS=-" << '\n';
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else if (myStr == "2") {
                cout << GameText << endl;
                cout << "\t\t> Ingresa la salud a buscar: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->saludMenorQue(myInt);
                } catch (...) {
                    cout << '\n' << "\t\t-=MENSAJE: GUERREROS IMPRESOS=-" << '\n';
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else if (myStr == "3") {
                cout << GameText << endl;
                cout << "\t\t> Ingresa la fuerza a buscar: ";
                cin >> myDouble;
                cin.ignore();
                try {
                    arr->fuerzaMayorIgual(myDouble);
                } catch (...) {
                    cout << '\n' << "\t\t-=MENSAJE: GUERREROS IMPRESOS=-" << '\n';
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else if (myStr == "4") {
                cout << GameText << endl;
                cout << "\t\t> Ingresa la fuerza a buscar: ";
                cin >> myDouble;
                cin.ignore();
                try {
                    arr->fuerzaMenorQue(myDouble);
                } catch (...) {
                    cout << '\n' << "\t\t-=MENSAJE: GUERREROS IMPRESOS=-" << '\n';
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }else if (myStr == "5") {
                cout << GameText << endl;
                cout << "\t\t> Ingresa el tipo a buscar: ";
                getline(cin, myStr);
                try {
                    arr->tipoGuerrero(myStr);
                } catch (...) {
                    cout << '\n' << "\t\t-=MENSAJE: GUERREROS IMPRESOS=-" << '\n';
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }

        }else if (myStr == "5") { //< Modificar Guerrero
            cout << GameText << endl;
            cout << "\t\t> Ingresa el ID del guerrero a modificar: ";
            cin >> myInt;
            cin.ignore();
                int findG;
                try {
                    findG = arr->linerFindGuerrero(myInt); //< Regresa 1 o -1
                } catch (...) {
                    cout << endl << "\t\t-=ERROR: NO EXISTE EL GUERRERO=-" << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            if(findG != -1){
                Guerrero mod = arr->datosG(findG);
                while (true) {
                    cout << GameText << endl;
                    cout << mod << endl;
                    cout << "\t\t1) Modificar salud\n";
                    cout << "\t\t2) Modificar escudo\n";
                    cout << "\t\t3) Modificar fuerza\n";
                    cout << "\t\t4) Terminar de modificar\n";
                    cout << "\t\tOpcion:";

                    int op;
                    cin >> op;
                    int nSalud;

                    system("cls");
                    if (op == 1) {
                        cout << GameText << endl;
                        cout << "\t\t> Ingresa la salud (0 - 100): ";
                        cin >> nSalud;
                        cin.ignore();
                        if (nSalud > 100) {
                            cout << endl << "\t\t-=ERROR: LA SALUD NO PUEDE SER MAYOR A 100=-\n"<<endl;
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }else{mod.setSaludGuerrero(nSalud);
                            cout << "\t\t-=MENSAJE: SE HA MODIFICADO LA SALUD=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }
                    }else if (op == 2) {
                        cout << GameText << endl;
                        double nDouble;
                        cout << "\t\t> Ingresa el escudo (0.0 - 30.0): ";
                        cin >> nDouble;
                        cin.ignore();
                        if (nDouble > 30.0) {
                            cout << endl << "\t\t-=ERROR: EL ESCUDO NO PUEDE SER MAYOR A 30.0=-\n"<<endl;
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }else{mod.setEscudoGuerrero(nDouble);cout << "\t\t-=MENSAJE: SE HA MODIFICADO EL ESCUDO=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }
                    }else if (op == 3) {
                        cout << GameText << endl;
                        double nDouble;
                        cout << "\t\t> Ingresa la fuerza (0.0 - 60.0): ";
                        cin >> nDouble;
                        cin.ignore();
                        if (nDouble > 60.0) {
                            cout << endl << "\t\t-=ERROR: LA FUERZA NO PUEDE SER MAYOR A 60.0=-\n"<<endl;
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                                            continue;
                        }else{mod.setFuerzaGuerrero(nDouble);cout << "\t\t-=MENSAJE: SE HA MODIFICADO LA FUERZA=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }
                    }else if (op == 4) {
                        cout << GameText << endl;
                        if (nSalud == 0) {
                            arr->datosG(findG)= mod;
                            arr->eliminarG(findG);
                            cout << endl << "\t\t-=EL GUERRERO TIENE 0 HP, POR LO TANTO SE HA ELIMINADO=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }else{
                            arr->datosG(findG)= mod;
                            cout << endl << "\t\t-=MENSAJE: SE HA TERMINADO DE MODIFICAR EL GUERRERO=-\n"<<endl;
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                            break;
                        }
                    }
                }
            }

        }else if (myStr == "6") { //< Eliminar Guerrero
            cout << GameText << endl;
            cout << "\t\t> Deseas eliminar por: \n";
            cout << "\t\t1) ID\n";
            cout << "\t\t2) Tipo de Guerrero\n";
            cout << "\t\t3) Salud menor que...\n";
            cout << "\t\tOpcion: ";
            getline(cin, myStr);
            system("cls");

            if (myStr == "1") { //< Eliminar por ID
                cout << GameText << endl;
                cout << "\t\t> Ingresa el ID del guerrero a eliminar: ";
                cin >> myInt;
                cin.ignore();
                    int findG;
                    try {
                        findG = arr->linerFindGuerrero(myInt); //< Regresa 1 o -1
                    } catch (...) {
                        cout << endl << "\t\t-=ERROR: NO EXISTE ESE ID DE GUERRERO=-";
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }
                    if (findG != -1) {
                        cout << "\t\t> Estas seguro de eliminar al guerrero? S/N: ";
                        getline(cin, myStr);
                        if (myStr == "S" || myStr == "s") {
                            arr->eliminarG(findG);
                            cout << endl << "\t\t-=MENSAJE: EL GUERRERO HA SIDO DESTRUIDO=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }else{
                            cout << endl << "\t\t-=MENSAJE: EL GUERRERO DEFIENDE SU PUEBLO DE NUEVO=-\n";
                            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                            continue;
                        }
                    }
            }else if (myStr == "2") { //< Eliminar por tipo
                cout << GameText << endl;
                cout << "\t\t> Ingresa el tipo de guerrero a elimnar: ";
                getline(cin, myStr);

                if (myStr == "Arquero") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << endl << "\t\t-=MENSAJE: SE HA ELIMINADO A LOS ARQUEROS=-\n";
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }

                }else if (myStr == "Mago") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << endl << "\t\t-=MENSAJE: SE HA ELIMINADO A LOS MAGOS=-\n";
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }

                }else if (myStr == "Caballero") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << endl << "\t\t-=MENSAJE: SE HA ELIMINADO A LOS CABALLEROS=-\n";
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }

                }else if (myStr == "Heroe") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << endl << "\t\t-=MENSAJE: SE HA ELIMINADO A LOS HEROES=-\n";
                        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                        continue;
                    }

                }else {
                    cout << endl << "\t\t-=MENSAJE: ERROR: NO EXISTE ESE TIPO DE GUERRERO=-\n";
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }

            }else if (myStr == "3") {//< Eliminar por salud
                cout << GameText << endl;
                cout << "\t\t> Borrar por salud menor que: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->borrarPorSalud(myInt);
                } catch (...) {
                    cout << endl << "\t\t-=MENSAJE: GUERREROS CON SALUD MENOR BORRADOS=-";
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }
            }


        // RECURSOS

        }else if (myStr == "7") { //< Agregar recurso
            cout << GameText << endl;
            if (arr->isEmpty()) {
                cout << endl << "\t\t-=ERROR: NO PUEDEN EXISTIR RECURSOS SIN ALDEANOS=-" << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

            idRecurso = intDice();
            cout << "\t\t> ID del recurso: " << idRecurso << '\n';
            r.setIdRecurso(idRecurso);

            cout << "\t\t> Ingrese el tipo de recurso." << '\n';
            cout << "\t\t Madera | Metal | Piedra | Comida : ";
            getline(cin, myStr);
            if (myStr == "Madera" or myStr == "Metal" or myStr == "Piedra" or myStr == "Comida") {
                r.setTipoRecurso(myStr);
            }else{
                cout << endl << "\t\t-=ERROR: NO EXISTE ESE TIPO DE RECURSO=-" << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

            cout << "\t\t> Ingrese la cantidad del recurso: ";
            cin >> myInt;
            cin.ignore();
            r.setCantidadRecurso(myInt);

            arr->agregarRecurso(r);

            cout << endl << "\t\t-=MENSAJE: RECURSO AGREGADO CON EXITO=-" << '\n';
            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
            continue;

        }else if (myStr == "8") { //< Mostrar sólo recurso
            cout << GameText << endl;
            cout << "\t\t> Recuros civilizacion: " << arr->getNombreC() << '\n';
            for (int i = 0; i < arr->colaSize(); ++i) {
                cout << arr->retrieveRecurso(i) << '\n';
            }
            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
            continue;
        }else if (myStr == "9") { //< Mostrar recursos por
            cout << GameText << endl;
            while (true) {
                cout << GameText << endl;
                cout << "\t\t1) Cantidad mayor igual que." << '\n';
                cout << "\t\t2) Cantidad menor que." << '\n';
                cout << "\t\t3) Tipo de recurso." << '\n';
                cout << "\t\t4) Regresar." << '\n';
                cout << "\t\tOpcion: ";
                getline(cin, myStr);
                system("cls");
                if (myStr == "1") {
                    cout << GameText << endl;
                    cout << "\t\t> Ingresa la cantidad a buscar: ";
                    cin >> myInt;
                    cin.ignore();
                    arr->mayorIgualQueCola(myInt);
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }else if (myStr == "2") {
                    cout << GameText << endl;
                    cout << "\t\t> Ingresa la cantidad a buscar: ";
                    cin >> myInt;
                    cin.ignore();
                    arr->menorQueCola(myInt);
                    cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                    continue;
                }else if (myStr == "3") {
                    cout << GameText << endl;
                   cout << "\t\t> Ingresa el tipo de recurso: ";
                   getline(cin, myStr);
                   arr->tipoRecurso(myStr);
                   cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                   continue;
                }else if (myStr == "4") {
                    break;
                }

            }
        }else if (myStr == "10") { //< Modificar recurso TODO
            cout << GameText << endl;
            /*Modificar recurso (pedir el id del recurso y mostrar un men ́u para modificar el atributo
            cantidad; si la cantidad es igual a 0, eliminar de la cola de prioridad ese recurso).*/

            cout << "\t\t> Ingresa el ID del recurso a buscar: ";
            cin >> myInt;
            cin.ignore();

            Recurso nR;
            int find = arr->findRecurso(myInt);
            if (find == -1) {
                cout << endl << "\t\t-=ERROR: ESE RECURSO NO EXISTE=-" << '\n';
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{
                 nR = arr->retrieveRecurso(find);
            }

            cout << "\t\t> Ingrese la nueva cantidad: ";
            cin >> myInt;
            cin.ignore();
            nR.setCantidadRecurso(myInt);

            if (nR.getCantidadRecurso() == 0) {
                arr->retrieveRecurso(find) = nR;
                arr->elimiarRecursoPos(find);
                cout << endl << "\t\t-=EL RECURSO TIENE 0, POR LO TANTO SE HA ELIMINADO=-\n";
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }else{
                arr->retrieveRecurso(find) = nR;
                cout << endl << "\t\t-=MENSAJE: RECURSO MODIFICADO EXITOSAMENTE=-\n";
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }

        // MOSTRAR TODO
        }else if (myStr == "11") { //< Muestra los aldeanos en la civilizacion actual
            cout << GameText << endl;
            if(arr->isEmpty()){
                //Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << endl << "\t\t-=ERROR: NO HAY ALDEANOS O GUERREROS PARA MOSTRAR=-" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
                continue;
            }
            arr->toString(); //< Se imprimen los datos de la civilizacion junto con sus aldeanos y guerreros
            cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
            continue;

        }else if (myStr == "0") {
            cout << GameText << endl;
            break; //< Cierro el ciclo y vuelvo al menu de civilizaciones
        }
    }
}
