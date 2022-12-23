#ifndef SCHNORR_VIEW_H
#define SCHNORR_VIEW_H
#include <iostream>
#include <cstdlib>

class cView {
private:
    long long int N=0,g=0,x=0,X=0,y=0,Y=0,c=0,z=0,Q=0,W=0;

public:
    cView();
    void set_variable(char type, long long int value);
    void Update() const;
};


#endif //SCHNORR_VIEW_H
