#include <stdio.h>

// Function to implement First Fit memory allocation
void first_Fit(int blockSize[], int bno, int processSize[], int pno) {
    int allocation[pno]; // To store block allocation for each process
    //  pno - number of processes 
    //  bno -  number of blocks 

    // Initialize all allocations to -1 (indicating not allocated)
    for (int i = 0; i < pno; i++) {
        allocation[i] = -1; // Initially, no process is allocated any block
    }

    // Iterate through each process to allocate memory blocks
    for (int i = 0; i < pno; i++) {
        for (int j = 0; j < bno; j++) {
            // Check if the block can accommodate the process
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j; // Allocate block j to process i
                blockSize[j] -= processSize[i]; // Reduce available memory in block
                break; // Move to the next process after allocation
            }
        }
    }

    printf("\nFIRST FIT MEMORY ALLOCATION\n");

    // Output the allocation results in a detailed format
    printf("\nDetailed Allocation Results:\n");
    for (int i = 0; i < pno; i++) {
        if (allocation[i] != -1) {
            printf("Process %d: Allocated %d KB in Block %d.\n", i + 1, processSize[i], allocation[i] + 1);
        } else {
            printf("Process %d: Not Allocated.\n", i + 1);
        }
    }

     // Output the allocation results in tabular format for better visualization
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    // Output the remaining sizes of the memory blocks
    printf("\nRemaining Block Sizes or Fragmentation:\n");
    for (int i = 0; i < bno; i++) {
        // Display the size of each memory block after allocation
        printf("Block %d: %d KB\n", i + 1, blockSize[i]); 
    }
}

int main() {
    int bno, pno; // Variables to store the number of blocks and processes

    // Ask the user for the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &bno);
    int blockSize[bno]; // Array to store the size of each memory block
    printf("Enter size of each block:\n");  // Input sizes of memory blocks from the user
    for (int i = 0; i < bno; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Ask the user for the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &pno);
    int processSize[pno]; // Array to store the size of each process
    printf("Enter size of each process:\n");  // Input sizes of processes from the user
    for (int i = 0; i < pno; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call the First Fit function
    first_Fit(blockSize, bno, processSize, pno);

    return 0;
}


