cmake_minimum_required(VERSION 3.21)
project(AjedrezPoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AjedrezPoo main.cpp PiezaDeAjedrez.cpp PartidaDeAjedrez.cpp Persona.cpp PartidaDeAjedrez.h Persona.h PiezaDeAjedrez.h Alfil.h Alfil.cpp MovimientoInvalido.h MovimientoInvalido.cpp)