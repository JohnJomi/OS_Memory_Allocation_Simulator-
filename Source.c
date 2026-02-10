#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Function to display memory blocks status
void displayBlocks(int blocks[], int m) {
    printf("\n%-15s%-15s\n", "Block Number", "Block Size");
    printf("-----------------------------------\n");
    for(int i = 0; i < m; i++) {
        printf("%-15d%-15d\n", i+1, blocks[i]);
    }
}

// First Fit Algorithm
void firstFit(int blocks[], int m, int process[], int n) {
    int allocation[MAX];
    int originalBlocks[MAX];
    
    // Store original block sizes
    for(int i = 0; i < m; i++) {
        originalBlocks[i] = blocks[i];
    }
    
    // Initialize allocation array
    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate processes
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }
    
    // Display results
    printf("\n========== FIRST FIT ALLOCATION ==========\n");
    printf("\n%-15s%-15s%-15s%-20s\n", "Process No.", "Process Size", "Block No.", "Status");
    printf("----------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%-15d%-15d", i+1, process[i]);
        if(allocation[i] != -1) {
            printf("%-15d%-20s\n", allocation[i]+1, "Allocated");
        } else {
            printf("%-15s%-20s\n", "N/A", "Not Allocated");
        }
    }
    
    // Calculate and display fragmentation
    int internalFrag = 0;
    int externalFrag = 0;
    int totalMemory = 0;
    int usedMemory = 0;
    
    printf("\n========== BLOCK STATUS AFTER ALLOCATION ==========\n");
    printf("\n%-15s%-20s%-20s%-20s\n", "Block No.", "Original Size", "Remaining Size", "Internal Frag.");
    printf("---------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < m; i++) {
        totalMemory += originalBlocks[i];
        int blockInternalFrag = 0;
        
        // Check if this block was allocated
        int isAllocated = 0;
        for(int j = 0; j < n; j++) {
            if(allocation[j] == i) {
                isAllocated = 1;
                blockInternalFrag = blocks[i];
                internalFrag += blockInternalFrag;
                usedMemory += process[j];
                break;
            }
        }
        
        printf("%-15d%-20d%-20d%-20d\n", i+1, originalBlocks[i], blocks[i], blockInternalFrag);
        
        // Add to external fragmentation if block is free
        if(!isAllocated && blocks[i] > 0) {
            externalFrag += blocks[i];
        }
    }
    
    printf("\n========== FRAGMENTATION ANALYSIS ==========\n");
    printf("Internal Fragmentation  : %d KB\n", internalFrag);
    printf("External Fragmentation  : %d KB\n", externalFrag);
    printf("Total Fragmentation     : %d KB\n", internalFrag + externalFrag);
    printf("Total Memory            : %d KB\n", totalMemory);
    printf("Used Memory             : %d KB\n", usedMemory);
    printf("Memory Utilization      : %.2f%%\n", (float)usedMemory/totalMemory * 100);
    printf("============================================\n");
}

// Best Fit Algorithm
void bestFit(int blocks[], int m, int process[], int n) {
    int allocation[MAX];
    int originalBlocks[MAX];
    
    // Store original block sizes
    for(int i = 0; i < m; i++) {
        originalBlocks[i] = blocks[i];
    }
    
    // Initialize allocation array
    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate processes
    for(int i = 0; i < n; i++) {
        int best = -1;
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                if(best == -1 || blocks[j] < blocks[best]) {
                    best = j;
                }
            }
        }
        if(best != -1) {
            allocation[i] = best;
            blocks[best] -= process[i];
        }
    }
    
    // Display results
    printf("\n========== BEST FIT ALLOCATION ==========\n");
    printf("\n%-15s%-15s%-15s%-20s\n", "Process No.", "Process Size", "Block No.", "Status");
    printf("----------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%-15d%-15d", i+1, process[i]);
        if(allocation[i] != -1) {
            printf("%-15d%-20s\n", allocation[i]+1, "Allocated");
        } else {
            printf("%-15s%-20s\n", "N/A", "Not Allocated");
        }
    }
    
    // Calculate and display fragmentation
    int internalFrag = 0;
    int externalFrag = 0;
    int totalMemory = 0;
    int usedMemory = 0;
    
    printf("\n========== BLOCK STATUS AFTER ALLOCATION ==========\n");
    printf("\n%-15s%-20s%-20s%-20s\n", "Block No.", "Original Size", "Remaining Size", "Internal Frag.");
    printf("---------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < m; i++) {
        totalMemory += originalBlocks[i];
        int blockInternalFrag = 0;
        
        // Check if this block was allocated
        int isAllocated = 0;
        for(int j = 0; j < n; j++) {
            if(allocation[j] == i) {
                isAllocated = 1;
                blockInternalFrag = blocks[i];
                internalFrag += blockInternalFrag;
                usedMemory += process[j];
                break;
            }
        }
        
        printf("%-15d%-20d%-20d%-20d\n", i+1, originalBlocks[i], blocks[i], blockInternalFrag);
        
        // Add to external fragmentation if block is free
        if(!isAllocated && blocks[i] > 0) {
            externalFrag += blocks[i];
        }
    }
    
    printf("\n========== FRAGMENTATION ANALYSIS ==========\n");
    printf("Internal Fragmentation  : %d KB\n", internalFrag);
    printf("External Fragmentation  : %d KB\n", externalFrag);
    printf("Total Fragmentation     : %d KB\n", internalFrag + externalFrag);
    printf("Total Memory            : %d KB\n", totalMemory);
    printf("Used Memory             : %d KB\n", usedMemory);
    printf("Memory Utilization      : %.2f%%\n", (float)usedMemory/totalMemory * 100);
    printf("============================================\n");
}

// Worst Fit Algorithm
void worstFit(int blocks[], int m, int process[], int n) {
    int allocation[MAX];
    int originalBlocks[MAX];
    
    // Store original block sizes
    for(int i = 0; i < m; i++) {
        originalBlocks[i] = blocks[i];
    }
    
    // Initialize allocation array
    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Allocate processes
    for(int i = 0; i < n; i++) {
        int worst = -1;
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                if(worst == -1 || blocks[j] > blocks[worst]) {
                    worst = j;
                }
            }
        }
        if(worst != -1) {
            allocation[i] = worst;
            blocks[worst] -= process[i];
        }
    }
    
    // Display results
    printf("\n========== WORST FIT ALLOCATION ==========\n");
    printf("\n%-15s%-15s%-15s%-20s\n", "Process No.", "Process Size", "Block No.", "Status");
    printf("----------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%-15d%-15d", i+1, process[i]);
        if(allocation[i] != -1) {
            printf("%-15d%-20s\n", allocation[i]+1, "Allocated");
        } else {
            printf("%-15s%-20s\n", "N/A", "Not Allocated");
        }
    }
    
    // Calculate and display fragmentation
    int internalFrag = 0;
    int externalFrag = 0;
    int totalMemory = 0;
    int usedMemory = 0;
    
    printf("\n========== BLOCK STATUS AFTER ALLOCATION ==========\n");
    printf("\n%-15s%-20s%-20s%-20s\n", "Block No.", "Original Size", "Remaining Size", "Internal Frag.");
    printf("---------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < m; i++) {
        totalMemory += originalBlocks[i];
        int blockInternalFrag = 0;
        
        // Check if this block was allocated
        int isAllocated = 0;
        for(int j = 0; j < n; j++) {
            if(allocation[j] == i) {
                isAllocated = 1;
                blockInternalFrag = blocks[i];
                internalFrag += blockInternalFrag;
                usedMemory += process[j];
                break;
            }
        }
        
        printf("%-15d%-20d%-20d%-20d\n", i+1, originalBlocks[i], blocks[i], blockInternalFrag);
        
        // Add to external fragmentation if block is free
        if(!isAllocated && blocks[i] > 0) {
            externalFrag += blocks[i];
        }
    }
    
    printf("\n========== FRAGMENTATION ANALYSIS ==========\n");
    printf("Internal Fragmentation  : %d KB\n", internalFrag);
    printf("External Fragmentation  : %d KB\n", externalFrag);
    printf("Total Fragmentation     : %d KB\n", internalFrag + externalFrag);
    printf("Total Memory            : %d KB\n", totalMemory);
    printf("Used Memory             : %d KB\n", usedMemory);
    printf("Memory Utilization      : %.2f%%\n", (float)usedMemory/totalMemory * 100);
    printf("============================================\n");
}

int main() {
    int blocks[MAX], process[MAX];
    int m, n, choice;
    
    printf("===============================================\n");
    printf("  MEMORY ALLOCATION SIMULATOR\n");
    printf("===============================================\n\n");
    
    // Input memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter size of each memory block (in KB):\n");
    for(int i = 0; i < m; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blocks[i]);
    }
    
    // Input processes
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process (in KB):\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &process[i]);
    }
    
    // Display initial memory status
    printf("\n========== INITIAL MEMORY STATUS ==========");
    displayBlocks(blocks, m);
    
    // Menu-driven approach
    do {
        printf("\n\n===============================================\n");
        printf("  MENU - SELECT ALLOCATION ALGORITHM\n");
        printf("===============================================\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Create temporary copy of blocks for each algorithm
        int temp[MAX];
        for(int i = 0; i < m; i++) {
            temp[i] = blocks[i];
        }
        
        switch(choice) {
            case 1:
                firstFit(temp, m, process, n);
                break;
            case 2:
                bestFit(temp, m, process, n);
                break;
            case 3:
                worstFit(temp, m, process, n);
                break;
            case 4:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}
