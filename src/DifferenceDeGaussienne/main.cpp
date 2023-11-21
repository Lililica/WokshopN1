#include <sil/sil.hpp>



int main()
{
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutput{"images/logo.png"};
    // TODO: modifier l'image

    int intensiteFlou{3};
    int intensiteFlouSub{7};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
            glm::vec3 vecteur{};
            for(int i{0}; i<2*intensiteFlou+1; i++){
                for(int j{0}; j<2*intensiteFlou+1; j++){
                    if((x+i-(intensiteFlou)<intensiteFlou)||(y+j-(intensiteFlou)<intensiteFlou)||(x+i-(intensiteFlou)>imageOutput.width()-intensiteFlou-1)||(y+j-(intensiteFlou)>imageOutput.height()-intensiteFlou-1)){
                        continue;
                    }
                    vecteur += imageRef.pixel(x+i-(intensiteFlou),y+j-(intensiteFlou));
                }
            }
            imageOutput.pixel(x,y) = vecteur/static_cast<float>(pow((intensiteFlou*2)+1,2));
        }
    }
    imageOutput.save("output/exo24.png");

}