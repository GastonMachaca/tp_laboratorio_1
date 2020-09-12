#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Se muestra menu con una serie de opciones.
 *
 * \param float El 1er operando ingresado.
 * \param float El 2do operando ingresado.
 * \param int Pregunta por el ingreso del 1er operando.
 * \param int Pregunta por el ingreso del 2do operando.
 * \return int El valor de opcion entre 1 y 5.
 *
 */

int menu(float num1,float num2,int bandera1,int bandera2);

/** \brief Suma de operandos.
 *
 * \param float 1er operando ingresado.
 * \param float 2do operando ingresado.
 * \return float Suma de ambos operandos.
 *
 */

float operacionSuma(float num1,float num2);

/** \brief Resta de operandos.
 *
 * \param float 1er operando ingresado.
 * \param float 2do operando ingresado.
 * \return float Resta de ambos operandos.
 *
 */

float operacionResta(float num1,float num2);

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
 * \param float 1er operando ingresado.
 * \param float 2do operando ingresado.
 * \return float Multiplicacion de operandos.
 *
 */

float operacionMultiplicacion (float num1,float num2);

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

/** \brief Conversion de float a int del 1er operando
 *
 * \param float 1er operando ingresado.
 * \return 1er operando a entero.
 *
 */

int numero1Validado (float num1);

/** \brief Conversion de float a int del 2do operando
 *
 * \param float 1er operando ingresado.
 * \return 2do operando a entero.
 *
 */

int numero2Validado (float num2);
#endif // MENU_H_INCLUDED
