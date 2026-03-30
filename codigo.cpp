#include <iostream>
#include <fstream>
#include <cmath>   // para abs
using namespace std;

int main() {
    // Arrays obligatorios
    float datos[100][3];
    int ids[100];
    float galga[100];
    float fuerza_izq[100];
    float fuerza_der[100];
    float fuerza_total[100];

    ifstream archivo("datos_pinza.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    int n = 0;

    // Lectura del archivo
    while (archivo >> ids[n] >> galga[n] >> fuerza_izq[n] >> fuerza_der[n]) {
        datos[n][0] = galga[n];
        datos[n][1] = fuerza_izq[n];
        datos[n][2] = fuerza_der[n];

        n++;
        if (n >= 100) break;
    }

    archivo.close();

    // Calcular fuerza total por muestra
    for (int i = 0; i < n; i++) {
        fuerza_total[i] = fuerza_izq[i] + fuerza_der[i];
    }

    // Mostrar datos
    for (int i = 0; i < n; i++) {
        cout << "ID: " << ids[i]
             << " Galga: " << galga[i]
             << " Izq: " << fuerza_izq[i]
             << " Der: " << fuerza_der[i]
             << " Total: " << fuerza_total[i] << endl;
    }

    // Medias
    float suma_g = 0, suma_i = 0, suma_d = 0;

    for (int i = 0; i < n; i++) {
        suma_g += galga[i];
        suma_i += fuerza_izq[i];
        suma_d += fuerza_der[i];
    }

    float media_g = suma_g / n;
    float media_i = suma_i / n;
    float media_d = suma_d / n;
    float media_total = media_i + media_d;

    cout << "\nMedia galga: " << media_g << endl;
    cout << "Media fuerza izquierda: " << media_i << endl;
    cout << "Media fuerza derecha: " << media_d << endl;
    cout << "Fuerza total media: " << media_total << endl;

    // Estabilidad
    string estado[100];

    for (int i = 0; i < n; i++) {
        float diferencia = abs(fuerza_izq[i] - fuerza_der[i]);

        if (diferencia > 0.15)
            estado[i] = "INESTABLE";
        else
            estado[i] = "ESTABLE";

        cout << "Estado muestra " << ids[i] << ": " << estado[i] << endl;
    }

    // Escritura en archivo
    ofstream salida("resultado_pinza.txt");

    if (!salida.is_open()) {
        cout << "Error al crear el archivo de salida." << endl;
        return 1;
    }

    salida << "RESULTADOS DEL SISTEMA DE PINZA ROBOTICA\n\n";

    salida << "Datos:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " "
               << galga[i] << " "
               << fuerza_izq[i] << " "
               << fuerza_der[i] << " "
               << fuerza_total[i] << "\n";
    }

    salida << "\nMedias:\n";
    salida << "Galga = " << media_g << endl;
    salida << "Fuerza izquierda = " << media_i << endl;
    salida << "Fuerza derecha = " << media_d << endl;
    salida << "Fuerza total media = " << media_total << endl;

    salida << "\nClasificacion:\n";
    for (int i = 0; i < n; i++) {
        salida << ids[i] << " " << estado[i] << endl;
    }

    salida.close();

    cout << "\nResultados guardados en resultado_pinza.txt" << endl;

    return 0;
}
