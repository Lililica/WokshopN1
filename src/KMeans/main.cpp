#include <sil/sil.hpp>
#include "random.hpp"
#include <vector>
#include <array>




int main(){
    sil::Image image{"images/photo.jpg"};

    int const facteurK{8};
    bool stop{false};
    float const facteurIteration{0};


    std::array<std::vector<glm::vec2>,facteurK> tableauDeRepartitionDesPixels{};
    std::array<glm::vec3,facteurK> tableauDesCouleursARetenir{};

    for(int i{0}; i<facteurK; i++){
        tableauDesCouleursARetenir[i] = image.pixel(random_int(0,image.width()-1), random_int(0, image.height()));
    }
    
    while(!stop){
        for(int x{0}; x<image.width(); x++){
            for(int y{0}; y<image.height(); y++){
                glm::vec3 color{image.pixel(x, y)};
                int indiceToSave{0};
                float distanceMin{static_cast<float>(image.width()*image.height())};
                for(int i{0}; i<facteurK; i++){    
                    float distanceActuelEni{glm::distance(color, tableauDesCouleursARetenir[i])};
                    if(distanceActuelEni<distanceMin){
                        distanceMin = distanceActuelEni;
                        indiceToSave = i;
                    }
                }
                tableauDeRepartitionDesPixels[indiceToSave].push_back(glm::vec2{x,y});
            }
        }

        for(int i{0}; i<tableauDeRepartitionDesPixels.size(); i++){
            glm::vec3 sum{};
            for(glm::vec2 coordOfColorInAZone : tableauDeRepartitionDesPixels[i]){
                    sum += image.pixel(coordOfColorInAZone[0],coordOfColorInAZone[1]);
            }
            sum /= static_cast<float>(tableauDeRepartitionDesPixels[i].size());
            if((abs(sum.r-tableauDesCouleursARetenir[i].r <= facteurIteration))&&(abs(sum.b-tableauDesCouleursARetenir[i].b <= facteurIteration))&&(abs(sum.g-tableauDesCouleursARetenir[i].g <= facteurIteration))){
                stop = true;
            }
            tableauDesCouleursARetenir[i] = sum;
        }
    }

    for(int i{0}; i<tableauDeRepartitionDesPixels.size(); i++){
        for(glm::vec2 couple : tableauDeRepartitionDesPixels[i]){
            image.pixel(couple[0], couple[1]) = tableauDesCouleursARetenir[i];
        }
    }

    image.save("output/exo27.png");

}