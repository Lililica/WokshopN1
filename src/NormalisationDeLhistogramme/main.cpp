#include <sil/sil.hpp>
#include <vector>

int main(){
    sil::Image image{"images/photo_faible_contraste.jpg"};

    std::vector<int> pixelLePlusBlanc{0,0};
    float maxBrightness{(image.pixel(0,0).r+image.pixel(0,0).b+image.pixel(0,0).g)/3};
    std::vector<int> pixelLePlusNoir{0,0};
    float minBrightness{(image.pixel(0,0).r+image.pixel(0,0).b+image.pixel(0,0).g)/3};
    
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            float brightness{(image.pixel(x,y).r+image.pixel(x,y).b+image.pixel(x,y).g)/3};
            if(brightness>maxBrightness){
                maxBrightness = brightness;
                pixelLePlusBlanc = {x,y};
            }
            if(brightness<minBrightness){
                minBrightness = brightness;
                pixelLePlusNoir = {x,y};
            }
        }
    }


    std::vector<float> facteur_blanc{
        (image.pixel(pixelLePlusBlanc[0],pixelLePlusBlanc[1]).r),
        (image.pixel(pixelLePlusBlanc[0],pixelLePlusBlanc[1]).b),
        (image.pixel(pixelLePlusBlanc[0],pixelLePlusBlanc[1]).g)
    };  

    std::vector<float> facteur_noir{
        1/(image.pixel(pixelLePlusNoir[0],pixelLePlusNoir[1]).r - facteur_blanc[0]),
        1/(image.pixel(pixelLePlusNoir[0],pixelLePlusNoir[1]).b - facteur_blanc[1]),
        1/(image.pixel(pixelLePlusNoir[0],pixelLePlusNoir[1]).g - facteur_blanc[2])
    };

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            float brightness{(image.pixel(x,y).r+image.pixel(x,y).b+image.pixel(x,y).g)/3};
            float realBright{(brightness-minBrightness)/(maxBrightness-minBrightness)};

            image.pixel(x,y).r = 1-(image.pixel(x,y).r - facteur_blanc[0])*facteur_noir[0];
            image.pixel(x,y).b = 1-(image.pixel(x,y).b - facteur_blanc[1])*facteur_noir[1];
            image.pixel(x,y).g = 1-(image.pixel(x,y).g - facteur_blanc[2])*facteur_noir[2];

        }
    }
    image.save("output/exo20.png");

}