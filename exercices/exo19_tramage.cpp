#include <sil/sil.hpp>
#include <vector>

int main()
{
	sil::Image image{"images/photo.jpg"};
	
	const int bayer_n{4};
	float matrice[][bayer_n] = {
		{-0.5, 0, -0.375, 0.125},
		{0.25, -0.25, 0.375, -0.125},
		{-0.3125, 0.1875, -0.4375, 0.0625},
		{0.4375, -0.0625, 0.3125, -0.1875},
	};

	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
		{
			float niv_gris = (image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3;
			image.pixel(x, y) = glm::vec3{niv_gris};
		}
	}

	for (int y{0}; y < image.height(); y++)
	{

		for (int x{0}; x < image.width(); x++)
		{
			float pixel_color{image.pixel(x, y).r};
			float color_result = 0.0f;
			float bayer_value = matrice[x % bayer_n][y % bayer_n];
			float color_add{bayer_value};
			float couleur_resultante{pixel_color + color_add};
			if (couleur_resultante > (1.0 / 2.0))
			{
				color_result = 1.0f;
			}
			image.pixel(x, y).r = color_result;
			image.pixel(x, y).g = color_result;
			image.pixel(x, y).b = color_result;
		}
	}

	image.save("output/tramage.png");
}