/********************************************************************************
* main.cpp: Demonstrerar implementering av dense-lager i C++.
********************************************************************************/
#include "dense_layer.hpp"

/********************************************************************************
* main: Implementerar ett dense-lager innehållande tre noder samt fyra vikter 
*       per nod. Nästa steg är att skapa en print-funktion för att skriva ut
*       samtliga parametrar och säkerhetsställa att initieringen sker korrekt.
********************************************************************************/
int main(void)
{
   dense_layer l1(3, 4);
   return 0;
}