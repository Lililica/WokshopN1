#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for (glm::vec3& color : image.pixels())
    {
        color.r = 1-color.r;
        color.b = 1-color.b;
        color.g = 1-color.g;
    }
    image.save("output/exo4.png");

}