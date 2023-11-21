#include <sil/sil.hpp>

int main()
{
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.height(), imageRef.width()};
    // TODO: modifier l'image

    for (int x{0}; x < imageOutPut.width(); x++)
    {
        for (int y{0}; y < imageOutPut.height(); y++)
        {
            imageOutPut.pixel(x, y) = imageRef.pixel(y,imageRef.height()-x-1);
        }
    }

    imageOutPut.save("output/exo8.png");

}