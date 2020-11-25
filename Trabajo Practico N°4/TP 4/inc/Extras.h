#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

/** \brief Funcion con el rol de identificar el ingreso de cadenas sin numeros de por medio.
 *
 * \param pAux char*
 * \param len int
 * \param mensaje char*
 * \param mensajeError char*
 * \return void
 *
 */
void confirmName(char *pAux, int len, char* mensaje, char* mensajeError);

/** \brief Funcion para identificar los numeros de una cadena.
 *
 * \param pAux char*
 * \param len int
 * \param mensaje char*
 * \param mensajeError char*
 * \return void
 *
 */
void confirmNumbers(char *pAux, int len, char* mensaje, char* mensajeError);

#endif // EXTRAS_H_INCLUDED
