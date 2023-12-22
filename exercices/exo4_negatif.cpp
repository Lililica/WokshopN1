#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    
    
    for (glm::vec3& color : image.pixels())
    {
        color = 1.0f - color; // On peut faire les opérations sur les vec3 directement, composante par composante
    }
    image.save("output/negatif.png");
}