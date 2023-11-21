#include <sil/sil.hpp>

int main()
{
    int nbrMosaique{5};
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.width()*nbrMosaique,imageRef.height()*nbrMosaique};


    for(int i{0}; i<nbrMosaique; i++){ 
        for(int j{0}; j<nbrMosaique; j++){
            if((i%2==0)&&(j%2==0)){
                for (int x{0}; x < imageRef.width(); ++x)
                {
                    for (int y{0}; y < imageRef.height(); ++y)
                    {
                        imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(x,y);
                    }
                }
            }

            if((i%2==0)&&(j%2==1)){
                for (int x{0}; x < imageRef.width(); ++x)
                {
                    for (int y{0}; y < imageRef.height(); ++y)
                    {
                        imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(x,imageRef.height()-y-1);
                    }
                }
            }

            if((i%2==1)&&(j%2==0)){
                for (int x{0}; x < imageRef.width(); ++x)
                {
                    for (int y{0}; y < imageRef.height(); ++y)
                    {
                        imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(imageRef.width()-x-1,y);
                    }
                }
            }

            if((i%2==1)&&(j%2==1)){
                for (int x{0}; x < imageRef.width(); ++x)
                {
                    for (int y{0}; y < imageRef.height(); ++y)
                    {
                        imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(imageRef.width()-x-1,imageRef.height()-y-1);
                    }
                }
            }
        }
    }
    
    imageOutPut.save("output/exo15.png");

}