#include "verifier.h"

void cVerifier::set_Variables(long long int ac) {
    challenge_c = ac;
    mProver->set_c(challenge_c);
    mView -> set_variable('c', challenge_c);
}

void cVerifier::setProver(cProver* aProver){
    mProver=aProver;
}

void cVerifier::setView(cView* aView) {
    mView = aView;
}

void cVerifier::set_variable(char type, long long int value) {
    switch(type){
        case 'N':
            received_N = value;
            break;
        case 'X':
            received_X = value;
            break;
        case 'Y':
            received_Y = value;
            break;
        case 'g':
            received_g = value;
            break;
        case 'z':
            received_z = value;
            break;
        default:
            break;
    }
}

void cVerifier::gen_challenge(long long int min_value, long long int max_value) {
    challenge_c = rand() % (max_value-min_value+1) + min_value;
    mProver->set_c(challenge_c);
    mView->set_variable('c', challenge_c);
}

void cVerifier::verification() {
    //OBLICZANIE W    g^z modN
    vec_1.erase(begin(vec_1),end(vec_1));
    vec_2.erase(begin(vec_2),end(vec_2));
    tmp=1;
    bool is_end = false;
    do{
        if(received_z>10){
            received_z = received_z - 10;
            vec_1.push_back(10);
        }
        else if(received_z<=10&&received_z>0)
        {
            vec_1.push_back(received_z);
            received_z=0;
            is_end = true;
        }
    } while(!is_end);

    for(int i : vec_1){
        vec_2.push_back(fmod((pow(received_g, i)),received_N));
    }

    for(int i : vec_2){
        if(i>0){
            tmp = tmp * i;
        }
    }
    value_2 = tmp % received_N;

    //czyszczenie wektorow

    vec_1.erase(begin(vec_1),end(vec_1));
    vec_2.erase(begin(vec_2),end(vec_2));
    tmp=1;
    is_end = false;

    //OBLICZANIE Q (Y*X^c)modN
    do{
        if(challenge_c>10){
            challenge_c = challenge_c - 10;
            vec_1.push_back(10);
        }
        else if(challenge_c<=10&&challenge_c>0)
        {
            vec_1.push_back(challenge_c);
            challenge_c=0;
            is_end = true;
        }
    } while(!is_end);

    for(int i : vec_1){
        vec_2.push_back(fmod((pow(received_X, i)),received_N));
    }

    for(int i : vec_2){
        if(i>0){
            tmp = tmp * i;
        }
    }
    tmp_2 = received_Y % received_N;
    value_1 = (tmp * tmp_2) % received_N;

    //ustawienie widoku w tabeli
    mView->set_variable('Q', value_1);
    mView->set_variable('W', value_2);

    //powiadomienie o wyniku
    if(value_2==value_1){
        std::cout<<"Weryfikacja przebiegla pomyslnie!\n";
    }
    else{
        std::cout<<"Blad weryfikacji!\n";
    }
}