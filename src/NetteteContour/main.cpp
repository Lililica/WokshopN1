#include <sil/sil.hpp>



int main()
{
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutput{"images/logo.png"};
    // TODO: modifier l'image

    int intensiteFlou{1};

    for(int x{0}; x<imageOutput.width(); x++){
        for(int y{0}; y<imageOutput.height(); y++){
            glm::vec3 vecteur{};
            for(int i{0}; i<2*intensiteFlou+1; i++){
                for(int j{0}; j<2*intensiteFlou+1; j++){
                    if((x+i-(intensiteFlou)<intensiteFlou)||(y+j-(intensiteFlou)<intensiteFlou)||(x+i-(intensiteFlou)>imageOutput.width()-intensiteFlou-1)||(y+j-(intensiteFlou)>imageOutput.height()-intensiteFlou-1)){
                        continue;
                    }
                    float facteur{1};
                    if(i-(intensiteFlou)>0){
                        if(j-(intensiteFlou)<0){
                            facteur = 0.f;
                        }
                        if(j-(intensiteFlou)==0){
                            facteur = -1.f;
                        }
                        if(j-(intensiteFlou)>0){
                            facteur = 0.f;
                        }
                    }
                    if(i-(intensiteFlou)==0){
                        if(j-(intensiteFlou)<0){
                            facteur = -1.f;
                        }
                        if(j-(intensiteFlou)==0){
                            facteur = 5.f;
                        }
                        if(j-(intensiteFlou)>0){
                            facteur = -1.f;
                        }
                    }
                    if(i-(intensiteFlou)<0){
                        if(j-(intensiteFlou)<0){
                            facteur = 0.f;
                        }
                        if(j-(intensiteFlou)==0){
                            facteur = -1.f;
                        }
                        if(j-(intensiteFlou)>0){
                            facteur = 0.f;
                        }
                    }
                    vecteur += facteur*imageRef.pixel(x+i-(intensiteFlou),y+j-(intensiteFlou));
                }
            }
            imageOutput.pixel(x,y) = vecteur;
        }
    }
    imageOutput.save("output/exo22_sharpen.png");
}