#include <sil/sil.hpp>
#include "random.hpp"

int main(){
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{"images/logo.png"};

    int nbr_glitch{100};

    for(int i{0}; i<nbr_glitch; i++){
        // Creation du rectangle à copier
        int x0{random_int(0, imageOutPut.width() - 50)};
        int y0{random_int(0, imageOutPut.height() - 10)};
        int x1{random_int(x0+2,x0+50)}; 
        int y1{random_int(y0+1,y0+5)};

        // Determiner ou on met le rectangle
        int xi{random_int(0, imageOutPut.width() - 50)};
        int yi{random_int(0, imageOutPut.height() - 10)};

        // On copie colle le rectangle
        for(int x{x0}; x < x1; x++){
            for(int y{y0}; y <= y1; y++){
                imageOutPut.pixel(x - x0 + xi,y - y0 + yi) = imageRef.pixel(x,y);
            }
        }
    }  

    imageOutPut.save("output/exo16.png");

}