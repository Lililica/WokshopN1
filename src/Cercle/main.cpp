#include <sil/sil.hpp>

int main()
{
    sil::Image image{500/*width*/, 500/*height*/};  

    int x0{(image.width()-1)/2};
    int y0{(image.height()-1)/2};
    int Rayon{100};
    int thickness{10};

    for(int x{0}; x<image.width(); x++){
        for(int y{0}; y<image.height(); y++){
            double rayonActuel{pow(pow(y-y0,2)+pow(x-y0,2),0.5)};
            if((rayonActuel <= Rayon) && (rayonActuel >= Rayon-thickness)){
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
                image.pixel(x,y).g = 1;
            }
        }
    }

    image.save("output/exo12.png");

}