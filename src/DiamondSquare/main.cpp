#include <sil/sil.hpp>
#include "random.hpp"
#include <vector>
#include <array>

struct extremP{
    int x{};
    int y{};
    int value{-1};
};

int moyenneRandomised(int scaleRandom, std::array<extremP,4> & vectorValue){
    int sum{0};
    for(extremP value : vectorValue){
        sum += value.value;
    }
    return (sum/static_cast<int>(vectorValue.size()))+random_int(-scaleRandom, scaleRandom);
}

float getBrightness(glm::vec3 & color){
    float sum{};
    for(int i{0}; i<3; i++){
        sum += color[i];
    }
    return sum/3;
}

// int getMiddleAbcsisse(std::array<extremP,4> & extremPoint){
//     return extremPoint[0].x/2 + (extremPoint[1].x-extremPoint[0].x + extremPoint[2].x-extremPoint[0].x)/2;
// }

// int getMiddleOrdonnee(std::array<extremP,4> & extremPoint){
//     return extremPoint[0].y/2 + (extremPoint[1].y-extremPoint[0].y + extremPoint[2].y-extremPoint[0].y)/2;
// }

// int getAbscisseOpposee(extremP & milieu, extremP & Top, extremP & Bot){
//     return milieu.x + (Top.x-milieu.x + Bot.x-milieu.x);
// }

// int getOrdoneeOpposee(extremP & milieu, extremP & Top, extremP & Bot){
//     return milieu.y + (Top.y-milieu.y + Bot.y-milieu.y);
// }

void squareStep(int & chunkSize, int & half, int &heightMapSize, sil::Image & image, float&  scaleRandom){
    for(int x{0}; x<heightMapSize-1; x+=chunkSize){
        for(int y{0}; y<heightMapSize-1; y+=chunkSize){
            float brightnessMiddle{(getBrightness(image.pixel(x,y))+getBrightness(image.pixel(x + chunkSize,y)) + getBrightness(image.pixel(x + chunkSize,y + chunkSize)) + getBrightness(image.pixel(x ,y + chunkSize)))/4};
            image.pixel(x + half, y + half) = glm::vec3{(brightnessMiddle)} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
        }
    }
}

void diamondStep(int & chunkSize, int & half, int &heightMapSize, sil::Image & image, float&  scaleRandom){
    for(int x{0}; x<heightMapSize-1; x+=half){
        for(int y{(x+half)%chunkSize}; y<heightMapSize-1; y+=chunkSize){
            if(y-half<0){
                float brightnessMiddle{(getBrightness(image.pixel(x - half,y)) + getBrightness(image.pixel(x + half,y )) + getBrightness(image.pixel(x ,y + half)))/3};
                image.pixel(x, y) = glm::vec3{brightnessMiddle} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
            }
            else if (x-half<0)
            {
                float brightnessMiddle{(getBrightness(image.pixel(x,y - half)) + getBrightness(image.pixel(x + half,y )) + getBrightness(image.pixel(x ,y + half)))/3};
                image.pixel(x, y) = glm::vec3{(brightnessMiddle)} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
            }
            else if (y+half>=image.height())
            {
                float brightnessMiddle{(getBrightness(image.pixel(x,y - half)) + getBrightness(image.pixel(x - half,y)) + getBrightness(image.pixel(x + half,y )))/3};
                image.pixel(x , y ) = glm::vec3{(brightnessMiddle)} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
            }
            else if (x+half>=image.width())
            {
                float brightnessMiddle{(getBrightness(image.pixel(x,y - half)) + getBrightness(image.pixel(x - half,y))  + getBrightness(image.pixel(x ,y + half)))/3};
                image.pixel(x , y ) = glm::vec3{(brightnessMiddle)} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
            }
            else{
                float brightnessMiddle{(getBrightness(image.pixel(x,y - half))+getBrightness(image.pixel(x - half,y)) + getBrightness(image.pixel(x + half,y )) + getBrightness(image.pixel(x ,y + half)))/4};
                image.pixel(x , y ) = glm::vec3{(brightnessMiddle)} + glm::vec3{random_float(-scaleRandom,scaleRandom)};
            }
            
        }
    }
}

int main(){
    
    int tailleDuTableau{9};

    sil::Image image{static_cast<int>(pow(2,tailleDuTableau))+1/*width*/, static_cast<int>(pow(2,tailleDuTableau))+1/*height*/};


    int heightMapSize{image.height()};
    int chunkSize{heightMapSize-1};


    int nbrDeNuance{8};
    float roughness{2.f};
    

    extremP botLef {0, 0, random_int(0,nbrDeNuance)};
    extremP botRig {image.width()-1, 0, random_int(0,nbrDeNuance)};
    extremP topLef {0, image.height()-1, random_int(0,nbrDeNuance)};
    extremP topRig {image.width()-1, image.height()-1, random_int(0,nbrDeNuance)};

    std::array<extremP,4> extremPoint{ botLef, botRig, topLef, topRig};


    for(int i{0}; i<extremPoint.size(); i++){
        image.pixel(extremPoint[i].x,extremPoint[i].y) = glm::vec3{static_cast<float>(extremPoint[i].value)/static_cast<float>(nbrDeNuance+roughness)};
    }

    while(chunkSize>1){
        int halfOfChunk{chunkSize/2};
        squareStep(chunkSize, halfOfChunk, heightMapSize, image, roughness);
        diamondStep(chunkSize, halfOfChunk, heightMapSize, image, roughness);
        chunkSize /= 2;
        roughness /= 2;
    }

    // int xMid{getMiddleAbcsisse(extremPoint)};
    // int yMid{getMiddleOrdonnee(extremPoint)};
    // if((image.pixel(xMid,yMid).r==0.f)&&(image.pixel(xMid,yMid).r==0.f)
    // extremP middle {xMid,yMid, moyenneRandomised(scaleRandom,extremPoint)};
    // image.pixel(middle.x,middle.y) = glm::vec3{static_cast<float>(middle.value)/static_cast<float>(nbrDeNuance+scaleRandom)};

    // int xi{getAbscisseOpposee(middle, botRig, botLef)};
    // int yi{getOrdoneeOpposee(middle, botRig, botLef)};
    // std::array<extremP,4> extremPointNew1{ middle, botRig, botLef, extremP {xi,yi,(xi>=0)||(xi<image.width())||(yi>=0)||(yi<image.height())?getBrightness(image.pixel(xi,yi)):-1}};
    
    // xi = getAbscisseOpposee(middle, botRig, topRig);
    // yi = getOrdoneeOpposee(middle, botRig, topRig); 
    // std::array<extremP,4> extremPointNew2{ middle, botRig, topRig, extremP {xi,yi,(xi>=0)||(xi<image.width())||(yi>=0)||(yi<image.height())?getBrightness(image.pixel(xi,yi)):-1}};
    
    // xi = getAbscisseOpposee(middle, topLef, topRig);
    // yi = getOrdoneeOpposee(middle, topLef, topRig); 
    // std::array<extremP,4> extremPointNew3{ middle, topRig, topLef, extremP {xi,yi,(xi>=0)||(xi<image.width())||(yi>=0)||(yi<image.height())?getBrightness(image.pixel(xi,yi)):-1}};
    
    // xi = getAbscisseOpposee(middle, topLef, botLef);
    // yi = getOrdoneeOpposee(middle, topLef, botLef);
    // std::array<extremP,4> extremPointNew4{ middle, botLef, topLef, extremP {xi,yi,(xi>=0)||(xi<image.width())||(yi>=0)||(yi<image.height())?getBrightness(image.pixel(xi,yi)):-1}};




    image.save("output/DiamondSquare/Rough(2).png");

}