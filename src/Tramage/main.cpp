#include <sil/sil.hpp>
#include "random.hpp"
#include <vector>
#include <iostream>



void displaysimplevec(std::vector<float> v);

std::vector<std::vector<float>> generateBayerLevel(int level){
    if(level == 0){
        std::vector<std::vector<float>> bayerInit{
            { 0.f , 2.f},
            { 3.f , 1.f}
        };
        return bayerInit;
    }
    std::vector<std::vector<float>> bayerMatrix{generateBayerLevel(level-1)};
    for(std::vector<float> & ligne : bayerMatrix){
        int ligneSize(ligne.size());
        for(int i{0}; i<ligneSize; i++){
            ligne.push_back(ligne[i]);
        }
    }

    int bayerSize{static_cast<int>(bayerMatrix.size())};
    for(int i{0}; i<bayerSize; i++){
        bayerMatrix.push_back(bayerMatrix[i]);  
    }
    for(int i{0}; i<pow(2,level); i++){
        for(int j{0}; j<pow(2,level); j++){
            bayerMatrix[i][j] *= 4;
            bayerMatrix[i][bayerMatrix[i].size()-1-j] = 4*bayerMatrix[i][bayerMatrix[i].size()-1-j] + 2;
            bayerMatrix[bayerMatrix[i].size()-1-i][j] = 4*bayerMatrix[bayerMatrix[i].size()-1-i][j] + 3;
            bayerMatrix[bayerMatrix[i].size()-1-i][bayerMatrix[i].size()-1-j] = 4*bayerMatrix[bayerMatrix[i].size()-1-i][bayerMatrix[i].size()-1-j] + 1;
        }
    }
    return bayerMatrix;
}

void displayvec(std::vector<std::vector<float>> v){
    for(std::vector<float> ligne : v){
        std::cout << "[ ";
        for(float elemt : ligne){
            std::cout << elemt << ", ";
        }
        std::cout << " ]" << std::endl;
    }
    std::cout << std::endl;
}

void displaysimplevec(std::vector<float> v){
    std::cout << "[ ";
    for(float a : v){
        std::cout << a << ", ";
    }
    std::cout << " ]";

}

int main(){
    sil::Image image{"images/photo.jpg"};

/*    std::vector<std::vector<float>> bayerInit{
        { 0.f, 8.f, 2.f, 10.f},
        { 12.f, 4.f, 14.f, 6.f},
        { 3.f, 11.f, 1.f, 11.f},
        { 15.f, 7.f, 13.f, 5.f}
    };*/

    int levelOfBayerMatrix{2};
    std::vector<std::vector<float>> bayerInit{generateBayerLevel(levelOfBayerMatrix)};

    for (int x{0}; x<image.width(); x++){
        for (int y{0}; y<image.height(); y++)
        {
            float brightness{((image.pixel(x,y).r+image.pixel(x,y).b+image.pixel(x,y).g)/3)>(bayerInit[x%bayerInit.size()][y%bayerInit.size()])/pow(bayerInit.size(),2)?1.f:0.f};
            image.pixel(x,y).r = brightness;
            image.pixel(x,y).b = brightness;
            image.pixel(x,y).g = brightness;
        }
    }

    image.save("output/exo19_bayer.png");


}