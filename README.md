# Matrices, Vectores y Archivos en C++
## 1.Descripción
Este repositorio contiene la segunda practica de la asignatura de Sistemas Operativos desarollado en C++ y Bash, y tiene como objetivo trabajar los fundamentos de C++.

---

## 2. Estructura del repositorio

```
├── bash.sh                          # Script en Bash
├── codigo.cpp                       # Código en C++
├── datos_pinza.txt                  # Datos archivo entrada
├── resultado_pinza.txt              # Datos archivo salida
├── pinza                            # Binario
├── LICENSE             
└── README.md
```

---

## 3. Requisitos del sistema
- Sistema operativo Linux (probado en Linux Mint 22.3)
- GNU Bash
- Gcc/G++

### Instalacion de las herramientas
```bash
sudo apt update && sudo apt upgrade
sudo apt install bash g++
```

---

## 4. Ejecución
```bash
./capture_mqtt.sh
```

---

## 5. Salida esperada
Ejecutando ./pinza en segundo plano...
[INFO] BIN_PID=15407

ID: 5118 Galga: 0.24 Izq: 1.796 Der: 1.752 Total: 3.548

ID: 6574 Galga: 0.22 Izq: 1.595 Der: 1.676 Total: 3.271


Media galga: 0.236

Media fuerza izquierda: 1.71876

Media fuerza derecha: 1.72284

Fuerza total media: 3.4416


Estado muestra 5118: ESTABLE

Estado muestra 6574: ESTABLE


## 6. Autoría
* Alumno: David

## 7. Licencia
GLP-3.0 license
