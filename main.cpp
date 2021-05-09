/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/

#include "lista.h"
#include "producto.h"
#include <fstream>

/* Función principal. Se declara un objeto de tipo Lista, el cual
➥servirá para llevar a cabo las operaciones de almacenamiento, consulta
➥y eliminación de información relacionada a productos. */
int main()
{ 
    system("color F1");
    system("cls");
    int opc, res, clave, i = 0;

    Lista<Producto> lista_p;
    NodoLista<Producto> *apunt;
    //NodoLista<Producto> *front;
    Producto prod;

    fstream prod_Entrada("prod_electronicos.dat", ios::in | ios::binary);

    if(prod_Entrada.is_open()){
        cout<<"\t\t\tRECUPERANDO LOS PRODUCTOS DESDE EL ARCHIVO"<<endl;
        //front = lista_p.RegresaPrimero();
        //cont++;
        
        while(!prod_Entrada.eof()){
            prod_Entrada.seekg((i) * sizeof(Producto));
            prod_Entrada.read(reinterpret_cast<char *>(&prod), sizeof(Producto));

            if(prod.regresarClave() != 0)
            {
                lista_p.InsertaOrdenCrec(prod);
                cout<<prod;
                i++;
            }
            prod_Entrada.peek();//Consulta y devuelve el siguiente caracter o eof()
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }
    prod_Entrada.close();
     
    if(!prod_Entrada.is_open())
    {
        do{

            cout<<"\t\tBienvenido al sistema de registro de productos.\n\n";
            cout<<"\n(1) Registrar un nuevo producto.\n";
            cout<<"\n(2) Dar de baja un producto.\n";
            cout<<"\n(3) Verificar si un producto ya fue registrado.\n";
            cout<<"\n(4) Imprimir la lista de productos registrados.\n";
            cout<<"\n(5) Salir.\n";

            cout<<"\n\nIngrese opcion de trabajo:\n";
            cin>>opc;

            system("cls");

            switch(opc)
            {
                case 1: 
                {
                        cout<<"\t\t\tREGISTRAR UN NUEVO PRODUCTO"<<endl<<endl;
                        int cont = 0;
                        cin>>prod;
                        lista_p.InsertaOrdenCrec(prod);
                        
                        cout<<"\n\n<-> PRODUCTO REGISTRADO <->";
                        cout<<prod;
                        
                        cout<<endl<<endl;
                        system("pause"); system("cls");
                }
                        break;

                case 2: 
                {       cout<<"\t\t\tDAR DE BAJA UN PRODUCTO"<<endl;

                        cout<<"\nIngrese la clave del producto a eliminar: ";
                        cin>>clave;

                        /* Se solicita sólo la clave del producto, ya que la
                        ➥búsqueda se hace tomando en cuenta este atributo que
                        ➥es el que lo identifica. */
                        Producto Produc(clave,"", 0);
                        res = lista_p.EliminaUnNodo(Produc);

                        switch (res)
                        { 
                            case 1: //cout<<prod;
                                    cout<<"\n\nEL PRODUCTO HA SIDO ELIMINADO.\n";
                                    break;
                            case 0: cout<<"\n\nESTE PRODUCTO NO SE ENCUENTRA REGISTRADO.\n";
                                    break;
                            case -1: cout<<"\n\nNO HAY PRODUCTOS REGISTRADOS.\n";
                        }

                        cout<<endl<<endl;
                        system("pause"); system("cls");
                }      
                        break;
                
                case 3: 
                {
                    cout<<"\t\tVERIFICAR SI UN PRODUCTO YA FUE REGISTRADO"<<endl;
                        
                        cout<<"\n\nIngrese la clave del producto a buscar:\n";
                        cin>>clave;
                        /* Se solicita sólo la clave del producto, ya que la
                        ➥búsqueda se hace tomando en cuenta este atributo que
                        ➥es el que lo identifica. */
                        Producto Produc(clave,"",0);
                        apunt = lista_p.BuscaOrdenada(Produc);
                        
                        if (!apunt)
                            cout<<"\n\nESTE PRODUCTO NO ESTA REGISTRADO.\n\n";
                        else
                        { 
                            cout<<"\n\nEL PRODUCTO ESTA REGISTRADO.\n";
                            lista_p.ImprimeUnNodo(apunt);
                        }

                        cout<<endl<<endl;
                        system("pause"); system("cls");
                }       
                        break;

                case 4: cout<<"\t\tLISTA DE PRODUCTOS REGISTRADOS"<<endl;
                        lista_p.ImprimeRecursivo(lista_p.RegresaPrimero());
                    
                        system("pause"); system("cls");
                        break;
                
                case 5: cout<<"\t\t\t\tSALIENDO..."<<endl<<endl;
                        cout<<"\t\tREGISTRANDO LA LISTA DE PRODUCTOS EN UN ARCHIVO"<<endl<<endl<<endl;
                        
                        fstream prod_Salida("prod_electronicos.dat", ios::out | ios::binary);

                        if(!prod_Salida)
                        {
                            cerr<<"EL ARCHIVO NO SE PUDO CREAR"<<endl<<endl;
                            exit(1);
                        }
                        
                        lista_p.guardarArchivo(prod_Salida);

                        prod_Salida.close();
                        
                        break;
            }

        }while(opc != 5);
    }

    
    
    return 0;
}