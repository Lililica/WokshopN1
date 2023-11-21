#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    
    
    for (glm::vec3& color : image.pixels())
    {
        color.r = 1.0 - color.r;
        color.g = 1.0 - color.g;
        color.b = 1.0 - color.b;
    }
    image.save("output/negatif.png");
}