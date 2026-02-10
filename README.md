===============================================
MEMORY ALLOCATION SIMULATOR - README
===============================================

PROJECT DETAILS
---------------
Course: Operating Systems (CS432P)
Topic: Simulation of Memory Allocation Techniques
Class: 4BTCS A
Semester: IV
Academic Year: 2025-26

CONTENTS
--------
1. memory_allocation.c - C source code
2. Memory_Allocation_Project_Report.docx - Project report
3. README.txt - This file


COMPILATION INSTRUCTIONS
------------------------
To compile the program, use the following command:

gcc memory_allocation.c -o memory_allocation

Alternatively, if you're using a C++ compiler:

g++ memory_allocation.c -o memory_allocation


EXECUTION
---------
To run the program:

./memory_allocation


PROGRAM FEATURES
----------------
1. Menu-driven interface for algorithm selection
2. Three memory allocation algorithms:
   - First Fit
   - Best Fit
   - Worst Fit
3. Detailed fragmentation analysis:
   - Internal fragmentation calculation
   - External fragmentation calculation
   - Total fragmentation
   - Memory utilization percentage
4. Visual representation of allocation status
5. Block-by-block status display


HOW TO USE
----------
1. Run the program
2. Enter the number of memory blocks
3. Enter the size of each memory block (in KB)
4. Enter the number of processes
5. Enter the size of each process (in KB)
6. Select an algorithm from the menu:
   - Option 1: First Fit
   - Option 2: Best Fit
   - Option 3: Worst Fit
   - Option 4: Exit
7. View the allocation results and fragmentation analysis
8. You can test multiple algorithms on the same input by selecting different options


SAMPLE TEST CASE 1
------------------
Input:
  Number of memory blocks: 5
  Block sizes: 100, 500, 200, 300, 600
  Number of processes: 4
  Process sizes: 212, 417, 112, 426

Expected Behavior:
- First Fit will allocate differently than Best Fit
- Different internal and external fragmentation values
- Compare memory utilization across algorithms


SAMPLE TEST CASE 2
------------------
Input:
  Number of memory blocks: 6
  Block sizes: 300, 600, 350, 200, 750, 125
  Number of processes: 5
  Process sizes: 115, 500, 358, 200, 375

Try all three algorithms and compare:
- Which algorithm has minimum internal fragmentation?
- Which algorithm has minimum external fragmentation?
- Which algorithm achieves best memory utilization?


SAMPLE TEST CASE 3 (Edge Case - All Processes Fit)
---------------------------------------------------
Input:
  Number of memory blocks: 4
  Block sizes: 200, 400, 600, 500
  Number of processes: 4
  Process sizes: 100, 300, 200, 150

All processes should be allocated in all algorithms.
Compare the fragmentation patterns.


SAMPLE TEST CASE 4 (Edge Case - No Process Fits)
-------------------------------------------------
Input:
  Number of memory blocks: 3
  Block sizes: 100, 150, 120
  Number of processes: 2
  Process sizes: 200, 250

No processes should be allocated.
All blocks remain as external fragmentation.


OUTPUT INTERPRETATION
---------------------
The program displays:

1. ALLOCATION TABLE
   - Shows which process is allocated to which block
   - Displays "Not Allocated" for processes that couldn't fit

2. BLOCK STATUS TABLE
   - Original block size
   - Remaining size after allocation
   - Internal fragmentation per block

3. FRAGMENTATION ANALYSIS
   - Internal Fragmentation: Wasted space within allocated blocks
   - External Fragmentation: Free space that couldn't be used
   - Total Fragmentation: Sum of internal + external
   - Total Memory: Original total memory available
   - Used Memory: Memory actually used by processes
   - Memory Utilization: Percentage of memory effectively used


UNDERSTANDING FRAGMENTATION
----------------------------
Internal Fragmentation:
- Occurs when allocated block is larger than process size
- Formula: (Allocated Block Size - Process Size)
- Example: Process needs 200KB, gets 300KB block → 100KB internal fragmentation

External Fragmentation:
- Free memory blocks that are too small to allocate
- Sum of all remaining unallocated block sizes
- Can be reduced by compaction (not implemented in this simulator)


ALGORITHM COMPARISON
--------------------
First Fit:
  + Fastest execution (stops at first suitable block)
  - May create fragments at beginning of memory
  
Best Fit:
  + Minimizes wasted space per allocation
  - Slower (scans all blocks)
  - May create many tiny unusable fragments
  
Worst Fit:
  + Leaves larger fragments (potentially usable)
  - Generally highest total fragmentation
  - Slower (scans all blocks)


DEMONSTRATION TIPS
------------------
For your project demonstration:

1. Show the menu-driven interface
2. Use one of the sample test cases
3. Demonstrate all three algorithms on the same input
4. Explain the allocation decisions for each algorithm
5. Compare fragmentation results
6. Discuss which algorithm performed best and why
7. Show edge cases (all fit, none fit)


TROUBLESHOOTING
---------------
Issue: Compilation errors
Solution: Ensure you have gcc/g++ installed. Check file name is correct.

Issue: Unexpected output
Solution: Verify input values are positive integers. Check block sizes are reasonable.

Issue: Program crashes
Solution: Don't exceed MAX (50) blocks or processes. Enter valid numeric input.


PROJECT REPORT
--------------
The accompanying Word document contains:
- Introduction to memory allocation
- Detailed explanation of algorithms
- Methodology and implementation
- Fragmentation analysis theory
- Sample outputs
- Conclusions and comparisons
- References


NOTES FOR SUBMISSION
--------------------
1. Code demonstrates all three algorithms ✓
2. Fragmentation analysis implemented ✓
3. Menu-driven interface ✓
4. Professional documentation ✓
5. Ready for demonstration ✓


CONTACT & CREDITS
-----------------
This project was created as part of the Continuous Internal Assessment - III
for the Operating Systems course at CHRIST University.

For questions or improvements, refer to your course instructor.

===============================================
END OF README
===============================================
