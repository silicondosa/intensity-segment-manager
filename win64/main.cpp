// win64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "segmentManager.h"

int main()
{
    segmentManager segments;

    std::cout << "Segment Manager for intensity values\n";

    // --------------
    // TEST EXAMPLE 1
    // --------------
    // Print initial state of segments
    std::cout << "Test 1: Initial state of segments: ";
    segments.printSegments();
    std::cout << std::endl;
    // Test calls here
    std::cout << "\tadd(10, 30, 1) => "; segments.add(10, 30, 1);
    std::cout << "\tadd(20, 40, 1) => "; segments.add(20, 40, 1);
    std::cout << "\tadd(10, 40,-2) => "; segments.add(10, 40, -2);
    // Print initial state of segments
    std::cout << "Test 1: Final state of segments: ";
    segments.printSegments();
    std::cout << std::endl << std::endl;
    segments.clear();
    
    // --------------
    // TEST EXAMPLE 2
    // --------------
    // Print initial state of segments
    std::cout << "Test 2: Initial state of segments: ";
    segments.printSegments();
    std::cout << std::endl;
    // Test calls here
    std::cout << "\tadd(10, 30, 1) => "; segments.add(10, 30, 1);
    std::cout << "\tadd(20, 40, 1) => "; segments.add(20, 40, 1);
    std::cout << "\tadd(10, 40,-1) => "; segments.add(10, 40, -1);
    std::cout << "\tadd(10, 40,-1) => "; segments.add(10, 40, -1);
    // Print initial state of segments
    std::cout << "Test 2: Final state of segments: ";
    segments.printSegments();
    std::cout << std::endl;
    std::cout << "\nHit [ENTER] to exit...\n";
    std::cin.get();
}

