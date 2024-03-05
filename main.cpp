#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "PartidaDeAjedrez.h"
#include "Persona.h"
#include "PiezaDeAjedrez.h"
#include "Alfil.h"

using namespace std;

/**
 * @file main.cpp
 * @brief Main file for the chess game
 *
 * Where a Persona is created by parameter, a PartidaDeAjedrez is created too and we set two players for the game.
 * Is created three pieces of chess by parameter and a try catch is implemented to create and copy a piece and his name is
 * shown on the screen. After a copy constructor is used to create a new PartidaDeAjedrez and finally the number of black
 * and white pieces is shown.
 *
 */

/**
 * @brief Main function of the program
 * @param[in] argc Number of command line arguments
 * @param[in] argv Array of command line arguments
 * @return int Returns 0 upon successful execution
 */
int main(int argc, char **argv) {

    Persona vpersona[4] = {Persona("YO", 'M'), Persona("TU", 'F'), Persona(), Persona()};///< Array of Person objetcts

    PartidaDeAjedrez primeraPartida(1, 1, 2017);///< Object primeraPartida is created
    primeraPartida.setjugador(1, &vpersona[0]);///< setting the first player
    primeraPartida.setjugador(2, &vpersona[1]);///< setting the second player

    /**
     * @brief Adding new pieces to the game
     */
    primeraPartida.nuevaPieza("caballo", 'b', 3, 1, 'a');///< adding the knight piece introducing parameters
    primeraPartida.nuevaPieza("rey", 'n', 6, 2, 'c');///< adding the king piece introducing parameters
    primeraPartida.nuevaPieza("reina", 'b', 8, 4, 'b');///< adding the queen introducing parameters

    /**
     * @brief Try-catch block to handle exceptions
     */
    try {
        PiezaDeAjedrez *p = primeraPartida.getPieza(6);// creating a new piece taking the data from primeraPartida
        std::cout << p->GetNombre() << std::endl;// getting the name of the piece we just created
    } catch (std::range_error &ra) {
        std::cerr << "Error: " << ra.what() << std::endl;
    }

    PartidaDeAjedrez nuevacopia(primeraPartida);///< copy constructor for PartidaDeAjedrez class


    std::cout << "Nº Piezas blancas: " << primeraPartida.numPiezass('b') << std::endl;///< displaying the number of black pieces
    std::cout << "Nº Piezas negras: " << primeraPartida.numPiezass('n') << std::endl;///< displaying the number of white pieces

    return 0;
}
