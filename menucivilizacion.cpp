#include "menucivilizacion.h"
#include "menu.h"
#include "civilizacion.h"
#include "aldeano.h"
#include "lista.h"

MenuCivilizacion::MenuCivilizacion()
{
    string op;

    Lista<Civilizacion<Aldeano>*> list;

    Civilizacion<Aldeano>* pos;

    Aldeano ald, ald2;

    while (true) {
        //Opciones del menu
        cout << "1) Agregar nueva civilizacion" << endl;
        cout << "2) Buscar civilizacion" << endl;
        cout << "3) Eliminar civilizacion" << endl;
        cout << "4) Mostrar civilizaciones" << endl;
        cout << "Opcion: "; getline(cin, op);
        system("cls");

        if (op=="1") {
            /* Agregar civilizacion
             * Creara un objeto apuntador de la clase "civilizacion"
             */

            string myStr;
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


        }else if(op=="2"){
            /*
             * Buscar civilizacion
             * pedira el nombre de una civilizacíon, si la civilizacion no
             * existe, mostrar un mensaje. Si existe la civilizacion,
             * mostrar el menu de la actividad 01
             */
            string myStr;

            cout << "Nombre de la civilizacion a buscar: ";
            getline(cin, myStr);

            if (list.posValida(myStr)) {//Que hacer si existe la civilizacion
                pos = list.findData(myStr);
                Menu m;
            }else{
                cout << endl<< "-=ERROR: LA CIVILIZACION NO EXISTE=-" << endl << endl;
            }

        }else if (op=="3") {
            /*Eliminar civilizacion
             * Pedira el nombre de la civilizacion y eliminara el nodo de la lista
             * simplemente ligada que corresponda a la civilizacion con ese nombre
             */
            string myStr,op;

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
                cout << "-=ERROR: LA CIVILIZACION NO EXISTE=-";
            }

        }else if (op=="4") {
            /*Mostrar civilizaciones
             * Muestra en pantalla el nombre de la civilizacion y su población
             */

        }else if (op == "5"){ }
    }
}
