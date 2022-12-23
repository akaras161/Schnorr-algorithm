#include "prover.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(nullptr));

    //  UWAGA!
    //  g^r mod N
    //  g musi byc mniejsze od N

    long long int min_mod_number = 10;
    long long int max_mod_Number = 15;

    long long int min_rand_number = 5;
    long long int max_rand_number = 10;

    cView View;
    cProver P;
    cVerifier V;


    // USTAWIENIE WSTAZNIKOW NA OBIEKTY W CELU OPEROWANIA NA NICH W METODACH INNYCH KLAS
    P.setVerifier(&V);
    P.setView(&View);
    V.setProver(&P);
    V.setView(&View);

    //P.set_Variables(89, 3, 25,25);
    //V.set_Variables(3);

    // /////////////////////////////////////////// BLOK DO ZAKOMENTOWANIA W CELU USTAWIENIA PARAMETROW NA SZTYWNO W KONSTRUKTORZE


    P.gen_g_number(min_rand_number,max_rand_number);
    P.gen_mod_N(min_mod_number,max_mod_Number);
    P.gen_x_number(min_rand_number,max_rand_number);
    P.gen_y_number(min_rand_number,max_rand_number);
    V.gen_challenge(min_rand_number,max_rand_number);


    // ////////////////////////////////////////////KONIEC BLOKU

    P.calculate_X();
    P.calculate_Y();
    P.calculate_z();
    V.verification();

    return 0;
}