#include <sil/sil.hpp>

glm::vec3 makeFlouGauss(int intensiteFlou, int x, int y, sil::Image imageRef){
            glm::vec3 vecteur{};
            for(int i{0}; i<2*intensiteFlou+1; i++){
                for(int j{0}; j<2*intensiteFlou+1; j++){
                    if((x+i-(intensiteFlou)<intensiteFlou)||(y+j-(intensiteFlou)<intensiteFlou)||(x+i-(intensiteFlou)>imageRef.width()-intensiteFlou-1)||(y+j-(intensiteFlou)>imageRef.height()-intensiteFlou-1)){
                        continue;
                    }
                    vecteur += imageRef.pixel(x+i-(intensiteFlou),y+j-(intensiteFlou));
                }
            }
            return vecteur;
}

int main()
{
    sil::Image imageRef{"images/photo.jpg"};
    sil::Image imageOutput{"images/photo.jpg"};
    // TODO: modifier l'image

    int intensiteFlou{1};
    int intensiteFlouSub{3};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
            glm::vec3 vecteur{makeFlouGauss(intensiteFlou, x, y, imageRef)};
            glm::vec3 vecteur_sub{makeFlouGauss(intensiteFlouSub, x, y, imageRef)};
            vecteur -= vecteur_sub;
            imageOutput.pixel(x,y) = vecteur/static_cast<float>(pow((intensiteFlou*2)+1,2));
        }
    }
    imageOutput.save("output/exo24.png");

}