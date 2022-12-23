#ifndef SCHNORR_PROVER_H
#define SCHNORR_PROVER_H
#include <cmath>
#include "verifier.h"
#include "view.h"
#include <iostream>
#include <vector>

// INFORMACJA O ISTNIENIU INNYCH KALS KTORE BEDA UZYTE
class cVerifier;
class cView;

class cProver{
private:

    cVerifier* mVerifier = nullptr;
    cView* mView = nullptr;

    // STWORZENIE WEKTOROW I ZMIENNYC POMOCNICZYCH UZYWANYCH DO ROZLOZENIA DUZYCH WYKLADNIKOW
    std::vector <long long int> vec_1, vec_2;
    int tmp=1, tmp_x, tmp_y;

    long long int mod_Number;
    int g;

    long long int private_x;
    long long int private_X;

    long long int private_y;
    long long int private_Y;

    long long int recived_c;

    long long int z;

public:
    //ustawia wartosci podane przez uzytkownika
    void set_Variables(long long int aN = 0, long long int ag = 0, long long int ax = 0, long long int ay = 0);
    //ustawienie wskaznikow
    void setVerifier(cVerifier*);
    void setView(cView*);
    //generuje wartosci N,g,x
    void gen_mod_N(long long int min_value, long long int max_value);
    void gen_g_number(long long int min_value, long long int max_value);
    void gen_x_number(long long int min_value, long long int max_value);
    //oblicza X
    void calculate_X();
    //generuje y
    void gen_y_number(long long int min_value, long long int max_value);
    //oblicz Y
    void calculate_Y();
    //ustawia wartosc odebranego c od verifier
    void set_c(long long int value);
    //oblicza z
    void calculate_z();

};
#endif //SCHNORR_PROVER_H
