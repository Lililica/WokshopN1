#include <sil/sil.hpp>
#include "random.hpp"

int main(){
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{"images/logo.png"};

    int const nbr_glitch{100};

    for(int i{0}; i<nbr_glitch; i++){
        // Creation du rectangle à copier
        int const maxWidth{80};
        int x0{random_int(0, imageOutPut.width() - maxWidth)};
        int y0{random_int(0, imageOutPut.height() - 10)};
        int w{random_int(2,maxWidth)}; 
        int h{random_int(1,5)};

        // Determiner ou on met le rectangle
        int xi{random_int(0, imageOutPut.width() - maxWidth)};
        int yi{random_int(0, imageOutPut.height() - 10)};

        // On copie colle le rectangle
        for(int x_offset{0}; x_offset < w; x_offset++){
            for(int y_offset{0}; y_offset < h; y_offset++){
                imageOutPut.pixel(xi + x_offset,yi + y_offset) = imageRef.pixel(x0 + x_offset,y0 + y_offset);
            }
        }
    }  

    imageOutPut.save("output/exo16.png");

}