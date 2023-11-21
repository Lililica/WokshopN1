#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
    image.save("output/exo1.png");

}