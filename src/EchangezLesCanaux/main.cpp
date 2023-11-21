#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for (glm::vec3& color : image.pixels())
    {
        std::swap(color.b, color.r);
    }
    image.save("output/exo2.png");

}