#include <sil/sil.hpp>
#include <complex>

int main(){
    sil::Image image{1000,1000};

    for(int x{0}; x<image.width(); x++){
        for(int y{0}; y<image.height(); y++){
            int compteur{0};
            std::complex<float> c{(static_cast<float>(x)/350.f)-2.f,(static_cast<float>(y)/350.f)-static_cast<float>(1.5)};
            std::complex<float> z{c};
            while(compteur < 50){
                if(std::abs(z) > 2){
                    break;
                }
                z = z*z + c;
                compteur++;
            }
            float nuance_gris{static_cast<float>(compteur)/static_cast<float>(50)};
            image.pixel(x,y) = glm::vec3{nuance_gris,nuance_gris,nuance_gris};
        }
    }

    image.save("output/Fractale/Test4.png");

}