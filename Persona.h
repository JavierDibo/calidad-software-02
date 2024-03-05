#ifndef AJEDREZPOO_PERSONA_H
#define AJEDREZPOO_PERSONA_H

#include <iostream>

/**
 * @file Persona.h
 * @brief Header file for the Persona class
 */

/**
 * @class Persona
 * @brief Class representing a person
 * @details This class contains all the information about a person, including their name and sex
 */
class Persona {
public:
    /**
     * @brief Constructor for the Persona class
     * @param[in] nnombre The name of the person
     * @param[in] ssexo The sex of the person
     */
    Persona(std::string nnombre = "", char ssexo = 'M');

    /**
     * @brief Copy constructor for the Persona class
     * @param[in] orig The original Persona object to be copied
     */
    Persona(const Persona &orig);

    /**
     * @brief Destructor for the Persona class
     */
    virtual ~Persona();

private:
    std::string nombre = ""; ///< The name of the person
    char sexo; ///< The sex of the person

};


#endif //AJEDREZPOO_PERSONA_H
