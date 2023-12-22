#include <sil/sil.hpp>
#include "random.hpp"
#include <vector>
#include <iostream>





std::vector<std::vector<float>> generateBayerLevel(int level){
    if(level == 0){
        std::vector<std::vector<float>> bayerInit{
            { 0.f , 2.f},
            { 3.f , 1.f}
        };
        return bayerInit;
    }
    std::vector<std::vector<float>> prevBayerMatrix{generateBayerLevel(level-1)};

    size_t const size{2* prevBayerMatrix.size()};
    std::vector<std::vector<float>> bayerMatrix(size);
    for(std::vector<float>& line : bayerMatrix)
        line.resize(size);

    for(int x {0}; x < size; ++x)
    {
        for(int y{0}; y < size; ++y)
        {
            int X = x / prevBayerMatrix.size();
            int Y = y / prevBayerMatrix.size();
            bayerMatrix[x][y] = 4 *  prevBayerMatrix[x%prevBayerMatrix.size()][y%prevBayerMatrix.size()] + 2*X*(1+Y);
        }
    }


    // Ma fonction, elle retourne la même chose mais plus compliqué à comprendre et surement plus complexe...

    /*for(std::vector<float> & ligne : bayerMatrix){
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
    }*/
    return bayerMatrix;
}

// Les deux fonctions suivantes m'ont permis de débuguer 

void displayvec(std::vector<std::vector<float>> v){
    for(std::vector<float> const& ligne : v){
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

    // Choix de la taille de ma matrice de Bayer à utiliser

    int const levelOfBayerMatrix{15};
    std::vector<std::vector<float>> bayerInit{generateBayerLevel(levelOfBayerMatrix)};

    // Application de l'algo pour chaque pixel

    for (int x{0}; x<image.width(); x++){
        for (int y{0}; y<image.height(); y++)
        {
            float CouleurNoirOuBlanche{((image.pixel(x,y).r+image.pixel(x,y).b+image.pixel(x,y).g)/3)>(bayerInit[x%bayerInit.size()][y%bayerInit.size()])/pow(bayerInit.size(),2)?
                1.f // Blanc 
                :
                0.f}; // Noir
            image.pixel(x,y) = glm::vec3{CouleurNoirOuBlanche};

        }
    }

    image.save("output/Tramage/MatriceLevel15.png");


}