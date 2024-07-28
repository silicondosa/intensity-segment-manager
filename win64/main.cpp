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
    // Print final state of segments
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
    // Print final state of segments
    std::cout << "Test 2: Final state of segments: ";
    segments.printSegments();
    std::cout << std::endl << std::endl;
    segments.clear();

    // --------------
    // TEST EXAMPLE 3
    // --------------
    // Print initial state of segments
    std::cout << "Test 3: Initial state of segments: ";
    segments.printSegments();
    std::cout << std::endl;
    // Test calls here
    std::cout << "\tadd(-10 , 30 , 10  ) => "; segments.add(-10 , 30 , 10  );
    std::cout << "\tadd( 40 , 60 , 100 ) => "; segments.add( 40 , 60 , 100 );
    std::cout << "\tadd( 20 , 35 , 0   ) => "; segments.add( 20 , 35 , 0   );
    std::cout << "\tadd(-300,-40 ,-1000) => "; segments.add(-300,-40 ,-1000);
    std::cout << "\tadd(-100, 100, 100 ) => "; segments.add(-100, 100,  100);
    // Print final state of segments
    std::cout << "Test 3: Final state of segments: ";
    segments.printSegments();
    std::cout << std::endl << std::endl;
    segments.clear();

    // --------------
    // TEST EXAMPLE 4
    // --------------
    // Print initial state of segments
    std::cout << "Test 4: Initial state of segments: ";
    segments.printSegments();
    std::cout << std::endl;
    // Test calls here
    std::cout << "\tadd( 10 , 20 , 0   ) => "; segments.add(10, 20, 0);
    std::cout << "\tadd( 15 , 30 , 0   ) => "; segments.add(15, 30, 0);
    std::cout << "\tadd(-10 ,-5  , 0   ) => "; segments.add(20, 35, 0);
    // Print final state of segments
    std::cout << "Test 4: Final state of segments: ";
    segments.printSegments();
    std::cout << std::endl << std::endl;
    segments.clear();

    std::cout << "Hit [ENTER] to exit...\n";
    std::cin.get();
}

