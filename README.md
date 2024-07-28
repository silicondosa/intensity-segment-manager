# intensity-segment-manager
This is a simple C++14 header-only library that manages intensity values by segments.

> [!WARNING]  
> This library was created as part of a coding challenge and is NOT being actively maintained.

## Assumptions
- Intensity starts at 0 for all segments.
- The segments are inclusive of the start point and exclusive of the end point.
- We will use a list (`std::vector`) of tuples (`std::pair`) to represent the intensity values from specific points.

## Notes on implementation
- The driver is implemented as a header-only C++14 library. It has been tested to work in a Windows 10 (x64) environment using Visual Studio 2022 IDE.
- `#define`s at the top of the file are used to set the maximum and minimum possible values of intensity for programmer convenience.
- Likewise, I have set the datatype of the segment and intensity values to `long int` by leveraging the `using` keyword.
- The driver is implemented as a class where public member functions `add(from, to, intensity)` and `set(from, to, intensity)` internally call a private member function `updateSegments` which updates the private member object `std::vector<std::pair<segmentType, intensityType>>` containing the segment values and their associated intensities.
- A vector of pairs were used for easy of understanding. Since vectors require elements to be in a contiguous block of memory, it is a time cost associated with inserting elements to or deleting elements from vectors. So, in certain situations, it might be better to use a `std::map` (hash map) for improved performance. 
- Per the requirement, the `updateSegments(lower_bound, upper_bound, intensity, setFlag)` function adds(`setFlag==false`, as called in the `add` function)/sets(`setFlag==true` as called in the `set` function) the `intensity` value to the existing segments from the lower_bound (inclusive) to the upper_bound (not inclusive) if `lower_bound < upper_bound`. It returns `0` if the updated intensity values had to be clipped to keep them in the range `[MIN_INTENSITY, MAX_INTENSITY]`, otherwise returning `1`.
- Helper functions were written for printing the current state of the vector (`segmentManager::printSegments()`), and clearing it (`segmentManager::clear()`).
- DoxyGen-compatible comments are implemented to help generate documentation files if need be. The rest of the code is also commented with explanations where necessary.

## Corner cases accounted for by `updateSegments`
The library accounts for a few corner cases that might arise:
- if `lower_bound >= upper_bound`, no operation needs to be performed.
- Insert segments only if they don't already exist.
- During update, the input intensity values and the updated intensity values are checked to make sure that they are in the range `[MIN_INTENSITY, MAX_INTENSITY]`.
- Upon update, if the first segment has an intensity of `0`, it can be deleted to keep the list minimal.
- Upon updating, you can delete a segment that has the same value as the previous segment.
- If the inserted/updated `upper_bound` has the same value as the segment before it, it is also deleted.

## License
The code is provided as-is without any warranty and distributed under the Mozilla Public License V2.