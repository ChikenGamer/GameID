#include "menucivilizacion.h"
#include "menu.h"
#include "civilizacion.h"
#include "aldeano.h"
#include "lista.h"

using namespace std;

MenuCivilizacion::MenuCivilizacion()
{
    string myStr;

    Lista<Civilizacion<Aldeano>*> list;

    Civilizacion<Aldeano>* pos;

    while (true) {
        //Opciones del menu
        cout << "\t-=GAME ID=-" << endl << endl;
        cout << "1) Agregar nueva civilizacion" << endl;
        cout << "2) Buscar civilizacion" << endl;
        cout << "3) Eliminar civilizacion" << endl;
        cout << "4) Mostrar civilizaciones" << endl;
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

        }else if(myStr == "0"){
            cout << endl <<"\t-=SEE YOU LATER=-"<< endl << endl;
            break;
        }else if (myStr == "5"){ }///To debug
    }
}
