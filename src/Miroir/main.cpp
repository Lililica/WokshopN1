#include <sil/sil.hpp>

int main(){
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{"images/logo.png"};
    // TODO: modifier l'image
    
    for (int x{0}; x < imageOutPut.width(); ++x)
    {
        for (int y{0}; y < imageOutPut.height(); ++y)
        {
            imageOutPut.pixel(x, y) = imageRef.pixel(imageOutPut.width()-x-1,y);
        }
    }
    imageOutPut.save("output/exo6.png");

}