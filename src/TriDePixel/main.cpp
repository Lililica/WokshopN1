#include <sil/sil.hpp>
#include <vector>
#include "random.hpp"
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};

    // std::vector<glm::vec3> vecImage{};

    // for(glm::vec3 color : image.pixels()){
    //     vecImage.push_back(color);
    // }

    int const size{static_cast<int>(image.pixels().size())};
    int const randomFiltrage{3};
    int const largeurATrier{(image.width()/3)+1};
    int randomCheck{random_int(1,randomFiltrage+1)};


    for(int i{0}; i<size; i++){
        if(i%largeurATrier==0){
            randomCheck = random_int(1,randomFiltrage+1);
        }
        if((randomCheck==randomFiltrage)&&(i+largeurATrier*((i/largeurATrier)+1)<2*size)){
            std::sort(image.pixels().begin()+i, image.pixels().begin()+largeurATrier*((i/largeurATrier)+1), [](glm::vec3 const& color1, glm::vec3 const& color2)
            {
                return (color1.r+color1.b+color1.g)/3 < (color2.r+color2.b+color2.g)/3; // Trie selon la composante rouge
            });
        }
    }
    image.save("output/exo25.png");
}