#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for(int nombrePixelModif{0}; nombrePixelModif<20000; nombrePixelModif++){
        int x{random_int(0,image.width()-1)};
        int y{random_int(0,image.height()-1)};
        image.pixel(x,y).r = random_float(0,1);
        image.pixel(x,y).b = random_float(0,1);
        image.pixel(x,y).g = random_float(0,1);
    }
    image.save("output/exo7.png");

}