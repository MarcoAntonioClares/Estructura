#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <locale.h>
#include <fstream>

using namespace std;

const int MAX_USERS = 100;
int i;

struct User {
    string username;
    string password;
};

User users[MAX_USERS];
int userCount = 0;

void guardarUsuariosEnArchivo() {
    ofstream archivo("usuarios.csv", ios::out);
    for (int i = 0; i < userCount; i++) {
        archivo << users[i].username << " " << users[i].password << endl;
    }
    archivo.close();
}

struct libro {
    int codigo;
    string titulo;
    string autor;
    double costo;
    string descripcion;
    string categoria;
};

void imprimirBoleta(string username, libro libroAdquirido, int cantidad) {
    ofstream archivo("boleta.csv", ios::out);
    archivo << "Boleta de Compra\n";
    archivo << "Usuario: " << username << endl;
    archivo << "Libro: " << libroAdquirido.titulo << endl;
    archivo << "Cantidad: " << cantidad << endl;
    archivo << "Costo Total: S/." << libroAdquirido.costo * cantidad << endl;
    archivo.close();
}

void tiendabusqueda(string username);//declarado

void registrarUsuario() {
    setlocale(LC_ALL, "spanish");
    if (userCount >= MAX_USERS) {
        cout << "No se pueden registrar más usuarios." << endl;
        return;
    }

    string mensaje1 = "Registro de nuevo usuario";
    for (i = 0; i < mensaje1.length(); ++i) {
        cout << mensaje1[i];
        Sleep(50);
    }
    cout << endl;

    cout << "Nombre de usuario: ";
    cin >> users[userCount].username;
    
    // Solicitar la contraseña
    string contrasena;
    cout << "Contraseña: ";
    
    // Censurar la contraseña mientras se ingresa
    char ch;
    while ((ch = _getch()) != '\r') {
        cout << "*";
        contrasena.push_back(ch);
    }
    cout << endl;
    
    users[userCount].password = contrasena; // Guardar la contraseña en la estructura
    userCount++;
    system("cls");

    string mensaje = "Usuario registrado exitosamente. \n";
    for (i = 0; i < mensaje.length(); ++i) {
        cout << mensaje[i];
        Sleep(50);
    }
    cout << "-------------------------" << endl;

    guardarUsuariosEnArchivo();
}

bool iniciarSesion() {
    setlocale(LC_ALL, "spanish");
    string username, password;

    string nombre = "Nombre de usuario: ";
    for (i = 0; i < nombre.length(); ++i) {
        cout << nombre[i];
        Sleep(50);
    }
    cin >> username;

    string contrasena = "Contraseña: ";
    for (i = 0; i < contrasena.length(); ++i) {
        cout << contrasena[i];
        Sleep(50);
    }
    
    // Censurar la contraseña mientras se ingresa
    char ch;
    while ((ch = _getch()) != '\r') {
        cout << "*";
        password.push_back(ch);
    }
    cout << endl;

    for (i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            system("cls");
            string mensaje3 = "Inicio de sesión exitoso. Bienvenido, " + username + "! \n";
            for (i = 0; i < mensaje3.length(); ++i) {
                cout << mensaje3[i];
                Sleep(50);
            }
            cout << endl;
            system("cls");
            tiendabusqueda(username);
            return true;
        }
    }
    system("cls");

    string incorrecto = "Nombre de usuario o contraseña incorrectos. \n";
    for (i = 0; i < incorrecto.length(); i++) {
        cout << incorrecto[i];
        Sleep(50);
    }
    return false;
}

void tiendabusqueda(string username) {
    int li, sdl, al, ml, canli, bl, i,sesionIniciada;

    libro libros[5] = {
        {1, "El Señor de los Anillos", "J.R.R. Tolkien", 39.0, "Una epica aventura de fantasía", "Aventura"},
        {2, "Harry Potter y la Piedra Filosofal", "J.K. Rowling", 30.0, "Una emocionante aventura de magia", "Aventura"},
        {3, "El Principito", "Antoine de Saint-Exupéry", 41.0, "Una conmovedora historia de amistad", "Fantasia"},
        {4, "Cien años de soledad", "Gabriel García Márquez", 42.0, "Una novela de realismo mágico", "Realismo"},
        {5, "El Alquimista", "Paulo Coelho", 43.0, "Una inspiradora historia de auto-descubrimiento", "Fantasia"}
    };

    string tienda = "Bienvenido a la tienda de libros Papu 7:";
    for (i = 0; i < tienda.length(); i++) {
        cout << tienda[i];
        Sleep(50);
    }
    cout << endl;

    do {
        do {
            cout << "1: Mostrar todos los libros\n";
            cout << "2: Buscar libro \n";
            cin >> li;
            switch (li) {
                case 1:
                    system("cls");
                    for (int i = 0; i < 5; i++) {
                        cout << "Codigo: " << libros[i].codigo << endl;
                        cout << "Titulo: " << libros[i].titulo << endl;
                        cout << "Autor: " << libros[i].autor << endl;
                        cout << "Costo: S/." << libros[i].costo << endl;
                        cout << "Categoria: " << libros[i].categoria << endl;
                        cout << "------------------------\n" << endl;
                    }
                    break;
                case 2:
                    system("cls");
                    cout << "Ingrese el codigo del libro:\n";
                    cin >> bl;
                    bl--;  // Restar 1 para usar el índice correcto (0 basado)
                    break;
                default:
                    system("cls");
                    cout << "Opción no válida. Intente de nuevo.\n";
            }
        } while (li != 2);

        if (bl >= 0 && bl < 5) {
            string libroen = "Libro encontrado:";
            for (int i = 0; i < libroen.length(); i++) {
                cout << libroen[i];
                Sleep(50);
            }
            cout << endl;

            cout << "Titulo: " << libros[bl].titulo << endl;
            cout << "Costo: S/." << libros[bl].costo << endl;
            cout << "Categoria: " << libros[bl].categoria << endl;
            cout << "------------------------\n" << endl;

            cout << "Desea saber mas del libro? (1: Sí, 0: No)"<<endl;
            cin >> sdl;
            if (sdl == 1) {
                cout << libros[bl].descripcion << endl;
            }
            else if ( sdl == 0){
            	cout<< "Regresando a la pantalla de inicio... \n"<<endl;
            	return ;
			}
				
            cout << "¿Desea adquirir libro? (1: Sí, 0: No) \n";
            cin >> al;
            if (al == 1) {
                cout << "cantidad de libros:";
                cin >> canli;
                imprimirBoleta(username, libros[bl], canli);
            }
            else if (al == 0) {
            	cout<< "Regresando a la pantalla de inicio...\n"<<endl;
            	
            	return ;
            	
			}
        } else {
            cout << "Código de libro no válido. Intente de nuevo.\n";
        }

        cout << "¿Buscar más libros? (1: Sí, 0: No): ";
        cin >> ml;
    } while (ml == 1);
}

int main() {
    setlocale(LC_ALL, "spanish");
    int opcion;
    bool sesionIniciada = false;

    do {
        cout << "----Bienvenido a la biblioteca virtual----" << endl;
        cout << "       #SELECCIONAR UNA OPCION" << endl;
        cout << "1) Registrar usuario" << endl;
        cout << "2) Iniciar sesión" << endl;
        cout << "3) Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                registrarUsuario();
                break;
            case 2:
                system("cls");
                sesionIniciada = iniciarSesion();
                break;
            case 3:
                system("cls");
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
