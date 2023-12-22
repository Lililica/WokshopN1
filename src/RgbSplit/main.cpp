#include <sil/sil.hpp>

int main()
{
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.width(),imageRef.height()};
    // TODO: modifier l'image
    
    int glitch_intensity{20};
    
    // On peut ne faire la boucle sur y qu'une seule fois, si on la met en premier
    for (int y{0}; y < imageOutPut.height(); ++y)
    {
        for (int x{0}; x < glitch_intensity; ++x)
        {
            imageOutPut.pixel(x, y).g = imageRef.pixel(x, y).g;
            imageOutPut.pixel(x, y).b = imageRef.pixel(x+20,y).b;
        }
        
        for (int x{glitch_intensity}; x < imageOutPut.width()-glitch_intensity; ++x)
        {
            imageOutPut.pixel(x, y).r = imageRef.pixel(x-20,y).r;
            imageOutPut.pixel(x, y).g = imageRef.pixel(x, y).g;
            imageOutPut.pixel(x, y).b = imageRef.pixel(x+20,y).b;
        }

        for (int x{imageOutPut.width()-glitch_intensity}; x < imageOutPut.width(); ++x)
        {
            imageOutPut.pixel(x, y).r = imageRef.pixel(x-20,y).r;
            imageOutPut.pixel(x, y).g = imageRef.pixel(x, y).g;
        }
    }
    imageOutPut.save("output/exo9.png");

}