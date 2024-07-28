#pragma once
#include <iostream>
#include <vector>

#ifndef _SEGMENT_MANAGER
#define _SEGMENT_MANAGER

#define MAX_INTENSITY    1000000 /**< The maximum value of intensity. */
#define MIN_INTENSITY   -1000000 /**< The minimum value of intensity. */

using segmentType   = long int; /**< Data type of the segments. */
using intensityType = long int; /**< Data type of intensity values. */


class segmentManager {
private:
    using intensitySegment = std::pair<segmentType, intensityType>;
    std::vector<intensitySegment> segmentVector;

    /**
     * @brief Updates the segments with intensity values.
     * @param lower_bound The value from which (including) the intensity should be updated.
     * @param upper_bound The value up to which (excluding) the intensity should be updated.
     * @param intensity The value/magnitude of intensity to be added. Can be positive or negative integer values in the range [MIN_INTENSITY, MAX_INTENSITY]. Values outside this range will the clipped to be within i.
     * @param setFlag If true, the intensitiy values will be set. Otherwise, the values will be added to the segments.
     * @return Returns 1 if intensity values have been successfully updated with no changes. Returns 0 if the final intensity values needed to be clipped after update due to being outside the range [MIN_INTENSITY, MAX_INTENSITY].
    */
    int updateSegments(segmentType lower_bound, segmentType upper_bound, intensityType intensity, bool setFlag)
    {
        int retVal = 1;
        int i = 0;
        bool insertFlag = false;
        intensityType prevIntensity = (intensityType)0;

        // If lower_bound is greater or equal to upper_bound, there is no need to do anything
        if (lower_bound >= upper_bound) return 1;

        // clip/limit intensity
        if (intensity < MIN_INTENSITY)
            intensity = MIN_INTENSITY;
        else if (intensity > MAX_INTENSITY)
            intensity = MAX_INTENSITY;
        

        // find insertion location of lower bound
        for (i = 0; i < segmentVector.size() && lower_bound > segmentVector[i].first; ++i) {
            prevIntensity = segmentVector[i].second;
        }
        if (i == segmentVector.size() || lower_bound < segmentVector[i].first) {
            segmentVector.insert(segmentVector.begin() + i, std::make_pair(lower_bound, (intensityType)0));
            insertFlag = true;
        }
       
        // Update intensity values
        for (; i < segmentVector.size() && upper_bound > segmentVector[i].first; ++i) {
            segmentVector[i].second = (setFlag) ? intensity : intensity + ((insertFlag) ? prevIntensity : segmentVector[i].second);
            insertFlag = false;
            // intensity range check
            if (segmentVector[i].second > MAX_INTENSITY) {
                segmentVector[i].second = MAX_INTENSITY;
                retVal = 0;
            } else if (segmentVector[i].second < MIN_INTENSITY) {
                segmentVector[i].second = MIN_INTENSITY;
                retVal = 0;
            }
            // erase if first value is 0. Also erase if current value is the same as the next value
            if ((i == 0 && segmentVector[i].second == 0) || (i != 0 && segmentVector[i].second == segmentVector[i-1].second)) { // 
                segmentVector.erase(segmentVector.begin() + i);
                --i;
            }
        }

        // insert upper bound if we have reached the end of the vector or if the upper bound is larger than the ith element
        if (!segmentVector.empty()) {
            if (i == segmentVector.size() || upper_bound < segmentVector[i].first) {
                segmentVector.insert(segmentVector.begin() + i, std::make_pair(upper_bound, (intensityType)0));
            }
            // If the updated upper_bound is the same as its previous element, delete it.
            if (segmentVector[i].second == segmentVector[i - 1].second) {
                segmentVector.erase(segmentVector.begin() + i);
                --i;
            }
        }

        return retVal;
    } // end updateSegments function

public:
    segmentManager() = default;
    
    /**
     * @brief Adds intensity from the range from lower_bound (inclusive) to upper_bound (non-inclusive).
     * @param lower_bound The value from which (including) the intensity should be added.
     * @param upper_bound The value up to which (excluding) the intensity should be added.
     * @param intensity The value/magnitude of intensity to be added. Can be positive or negative integer values in the range [MIN_INTENSITY, MAX_INTENSITY]. Values outside this range will the clipped to be within i.
     * @return Returns 1 if intensity values have been successfully updated with no changes. Returns 0 if the final intensity values needed to be clipped after update due to being outside the range [MIN_INTENSITY, MAX_INTENSITY].
    */    
    inline int add(segmentType lower_bound, segmentType upper_bound, intensityType intensity)
    {
        int retVal = updateSegments(lower_bound, upper_bound, intensity, false);
        printSegments();
        std::cout << std::endl;
        return retVal;
    }

    /**
     * @brief Sets the intensity from the range from lower_bound (inclusive) to upper_bound (non-inclusive).
     * @param lower_bound The value from which (including) the intensity should be set.
     * @param upper_bound The value up to which (excluding) the intensity should be set.
     * @param intensity The value/magnitude of intensity to be set. Can be positive or negative integer values in the range [MIN_INTENSITY, MAX_INTENSITY]. Values outside this range will the clipped to be within i.
     * @return Returns 1 if intensity values have been successfully updated with no changes. Returns 0 if the final intensity values needed to be clipped after update due to being outside the range [MIN_INTENSITY, MAX_INTENSITY].
    */
    inline int set(segmentType lower_bound, segmentType upper_bound, intensityType intensity)
    {
        int retVal = updateSegments(lower_bound, upper_bound, intensity, true);
        printSegments();
        std::cout << std::endl;
        return retVal;
    }

    /**
     * @brief Clear all segments and reset the segment manager.
    */
    inline void clear()
    {
        segmentVector.clear();
    }

    /**
     * @brief Prints the segments along with their intensities.
    */
    void printSegments()
    {
        std::cout << "[ ";
        for (intensitySegment segment : segmentVector)
            std::cout << '[' << segment.first << ',' << segment.second << "] ";
        std::cout << ']';
    }

    ~segmentManager()
    {
        this->clear();
    }
};

#endif // !INTENSITY_SEGMENT_MANAGER

