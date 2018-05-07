#include "menu.h"
#include <math.h>

using namespace std;

int digits(int x) { //< Conseguir longitud de un entero
    return ((bool) x * (int) log10(abs(x)) + 1);
}

Menu::Menu(Civilizacion<Aldeano> *arr)
{
    string myStr;
    int myInt;
    double myDouble;
    double myDouble2;
    Aldeano a;//< Objeto 'Aldeano'
    Guerrero g;

    while (true) {
        //Nombre de la civ actual
        cout << endl << "-Nombre de la civilizacion: " << arr->getNombreC() << endl<< endl;
        //Opciones del menu
        cout << "1) Agregar aldeano." << endl;
        cout << "2) Eliminar aldeano." << endl;
        cout << "3) Agregar Guerrero." << endl;
        cout << "4) Buscar Guerrero." << endl;
        cout << "5) Modificar Guerrero." << endl;
        cout << "6) Eliminar Guerrero." << endl;
        cout << "7) Mostrar poblacion." << endl;
        cout << "0) Regresar." << endl;
        cout << "Opcion: "; getline(cin, myStr);
        system("cls");

        if (myStr == "1") { //< Agregar aldeano
            //Se piden los datos para el aldeano
            cout << "Ingresa el nombre: ";
            getline(cin, myStr);
            a.setNombreA(myStr);

            cout << "Ingresa la edad: ";
            cin >> myInt;
            a.setEdadA(myInt);

            cin.ignore();
            cout << "Ingresa el genero (H|M): ";
            getline(cin, myStr);
            if (myStr == "H" or myStr == "M") {
                //Si se ingresa una H o una M se setea el genero
                a.setGeneroA(myStr);
            }else{
                //Si se ingresa algo diferente de H o M se cancela
                cout << endl << "-=ERROR: UTILIZA H O M" << endl << endl;
                continue;

            }

            cout << "Ingresa la salud (HP): ";
            cin >> myInt;
            a.setSaludA(myInt);
            cin.ignore();
            /* Se agrega el aldeano al arreglo siempre y cuando no exista uno con el mismo nombre
             * Si 'linearFindData' regresa '-1' el aldeano no existe, así que lo agrego
             */
            myInt = arr->linearFindData(a);
            if(myInt != -1){
                cout << endl << "-=ERROR: EXISTE UN ALDEANO CON EL MISMO NOMBRE=-" << endl << endl;
                continue;
            }else{
                arr->agregarA(a);
            }

        }else if (myStr == "2") { //< Eliminar aldeano
            if(arr->isEmpty()){
                //Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << "-=ERROR: NO HAY ALDEANOS PARA ELIMINAR=-" << endl << endl;
                continue;
            }
            //Si no esta vacío se pide el nombre del aldeano y se hace la busqueda
            cout << "Ingresa el nombre del aldeano a eliminar: ";
            getline(cin, myStr);
            a.setNombreA(myStr);
            myInt = arr->linearFindData(a);
            if(myInt == -1){
                //Si la busqueda regresa -1 el adeano no existe
                cout << endl << "-=ERROR: EL ALDEANO NO EXISTE-=" << endl << endl;
                continue;
            }else{
                //El aldeano existe, preguntar si desea eliminarlo
                cout << "Estas seguro de eliminar a '" << myStr << "'? S/N: ";
                getline(cin, myStr);
                if(myStr == "S"){
                    //Si dice que sí se elimina al aldeano y se envia la confirmación
                    arr->eliminarA(myInt);
                    cout << endl << "-=ALDEANO ELIMINADO=-" << endl << endl;
                }else if(myStr == "N"){
                    //Si dice que no el aldeano vuelve "a su hogar" y se sigue con el menu
                    cout << endl << "-=EL ALDEANO VOLVIO A SU HOGAR=-" << endl << endl;
                    continue;
                }else{
                    //Si se usa una letra diferente de 'S' o 'N'
                    cout << endl << "-=ERROR: OPCION NO VALIDA=-" << endl << endl;
                }
            }

        }else if (myStr == "3") { //< Agregar guerrero

            if (arr->isEmpty()) {
                cout << "-=ERROR: NO PUEDEN EXISTIR GUERREROS SIN ALDEANOS=-"<<endl;
                system("PAUSE");
                continue;
            }
            //Se piden los datos para el guerrero
            cout << "Ingresa el ID (4 digitos): ";
            cin >> myInt;
            cin.ignore();
            if(digits(myInt) != 4){
                cout << "-=ERROR: EL ID SOLO PUEDE TENER 4 DIGITOS=-"<<endl;
                system("PAUSE");
                continue;
            }else{g.setIdGuerrero(myInt);}

            cout << "Ingresa la salud (0 - 100): ";
            cin >> myInt;
            cin.ignore();
            if (myInt > 100) {
                cout << "-=ERROR: LA SALUD NO PUEDE SER MAYOR A 100=-"<<endl;
                system("PAUSE");
                continue;
            }else if (myInt == 0) {
                cout << "-=ERROR: LA SALUD NO PUEDE SER 0 DE INICIO=-"<<endl;
                system("PAUSE");
                continue;
            }else{g.setSaludGuerrero(myInt);}

            cout << "Ingresa la fuerza (0.0 - 60.0): ";
            cin >> myDouble;
            cin.ignore();
            if (myDouble > 60.0) {
                cout << "-=ERROR: LA FUERZA NO PUEDE SER MAYOR A 60.0=-"<<endl;
                system("PAUSE");
                continue;
            }else{g.setFuerzaGuerrero(myDouble);}

            cout << "Ingresa el escudo (0.0 - 30.0): ";
            cin >> myDouble2;
            cin.ignore();
            if (myDouble2 > 30.0) {
                cout << "-=ERROR: EL ESCUDO NO PUEDE SER MAYOR A 30.0=-"<<endl;
                system("PAUSE");
                continue;
            }else{g.setEscudoGuerrero(myDouble2);}

            cout << "Ingresa el tipo de guerrero(Arquero|Mago|Caballero|Heroe): ";
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
                cout << "-=ERROR: NO EXISTE ESE TIPO DE GUERRERO=-";
                continue;
            }
            arr->agregarGuerrero(g);

        }else if (myStr == "4") { //< Buscar guerrero
            cout << "Deseas buscar por: \n";
            cout << "1) Salud mayor igual que.\n";
            cout << "2) Salud menor que.\n";
            cout << "3) Fuerza mayor igual que..\n";
            cout << "4) Fuerza menor que.\n";
            cout << "5) Clase de guerrero.\n";
            cout << "Opcion: ";
            getline(cin, myStr);
            system("cls");

            if (myStr == "1") {
                cout << "Ingresa la salud a buscar: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->saludMayorIgual(myInt);
                } catch (...) {
                    cout << '\n' << "-=GUERREROS IMPRESOS=-" << '\n';
                }
            }else if (myStr == "2") {
                cout << "Ingresa la salud a buscar: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->saludMenorQue(myInt);
                } catch (...) {
                    cout << '\n' << "-=GUERREROS IMPRESOS=-" << '\n';
                }
            }else if (myStr == "3") {
                cout << "Ingresa la fuerza a buscar: ";
                cin >> myDouble;
                cin.ignore();
                try {
                    arr->fuerzaMayorIgual(myDouble);
                } catch (...) {
                    cout << '\n' << "-=GUERREROS IMPRESOS=-" << '\n';
                }
            }else if (myStr == "4") {
                cout << "Ingresa la fuerza a buscar: ";
                cin >> myDouble;
                cin.ignore();
                try {
                    arr->fuerzaMenorQue(myDouble);
                } catch (...) {
                    cout << '\n' << "-=GUERREROS IMPRESOS=-" << '\n';
                }
            }else if (myStr == "5") {
                cout << "Ingresa el tipo a buscar: ";
                getline(cin, myStr);
                cin.ignore();
                try {
                    arr->tipoGuerrero(myStr);
                } catch (...) {
                    cout << '\n' << "-=GUERREROS IMPRESOS=-" << '\n';
                }
            }

        }else if (myStr == "5") { //< Modificar Guerrero
            cout << "Ingresa el ID del guerrero a modificar: ";
            cin >> myInt;
            cin.ignore();
                int findG;
                try {
                    findG = arr->linerFindGuerrero(myInt); //< Regresa 1 o -1
                } catch (...) {
                    cout << "-=ERROR: NO EXISTE EL GUERRERO=-";
                    continue;
                }
            if(findG != -1){
                Guerrero mod = arr->datosG(findG);
                while (true) {
                    cout << mod << endl;
                    cout << "1) Modificar salud\n";
                    cout << "2) Modificar escudo\n";
                    cout << "3) Modificar fuerza\n";
                    cout << "4) Terminar de modificar\n";
                    cout << "Opcion:";

                    int op;
                    cin >> op;
                    int nSalud;

                    system("cls");
                    if (op == 1) {
                        cout << "Ingresa la salud (0 - 100): ";
                        cin >> nSalud;
                        cin.ignore();
                        if (nSalud > 100) {
                            cout << "\n-=ERROR: LA SALUD NO PUEDE SER MAYOR A 100=-\n"<<endl;
                            system("PAUSE");
                            continue;
                        }else{mod.setSaludGuerrero(nSalud); cout << "\n-=SE HA MODIFICADO LA SALUD=-\n"; }
                    }else if (op == 2) {
                        double nDouble;
                        cout << "Ingresa el escudo (0.0 - 30.0): ";
                        cin >> nDouble;
                        cin.ignore();
                        if (nDouble > 30.0) {
                            cout << "\n-=ERROR: EL ESCUDO NO PUEDE SER MAYOR A 30.0=-\n"<<endl;
                            system("PAUSE");
                            continue;
                        }else{mod.setEscudoGuerrero(nDouble);cout << "\n-=SE HA MODIFICADO EL ESCUDO=-\n"; }
                    }else if (op == 3) {
                        double nDouble;
                        cout << "Ingresa la fuerza (0.0 - 60.0): ";
                        cin >> nDouble;
                        cin.ignore();
                        if (nDouble > 60.0) {
                            cout << "\n-=ERROR: LA FUERZA NO PUEDE SER MAYOR A 60.0=-\n"<<endl;
                            system("PAUSE");
                            continue;
                        }else{mod.setFuerzaGuerrero(nDouble);cout << "\n-=SE HA MODIFICADO LA FUERZA=-\n"; }
                    }else if (op == 4) {
                        if (nSalud == 0) {
                            arr->datosG(findG)= mod;
                            arr->eliminarG(findG);
                            cout << "\n-=EL GUERRERO TIENE 0 HP, POR LO TANTO SE HA ELIMINADO=-\n";
                            system("PAUSE");
                            break;
                        }else{
                            arr->datosG(findG)= mod;
                            break;
                        }
                    }
                }
            }

        }else if (myStr == "6") { //< Eliminar Guerrero
            cout << "Deseas eliminar por: \n";
            cout << "1) ID\n";
            cout << "2) Tipo de Guerrero\n";
            cout << "3) Salud menor que...\n";
            cout << "Opcion: ";
            getline(cin, myStr);
            system("cls");

            if (myStr == "1") { //< Eliminar por ID
                cout << "Ingresa el ID del guerrero a eliminar: ";
                cin >> myInt;
                cin.ignore();
                    int findG;
                    try {
                        findG = arr->linerFindGuerrero(myInt); //< Regresa 1 o -1
                    } catch (...) {
                        cout << "-=ERROR: NO EXISTE ESE ID DE GUERRERO=-";
                        continue;
                    }
                    if (findG != -1) {
                        cout << "Estas seguro de eliminar al guerrero? S/N: ";
                        getline(cin, myStr);
                        if (myStr == "S" || myStr == "s") {
                            arr->eliminarG(findG);
                            cout << "\n-=EL GUERRERO HA SIDO DESTRUIDO=-\n";
                        }else{
                            cout << "\n-=EL GUERRERO DEFIENDE SU PUEBLO DE NUEVO=-\n";
                        }
                    }
            }else if (myStr == "2") { //< Eliminar por tipo
                cout << "Ingresa el tipo de guerrero a elimnar: ";
                getline(cin, myStr);

                if (myStr == "Arquero") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << "\n-=SE HA ELIMINADO A LOS ARQUEROS=-\n";
                        continue;
                    }

                }else if (myStr == "Mago") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << "\n-=SE HA ELIMINADO A LOS MAGOS=-\n";
                        continue;
                    }

                }else if (myStr == "Caballero") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << "\n-=SE HA ELIMINADO A LOS CABALLEROS=-\n";
                        continue;
                    }

                }else if (myStr == "Heroe") {
                    try {
                        arr->borrarPorTipo(myStr);
                    } catch (...) {
                        cout << "\n-=SE HA ELIMINADO A LOS HEROES=-\n";
                        continue;
                    }

                }else {
                    cout << "\n-=ERROR: NO EXISTE ESE TIPO DE GUERRERO=-\n";
                    continue;
                }

            }else if (myStr == "3") {//< Eliminar por salud
                cout << "Borrar por salud menor que: ";
                cin >> myInt;
                cin.ignore();
                try {
                    arr->borrarPorSalud(myInt);
                } catch (...) {
                    cout << "-=GUERREROS CON SALUD MENOR BORRADOS=-";
                    continue;
                }
            }

        }else if (myStr == "7") { //< Muestra los aldeanos en la civilizacion actual
            if(arr->isEmpty()){
                //Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << "-=ERROR: NO HAY ALDEANOS O GUERREROS PARA MOSTRAR=-" << endl << endl;
                continue;
            }
            arr->toString(); //< Se imprimen los datos de la civilizacion junto con sus aldeanos y guerreros

        }else if (myStr == "0") {
            break; //< Cierro el ciclo y vuelvo al menu de civilizaciones
        }
    }
}
