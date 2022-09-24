# Anteckningar - 2022-09-23
Implementering av neuralt nätverk i C++ (del I) - Skapande av strukt för dense-lager.

I detta stadie har samtliga medlemmar deklarerats (vektorer för lagring av nodernas utsignaler, avvikelser, bias samt vikter).
Ett flertal medlemsfunktioner, såsom två konstruktorer, en destruktor, en initieringsrutin, en tömningsrutin med mera har initierats.
Därmed kan dense-lager med godtyckligt antal noder samt vikter per nod skapas. Dock saknars funktionalitet för implementering av
feedforward, backpropagation samt optimering, vilket skall läggas till i nästa steg, tillsammans med en utskriftsrutin för att
skriva ut samtliga parametrar.

Filen dense_layer.hpp innehåller strukten dense-layer, som används för att implementera dense-lager. Denna strukt är inte komplett än.

Filen main.cpp demonstrerar hur skapandet av ett dense-lager innehållande tre noder samt fyra vikter per nod. I nästa steg skall
kontroll ske att initiering av dense-lagrets parametrar har genomförts korrekt.