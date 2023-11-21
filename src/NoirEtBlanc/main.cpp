#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    
    for (glm::vec3& color : image.pixels())
    {
        float pixel_baw{(color.r+color.b+color.g)/3};
        color.r = pixel_baw;
        color.b = pixel_baw;
        color.g = pixel_baw;
    }
    image.save("output/exo3.png");

}