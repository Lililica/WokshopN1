#include <sil/sil.hpp>
#include "glm/gtx/matrix_transform_2d.hpp"


glm::vec2 rotated(glm::vec2 v, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{v, 0.f}};
} 

int main(){
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.width(), imageRef.height()};
    

    int x0{imageOutPut.width()/2};
    int y0{imageOutPut.height()/2};

    for (int x{0}; x < imageOutPut.width(); ++x)
    {
        for (int y{0}; y < imageOutPut.height(); ++y)
        {
            double rayonActuel{pow(pow(x-x0,2)+pow(y-y0,2),0.5)};
            double angle{rayonActuel*2*3.14/static_cast<float>(imageRef.height()/5)};

            glm::vec2 vecteur{x-x0,y-y0};
            vecteur = rotated(vecteur, angle);
            vecteur = {vecteur[0]+x0, vecteur[1]+y0};
            if((vecteur[0] <= imageOutPut.width()-1)&&(vecteur[1] <= imageOutPut.height()-1)&&(vecteur[0] >= 0)&&(vecteur[1] >= 0)){
                imageOutPut.pixel(x, y) = imageRef.pixel(static_cast<int>(vecteur[0]), static_cast<int>(vecteur[1]));
            }

        }
    }

    imageOutPut.save("output/exo18.png");

}