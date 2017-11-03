#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    char * brand;
    char * model;
    int horsePower;
    int torque;
    int horsePowerTuned;
    int torqueTuned;

} Car;

Car * car(char * brand, char * model, int horsePower, int torque, int horsePowerTuned, int torqueTuned){

    Car * c = malloc(sizeof(Car));
    c->brand = brand;
    c->model = model;
    c->horsePower = horsePower;
    c->torque = torque;
    c->horsePowerTuned = horsePowerTuned;
    c->torqueTuned = torqueTuned;
    return c;

};

int main() {

    //int carsNumber;
    char * carModel = malloc(sizeof(char)*5);
    bool isAvailable = false;

    printf("Please enter the car model\n");
    scanf("%s", carModel);

    Car ** cars = malloc(sizeof(Car *) * 5);

    cars[0] = car("BMW", "121", 1, 10, 15, 20);
    cars[1] = car("Audi", "121", 1, 10, 15, 20);
    cars[2] = car("Lada", "123", 1, 10, 15, 20);
    cars[3] = car("Opel", "124", 1, 10, 15, 20);
    cars[4] = car("Suzuki", "125", 1, 10, 15, 20);

    for(int i = 0; i < 5; i++){

        if(strcmp(cars[i]->model, carModel) == 0){

            printf("%s, %s, %d, %d , %d, %d\n",cars[i]->brand, cars[i]->model, cars[i]->horsePower, cars[i]->torque, cars[i]->horsePowerTuned, cars[i]->torqueTuned);
            isAvailable = true;
            //break;
        }

    }

    if(isAvailable == false){
        printf("No information available.");

    }

    free(carModel);


    for(int i = 0; i < 5; i++){

        free(cars[i]);

    }

    free(cars);

    return 0;
}