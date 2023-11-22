#include <sil/sil.hpp>



int main()
{
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutput{"images/logo.png"};
    // TODO: modifier l'image

    int intensiteFlou{20};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
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
            imageOutput.pixel(x,y) = vecteuri/static_cast<float>((intensiteFlou*2)+1);
        }
    }
    imageOutput.save("output/exo23.png");
}