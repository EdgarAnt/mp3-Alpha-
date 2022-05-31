#include <iostream>
#include<string.h>
#include<cstdlib>

using namespace std;


class Lista
{


public:
    Lista(); //Constructor No Parametrizado
    ~Lista(); //Destructor
    int travel();
    void Remover(int);
    void buscarP(int);
    void modificar(int);
    bool Vacia() const;
    void mostrar() const;
    void Menu() const ;
    bool validarDatos(char []);
    void First(int);
    void Last(int);



private:
    class Nodo
    {
    public:
        int numero;
        Nodo *siguiente;
        Nodo *anterior;
    };
    Nodo *ptrCab;
};

Lista::Lista()
{
    ptrCab = NULL;
}


void Lista::First(int numero)  //mande un 5
{
    Nodo *nuevo_nodo = new Nodo(); //espacio de memoria para nuevo nodo
    nuevo_nodo->numero = numero; //nuevo nodo.numero = 5

    if (ptrCab == NULL)
    {
        nuevo_nodo->siguiente = nuevo_nodo; //*siguiente = 5
        nuevo_nodo->anterior = nuevo_nodo; // *anterior = 5
        ptrCab = nuevo_nodo; // 5
    }
    else
    {
        Nodo *ultimo_nodo = ptrCab->anterior; //5
        nuevo_nodo->siguiente = ptrCab; //
        nuevo_nodo->anterior = ultimo_nodo;
        ptrCab->anterior = nuevo_nodo;
        ultimo_nodo->siguiente = nuevo_nodo;
        ptrCab = nuevo_nodo;
    }
}

Lista::~Lista()
{

    if (ptrCab != NULL)
    {
        Nodo *temp = ptrCab->siguiente;
        Nodo *temp_ptrCab;

        while (temp != ptrCab)
        {
            temp_ptrCab = temp;
            temp = temp->siguiente;
            delete temp_ptrCab;
        }
        delete ptrCab;
    }
}


void Lista::buscarP(int numero)
{
    Nodo* temp = ptrCab;

    int i=0,cont=-1;
    if(temp != NULL)
    {
        while(true)
        {
            i++;

            if(temp->numero == numero)
            {
                cont++;
                break;
            }
            temp = temp->siguiente;

            if(temp == ptrCab)
            {
                break;
            }
        }

        if(cont == 0)
        {
            cout<<"\nCancion: "<<numero<<endl;
            cout<<"La cancion esta en la posicion: "<<i-1<<endl<<endl;
        }
        else
        {
            cout<<"\nNo esta la cancion."<<endl<<endl;
        }
    }
    else
    {
        cout<<"\n\t\t\t(No hay canciones)"<<endl<<endl;
    }
}


void Lista::Last(int numero)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->numero = numero;

    if (ptrCab == NULL)
    {
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
        ptrCab = nuevo_nodo;
    }

    else
    {
        Nodo *ultimo_nodo = ptrCab->anterior;
        nuevo_nodo->siguiente = ptrCab;
        nuevo_nodo->anterior = ultimo_nodo;
        ptrCab->anterior = nuevo_nodo;
        ultimo_nodo->siguiente = nuevo_nodo;
    }
}

bool Lista::Vacia() const
{
    if (ptrCab == NULL)
    {
        cout<<"\n\t\t\t(No hay canciones)"<<endl<<endl;
        return true;
    }
    else
    {
        return false;
    }
}


void Lista::modificar(int posicion)
{
    Nodo *temp = ptrCab;
    int cont=0,i=0,nuevo_valor=0;

    if(temp != NULL)
    {
        while(true)
        {
            i++;
            if(temp->numero == posicion)
            {
                cont++;
                break;
            }
            temp = temp->siguiente;

            if(temp == ptrCab)
            {
                break;
            }

        }
        if (cont == 1)
        {
            cout<<"\nCancion: "<<posicion<<endl;
            cout<<"Dato encontrado en la posicion: "<<i-1<<endl<<endl;

            cout<<"Ingrese la nueva cancion: ";
            cin>>nuevo_valor;

            temp->numero = nuevo_valor;

            cout<<"\Cancion modificada :)"<<endl<<endl;


        }
        else
        {
            cout<<"La cancion no existe en la lista. . ."<<endl<<endl;
        }
    }
    else
    {
        cout<<"\n\t\t\t(Lista Vacia)"<<endl<<endl;
    }
}


void Lista::mostrar() const
{
    if (!Vacia())
    {
        Nodo *temp = ptrCab;

        do
        {
            cout<<temp->numero <<".mp3\n\t\t\t";
            temp = temp->siguiente;
        }
        while(temp != ptrCab);
        cout<<"\n";
    }
}


void Lista::Remover(int posicion)
{
    if(posicion <= travel())
    {
        if(posicion == 0)
        {
            if(travel() == 0)
            {
                delete ptrCab;
                ptrCab = NULL;
            }
            else
            {
                Nodo *temp_ptrCab= ptrCab;
                Nodo *ultimo_nodo = ptrCab->anterior;
                ptrCab = ptrCab->siguiente;
                ultimo_nodo->siguiente = ptrCab;
                ptrCab->anterior = ultimo_nodo;
                delete temp_ptrCab;
            }
        }
        else
        {
            Nodo *temp = ptrCab;
            for (int i = 0; i <= posicion-1; i++)
                temp = temp->siguiente;
            Nodo *temp_ptrCab = temp;
            Nodo *anterior = temp->anterior;
            temp = temp->siguiente;
            anterior->siguiente = temp;
            temp->anterior = anterior;
            delete temp_ptrCab;
        }
    }
    if(posicion > travel())
    {
        cout<<"\nPosicion invalida"<<endl<<endl;
        system("pause");
    }
}

bool Lista::validarDatos(char opc[])
{
    bool bandera = false;

    if((int(opc[0]) >= 47 ) and (int(opc[0]) <=58 ))
    {
        bandera = true;
    }
    return bandera;
}


int Lista::travel()
{
    int contador = 0;

    if (!Vacia())
    {
        Nodo *temp = ptrCab;

        do
        {
            contador++;
            temp = temp->siguiente;
        }
        while (temp != ptrCab);
    }
    return contador;
}

void Lista::Menu() const
{
    bool ban = false;
    char opc[256],n[256];
    int opcion=0,numero=0,posicion=0;
    Lista validar;
    Lista *obj = new Lista();

        do
        {
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t            Spotify: "<<endl<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|-----------------------------------------------------------|"<<endl;
            cout<<"|Nota: el programa aun esta con enteros, solo son numeros   |\n| y no es con string estoy reutilizando el codigo           |\n|aun no corrijo esa parte.                                  |"<<endl;
            cout<<"|-----------------------------------------------------------|"<<endl;
            cout<<"\n\n\t\t\tCanciones:"<<endl<<endl;
            cout<<"\t\t\t";
            obj->mostrar();
            cout<<"\n";
            cout<<"1) Nueva cancion\n"<<endl;
            cout<<"2) Buscar posicion de la cancion\n"<<endl;
            cout<<"3) Editar registro\n"<<endl;
            cout<<"4) Eliminar\n"<<endl;
            cout<<"5) Salir\n"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>opc;


                opcion = atoi(opc);

                switch(opcion)
                {
                case 1:
                {
                    cout<<"1) Insertar al Principio\n"<<endl;
                    cout<<"2) Insertar al Final\n"<<endl;
                    cout<<"Elige la opcion";
                    cin>>opc;
                    opcion = atoi(opc);

                    switch(opcion)
                    {
                    case 1:
                        cout<<"\nNumero deseado: ";
                        cin>>n;
                        numero = atoi(n);
                        obj->First(numero);
                        break;

                    case 2:
                        cout<<"\nNumero deseado: ";
                        cin>>n;

                            numero = atoi(n);
                            obj->Last(numero);

                    break;


                    }
                    break;

                }

                case 2:
                {

                    cout<<"\Cancion deseada a buscar: ";
                    cin>>n;
                    numero = atoi(n);
                    obj->buscarP(numero);
                    break;
                }

                case 3:
                {

                        cout<<"\nCancion deseada a editar: ";
                        cin>>n;
                        numero = atoi(n);
                        obj->modificar(numero);
                    break;
                }

                case 4:
                {

                        cout<<"\nPosicion de la cancion deseada a remover: ";
                        cin>>n;
                        numero = atoi(n);
                        obj->Remover(numero);

                    system("pause");

                    break;
                }

                case 5:
                {

                    cout<<"\nPresione (Enter) para salir."<<endl;
                    break;

                }

                default:
                {
                    cout<<"Opcion invalida "<<endl;
                    system("pause");
                    system("cls");
                }
                }

        }
        while(opcion != 5);

}

int main()
{
    Lista menu;
    menu.Menu();

    return 0;
}
