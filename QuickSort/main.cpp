#include <iostream>
#include <fstream>
using namespace std;


int mitad (int a[],int pinicial, int pfinal);
void ordenar (int a[],int pinicial, int pfinal);
void ingresar(int a[],int n);


int main()
{
    const int N = 10;
    int A[N];
    ofstream archivo;
    archivo.open("quicksort.txt", ios::out);
    cout<<"ALGORITMO: QuickSort"<<endl;
    archivo<<"ALGORITMO: QuickSort"<<endl;
    cout<<"INGRESE 10 ELEMENTOS AL ARREGLO :"<<endl;
    ingresar(A,N);
    cout<<"Elementos originales"<<endl;
    archivo<<"Elementos originales"<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<"["<<A[i]<<"]";
        archivo<<"["<<A[i]<<"]";
    }
    cout<<"\nElementos ordenados"<<endl;
    archivo<<"\nElementos ordenados"<<endl;
    ordenar(A,0,N-1);
    for(int i=0;i<N;i++)
        {
            cout<<"["<<A[i]<<"]";
            archivo<<"["<<A[i]<<"]";
        }
    archivo.close();
    return 0;

}


int mitad (int a[],int pinicial, int pfinal)
{
    return a[(pinicial+pfinal)/2];
}


void ordenar (int a[],int pinicial, int pfinal)
{

    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a,pinicial,pfinal);

    do
    {
        while(a[i]<piv)
        {
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp =a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
      ordenar(a,i,pfinal);
    }
}

void ingresar(int a[],int n)
{
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
}


