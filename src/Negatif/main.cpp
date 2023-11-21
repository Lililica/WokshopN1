#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for (glm::vec3& color : image.pixels())
    {
        color = 1.f-color;
    }
    image.save("output/exo4.png");

}