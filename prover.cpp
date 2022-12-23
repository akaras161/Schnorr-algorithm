#include "prover.h"

void cProver::set_Variables(long long int aN, long long int ag, long long int ax, long long int ay){
    mod_Number = aN;
    g = ag;
    private_x = ax;
    private_y= ay;

    mVerifier->set_variable('g',g);
    mVerifier->set_variable('N',mod_Number);

    mView->set_variable('N', mod_Number);
    mView->set_variable('g', g);
    mView->set_variable('x',private_x);
    mView->set_variable('y',private_y);
}

void cProver::setVerifier(cVerifier* aVerifier){
    mVerifier = aVerifier;
}

void cProver::setView(cView* aView) {
    mView = aView;
}

void cProver::gen_mod_N(long long int min_value, long long int max_value) {
    bool is_primary = false;
    int rand_number;
    do{
        rand_number = rand() % (max_value-min_value+1) + min_value;
        for(int i=2; i<=rand_number-1; i++){
            if(rand_number%i==0) {
                is_primary = false;
                break;
            }else{
                is_primary = true;
                mod_Number = rand_number;
            }
        }
    }while(!is_primary);

    if(mod_Number <= g || mod_Number % g == 0 || g % mod_Number == 0){
        gen_mod_N(min_value,max_value);
    }

    mVerifier->set_variable('N', mod_Number);

    mView->set_variable('N', mod_Number);
}

void cProver::gen_x_number(long long int min_value, long long int max_value) {
    private_x = rand() % (max_value-min_value+1) + min_value;

    mView->set_variable('x', private_x);
}

void cProver::gen_g_number(long long int min_value, long long int max_value) {
    g = rand() % (max_value-min_value+1) + min_value;
    mVerifier->set_variable('g', g);

    mView->set_variable('g', g);
}

void cProver::calculate_X() {
    //private_X = (int)fmod(pow(g, private_x), mod_Number);

    tmp=1;
    tmp_x = private_x;
    bool is_end = false;

    do{
        if(tmp_x>10){
            tmp_x -= 10;
            vec_1.push_back(10);
        }
        else if(tmp_x<=10&&tmp_x>0)
        {
            vec_1.push_back(tmp_x);
            tmp_x=0;
            is_end = true;
        }
    } while(!is_end);

    for(int i : vec_1){
        vec_2.push_back(fmod((pow(g, i)),mod_Number));
    }

    for(int i : vec_2){
        if(i>0){
            tmp = tmp * i;
        }
    }
    private_X = tmp % mod_Number;

    mVerifier->set_variable('X', private_X);

    mView->set_variable('X', private_X);
}

void cProver::gen_y_number(long long int min_value, long long int max_value) {
    private_y = rand() % (max_value-min_value+1) + min_value;

    mView->set_variable('y', private_y);
}

void cProver::calculate_Y() {
    //private_Y = (int)fmod(pow(g,private_y), mod_Number);

    vec_1.erase(begin(vec_1),end(vec_1));
    vec_2.erase(begin(vec_2),end(vec_2));
    tmp=1;
    tmp_y = private_y;
    bool is_end = false;

    do{
        if(tmp_y>10){
            tmp_y -= 10;
            vec_1.push_back(10);
        }
        else if(tmp_y<=10&&tmp_y>0)
        {
            vec_1.push_back(tmp_y);
            tmp_y=0;
            is_end = true;
        }
    } while(!is_end);

    for(int i : vec_1){
        vec_2.push_back(fmod((pow(g, i)),mod_Number));
    }

    for(int i : vec_2){
        if(i>0){
            tmp = tmp * i;
        }
    }
    private_Y = tmp % mod_Number;


    mVerifier->set_variable('Y',private_Y);

    mView->set_variable('Y', private_Y);
}

void cProver::set_c(long long int value) {
    recived_c=value;
}

void cProver::calculate_z() {
    z=(private_y+private_x*recived_c);
    mVerifier->set_variable('z', z);

    mView->set_variable('z', z);
}
