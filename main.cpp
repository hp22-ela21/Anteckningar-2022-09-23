/********************************************************************************
* main.cpp: Demonstrerar implementering av dense-lager i C++.
********************************************************************************/
#include "dense_layer.hpp"

/********************************************************************************
* main: Implementerar ett dense-lager inneh�llande tre noder samt fyra vikter 
*       per nod. N�sta steg �r att skapa en print-funktion f�r att skriva ut
*       samtliga parametrar och s�kerhetsst�lla att initieringen sker korrekt.
********************************************************************************/
int main(void)
{
   dense_layer l1(3, 4);
   return 0;
}