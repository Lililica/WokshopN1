#include <sil/sil.hpp>

int main(){
    sil::Image imageRef{"images/logo.png"};
    // TODO: modifier l'image
    
    for (int x{0}; x < imageRef.width() / 2; ++x)
    {
        for (int y{0}; y < imageRef.height(); ++y)
        {
          std::swap(
             imageRef.pixel(x, y) ,
              imageRef.pixel(imageRef.width()-x-1,y)
          );
        }
    }
    imageRef.save("output/exo6.png");

}