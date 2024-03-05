#include "PartidaDeAjedrez.h"
#include "MovimientoInvalido.h"

/**
 * @file PartidaDeAjedrez.cpp
 * @brief Implementation file for the PartidaDeAjedrez class
 */

/**
 * @brief Constructor for the PartidaDeAjedrez class
 * @param[in] ddia The day of the chess match
 * @param[in] mmes The month of the chess match
 * @param[in] aanio The year of the chess match
 */
PartidaDeAjedrez::PartidaDeAjedrez(int ddia, int mmes, int aanio) :
        dia(ddia), mes(mmes), anio(aanio), numPiezas(0) {
    jugadores[0] = nullptr;
    jugadores[1] = nullptr;
    for (int i = 0; i < MAX_PIEZAS; i++)
        piezas[i] = nullptr;
}

/**
 * @brief Copy constructor for the PartidaDeAjedrez class
 * @param[in] orig The original PartidaDeAjedrez object to be copied
 */
PartidaDeAjedrez::PartidaDeAjedrez(const PartidaDeAjedrez &orig) :
        dia(orig.dia), mes(orig.mes), anio(orig.anio), numPiezas(orig.numPiezas) {
    jugadores[0] = orig.jugadores[0];
    jugadores[1] = orig.jugadores[1];
    for (int i = 0; i < MAX_PIEZAS; i++) {
        if (orig.piezas[i])
            piezas[i] = new PiezaDeAjedrez(*orig.piezas[i]);
        else
            piezas[i] = nullptr;
    }
}

/**
 * @brief Destructor for the PartidaDeAjedrez class
 * @details Deletes all the chess pieces and sets the pointers to null
 */
PartidaDeAjedrez::~PartidaDeAjedrez() {
    jugadores[0] = nullptr;
    jugadores[1] = nullptr;

    for (int i = 0; i < MAX_PIEZAS; i++) {
        if (piezas[i]) {
            delete (piezas[i]);
            piezas[i] = nullptr;
        }
    }
}

/**
 * @brief Sets the year of the chess match
 * @param[in] anio The year of the chess match
 */
void PartidaDeAjedrez::SetAnio(int anio) {
    this->anio = anio;
}

/**
 * @brief Gets the year of the chess match
 * @return The year of the chess match
 */
int PartidaDeAjedrez::GetAnio() const {
    return anio;
}

/**
 * @brief Sets the month of the chess match
 * @param[in] mes The month of the chess match
 * @throws std::invalid_argument if the month is not between 1 and 12
 */
void PartidaDeAjedrez::SetMes(int mes) {
    if (mes < 1 || mes > 12)
        throw std::invalid_argument("PartidaDeAjedrez::SetMes: mes invalido");
    this->mes = mes;
}

/**
 * @brief Gets the month of the chess match
 * @return The month of the chess match
 */
int PartidaDeAjedrez::GetMes() const {
    return mes;
}

/**
 * @brief Sets the day of the chess match
 * @param[in] dia The day of the chess match
 */
void PartidaDeAjedrez::SetDia(int dia) {
    this->dia = dia;
}

/**
 * @brief Gets the day of the chess match
 * @return The day of the chess match
 */
int PartidaDeAjedrez::GetDia() const {
    return dia;
}

/**
 * @brief Modifica uno de los dos jugadores
 * @param[in] numJugador[in] entero con el numero de jugador a modificar
 * @param[in] nuevoJugador[in] puntero al nuevoJugador
 * @post[in] Modifica el Jugador de la posicion dada, si es correcta (1 o 2)
 * @throws[in] Lanza excepcion si el numero de jugador es incorrecto
 * @return aux es el puntero al anterior jugador o 0 si no tenía.
 */

Persona *PartidaDeAjedrez::setjugador(int numJugador, Persona *nuevoJugador) {
    if (numJugador != 1 && numJugador != 2)
        throw std::invalid_argument("PartidaDeAjedrez::setjugador: jugador incorrecto");

    Persona *aux = jugadores[numJugador - 1];
    jugadores[numJugador - 1] = nuevoJugador;
    return aux;
}


/**
 * @brief Creates a new chess piece and adds it to the game
 * @param[in] nombreP The name of the chess piece
 * @param[in] colorP The color of the chess piece
 * @param[in] valorP The value of the chess piece
 * @param[in] filaP The row position of the chess piece on the board
 * @param[in] colP The column position of the chess piece on the board
 * @throws std::bad_alloc if memory allocation for the new piece fails
 */
void PartidaDeAjedrez::nuevaPieza(std::string nombreP, char colorP, int valorP, int filaP, char colP) {
    if (numPiezas < MAX_PIEZAS) {
        try {
            piezas[numPiezas] = new PiezaDeAjedrez(nombreP, colorP, valorP, filaP, colP);
            numPiezas++;
        } catch (std::bad_alloc &ba) {
            throw ba;
        }
    }
}

/**
 * @brief Retrieves a chess piece from the game
 * @param[in] pos The position of the chess piece in the array
 * @throws std::range_error if the position is invalid
 * @return A pointer to the chess piece
 */
PiezaDeAjedrez *PartidaDeAjedrez::getPieza(int pos) {
    if (pos < 0 || pos >= numPiezas)
        throw std::range_error("PartidaDeAjedrez::getPieza: posicion invalida");
    return piezas[pos];
}

/**
 * @brief Counts the number of chess pieces of a specific color
 * @param[in] c The color of the chess pieces to count
 * @return The number of chess pieces of the specified color
 */
int PartidaDeAjedrez::numPiezass(char c) {
    int cont = 0;
    for (int i = 0; i < numPiezas; i++) {
        if (piezas[i]->GetColor() == c)
            cont++;
    }
    return cont;
}

/**
 * @brief Moves a chess piece to a new position
 * @param[in] pieza The position of the chess piece in the array
 * @param[in] incFila The row increment for the move
 * @param[in] incCol The column increment for the move
 * @throws std::range_error if the position of the chess piece is invalid
 * @throws MovimientoInvalido if the move is invalid
 */
void PartidaDeAjedrez::mover(int pieza, int incFila, int incCol) {
    if (pieza < 0 || pieza >= numPiezas) {
        throw std::range_error("mover. Pieza no valida.");
    }
    try {
        piezas[pieza]->mover(incFila, incCol);
    } catch (MovimientoInvalido &e) {
        std::cerr << e.what() << std::endl;
    }
}
