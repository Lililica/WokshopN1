#include <sil/sil.hpp>
#include <cmath> 

int main()
{
    sil::Image image{500/*width*/, 500/*height*/}; 

    int nbrRosace{9};
    int Rayon{100};
    int thickness{5};

    int x0{(image.width()-1)/2};
    int y0{(image.height()-1)/2};

    for(int x{0}; x<image.width(); x++){
        for(int y{0}; y<image.height(); y++){
            double rayonActuel{pow(pow(y-y0,2)+pow(x-x0,2),0.5)};
            if((rayonActuel <= Rayon) && (rayonActuel >= Rayon-thickness)){
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
                image.pixel(x,y).g = 1;
            }
        }
    }

    for(int i{0}; i<nbrRosace; i++){
        double teta{i*2*3.14/nbrRosace};
        int xi{x0 + static_cast<int>(std::cos(teta)*Rayon)};
        int yi{y0 + static_cast<int>(std::sin(teta)*Rayon)};

        for(int x{0}; x<image.width(); x++){
            for(int y{0}; y<image.height(); y++){
                double rayonActuel{pow(pow(y-yi,2)+pow(x-xi,2),0.5)};
                if((rayonActuel <= Rayon) && (rayonActuel >= Rayon-thickness)){
                    image.pixel(x,y).r = 1;
                    image.pixel(x,y).b = 1;
                    image.pixel(x,y).g = 1;
                }
            }
        }
    
    }


    image.save("output/exo13.png");

}