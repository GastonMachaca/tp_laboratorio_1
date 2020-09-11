#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Se muestra menu con una serie de opciones.
 *
 * \param int El 1er operando ingresado.
 * \param int El 2do operando ingresado.
 * \param int Pregunta por el ingreso del 1er operando.
 * \param int Pregunta por el ingreso del 2do operando.
 * \return int El valor de opcion entre 1 y 5.
 *
 */

int menu(int num1,int num2,int bandera1,int bandera2);

/** \brief Suma de operandos.
 *
 * \param int 1er operando ingresado.
 * \param int 2do operando ingresado.
 * \return int Suma de ambos operandos.
 *
 */

int operacionSuma(int num1,int num2);

/** \brief Resta de operandos.
 *
 * \param int 1er operando ingresado.
 * \param int 2do operando ingresado.
 * \return int Resta de ambos operandos.
 *
 */

int operacionResta(int num1,int num2);

/** \brief Division de operandos.
 *
 * \param float 1er operando ingresado.
 * \param float 2do operando ingresado.
 * \return float Division de operandos.
 *
 */

float operacionDivision(float num1,float num2);

/** \brief Multiplicacion de operandos.
 *
 * \param int 1er operando ingresado.
 * \param int 2do operando ingresado.
 * \return int Multiplicacion de operandos.
 *
 */

int operacionMultiplicacion (int num1,int num2);

/** \brief Factorial del 1er operando.
 *
 * \param int 1er operando ingresado.
 * \return long long int Factorial del operando 1.
 *
 */

long long int operacionFactorial(int num1);

/** \brief Factorial del 1er operando.
 *
 * \param int 2do operando ingresado.
 * \return long long int Factorial del operando 2.
 *
 */

long long int operacionFactorial2(int num2);


#endif // MENU_H_INCLUDED
