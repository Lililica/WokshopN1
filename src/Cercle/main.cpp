#include <sil/sil.hpp>

int main()
{
    sil::Image image{500/*width*/, 500/*height*/};  

    int const centerX{(image.width()-1)/2};
    int const centerY{(image.height()-1)/2};
    int const Rayon{100};
    int const thickness{10};

    for(int x{0}; x<image.width(); x++){
        for(int y{0}; y<image.height(); y++){
            double const rayonActuel{pow(pow(y-centerY,2)+pow(x-centerX,2),0.5)};
            if((rayonActuel <= Rayon) && (rayonActuel >= Rayon-thickness)){
                image.pixel(x, y) = glm::vec3{1.f};
            }
        }
    }

    image.save("output/exo12.png");

}