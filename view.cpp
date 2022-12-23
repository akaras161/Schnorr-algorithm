#include "view.h"

cView::cView() {
    Update();
}

void cView::set_variable(char type, long long int value) {
    switch(type){
        case 'N':
            N = value;
            std::cout<<"Wylosowano liczbe N: "<<N<<std::endl;
            Update();
            break;
        case 'X':
            X = value;
            std::cout<<"Obliczono liczbe X: "<<X<<std::endl;
            Update();
            break;
        case 'Y':
            Y = value;
            std::cout<<"Obliczono liczbe Y: "<<Y<<std::endl;
            Update();
            break;
        case 'g':
            g = value;
            std::cout<<"Wylosowano liczbe g: "<<g<<std::endl;
            Update();
            break;
        case 'z':
            z = value;
            std::cout<<"Obliczono liczbe z: "<<z<<std::endl;
            Update();
            break;
        case 'c':
            c = value;
            std::cout<<"Wylosowano liczbe c: "<<c<<std::endl;
            Update();
            break;
        case 'Q':
            Q = value;
            std::cout<<"Obliczono liczbe Q: "<<Q<<std::endl;
            Update();
            break;
        case 'W':
            W = value;
            std::cout<<"Obliczono liczbe W: "<<W<<std::endl;
            Update();
            break;
        case 'x':
            x = value;
            std::cout<<"Wylosowano liczbe x: "<<x<<std::endl;
            Update();
            break;
        case 'y':
            y = value;
            std::cout<<"Wylosowano liczbe y: "<<y<<std::endl;
            Update();
            break;
        default:
            break;
    }
}

void cView::Update() const {

    std::cout<<"PROVER"<<"\t\t"<<"|\t"<<"VERIFIER\n";
    std::cout<<"[N= "<<N<<"]"<<"\t\t"<<"|\t"<<"[N= "<<N<<"]\n";
    std::cout<<"[g= "<<g<<"]"<<"\t\t"<<"|\t"<<"[g= "<<g<<"]\n";
    std::cout<<"[x= "<<x<<"]"<<"\t\t"<<"|\t"<<"[x= -]\n";
    std::cout<<"[X= "<<X<<"]"<<"\t\t"<<"|\t"<<"[X= "<<X<<"]\n";
    std::cout<<"[y= "<<y<<"]"<<"\t\t"<<"|\t"<<"[y= -]\n";
    std::cout<<"[Y= "<<Y<<"]"<<"\t\t"<<"|\t"<<"[Y= "<<Y<<"]\n";
    std::cout<<"[c= "<<c<<"]"<<"\t\t"<<"|\t"<<"[c= "<<c<<"]\n";
    std::cout<<"[z= "<<z<<"]"<<"\t\t"<<"|\t"<<"[z= "<<z<<"]\n";
    std::cout<<"[Q= -]"<<"\t\t"<<"|\t"<<"[Q= "<<Q<<"]\n";
    std::cout<<"[W= -]"<<"\t\t"<<"|\t"<<"[W= "<<W<<"]\n\n";

}