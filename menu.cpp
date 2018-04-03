#include "menu.h"
#include "civilizacion.h"
#include "aldeano.h"
using namespace std;
Menu::Menu(Civilizacion<Aldeano> *arr)
{
    string myStr;
    int myInt;
    Aldeano a;///Para el aldeano
    ///Para el arreglo

    while (true) {
        ///nombre de la civ actual
        cout << endl << "-Nombre de la civilizacion: " << arr->getNombreC() << endl<< endl;
        ///Opciones del menu
        cout << "1) Agregar aldeano." << endl;
        cout << "2) Eliminar aldeano." << endl;
        cout << "3) Mostrar aladenos." << endl;
        cout << "0) Regresar." << endl;
        cout << "Opcion: "; getline(cin, myStr);
        system("cls");

        if (myStr == "1") {
            ///Se piden los datos para el aldeano
            cout << "Ingresa el nombre: ";
            getline(cin, myStr);
            a.setNombreA(myStr);

            cout << "Ingresa la edad: ";
            cin >> myInt;
            a.setEdadA(myInt);

            cin.ignore();
            cout << "Ingresa el genero (H/M): ";
            getline(cin, myStr);
            if (myStr == "H" or myStr == "M") {
                ///Si se ingresa una H o una M se setea el genero
                a.setGeneroA(myStr);
            }else{
                ///Si se ingresa algo diferente de H o M se cancela
                cout << endl << "-=ERROR: UTILIZA H O M" << endl << endl;
                continue;
            }

            cout << "Ingresa la salud (HP): ";
            cin >> myInt;
            a.setSaludA(myInt);
            cin.ignore();
            ///Se agrega el aldeano al arreglo siempre y cuando no exista uno con el mismo nombre
            myInt = arr->linearFindData(a);
            if(myInt != -1){
                cout << endl << "-=ERROR: EXISTE UN ALDEANO CON EL MISMO NOMBRE=-" << endl << endl;
                continue;
            }else{
                arr->agregarA(a);
            }

        }else if (myStr == "2") {
            if(arr->isEmpty()){
                ///Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << "-=ERROR: NO HAY ALDEANOS PARA ELIMINAR=-" << endl << endl;
                continue;
            }
            ///Si no esta vacío se pide el nombre del aldeano y se hace la busqueda
            cout << "Ingresa el nombre del aldeano a eliminar: ";
            getline(cin, myStr);
            a.setNombreA(myStr);
            myInt = arr->linearFindData(a);
            if(myInt == -1){
                ///Si la busqueda regresa -1 el adeano no existe
                cout << endl << "-=ERROR: EL ALDEANO NO EXISTE-=" << endl << endl;
                continue;
            }else{
                ///El aldeano existe, preguntar si desea eliminarlo
                cout << "Estas seguro de eliminar a '" << myStr << "'? S/N: ";
                getline(cin, myStr);
                if(myStr == "S"){
                    ///Si dice que sí se elimina al aldeano y se envia la confirmación
                    arr->eliminarA(myInt);
                    cout << endl << "-=ALDEANO ELIMINADO=-" << endl << endl;
                }else if(myStr == "N"){
                    ///Si dice que no el aldeano vuelve "a su hogar" y se sigue con el menu
                    cout << endl << "-=EL ALDEANO VOLVIO A SU HOGAR=-" << endl << endl;
                    continue;
                }else{
                    ///Si se usa una letra diferente de 'S' o 'N'
                    cout << endl << "-=ERROR: OPCION NO VALIDA=-" << endl << endl;
                }
            }

        }else if (myStr == "3") {
            ///Muestra los aldeanos en la civilizacion actual
            if(arr->isEmpty()){
                ///Si el arreglo esta vacío no es posible eliminar aldeanos, se sigue con el menu
                cout << "-=ERROR: NO HAY ALDEANOS PARA MOSTRAR=-" << endl << endl;
                continue;
            }
            //for (int i(0); i < arr->poblacionT(); ++i) {
                arr->toString();
            //}
        }else if (myStr == "0") {
            ///Se cierra el programa
            break;
        }else if(myStr == "5"){}
    }
}
