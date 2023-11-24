#include <sil/sil.hpp>
#include "random.hpp"
#include <vector>
#include <array>




int main(){
    sil::Image image{"images/photo.jpg"};

    int const facteurK{3};
    bool stop{false};
    float const facteurIteration{0};

    std::array<std::vector<glm::vec2>,facteurK> positionDesPixelsParZone{};
    std::array<glm::vec3,facteurK> couleurPixelMoyen{};

    for(int i{0}; i<facteurK; i++){
        couleurPixelMoyen[i] = image.pixel(random_int(0,image.width()-1), random_int(0, image.height()));
    }
    
    while(!stop){
        for(int x{0}; x<image.width(); x++){
            for(int y{0}; y<image.height(); y++){
                glm::vec3 color{image.pixel(x, y)};
                int indiceToSave{0};
                float distanceMin{static_cast<float>(image.width()*image.height())};
                for(int i{0}; i<facteurK; i++){    
                    float distanceActuelEni{glm::distance(color, couleurPixelMoyen[i])};
                    if(distanceActuelEni<distanceMin){
                        distanceMin = distanceActuelEni;
                        indiceToSave = i;
                    }
                }
                positionDesPixelsParZone[indiceToSave].push_back(glm::vec2{x,y});
            }
        }

        for(int i{0}; i<positionDesPixelsParZone.size(); i++){
            glm::vec3 sum{};
            for(glm::vec2 coordOfColorInAZone : positionDesPixelsParZone[i]){
                    sum += image.pixel(coordOfColorInAZone[0],coordOfColorInAZone[1]);
            }
            sum /= static_cast<float>(positionDesPixelsParZone[i].size());
            if((abs(sum.r-couleurPixelMoyen[i].r <= facteurIteration))&&(abs(sum.b-couleurPixelMoyen[i].b <= facteurIteration))&&(abs(sum.g-couleurPixelMoyen[i].g <= facteurIteration))){
                stop = true;
            }
            couleurPixelMoyen[i] = sum;
        }
    }

    for(int i{0}; i<positionDesPixelsParZone.size(); i++){
        for(glm::vec2 couple : positionDesPixelsParZone[i]){
            image.pixel(couple[0], couple[1]) = couleurPixelMoyen[i];
        }
    }

    image.save("output/KMeans/3colors1.png");

}