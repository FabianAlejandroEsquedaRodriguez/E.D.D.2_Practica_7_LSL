#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string.h>
using namespace std;

/* Definición de la clase Producto. Se sobrecargan algunos operadores
➥para que objetos de esta clase puedan ser usados de manera directa.
➥Esta clase se guarda en la biblioteca ”Productos.h”. */
class Producto
{ 
    private:
        int Clave;
        char NomProd[15];
        double Precio;
    public:
        Producto();
        Producto(int, char[], double);

        double RegresaPrecio();
        int regresarClave();
        
        int operator == (Producto);
        int operator != (Producto);
        int operator > (Producto);
        int operator < (Producto);
        friend istream &operator>> (istream &, Producto &);
        friend ostream &operator<< (ostream &, Producto &);
};

/* Declaración del método constructor por omisión. */
Producto::Producto()
{}

/* Declaración del método constructor con parámetros. */
Producto::Producto(int Cla, char NomP[], double Pre)
{ 
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

/* Método que regresa el valor del atributo Precio. */
double Producto::RegresaPrecio()
{ 
    return Precio;
}

int Producto::regresarClave()
{
    return Clave;
}

/* Método que permite comparar dos objetos de tipo Producto para
➥determinar si son iguales. Regresa 1 si los productos son iguales
➥(tienen la misma clave) y 0 en caso contrario. Se usa sobrecarga del
➥operador ==. */
int Producto::operator == (Producto Prod)
{ 
    int Resp=0;

    if (Clave == Prod.Clave)
        Resp= 1;
    return Resp;
}

/* Método que permite comparar dos objetos de tipo Producto para
➥determinar si son distintos. Regresa 1 si los productos son distintos
➥(tienen diferente clave) y 0 en caso contrario. Se usa 
➥sobrecarga del operador !=. */
int Producto::operator != (Producto Prod)
{ 
    int Resp=0;
    
    if (Clave != Prod.Clave)
        Resp= 1;
    return Resp;
}

/* Método que permite comparar dos objetos de tipo Producto para
➥determinar si el asociado al operador es mayor que el dado como
➥parámetro. Regresa 1 cuando es mayor (su clave es mayor que la clave
➥del dado como parámetro) y 0 en caso contrario. Se usa sobrecarga del
➥operador >. */
int Producto::operator > (Producto Prod)
{ 
    int Resp=0;

    if (Clave > Prod.Clave)
        Resp= 1;
    return Resp;
}

/* Método que permite comparar dos objetos de tipo Producto para
➥determinar si el asociado al operador es menor que el dado como
➥parámetro. Regresa 1 cuando es menor (su clave es menor que la clave
➥del dado como parámetro) y 0 en caso contrario. Se usa sobrecarga del
➥operador <. */
int Producto::operator < (Producto Prod)
{ 
    int Resp=0;
    
    if (Clave < Prod.Clave)
        Resp= 1;
    return Resp;
}

/* Sobrecarga del operador >> para permitir la lectura de objetos de
➥tipo Producto de manera directa con el cin. */
istream &operator>> (istream &Lee, Producto &ObjProd)
{ 
    cout<<"\n\nIngrese clave del producto: ";
    Lee>> ObjProd.Clave; 
    cout<<"\nIngrese nombre del producto: ";
    Lee>> ObjProd.NomProd; 
    cout<<"\nIngrese precio: $";
    Lee>> ObjProd.Precio;
    
    return Lee;
}

/* Sobrecarga del operador << para permitir la impresión de objetos de
➥tipo Producto de manera directa con el cout. */
ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{ 
    Escribe<<"\n\nDatos del producto\n";
    Escribe<<"\nClave: "<<ObjProd.Clave;
    Escribe<<"\nNombre: "<<ObjProd.NomProd;
    Escribe<<"\nPrecio: $"<<ObjProd.Precio<<"\n";

    return Escribe;
}

#endif 