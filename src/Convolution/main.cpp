#include <sil/sil.hpp>



int main()
{
    sil::Image imageRef{"images/photo.jpg"};
    sil::Image imageOutput{"images/photo.jpg"};
    // TODO: modifier l'image

    int intensiteFlou{1};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
            glm::vec3 vecteur{};
            for(int i{0}; i<2*intensiteFlou+1; i++){
                for(int j{0}; j<2*intensiteFlou+1; j++){
                    int xi{x+i-(intensiteFlou)};
                    int yi{y+j-(intensiteFlou)};
                    if((xi<0)||(xi>=imageRef.width())){
                        xi = x;
                    }
                    if((yi<0)||(yi>=imageRef.height())){
                        yi = y;
                    }
                    vecteur += imageRef.pixel(xi,yi);
                }
            }
            imageOutput.pixel(x,y) = vecteur/static_cast<float>(pow((intensiteFlou*2)+1,2));
        }
    }
    imageOutput.save("images/photoFlou.jpg");
}