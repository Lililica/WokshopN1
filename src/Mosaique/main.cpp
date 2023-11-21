#include <sil/sil.hpp>

int main()
{
    int nbrMosaique{5};
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.width()*nbrMosaique,imageRef.height()*nbrMosaique};


    // for(int i{0}; i<nbrMosaique; i++){ 
    //     for(int j{0}; j<nbrMosaique; j++){
    //         for (int x{0}; x < imageRef.width(); ++x)
    //         {
    //             for (int y{0}; y < imageRef.height(); ++y)
    //             {
    //                 imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(x,y);
    //             }
    //         }
    //     }
    // }
    

    for (int x{0}; x < imageOutPut.width(); ++x)
    {
        for (int y{0}; y < imageOutPut.height(); ++y)
            {
                    imageOutPut.pixel(x ,y) = imageRef.pixel(x%imageRef.width(),y%imageRef.height());
            }
    }

    imageOutPut.save("output/exo14.png");

}