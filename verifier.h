#ifndef SCHNORR_VERIFIER_H
#define SCHNORR_VERIFIER_H
#include "prover.h"
#include <iostream>
#include "view.h"
#include <vector>

class cProver;
class cView;

class cVerifier{
private:
    cProver* mProver = nullptr;
    cView* mView = nullptr;

    long long int received_N;
    long long int received_g;
    long long int received_X;
    long long int received_Y;
    long long int received_z;

    std::vector <long long int> vec_1, vec_2;
    long long int tmp=1,tmp_2;

    long long int value_1;
    long long int value_2;

    long long int challenge_c=4;

public:

    // ustawienie wartosci c przez uzytkownika
    void set_Variables(long long int ac);
    //ustawienie wskaznikow`
    void setProver(cProver* aProver);
    void setView(cView*);
    //ustawienie wartosci wysylanych przez prover
    void set_variable(char type, long long int value);
    //generowanie wyzwania c ld aprovera`
    void gen_challenge(long long int min_value, long long int max_value);
    //porownanie wartosci w celu weryfikacji provera
    void verification();

};

#endif //SCHNORR_VERIFIER_H
