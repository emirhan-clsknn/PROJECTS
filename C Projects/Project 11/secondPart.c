#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CITIES 6
#define MAX_CITY_NAME_LENGTH 2

typedef struct {
    char* name;
    char servedCities[3][MAX_CITY_NAME_LENGTH];
} Hospital;

int all_cities_covered(char cities[][MAX_CITY_NAME_LENGTH], int city_count, int* covered) {
    int i;
    for (i = 0; i < city_count; i++) {
        if (!covered[i]) {
            return 0;
        }
    }
    return 1;
}

void find_facilities_recursive(Hospital facilities[], int facility_count, int max_facilities, char cities[][MAX_CITY_NAME_LENGTH], int city_count, int* covered, int* result, int* best_result, int current_facilities, int start, int* found) {
    if (current_facilities > max_facilities) {
        return;
    }

    if (all_cities_covered(cities, city_count, covered)) {
        *found = 1;
        if (current_facilities <= max_facilities) {
            memcpy(best_result, result, sizeof(int) * current_facilities);
        }
        return;
    }
    int i, j, k;
    for (i = start; i < facility_count; i++) {
        result[current_facilities] = i;
        for (j = 0; j < 3; j++) {
            for (k = 0; k < city_count; k++) {
                if (strcmp(facilities[i].servedCities[j], cities[k]) == 0) {
                    covered[k]++;
                }
            }
        }
        find_facilities_recursive(facilities, facility_count, max_facilities, cities, city_count, covered, result, best_result, current_facilities + 1, i + 1, found);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < city_count; k++) {
                if (strcmp(facilities[i].servedCities[j], cities[k]) == 0) {
                    covered[k]--;
                }
            }
        }
    }
}

void find_medical_facility_locations(Hospital facilities[], int facility_count, int max_facilities, char cities[][MAX_CITY_NAME_LENGTH], int city_count) {
    int covered[MAX_CITIES] = {0};
    int result[max_facilities];
    int best_result[max_facilities];
    int found = 0;

    find_facilities_recursive(facilities, facility_count, max_facilities, cities, city_count, covered, result, best_result, 0, 0, &found);

    if (found) {
        printf("Yes, can offer health care to all!\n");
        int i, j;
        for (i = 0; i < facility_count; i++) {
            if (best_result[i] < facility_count) {
                printf("Hospital - %d\n", i + 1);
                printf("Hospital location: ");
                for (j = 0; j < 3; j++) {
                    printf("%s", facilities[best_result[i]].servedCities[j]);
                }
                printf("\n");
            }
        }
    } else {
        printf("No, some cities are not covered.\n");
    }
}

int main() {
    char cities[MAX_CITIES][MAX_CITY_NAME_LENGTH] = {"A", "B", "C", "D", "E", "F"};
    Hospital facilities[] = {
        {"F1", {"A", "", ""}},
        {"F2", {"D", "F", ""}},
        {"F3", {"B", "C", ""}},
        {"F4", {"C", "E", "D"}}
    };
    int facility_count = sizeof(facilities) / sizeof(facilities[0]);
    int max_facilities;

    printf("Enter the maximum number of hospitals that can be constructed: ");
    scanf("%d", &max_facilities);

    find_medical_facility_locations(facilities, facility_count, max_facilities, cities, MAX_CITIES);

    return 0;
}
