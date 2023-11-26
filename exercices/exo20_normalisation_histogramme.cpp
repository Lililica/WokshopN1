#include <sil/sil.hpp>


int main()
{
	sil::Image image{"images/photo_faible_contraste.jpg"};
	
	
	float luminance_min{1.0f};
	float luminance_max{0.0f};

	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
		{
			float luminance {(image.pixel(x,y).r + image.pixel(x,y).g  + image.pixel(x,y).b)/3};
			if (luminance > luminance_max) {
				luminance_max = luminance;
			}
			if (luminance < luminance_min) {
				luminance_min = luminance;
			}
		}
	}

	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
		{
			image.pixel(x,y).r = (image.pixel(x,y).r - luminance_min)/(luminance_max - luminance_min);
			image.pixel(x,y).g = (image.pixel(x,y).g - luminance_min)/(luminance_max - luminance_min);
			image.pixel(x,y).b = (image.pixel(x,y).b - luminance_min)/(luminance_max - luminance_min);
		}
	}

	

	image.save("output/normalisation_histogramme.png");
}