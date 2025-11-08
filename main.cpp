#include "ScratchDetector.h"
#include "ImageLoader.h"
#include <iostream>

int main() {
    std::cout << "=== Testing Image Loader ===" << std::endl;
    
    ImageLoader loader;
    
    // TODO 2.4: Test loading a single image
    // 1. Create a test image or download one
    // 2. Try to load it
    cv::Mat image = loader.loadImage("../test_images/cards.png");
    
    // 3. Check if it's valid
    if (!loader.isValidImage(image)) {
        std::cerr << "Invalid image." << std::endl;
        return -1;
    }
    std::cout << "Image loaded and validated successfully." << std::endl;
    
    ScratchDetector* scratchDetector = new ScratchDetector();

    std::vector<Scratch> scratches = scratchDetector->detect(image);

    std::cout<< "Number of scratches: "<< scratches.size() <<std::endl;

    cv::Mat edgeImage = scratchDetector->getEdgeImage();
    // 4. Display it using cv::imshow()
    cv::imshow("Test Image", edgeImage);
    // 5. Wait for key press with cv::waitKey()
    cv::waitKey(0);
    
    std::cout << "Test complete!" << std::endl;
    return 0;
}
