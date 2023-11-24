#include <sil/sil.hpp>
#include <iostream>

glm::vec3 makeFlouGauss(int intensiteFlou, int x, int y, sil::Image const& imageRef){
            glm::vec3 vecteuri{};
            for(int i{0}; i<2*intensiteFlou+1; i++){
                glm::vec3 vecteurj{};
                for(int j{0}; j<2*intensiteFlou+1; j++){
                    int xi{x+i-(intensiteFlou)};
                    int yi{y+j-(intensiteFlou)};
                    if((xi<0)||(xi>=imageRef.width())){
                        xi = x;
                    }
                    if((yi<0)||(yi>=imageRef.height())){
                        yi = y;
                    }
                    vecteurj += imageRef.pixel(xi,yi);
                }
                vecteuri += vecteurj/static_cast<float>((2*intensiteFlou)+1);
            }
            return vecteuri;
}

int main()
{
    sil::Image imageRef{"images/photo.jpg"};
    sil::Image imageOutput{"images/photo.jpg"};
    // TODO: modifier l'image

    int intensiteFlou{1};
    int intensiteFlouSub{5};
    float const facteurBlancNoir{0.2};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){

            glm::vec3 vecteur{makeFlouGauss( intensiteFlou, x, y, imageRef)};
            glm::vec3 vecteurSub{makeFlouGauss( intensiteFlouSub, x, y, imageRef)};
    
            vecteur /= static_cast<float>((intensiteFlou*2)+1);
            vecteurSub /= static_cast<float>((intensiteFlouSub*2)+1);
            float tau{2.5};
            vecteur = (1+tau)*vecteur-tau*vecteurSub;
             float brightness{(vecteur.r+vecteur.b+vecteur.g)/3};
            // float brightnessSub{(vecteurSub.r+vecteurSub.b+vecteurSub.g)/3};
            if(brightness>facteurBlancNoir){
                 imageOutput.pixel(x,y) = glm::vec3{1.f};
                 continue;
            }
            imageOutput.pixel(x,y) = glm::vec3{0.f};
            // imageOutput.pixel(x,y) = vecteur;
        }
    }
    imageOutput.save("output/exo24.png");

}