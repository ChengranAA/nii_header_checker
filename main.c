#include <stdio.h>
#include <stdlib.h>
#include "nifti1.h"
#include "nifti1_io.h"




int main(int argc, char * argv[]) {
    // check for command line argument 
    if (argc != 2){
        fprintf(stderr, "\nUsage: %s <-r|-w> <data file|header file>\n", argv[0]);
        exit(1);
    }


    // Load a NIfTI image from file
    nifti_image* nim = nifti_image_read(argv[1], 1);
    if (!nim) {
        fprintf(stderr, "Error loading NIfTI image.\n");
        exit(1);
    }

    // Print some basic information about the image
    printf("Dimensions: %d x %d x %d\n", nim->nx, nim->ny, nim->nz);
    printf("Voxel size: %g x %g x %g mm\n", nim->dx, nim->dy, nim->dz);
    printf("Data type: %d\n", nim->datatype);

    // Free the NIfTI image structure
    nifti_image_free(nim);
    return 0;
}
