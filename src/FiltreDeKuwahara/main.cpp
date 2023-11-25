#include <sil/sil.hpp>
#include <vector>
#include <array>
#include <iostream>

float getEcartType(std::vector<glm::vec3> const& section, glm::vec3 moyenne){
    glm::vec3 sum{0, 0, 0};
    for(int i{0}; i<section.size(); i++){
        sum += glm::vec3{pow(section[i].r-moyenne.r,2),pow(section[i].b-moyenne.b,2),pow(section[i].g-moyenne.g,2)};
    }
    sum = glm::vec3{pow(sum.r/section.size(),0.5f),pow(sum.g/section.size(),0.5f),pow(sum.b/section.size(),0.5f)};
    float result{(sum.r+sum.b+sum.g)/3};
    return result;
}

glm::vec3 getMoyenne(std::vector<glm::vec3> const& section){
    glm::vec3 sum{0, 0, 0};
    for(int i{0}; i<section.size(); i++){
        sum += section[i];
    }
    sum /= section.size();
    return sum;
}

int getIndiceDuMax(std::array<float,4> ecartType){
    int indiceDuMax{0};
    float minDeEcartType{1}; 
    for(int i{0}; i<4; i++){
        if(ecartType[i]<minDeEcartType){
            minDeEcartType = ecartType[i];
            indiceDuMax = i;
        }
    }
    return indiceDuMax;
}

int main()
{
    sil::Image imageRef{"images/photoFlou10.jpg"};
    sil::Image imageOutput{"images/photoFlou10.jpg"};
    // TODO: modifier l'image

    int intensiteFlou{2};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
            std::vector<glm::vec3> firstSection{};
            std::vector<glm::vec3> secondSection{};
            std::vector<glm::vec3> thirdSection{};
            std::vector<glm::vec3> fourthSection{};
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
                    if((i-intensiteFlou)>=0){
                        if((j-intensiteFlou)>=0){
                            fourthSection.push_back(imageRef.pixel(xi,yi));
                        }
                        if((j-intensiteFlou)<=0){
                            thirdSection.push_back(imageRef.pixel(xi,yi));
                        }
                    }
                    if((i-intensiteFlou)<=0){
                        if((j-intensiteFlou)>=0){
                            secondSection.push_back(imageRef.pixel(xi,yi));
                        }
                        if((j-intensiteFlou)<=0){
                            firstSection.push_back(imageRef.pixel(xi,yi));
                        }
                    }
                }
            }

            std::array<glm::vec3,4> pixelMoyen{
                glm::vec3{getMoyenne(firstSection)},
                glm::vec3{getMoyenne(secondSection)},
                glm::vec3{getMoyenne(thirdSection)},
                glm::vec3{getMoyenne(fourthSection)},

            };

            std::array<float,4> ecartType{
                getEcartType(firstSection, pixelMoyen[0]),
                getEcartType(secondSection, pixelMoyen[1]),
                getEcartType(thirdSection, pixelMoyen[2]),
                getEcartType(fourthSection, pixelMoyen[3]),
            };


            int indiceDuMax{getIndiceDuMax(ecartType)};

            imageOutput.pixel(x,y) = pixelMoyen[indiceDuMax];
        }
    }
    imageOutput.save("output/Kuwahara/intensiteentree10.png");
}