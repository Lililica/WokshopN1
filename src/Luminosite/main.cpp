#include <sil/sil.hpp>

int main()
{
    sil::Image imageEclaircie{"images/photo.jpg"};
    sil::Image imageAssombrie{"images/photo.jpg"};

    float intensiteModify{-2};

    // TODO: modifier l'image
    for(glm::vec3& color : imageAssombrie.pixels()){
        color = glm::pow(color, glm::vec3{intensiteModify});
    }

    for(glm::vec3& color : imageEclaircie.pixels()){
        color = glm::pow(color,glm::vec3{1/intensiteModify});
    }   

    imageEclaircie.save("output/Luminosite/LumiUpModif-2.png");
    imageAssombrie.save("output/Luminosite/LumiDownModif-2.png");

}