#!/usr/bin/env bash

binfile="./pinza"
[[ ! -f "$binfile" ]] && echo "El archivo $binfile no existe, saliendo del programa" >&2 && exit 1 
[[ ! -x "$binfile" ]] && echo "El archivo $binfile no tiene permisos de ejecución, saliendo del programa" >&2 && exit 1 

echo "Ejecutando $binfile en segundo plano..."

# Ejecuta el binario en segundo plano
/bin/sh -c $binfile &

PID=$!

echo "[INFO] BIN_PID=$PID"
wait "$PID"

# Comprobar si sigue activo
if kill -0 "$PID" 2> /dev/null
then
    kill "$PID"
    echo "Deteniendo proceso (pid=$PID)"
fi

echo "Fin del programa [$PID]"

