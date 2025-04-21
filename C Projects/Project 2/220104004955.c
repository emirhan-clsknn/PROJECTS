#include <stdio.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Dosya acilamadi.\n");
        return 0;
    }

    int x, y, z;
    int dataSize = 0;
    int maxC0x = -1000000, maxC0y = -1000000, maxC1x = -1000000, maxC1y = -1000000;
    int minC0x = 1000000, minC0y = 1000000, minC1x = 1000000, minC1y = 1000000;
    int bestX, bestY, minError = 10000;
    int correctPredictions = 0;
    float successRate = 0.0;

    while (fscanf(file, "%d %d %d", &x, &y, &z) == 3) // 2 class için ayrı ayrı max min bulma
    {
        if (z == 0)
        {
            if (x < minC0x)
                minC0x = x;
            if (x > maxC0x)
                maxC0x = x;
            if (y < minC0y)
                minC0y = y;
            if (y > maxC0y)
                maxC0y = y;
        }
        else if (z == 1)
        {
            if (x < minC1x)
                minC1x = x;
            if (x > maxC1x)
                maxC1x = x;
            if (y < minC1y)
                minC1y = y;
            if (y > maxC1y)
                maxC1y = y;
        }
        dataSize++;
    }
    fclose(file);
    int minX;
    int maxX;
    int minY;
    int maxY;

    if (minC1x < minC0x) // mutlak max mutlak min bulma
        minX = minC1x;
    else
        minX = minC0x;
    if (maxC1x < maxC0x)
        maxX = maxC0x;
    else
        maxX = maxC1x;
    if (minC0y < minC1y)
        minY = minC0y;
    else
        minY = minC1y;
    if (maxC0y < maxC1y)
        maxY = maxC1y;
    else
        maxY = maxC0y;

    int separatorX;
    int separatorY;
    int R1, R2, R3, R4;
    int R1s, R2s, R3s, R4s;
    int error = 0;
    int error2 = 0;
    int error3 = 0;
    int error4 = 0;
    int error5 = 0;
    int error6 = 0;
    int error7 = 0;
    int error8 = 0;
    for (separatorX = minX; separatorX <= maxX; separatorX++)  //  ayırıcı noktaları tek tek deneme
    {
        for (separatorY = minY; separatorY <= maxY; separatorY++)
        {
            R1s, R2s, R3s, R4s;
            error = 0;
            error2 = 0;
            error3 = 0;
            error4 = 0;
            error5 = 0;
            error6 = 0;
            error7 = 0;
            error8 = 0;
            file = fopen("data.txt", "r");
            if (file == NULL)
            {
                printf("Dosya acilamadi.\n");
                return 0;
            }
            while (fscanf(file, "%d %d %d", &x, &y, &z) == 3) // ayırıcı noktalarda hangi ragionda hangi class daha mantıklı bulma
            {
                if (x > separatorX && y > separatorY)
                {
                    if (z == 0)
                    {
                        error++;
                    }
                    else if (z == 1)
                    {
                        error2++;
                    }
                }
                else if (x <= separatorX && y > separatorY)
                {
                    if (z == 0)
                    {
                        error3++;
                    }
                    else if (z == 1)
                    {
                        error4++;
                    }
                }
                else if (x > separatorX && y <= separatorY)
                {
                    if (z == 0)
                    {
                        error5++;
                    }
                    else if (z == 1)
                    {
                        error6++;
                    }
                }
                else if (x <= separatorX && y <= separatorY)
                {
                    if (z == 0)
                    {
                        error7++;
                    }
                    else if (z == 1)
                    {
                        error8++;
                    }
                }
            }
            fclose(file);
            if (error2 < error) // reginları belirleme 
            {
                error = error2;
                R2s = 0;
            }
            else
            {
                R2s = 1;
            }
            if (error4 < error3)
            {
                error3 = error4;
                R1s = 0;
            }
            else
            {
                R1s = 1;
            }
            if (error6 < error5)
            {
                error5 = error6;
                R4s = 0;
            }
            else
            {
                R4s = 1;
            }
            if (error8 < error7)
            {
                error7 = error8;
                R3s = 0;
            }
            else
            {
                R3s = 1;
            }
            int totalerror = error + error3 + error5 + error7;
            if (totalerror < minError) // mutlak regionları belirleme
            {
                minError = totalerror;
                bestX = separatorX;
                bestY = separatorY;
                R1 = R1s;
                R2 = R2s;
                R3 = R3s;
                R4 = R4s;
            }
        }
    }

    file = fopen("test.txt", "r");
    if (file == NULL)
    {
        printf("Test dosyasi acilamadi.\n");
        return 0;
    }
    int predictedClass = 0;
    while (fscanf(file, "%d %d %d", &x, &y, &z) == 3)  // test dosyasındaki regionları tahmin edip successi hesaplama
    {
        if (x > bestX && y > bestY)
        {
            predictedClass = R2;
        }
        else if (x > bestX && y <= bestY)
        {
            predictedClass = R4;
        }
        else if (x <= bestX && y <= bestY)
        {
            predictedClass = R3;
        }
        else if (x <= bestX && y > bestY)
        {
            predictedClass = R1;
        }

        if (predictedClass == z)
            correctPredictions++;
    }
    fclose(file);
    successRate = (float)correctPredictions / 12 * 100;

    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Explore Data\n");
        printf("2. Train Model\n");
        printf("3. Test Model\n");
        printf("4. Test.final Model\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            file = fopen("data.txt", "r");
            if (file == NULL)
            {
                printf("Data dosyasi acilamadi.\n");
                break;
            }
            while (fscanf(file, "%d %d %d", &x, &y, &z) == 3)
            {
                printf("X: %d, Y: %d, Class: %d\n", x, y, z);
            }
            fclose(file);
            break;
        case 2:
            printf("Minimum and Maximum X and Y values:\n");
            printf("Class 0: X in [%d %d], Y in [%d %d]\n", minC0x, maxC0x, minC0y, maxC0y);
            printf("Class 1: X in [%d %d], Y in [%d %d]\n", minC1x, maxC1x, minC1y, maxC1y);
            printf("Separator Coordinates: X = %d, Y = %d\n", bestX, bestY);
            printf("Training Error of the Model: %d\n", minError);
            printf("Labels of the regions:\n");
            printf(" R1: %d\n", R1);
            printf(" R2: %d\n", R2);
            printf(" R3: %d\n", R3);
            printf(" R4: %d\n", R4);
            break;
        case 3:
            file = fopen("test.txt", "r");
            if (file == NULL)
            {
                printf("Test dosyasi acilamadi.\n");
                return 0;
            }
            while (fscanf(file, "%d %d %d", &x, &y, &z) == 3)
            {
                if (x > bestX && y > bestY)
                {
                    predictedClass = R2;
                }
                else if (x > bestX && y <= bestY)
                {
                    predictedClass = R4;
                }
                else if (x <= bestX && y <= bestY)
                {
                    predictedClass = R3;
                }
                else if (x <= bestX && y > bestY)
                {
                    predictedClass = R1;
                }
                printf("X: %d, Y: %d, Class: %d, predictedClass: %d\n", x, y, z, predictedClass);
            }
            fclose(file);
            printf("Test success rate: %.2f%%\n", successRate);
            break;
        case 4:
            file = fopen("test-final.txt", "r");
            if (file == NULL)
            {
                printf("Test dosyasi acilamadi.\n");
                return 0;
            }
            while (fscanf(file, "%d %d", &x, &y) == 2) // tahmin edip bastıryoruz
            {
                if (x > bestX && y > bestY)
                {
                    predictedClass = R2;
                }
                else if (x > bestX && y <= bestY)
                {
                    predictedClass = R4;
                }
                else if (x <= bestX && y <= bestY)
                {
                    predictedClass = R3;
                }
                else if (x <= bestX && y > bestY)
                {
                    predictedClass = R1;
                }
                printf("X: %d, Y: %d, predictedClass: %d\n", x, y, predictedClass);
            }
            fclose(file);
            break;
        case 5:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            break;
        }
    }
    return 0;
}
