#include <sil/sil.hpp>
#include <vector>
#include <array>
#include <iostream>

float getEcartType(std::vector<glm::vec3> section, int color, float moyenne){
    float sum{0};
    for(int i{0}; i<section.size(); i++){
        sum += pow(section[i][color]-moyenne,2);
    }
    sum = pow(sum/section.size(),0.5f);
    return sum;
}

float getMoyenne(std::vector<glm::vec3> section, int color){
    float sum{0};
    for(int i{0}; i<section.size(); i++){
        sum += section[i][color];
    }
    sum /= section.size();
    return sum;
}

int main()
{
    sil::Image imageRef{"images/photoFlou.jpg"};
    sil::Image imageOutput{"images/photoFlou.jpg"};
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
                    if((i-intensiteFlou)>0){
                        if((j-intensiteFlou)>0){
                            fourthSection.push_back(imageRef.pixel(xi,yi));
                        }
                        if((j-intensiteFlou)<0){
                            thirdSection.push_back(imageRef.pixel(xi,yi));
                        }
                    }
                    if((i-intensiteFlou)<0){
                        if((j-intensiteFlou)>0){
                            secondSection.push_back(imageRef.pixel(xi,yi));
                        }
                        if((j-intensiteFlou)<0){
                            firstSection.push_back(imageRef.pixel(xi,yi));
                        }
                    }
                }
            }

            std::array<glm::vec3,4> pixelMoyen{
                glm::vec3{getMoyenne(firstSection, 0),getMoyenne(firstSection, 1),getMoyenne(firstSection, 2)},
                glm::vec3{getMoyenne(secondSection, 0),getMoyenne(secondSection, 1),getMoyenne(secondSection, 2)},
                glm::vec3{getMoyenne(thirdSection, 0),getMoyenne(thirdSection, 1),getMoyenne(thirdSection, 2)},
                glm::vec3{getMoyenne(fourthSection, 0),getMoyenne(fourthSection, 1),getMoyenne(fourthSection, 2)},

            };

            std::array<float,4> ecartType{
                (getEcartType(firstSection, 0, getMoyenne(firstSection, 0))+getEcartType(firstSection, 1, getMoyenne(firstSection, 1))+getEcartType(firstSection, 2, getMoyenne(firstSection, 2)))/3,
                (getEcartType(secondSection, 0, getMoyenne(secondSection, 0))+getEcartType(secondSection, 1, getMoyenne(secondSection, 1))+getEcartType(secondSection, 2, getMoyenne(secondSection, 2)))/3,
                (getEcartType(thirdSection, 0, getMoyenne(thirdSection, 0))+getEcartType(thirdSection, 1, getMoyenne(thirdSection, 1))+getEcartType(thirdSection, 2, getMoyenne(thirdSection, 2)))/3,
                (getEcartType(fourthSection, 0, getMoyenne(fourthSection, 0))+getEcartType(fourthSection, 1, getMoyenne(fourthSection, 1))+getEcartType(fourthSection, 2, getMoyenne(fourthSection, 2)))/3,
            };

            // for(float a : ecartType){
            //     std::cout << a << ", ";
            // }
            // std::cout << std::endl;
            int indiceDuMax{0};
            float minDeEcartType{1};
            for(int i{0}; i<4; i++){
                if(ecartType[i]<minDeEcartType){
                    minDeEcartType = ecartType[i];
                    indiceDuMax = i;
                }
            }

            imageOutput.pixel(x,y) = pixelMoyen[indiceDuMax];
        }
    }
    imageOutput.save("output/exo26.png");
}