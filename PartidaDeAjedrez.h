#ifndef AJEDREZPOO_PARTIDADEAJEDREZ_H
#define AJEDREZPOO_PARTIDADEAJEDREZ_H

#include "Persona.h"
#include "PiezaDeAjedrez.h"

/**
 * @file PartidaDeAjedrez.h
 * @brief Header file for the PartidaDeAjedrez class
 */

/**
 * @class PartidaDeAjedrez
 * @brief Class representing a chess game
 * @details This class contains all the information about a chess game, including the date, the players, and the pieces
 */
class PartidaDeAjedrez {
public:
    static const int MAX_PIEZAS = 32;

    /**
     * @brief Default constructor for the PartidaDeAjedrez class
     */
    PartidaDeAjedrez() = default;

    /**
     * @brief Constructor for the PartidaDeAjedrez class
     * @param[in] ddia The day of the chess match
     * @param[in] mmes The month of the chess match
     * @param[in] aanio The year of the chess match
     */
    PartidaDeAjedrez(int ddia, int mmes, int aanio);

    /**
     * @brief Copy constructor for the PartidaDeAjedrez class
     * @param[in] orig The original PartidaDeAjedrez object to be copied
     */
    PartidaDeAjedrez(const PartidaDeAjedrez &orig);

    /**
     * @brief Destructor for the PartidaDeAjedrez class
     */
    virtual ~PartidaDeAjedrez();

    /**
     * @brief Sets the year of the chess match
     * @param[in] anio The year of the chess match
     */
    void SetAnio(int anio);

    /**
     * @brief Gets the year of the chess match
     * @return The year of the chess match
     */
    int GetAnio() const;

    /**
     * @brief Sets the month of the chess match
     * @param[in] mes The month of the chess match
     */
    void SetMes(int mes);

    /**
     * @brief Gets the month of the chess match
     * @return The month of the chess match
     */
    int GetMes() const;

    /**
     * @brief Sets the day of the chess match
     * @param[in] dia The day of the chess match
     */
    void SetDia(int dia);

    /**
     * @brief Gets the day of the chess match
     * @return The day of the chess match
     */
    int GetDia() const;

    /**
     * @brief Sets a player for the chess match
     * @param[in] numJugador The number of the player (0 or 1)
     * @param[in] nuevoJugador A pointer to the new player
     * @return A pointer to the new player
     */
    Persona *setjugador(int numJugador, Persona *nuevoJugador);

    /**
     * @brief Creates a new chess piece and adds it to the game
     * @param[in] nombreP The name of the chess piece
     * @param[in] colorP The color of the chess piece
     * @param[in] valorP The value of the chess piece
     * @param[in] filaP The row position of the chess piece on the board
     * @param[in] colP The column position of the chess piece on the board
     */
    void nuevaPieza(std::string nombreP, char colorP, int valorP, int filaP, char colP);

    /**
     * @brief Retrieves a chess piece from the game
     * @param[in] pos The position of the chess piece in the array
     * @return A pointer to the chess piece
     */
    PiezaDeAjedrez *getPieza(int pos);

    /**
     * @brief Counts the number of chess pieces of a specific color
     * @param[in] c The color of the chess pieces to count
     * @return The number of chess pieces of the specified color
     */
    int numPiezass(char c);

    /**
     * @brief Moves a chess piece to a new position
     * @param[in] pieza The position of the chess piece in the array
     * @param[in] incFila The row increment for the move
     * @param[in] incCol The column increment for the move
     */
    void mover(int pieza, int incFila, int incCol);

private:
    int dia = 1; ///< day the chess game
    int mes = 1; ///< month of the chess game
    int anio = 1; ///< year of the chess game

    Persona *jugadores[2] = {nullptr, nullptr};///< default players for the chess game
    PiezaDeAjedrez *piezas[MAX_PIEZAS];///< vector of pieces
    int numPiezas = 0;///< default number of pieces

};

#endif //AJEDREZPOO_PARTIDADEAJEDREZ_H
