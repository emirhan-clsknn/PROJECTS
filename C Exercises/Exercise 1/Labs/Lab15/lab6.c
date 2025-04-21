#include <stdio.h>
#define C 0
#define M 1
#define B 2
union VehicleData {
    struct {
        int doors;
        int seats;
    } car;
    struct {
        int wheels;
        int power;
    } motorcycle;
    struct {
        int wheels;
    } bicycle;
};


typedef struct {
    int type;
    union VehicleData data;
} Vehicle;


int calculateMaxSpeed(Vehicle vehicle) {
    int max_speed = 0;
    switch (vehicle.type) {
        case C:
            max_speed = vehicle.data.car.doors * 20;
            break;
        case M:
            max_speed = vehicle.data.motorcycle.power / 2;
            break;
        case B:
            max_speed = 30;
            break;
        default:
            printf("Invalid vehicle type\n");
            break;
    }
    return max_speed;
}

void modify_car_doors(Vehicle *car, int new_num_doors) {
    if (car->type == 0) {
        car->data.car.doors = new_num_doors;
    } else {
        printf("Cannot modify doors for this vehicle type\n");
    }
}

int main() {
 
    Vehicle vehicle1 = {C, {2, 5}};      
    Vehicle vehicle2 = {M, {4, 300}};    
    Vehicle vehicle3 = {B, {4}};          

    int newdoor;

    
    printf("Maximum speeds:\n");
    printf("Car: %d km/h\n", calculateMaxSpeed(vehicle1));
    printf("Motorcycle: %d km/h\n", calculateMaxSpeed(vehicle2));
    printf("Bicycle: %d km/h\n", calculateMaxSpeed(vehicle3));
-
    printf("Enter a new door number: ");
    scanf("%d", &newdoor);

    modify_car_doors(&vehicle1, newdoor);

    printf("Updated Maximum Speed of Car: %d km/h\n", calculateMaxSpeed(vehicle1));

    return 0;
}

