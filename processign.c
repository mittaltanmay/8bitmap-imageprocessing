#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{

    printf("\n###########  8-BIMP #############\n");
    char file_name[25];
    printf("\n enter the image file:");
    gets(file_name);

    char ch = 'y';
    do
    {
        printf("\nEnter the operation you want to perform");
        printf("\n1. Turn image negative");
        printf("\n2. Rotate image 90 degree CW");
        printf("\n3. Turn image 90 degree ACW");
        printf("\n4. brightness adjust");
        printf("\n5. 180 rotation");
        printf("\n6. Mirror/Flip image");
        printf("\n0. Exit\n");

        FILE *fp = fopen(file_name, "rb"); // read the file//

        unsigned char *imageData;       // to store the image information
        unsigned char *newimageData;    // to store the new image information, i.e. the negative image
        unsigned char imageHeader[54];  // to get the image header
        unsigned char colorTable[1024]; // to get the color table
        int i, j;
        fread(imageHeader, sizeof(unsigned char), 54, fp); // read the 54-byte from fp to imageHeader

        // extract image height and width from imageHeader
        int width = *(int *)&imageHeader[18];
        int height = *(int *)&imageHeader[22];
        int bitDepth = *(int *)&imageHeader[28];
        int imgDataSize = width * height; // calculate image size

        imageData = (unsigned char *)malloc(imgDataSize * sizeof(unsigned char)); // allocate the block of memory as big as the image size
        newimageData = (unsigned char *)malloc(imgDataSize * sizeof(unsigned char));

        int choice;
        printf("\nenter your choice:");
        scanf("%d", &choice);
       
        switch (choice)
        {
        case 1:; // empty as declaration is not a statement and a statement should follow a declaration
            // negative
            char output[25];
            printf("\nenter the name of output file:");
            scanf("%s",output);

            if (bitDepth <= 8)
            {
                fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
            }

            fread(imageData, sizeof(unsigned char), imgDataSize, fp);

            // Calculate the mean of the image
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    newimageData[i * width + j] = 255 - imageData[i * width + j];
                }
            }
 
            FILE *fo = fopen(output, "wb");
            fwrite(imageHeader, sizeof(unsigned char), 54, fo); // write the header back.

            if (bitDepth <= 8)
            {
                fwrite(colorTable, sizeof(unsigned char), 1024, fo); // write the color table back
            }
            fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo); // write the values of the negative image.
            fclose(fo);
            fclose(fp);
            printf("%s file created\n",output);
            system(output);
            break;

        case 2:; // empty as declaration is not a statement and a statement should follow a declaration
            char output1[25];
            printf("\nenter the name of output file:");
            scanf("%s",output1);

            if (bitDepth <= 8)
            {
                fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
            }

            fread(imageData, sizeof(unsigned char), imgDataSize, fp);

            //
            for (i = 0; i < height; i++)//to rotate image 90 degree right
            {
                for (j = 0; j < width; j++)
                {
                    newimageData[i * width + j] = imageData[j * width - i];
                }
            }

            FILE *fo2 = fopen(output1, "wb");
            fwrite(imageHeader, sizeof(unsigned char), 54, fo2); // write the header back.

            if (bitDepth <= 8)
            {
                fwrite(colorTable, sizeof(unsigned char), 1024, fo2); // write the color table back
            }
            fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo2); // write the values of the negative image.
            fclose(fo2);
            fclose(fp);
            printf("%s file created",output1);
            system(output1);
            break;

        case 3:; //
            char output2[25];
            printf("enter the name of output file:");
            scanf("%s",output2);

            if (bitDepth <= 8)
            {
                fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
            }

            fread(imageData, sizeof(unsigned char), imgDataSize, fp);

            //
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    newimageData[i * width - j] = imageData[j * width + i];
                }
            }

            FILE *fo3 = fopen(output2, "wb");
            fwrite(imageHeader, sizeof(unsigned char), 54, fo3); // write the header back.

            if (bitDepth <= 8)
            {
                fwrite(colorTable, sizeof(unsigned char), 1024, fo3); // write the color table back
            }
            fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo3); // write the values of the negative image.
            fclose(fo3);
            fclose(fp);
            printf("%s file created",output2);
            system(output2);
            break;

        case 4:;
        int x; //brightness slider
            char output3[25];
            printf("enter the name of output file:");
            scanf("%s",output3);

        printf("\n enter a number between -30 to +30 : ");
        scanf("%d", &x);

        
            if (bitDepth <= 8)
            {
                fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
            }

            fread(imageData, sizeof(unsigned char), imgDataSize, fp);

            // Calculate the mean of the image
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    newimageData[i * width + j] = imageData[i * width + j]+x;
                }
            }

            FILE *fo4 = fopen(output3, "wb");
            fwrite(imageHeader, sizeof(unsigned char), 54, fo4); // write the header back.

            if (bitDepth <= 8)
            {
                fwrite(colorTable, sizeof(unsigned char), 1024, fo4); // write the color table back
            }
            fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo4); // write the values of the negative image.
            fclose(fo4);
            fclose(fp);
            printf("%s is created",output3);
            system(output3);
            break;
        case 5:;
            char output4[25];
            printf("enter the name of output file:");
            scanf("%s",output4);
            if (bitDepth <= 8)
            {
                fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
            }

            fread(imageData, sizeof(unsigned char), imgDataSize, fp);

            //
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    newimageData[i * width + j] = imageData[j * width - i];
                }
            }

            FILE *fo5 = fopen(output4, "wb");
            fwrite(imageHeader, sizeof(unsigned char), 54, fo5); // write the header back.

            if (bitDepth <= 8)
            {
                fwrite(colorTable, sizeof(unsigned char), 1024, fo5); // write the color table back
            }
            fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo5); // write the values of the negative image.
            fclose(fo5);
            fclose(fp);
            FILE *fp1= fopen(output4, "rb"); // read the file//

        unsigned char *imageData1;       // to store the image information
        unsigned char *newimageData1;    // to store the new image information, i.e. the negative image
        unsigned char imageHeader1[54];  // to get the image header
        unsigned char colorTable1[1024]; // to get the color table
        int a, b;
        fread(imageHeader1, sizeof(unsigned char), 54, fp1); // read the 54-byte from fp to imageHeader

        // extract image height and width from imageHeader
        int width1 = *(int *)&imageHeader1[18];
        int height1 = *(int *)&imageHeader1[22];
        int bitDepth1 = *(int *)&imageHeader1[28];
        int imgDataSize1 = width1 * height1; // calculate image size

        imageData1= (unsigned char *)malloc(imgDataSize1 * sizeof(unsigned char)); // allocate the block of memory as big as the image size
        newimageData1= (unsigned char *)malloc(imgDataSize1 * sizeof(unsigned char));
        if (bitDepth1<= 8)
            {
                fread(colorTable1, sizeof(unsigned char), 1024, fp1); // read the 1024-byte from fp to colorTable
            }

            fread(imageData1, sizeof(unsigned char), imgDataSize1, fp1);

            //
            for (a = 0; a < height1; a++)
            {
                for (b = 0; b < width1; b++)
                {
                    newimageData1[a * width1 + b] = imageData1[b * width1 - a];
                }
            }

            FILE *fo6 = fopen(output4, "wb");
            fwrite(imageHeader1, sizeof(unsigned char), 54, fo6); // write the header back.

            if (bitDepth1<= 8)
            {
                fwrite(colorTable1, sizeof(unsigned char), 1024, fo6); // write the color table back
            }
            fwrite(newimageData1, sizeof(unsigned char), imgDataSize1, fo6); // write the values of the negative image.
            fclose(fo6);
            fclose(fp1);
            printf("%s is created",output4);
            system(output4);
            break;
        case 6:;
         char output5[25];
            printf("enter the name of output file:");
            scanf("%s",output5);
            if(bitDepth <= 8)
           {
            fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable
           }
        fread( imageData, sizeof(unsigned char), imgDataSize, fp);

	    for(i = 0; i < height; i++){
	      for(j = 0; j < width; j++){
		     newimageData[i*width + j] = imageData[i*width - j];
		   }
	    }

	FILE *fo7 = fopen(output5, "wb");
	fwrite(imageHeader, sizeof(unsigned char), 54, fo7); // write the header back.

	if(bitDepth <= 8)
    {
        fwrite(colorTable, sizeof(unsigned char), 1024, fo7); // write the color table back
    }
    fwrite( newimageData, sizeof(unsigned char), imgDataSize, fo7); // write the values of the negative image.
    fclose(fo7);
	fclose(fp);
    system(output5);
    break;
    case 0:
    exit(0);
    break;
    default:
    printf("\nenter valid input or press 0 to exit\n");
        }
    } while (ch == 'y');
   
}
