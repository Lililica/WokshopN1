cmake_minimum_required(VERSION 3.20)

# You can set the name of your project here
project(ImageEditor)
include(FetchContent)
FetchContent_Declare(
    sil
    GIT_REPOSITORY https://github.com/JulesFouchy/Simple-Image-Lib
    GIT_TAG 89bd175cd55fb6daa9e99b218e869c3d516043f4
)
FetchContent_MakeAvailable(sil)
function(add_exercise FOLDER)
    add_executable(${FOLDER})

    # Choose your C++ version
    target_compile_features(${FOLDER} PRIVATE cxx_std_17)

    # Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
    set_target_properties(${FOLDER} PROPERTIES
        CXX_EXTENSIONS OFF)

    # Add all the source files
    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/${FOLDER}/* lib/*)
    target_sources(${FOLDER} PRIVATE ${SOURCES})
    target_include_directories(${FOLDER} PRIVATE src/${FOLDER} lib)


    # Link sil into the project
    target_link_libraries(${FOLDER} PRIVATE sil)

endfunction(add_exercise)

add_exercise(NeGardezQueLeVert)
add_exercise(EchangezLesCanaux)
add_exercise(NoirEtBlanc)
add_exercise(Negatif)
add_exercise(Degrade)
add_exercise(Miroir)
add_exercise(ImageBruitee)
add_exercise(RotationDe90Deg)
add_exercise(RgbSplit)
add_exercise(Luminosite)
add_exercise(Disque)
add_exercise(Cercle)
add_exercise(Rosace)
add_exercise(Mosaique)
add_exercise(MosaiqueMiroir)
add_exercise(Glitch)
add_exercise(FractaleDeMandelbrot)
add_exercise(Vortex)
add_exercise(Tramage)
add_exercise(NormalisationDeLhistogramme)
add_exercise(Convolution)
add_exercise(NetteteContour)
add_exercise(DifferenceDeGaussienne)
add_exercise(FiltreSeparable)