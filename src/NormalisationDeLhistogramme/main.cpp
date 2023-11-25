#include <sil/sil.hpp>
#include <vector>

int main(){
    sil::Image image{"images/photo_faible_contraste.jpg"};

    float maxBrightness{(image.pixel(0,0).r+image.pixel(0,0).b+image.pixel(0,0).g)/3};
    float minBrightness{(image.pixel(0,0).r+image.pixel(0,0).b+image.pixel(0,0).g)/3};
    
    // Calcul de notre luminosité max et min de l'image 

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            float brightness{(image.pixel(x,y).r+image.pixel(x,y).b+image.pixel(x,y).g)/3};
            if(brightness>maxBrightness){
                maxBrightness = brightness;
            }
            if(brightness<minBrightness){
                minBrightness = brightness;
            }
        }
    }

    //  Application de l'algorithme à chaque pixel

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x,y) = (image.pixel(x,y)-minBrightness)/(maxBrightness-minBrightness);
        }
    }

    image.save("output/NomalisationDeLhisto/Normalisation.png");

}