#include <sil/sil.hpp>

int main()
{
    sil::Image imageEclaircie{"images/photo.jpg"};
    sil::Image imageAssombrie{"images/photo.jpg"};

    // TODO: modifier l'image
    for(glm::vec3& color : imageAssombrie.pixels()){


        color = glm::pow(color, glm::vec3{5.});
    }

    for(glm::vec3& color : imageEclaircie.pixels()){
        color.r = pow(color.r,0.3);
        color.g = pow(color.g,0.3);
        color.b = pow(color.b,0.3);
    }   

    imageEclaircie.save("output/exo10LumiUp.png");
    imageAssombrie.save("output/exo10LumiDown.png");

}