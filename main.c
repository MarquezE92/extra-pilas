#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///prototipado
void bajarTope(Pila* pilita);

void barajar(Pila* mazo, Pila* jugador1, Pila* jugador2);

int compararPilas(Pila* pilaA, Pila* pilaB);

int superComparar(Pila* pilaA, Pila* pilaB);

void eliminaTope(Pila* modelo, Pila* dada);

void eliminaTodo(Pila* modelo, Pila* dada);

void dividirMayorMenor(Pila* pilaMadre, Pila* mayor, Pila* menor, int valor);

int determinarParImpar(Pila* pilita);

float transformarEnDecimal(Pila* pilita);

int sumaDos(Pila* pilita);

int verificarCapicua(Pila* pilita);

void apilarConjuntos(Pila* pilaA, Pila* pilaB, Pila* pilaC);

void unirOrdenadas(Pila* ordenada1, Pila* ordenada2, Pila* ordenadaFinal);

Pila ordenaPorParametro(Pila desordenada);

Pila ordenaAscendente(Pila desordenada);

int main()
{
    Pila pilita, jugador1, jugador2;
    inicpila(&pilita);
    inicpila(&jugador1);
    inicpila(&jugador2);
    apilar(&pilita, 31);
    apilar(&pilita, 22);
    apilar(&pilita, 301);
    apilar(&pilita, 1);

//    apilar(&jugador1, 55);
//    apilar(&jugador1, 30);
//    apilar(&jugador1, 22);
//    apilar(&jugador1, 15);


    mostrar(&pilita);
//    mostrar(&jugador1);
    ///Ej 1
    //bajarTope(&pilita);

    ///Ej 2
    //barajar(&pilita, &jugador1, &jugador2);
    //mostrar(&jugador1);
    //mostrar(&jugador2);

    ///Ej 3
    //int comparacion = compararPilas(&pilita, &jugador1);
//    if(comparacion == 0){
//        printf("Ambas pilas miden lo mismo");
//    } else if(comparacion == -1){
//        printf("Pila A tiene mas elementos");
//    } else {
//        printf("Pila B tiene mas elementos");
//    }
    ///Ej4
//    int supercomparacion = superComparar(&pilita, &jugador1);
//    if(supercomparacion == 1){
//        printf("\nAmbas pilas son iguales");
//    }else{
//        printf("\n Las pilas no son iguales");
//    }


    ///Ej5
//    eliminaTope(&pilita, &jugador1);


    ///Ej6
//    eliminaTodo(&pilita, &jugador1);

    ///Ej7
//    dividirMayorMenor(&pilita, &jugador1, &jugador2, 29);

    ///Ej8
//    if(determinarParImpar(&pilita) == 1){
//        printf("La pila es impar");
//    }else{
//        printf("La pila es par");
//    }


    ///Ej9
//    printf("la pila en decimal es %f", transformarEnDecimal(&pilita));

    ///Ej10
//    printf("La suma de los dos numeros de arriba es %i", sumaDos(&pilita));

    ///Ej11
//    if(verificarCapicua(&pilita) == 1){
//        printf("La pila es capicua");
//    }else{
//        printf("La pila no es capicua");
//    }

    ///Ej12
//    apilarConjuntos(&pilita, &jugador1, &jugador2);

    ///Ej13
//    unirOrdenadas(&pilita, &jugador1, &jugador2);

    ///Ej14
//    ordenaPorParametro(pilita);

    ///Ej15
    Pila ordenada = ordenaAscendente(pilita);
    mostrar(&ordenada);

//    mostrar(&jugador1);
//    mostrar(&jugador2);
    return 0;
}

///FUNCIONES

void traspasar(Pila* pRecibe, Pila* pPasaDatos)
{
    while(!pilavacia(pPasaDatos))
    {
        apilar(pRecibe, desapilar(pPasaDatos));
    }
}

///Hacer una función que pase el primer elemento (tope) de una pila a su última
///posición (base), dejando los restantes elementos en el mismo orden. Retornar la
///Pila o usar puntero para modificar la misma.
void bajarTope(Pila* pilita)
{
    Pila aux;
    int nuevaBase;
    inicpila(&aux);

    if(tope(pilita))
    {
        nuevaBase = desapilar(pilita);

        traspasar(&aux,pilita);
        apilar(pilita, nuevaBase);
        traspasar(pilita, &aux);
    }
}

///Hacer una función que reparta los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternada.
void barajar(Pila* mazo, Pila* jugador1, Pila* jugador2)
{
    while(!pilavacia(mazo))
    {
        apilar(jugador1, desapilar(mazo));
        if(!pilavacia(mazo))
        {
            apilar(jugador2, desapilar(mazo));
        }
    }
}

///Hacer una función que compare la cantidad de elementos de dos pilas A y B. La función deberá retornar:
/// -1 si la Pila A tiene más elementos
/// 0 misma cantidad de elementos
/// 1 si la Pila B tiene más elementos.
/// En el Main se evaluará este resultado para informar al usuario cuál Pila tiene más elementos.
///El ejercicio debe resolverse SIN CONTAR los elementos de las Pilas.
int compararPilas(Pila* pilaA, Pila* pilaB)
{
    Pila auxA, auxB;
    inicpila(&auxA);
    inicpila(&auxB);
    int respuesta = 0;

    if(pilavacia(pilaA))
    {
        respuesta = 1;
    }
    if(pilavacia(pilaB))
    {
        respuesta = -1;
    }
    while(!pilavacia(pilaA) && !pilavacia(pilaB))
    {
        apilar(&auxA, desapilar(pilaA));
        apilar(&auxB, desapilar(pilaB));
        if(pilavacia(pilaA))
        {
            respuesta = 1;
        }
        else
        {
            if(pilavacia(pilaB))
            {
                respuesta = -1;
            }
        }
    }
    traspasar(pilaA, &auxA);
    traspasar(pilaB, &auxB);
    return respuesta;
}

///Hacer una función que compare dos pilas A y B para ver si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos).
///La función deberá retornar 0 o 1, y en el Main se evaluará el resultado para informar al usuario
int superComparar(Pila* pilaA, Pila* pilaB)
{
    Pila auxiliarA, auxiliarB;
    inicpila(&auxiliarB);
    inicpila(&auxiliarA);
    int respuesta = 1, seguirComparando = 1;

    while((!pilavacia(pilaA) || !pilavacia(pilaB)) && seguirComparando)
    {
        if(!pilavacia(pilaA) && !pilavacia(pilaB))
        {
            if(tope(pilaA) != tope(pilaB))
            {
                respuesta = 0;
                seguirComparando = 0;
            }
            else
            {
                apilar(&auxiliarA, desapilar(pilaA));
                apilar(&auxiliarB, desapilar(pilaB));
            }
        }
        else
        {
            respuesta = 0;
        }
    }

    traspasar(pilaA, &auxiliarA);
    traspasar(pilaB, &auxiliarB);

    return respuesta;
}

///Hacer una función que reciba una pila MODELO (vacía o no), y elimine de la pila DADA todos los elementos que sean iguales al TOPE de la pila MODELO.
void eliminaTope(Pila* modelo, Pila* dada)
{
    int eliminable;
    Pila auxiliar;
    inicpila(&auxiliar);
    if(tope(modelo))
    {
        eliminable = tope(modelo);
        while(!pilavacia(dada))
        {
            if(eliminable == tope(dada))
            {
                desapilar(dada);
            }
            else
            {
                apilar(&auxiliar, desapilar(dada));
            }
        }
    }
    traspasar(dada, &auxiliar);
}


///Hacer una función que reciba una pila MODELO (vacía o no), y elimine de la pila DADA todos los elementos que existan en la pila MODELO.
void eliminaTodo(Pila* modelo, Pila* dada)
{
    Pila auxiliarModelo;

    inicpila(&auxiliarModelo);

    while(!pilavacia(modelo))
    {
        eliminaTope(modelo, dada);
        apilar(&auxiliarModelo, desapilar(modelo));
    }
    traspasar(modelo, &auxiliarModelo);

}

///Hacer una función que reciba por parámetro una Pila y un valor elegido por el usuario del sistema.
/// La función debe pasar a la pila MAYORES los elementos de la pila que sean mayores o iguales a dicho valor elegido,
/// y a la pila MENORES los elementos que sean menores. La Pila original debe quedar con todos sus elementos.
void dividirMayorMenor(Pila* pilaMadre, Pila* mayor, Pila* menor, int valor)
{
    Pila auxiliar;
    inicpila(&auxiliar);

    while(!pilavacia(pilaMadre))
    {
        int topePila = tope(pilaMadre);
        if(topePila < valor)
        {
            apilar(menor, topePila);
        }
        else
        {
            apilar(mayor, topePila);
        }
        apilar(&auxiliar, desapilar(pilaMadre));
    }

    traspasar(pilaMadre, &auxiliar);
}


///Hacer una función que reciba una Pila y determine si la cantidad de elementos de la misma es par o impar. La función deberá retornar 0 o 1, y en el Main se
/// evaluará este resultado para informar al usuario si la pila es par o impar. El ejercicio debe resolverse SIN CONTAR los elementos de las Pilas.
int determinarParImpar(Pila* pilita)
{
    int marcador = -1;
    Pila auxiliar;
    inicpila(&auxiliar);

    while(!pilavacia(pilita))
    {
        marcador *= -1;
        apilar(&auxiliar, desapilar(pilita));
    }
    traspasar(pilita, &auxiliar);
    if(marcador < 0)
    {
        marcador = 0;
    }
    return marcador;
}

/// Hacer una función que reciba una pila con números de un solo dígito (ello es responsabilidad de quien usa el programa) y
/// que transforme esos dígitos en un número decimal
float transformarEnDecimal(Pila* pilita)
{
    Pila auxiliar;
    float respuesta=0;
    int divisor=1;
    inicpila(&auxiliar);

    while(!pilavacia(pilita))
    {
        respuesta += (float) tope(pilita)/divisor;
        divisor *=10;
        apilar(&auxiliar, desapilar(pilita));
    };

    traspasar(pilita, &auxiliar);
    return respuesta;
}

///Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma, sin alterar el contenido de la pila.
int sumaDos(Pila* pilita)
{
    Pila aux;
    int resultado = 0;
    inicpila(&aux);

    for(int i = 0; i < 2; i++)
        if(tope(pilita))
        {
            resultado += tope(pilita);
            apilar(&aux, desapilar(pilita));
        };

    traspasar(pilita, &aux);
    return resultado;
}

///Hacer una función que verifique si una pila DADA es capicúa.
/// La función deberá retornar 0 o 1, y en el Main se evaluará este resultado para informar al usuario.
int verificarCapicua(Pila* pilita)
{
    Pila auxiliarComparacion, auxiliarA;
    inicpila(&auxiliarA);
    inicpila(&auxiliarComparacion);
    int esCapicua = 1;

    while(!pilavacia(pilita))
    {
        apilar(&auxiliarComparacion, tope(pilita));
        apilar(&auxiliarA, desapilar(pilita));
    };
    traspasar(pilita, &auxiliarA);
    while(!pilavacia(&auxiliarComparacion) && esCapicua == 1)
    {

        if(desapilar(&auxiliarComparacion) != tope(pilita))
        {
            esCapicua = 0;
        }
        apilar(&auxiliarA, desapilar(pilita));
    };

    traspasar(pilita, &auxiliarA);

    return esCapicua;
}

///Hacer una función que reciba por parámetro dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo). La función debe
///calcular en la pila C la operación de unión (pero los que se encuentren en ambas deben apilarse solo una vez)
void agregarSiFalta(Pila* pilita, int valor)
{
    Pila auxiliar;
    inicpila(&auxiliar);
    while(!pilavacia(pilita))
    {
        if(tope(pilita) == valor)
        {
            desapilar(pilita);
        }
        else
        {
            apilar(&auxiliar, desapilar(pilita));
        }
    }
    traspasar(pilita, &auxiliar);
    apilar(pilita, valor);

}

void apilarConjuntos(Pila* pilaA, Pila* pilaB, Pila* pilaC)
{
    Pila auxiliar;
    inicpila(&auxiliar);

    while(!pilavacia(pilaA))
    {
        apilar(pilaC, tope(pilaA));
        apilar(&auxiliar, desapilar(pilaA));
    };
    traspasar(pilaA, &auxiliar);

    while(!pilavacia(pilaB))
    {
        agregarSiFalta(pilaC, tope(pilaB));
        apilar(&auxiliar, desapilar(pilaB));
    };
    traspasar(pilaB, &auxiliar);
}


///Hacer una función que reciba dos pilas ordenadas en forma creciente
///y pase los elementos de las mismas a otra pila también ordenada en forma creciente (ORDENADAFINAL).
void unirOrdenadas(Pila* ordenada1, Pila* ordenada2, Pila* ordenadaFinal)
{
    Pila auxiliar1, auxiliar2;
    inicpila(&auxiliar1);
    inicpila(&auxiliar2);

    while(!pilavacia(ordenada1))
    {
        apilar(&auxiliar1, desapilar(ordenada1));
    };
    while(!pilavacia(ordenada2))
    {
        apilar(&auxiliar2, desapilar(ordenada2));
    };

    while(!pilavacia(&auxiliar1) || !pilavacia(&auxiliar2))
    {
        if(pilavacia(&auxiliar1))
        {
            while(!pilavacia(&auxiliar2))
            {
                apilar(ordenadaFinal, tope(&auxiliar2));
                apilar(ordenada2, desapilar(&auxiliar2));
            }
        }
        else if(pilavacia(&auxiliar2))
        {
            while(!pilavacia(&auxiliar1))
            {
                apilar(ordenadaFinal, tope(&auxiliar1));
                apilar(ordenada1, desapilar(&auxiliar1));
            }
        }
        else
        {
            if(tope(&auxiliar1) > tope(&auxiliar2))
            {
                apilar(ordenadaFinal, tope(&auxiliar1));
                apilar(ordenada1, desapilar(&auxiliar1));
            }
            else
            {
                apilar(ordenadaFinal, tope(&auxiliar2));
                apilar(ordenada2, desapilar(&auxiliar2));
            }
        }

    }
}

///Utilizando la función del punto 7 de buscar, eliminar y retornar el menor de una Pila hacer una función que:
///reciba una Pila por parámetro, genere una nueva Pila ordenada, utilizando cada dato extraído de la Pila recibida por parámetro y la retorne.
int devolverMenor(Pila* pilita)
{
    Pila auxiliar;
    inicpila(&auxiliar);
    int menor = tope(pilita);
    apilar(&auxiliar, desapilar(pilita));

    while(!pilavacia(pilita))
    {

        if(menor > tope(pilita))
        {
            menor = tope(pilita);
        };
        apilar(&auxiliar, desapilar(pilita));

    }
    while(!pilavacia(&auxiliar))
    {
        if(menor == tope(&auxiliar))
        {
            desapilar(&auxiliar);
        }
        else
        {
            apilar(pilita, desapilar(&auxiliar));
        }
    }

    return menor;
}

Pila ordenaPorParametro(Pila desordenada)
{
    Pila ordenada;
    inicpila(&ordenada);

    while(!pilavacia(&desordenada))
    {
        apilar(&ordenada, devolverMenor(&desordenada));
    };
    mostrar(&ordenada);

    return ordenada;
}

///Utilizando la función del punto 8 de insertar un dato en orden en una pila de la guía
///número 2 (Funciones con Pilas), hacer una función que reciba una Pila por
///parámetro, genere una nueva Pila ordenada, insertando cada dato desapilado de la
///Pila recibida por parámetro y la retorne.
void insertarEnOrden(Pila* ordenada, int valor){
    Pila auxiliar;
    inicpila(&auxiliar);
    int seApilo = 0;

    if(pilavacia(ordenada)){
        apilar(ordenada, valor);
        seApilo = 1;
    }else{
        while(!pilavacia(ordenada) && seApilo == 0){
            if(tope(ordenada)> valor){
                apilar(ordenada, valor);
                seApilo = 1;
            }else{
                apilar(&auxiliar, desapilar(ordenada));
            }
        }
    };
    if(seApilo == 0){
        apilar(ordenada, valor);
    }
    traspasar(ordenada, &auxiliar);
}

Pila ordenaAscendente(Pila desordenada){
    Pila ordenada;
    inicpila(&ordenada);

    while(!pilavacia(&desordenada)){
        insertarEnOrden(&ordenada, desapilar(&desordenada));
    };

    return ordenada;
}
