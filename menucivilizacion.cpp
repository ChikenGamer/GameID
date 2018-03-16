#include "menucivilizacion.h"
#include "menu.h"
#include "civilizacion.h"
#include "aldeano.h"
#include "lista.h"

MenuCivilizacion::MenuCivilizacion()
{
    string op;
    //Aldeano a;///Para el aldeano
    //Civilizacion<Aldeano> arr;///Para el arreglo
    Lista<Civilizacion<Aldeano>> list;

    while (true) {
        //Opciones del menu
        cout << "1) Agregar civilizacion a la lista simplemente ligada" << endl;
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
            cout << "Ingresa el nombre: ";
            getline(cin, myStr);

            Civilizacion<Aldeano> c;
            c.setNombreC(myStr);
            list.insertarIn(c);

            cout << "Tam:" << list.tamano() << endl;

            //list.buscarCivilizacion(c);

            //Menu m;

//Código profesor
//            //void agregarCiv(Lista<Civilizacion*> &Lista){
//                //definicion de variables
//                string nombre;
//                //Civilizacion *c = new Civilizacion();
//                cout << "-Nombre de la civilizacion: ";
//                getline(cin, nombre);
//                c->setNombreC(nombre);
//                //insertar en la lista el objeto *c
//                list.insertarIn(c);
//            //}

        }else if(op=="2"){
            /*
             * Buscar civilizacion
             * pedira el nombre de una civilizacíon, si la civilizacion no
             * existe, mostrar un mensaje. Si existe la civilizacion,
             * mostrar el menu de la actividad 01
             */

        }else if (op=="3") {
            /*Eliminar civilizacion
             * Pedira el nombre de la civilizacion y eliminara el nodo de la lista
             * simplemente ligada que corresponda a la civilizacion con ese nombre
             */

        }else if (op=="4") {
            /*Mostrar civilizaciones
             * Muestra en pantalla el nombre de la civilizacion y su población
             */

        }
    }
}
