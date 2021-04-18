#include "Complex.h"
#include "game.h"
#include "my_memory_copy.h"

int main()
{
    Complex number1{ 1.0, 2.0 };
    Complex number2{ 3.0, 2.0 };
    Complex result;

    std::cout << "Testing a class of complex numbers:" << std::endl;
    std::cout << "First number -- " << number1 << std::endl;
    std::cout << "Second number -- " << number2 << std::endl;

    result = number1 + number2;
    std::cout << "First + Second = " << result << std::endl;

    result = number1 - number2;
    std::cout << "First - Second = " << result << std::endl;

    result = number1 * number2;
    std::cout << "First * Second = " << result << std::endl;

    result = number1 + 5.0;
    std::cout << "First + " << 5.0 << " = " << result << std::endl;

    result = number1 - 7.0;
    std::cout << "First - " << 7.0 << " = " << result << std::endl;

    result = number1 * 3.0;
    std::cout << "First * " << 3.0 << " = " << result << std::endl;

    result = 5.0 + number1;
    std::cout << 5.0 << " + First = " << result << std::endl;

    result = 7.0 - number1;
    std::cout << 7.0 << " - First = " << result << std::endl;

    result = 3.0 * number1;
    std::cout << 3.0 << " * First = " << result << std::endl;
    //---------------------------------------------------------

    std::cout << "\n\nChecking static and dynamic casts:" << std::endl;
    GameObject* gameObject;
    NonControllable* nonControllable;
    Controllable* controllable;
    Cube* cube;
    Sphere* sphere;
    Camera* camera;
    Player* player;

    GameObject* experimental = new Cube(5, 10, 7);

    std::cout << "Static_cast:" << std::endl;

    // Will translated. One type
    cube = static_cast<Cube*>(experimental);
    std::cout << cube << std::endl;
    
    // Won't translate. static_cast doesn't check that the object is actually of type Cube
    sphere = static_cast<Sphere*>(experimental);
    std::cout << sphere << std::endl;

    // Won't translate. static_cast doesn't check that the object is actually of type Cube
    camera = static_cast<Camera*>(experimental);
    std::cout << camera << std::endl;

    // Won't translate. static_cast doesn't check that the object is actually of type Cube
    player = static_cast<Player*>(experimental);
    std::cout << player << std::endl;

    // Won't translate. static_cast doesn't check that the object is actually of type Cube
    controllable = static_cast<Controllable*>(experimental);
    std::cout << controllable << std::endl;

    // Will translated. Parent of the Cube class
    nonControllable = static_cast<NonControllable*>(experimental);
    std::cout << nonControllable << std::endl;

    // Will translated. Parent of the Cube class
    gameObject = static_cast<GameObject*>(experimental);
    std::cout << gameObject << std::endl;

    //-----------------------

    std::cout << "Dynamic_cast:" << std::endl;

    // Will translated. One type
    cube = dynamic_cast<Cube*>(experimental);
    std::cout << cube << std::endl;

    // Won't translate. Different types
    sphere = dynamic_cast<Sphere*>(experimental);
    std::cout << sphere << std::endl;

    // Won't translate. Different types
    camera = dynamic_cast<Camera*>(experimental);
    std::cout << camera << std::endl;

    // Won't translate. Different types
    player = dynamic_cast<Player*>(experimental);
    std::cout << player << std::endl;

    // Won't translate. Different types
    controllable = dynamic_cast<Controllable*>(experimental);
    std::cout << controllable << std::endl;

    // Will translated. Parent of the Cube class
    nonControllable = dynamic_cast<NonControllable*>(experimental);
    std::cout << nonControllable << std::endl;

    cube->Destroy();

    //---------------------------------------------------------
    std::cout << "\n\nBitwise copy testing:" << std::endl;
    int source[] = { 1, 2, 3, 4, 5 };
    int* recipient = new int[5];

    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << "Source -- Recipient" << std::endl;
        std::cout << source[i] << " -- " << recipient[i] << std::endl;
    }

    MyMemoryCopy(source, recipient, 8);
    std::cout << "\nArrays after copying:" << std::endl;

    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << "Source -- Recipient" << std::endl;
        std::cout << source[i] << " -- " << recipient[i] << std::endl;
    }

    delete[] recipient;
}
