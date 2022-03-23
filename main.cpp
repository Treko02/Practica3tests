#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

using namespace std;

int factorial(int);
float potencia(float, int);
int suma(int [],int);
float media(int [],int);
int maximo(int [],int);
int minimo(int [],int);
void leevec(int [], int n);

/*int main()
{

    int n, p, a, r, u, o;
    int Vec[10];
    do{
        cout << "1. Factorial" << endl;
        cout << "2.  cálculo de la potencia an para cualquier real a y para cualquier entero n " << endl;
        cout << "3. Vectores" << endl;
        cout << "4. Salir" << endl;
        cin >> n;

        switch (n) {
            case 1:
            {
                cout<<"Introduce un entero n"<<endl;
                cin>>p;
                cout<<"El factorial de "<<p<<" es: "<<factorial(p)<<endl;

                break;
            }
            case 2:
            {
                cout<<"Introduce una base a: "<<endl;
                cin>>a;
                cout<<"Y un exponente cualquiera: "<<endl;
                cin>>r;
                cout<<"El  resultado es: "<<potencia(a,r)<<endl;

                break;
            }
            case 3:
            {
                cout<<"Introduce el numero dee valores incluidos en el vector"<<endl;
                cin>>o;
                leevec(Vec, o);
                cout << "1. Suma" << endl;
                cout << "2. Media" << endl;
                cout << "3. Maximo y minimo" << endl;
                cout << "4. Salir" << endl;
                cin >> u;
                switch (u) {
                    case 1:
                    {
                        cout<<suma(Vec, o)<<endl;

                        break;
                    }
                    case 2:
                    {
                        cout<<"La media es: "<<media(Vec, o)<<endl;
                        break;
                    }
                    case 3:
                    {
                        cout<<"El maximo es: "<<maximo(Vec, o)<<" y el minimo: "<<minimo(Vec,o)<<endl;
                        break;
                    }
                    case 4: {

                        break;
                    }
                    default:
                    {
                        cout << "Opcion no valida" << endl;
                    }
                }

                break;
            }
            case 4: {

                break;
            }
            default:
            {
                cout << "Opcion no valida" << endl;
            }
        }
    } while (n != 4);

    return 0;

}*/





// Ejercicio 1. FunciÃ³n recursiva para calcular el factorial de un nÃºmero.
/*
{Pre: }
{Post: }
*/
int factorial(int n){
    int fact=1;
    if (n==0){
        return fact;
    }else{
        return fact=n*factorial(n-1);

    }

}


// Ejercicio 2. FunciÃ³n recursiva para calcular el cÃ¡lculo de la potencia de a elevado a n.
/*
{Pre: }
{Post: }
*/
float potencia(float a, int n){
    float poti=1;
    if (n==0){
        return poti;
    }else if(n<0){
        poti=(1/a)* potencia(a, n +1);
        return poti;
    }else {
        poti=a* potencia(a, n - 1);
        return poti;
    }


}


// Ejercicio 3.a. Suma las componentes de un vector. Recuerda que el segundo parÃ¡metro de
// la funciÃ³n representa el tamaÃ±o del vector, no la posiciÃ³n de la Ãºltima componente.
/*
{Pre: }
{Post: }
*/
int suma(int v[],int n){
    int sum=0;
    if (n==0){
        return sum;
    }else {
        sum=v[n-1]+ suma(v, n-1);
        return sum;
    }
}


// Ejercicio 3.b. Calcula la media de los elementos de un vector.
/*
{Pre: }
{Post: }
*/
float media(int v[],int n){
    float media=0.0;
    if (n==0){
        return media;
    }else {
        media= suma(v, n)/n;
        return media;
    }

}

// Ejercicio 3.c. Calcula el mÃ¡ximo de los elementos de un vector.
/*
{Pre: }
{Post: }
*/
int maximo(int v[],int n){
    int max;
    if (n==0){
        return max=0;
    }else {
        if (v[n-1]> maximo(v, n-1)){
            max=v[n-1];
        }else{
            max= maximo(v, n-1);
        }
        return max;
    }

}

// Ejercicio 3.d. Calcula el mÃ­nimo de los elementos de un vector.
/*
{Pre: }
{Post: }
*/
int minimo(int v[],int n){
    int min;
    if(n==0){
        return min=0;
    }else {
        if((v[n-1]< minimo(v,n-1))||(minimo(v,n-1)==0)){
            min=v[n-1];
        }else{
            min= minimo(v,n-1);
        }
        return min;
    }
}

void leevec(int v[], int n){
    int i=0;

    while (i<n){
        cout<<"Introduce el "<<i+1<<" valor del vector"<<endl;
        cin>>v[i];
        i++;
    }
}

TEST_CASE( "Calculando factoriales", "[factorial]" ) {
    REQUIRE( factorial(0) == 1 );
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}

TEST_CASE( "Calculando potencias", "[potencia]" ) {
    REQUIRE( potencia(1,0) == 1 );
    REQUIRE( potencia(2,2) == 4 );
    REQUIRE( potencia(3,3) == 27 );
    REQUIRE( potencia(5,0) == 1 );
    REQUIRE( potencia(0,5) == 0 );
    REQUIRE( potencia(2,-4) == 0.0625 );
}

TEST_CASE( "Calculando suma de vectores", "[suma]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {1,2,3,4,5,5, 15, 20, 25, 30};

    REQUIRE( suma(v1,5) == 95 );
    REQUIRE( suma(v2,1) == 1 );
    REQUIRE( suma(v3,5) == 15 );
    REQUIRE( suma(v4,10) == 110 );
}

TEST_CASE( "Calculando maximo de vectores", "[maximo]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {1,2,3,4,30,5,5, 15, 20, 25};

    REQUIRE( maximo(v1,5) == 30 );
    REQUIRE( maximo(v2,1) == 1 );
    REQUIRE( maximo(v3,5) == 5 );
    REQUIRE( maximo(v4,10) == 30 );
}

TEST_CASE( "Calculando minimo de vectores", "[minimo]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {2,3,4,30,5,5, 15, 20, 25,1};

    REQUIRE( minimo(v1,5) == 5 );
    REQUIRE( minimo(v2,1) == 1 );
    REQUIRE( minimo(v3,5) == 1 );
    REQUIRE( minimo(v4,10) == 1 );
}

TEST_CASE( "Calculando media de vectores", "[media]" ) {
    int v1[] = {5, 15, 20, 25, 30};
    int v2[] = {1};
    int v3[] = {1,2,3,4,5};
    int v4[] = {2,3,4,30,5,5, 15, 20, 25,1};

    REQUIRE( media(v1,5) == 19 );
    REQUIRE( media(v2,1) == 1 );
    REQUIRE( media(v3,5) == 3 );
    REQUIRE( media(v4,10) == 11 );
}