#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct User {
    char username[50];
    char password[20];
    float weight;
    float height;
    float activityLevel;
    float weightGoal;
    char dietaryPreferences[100];
    char allergies[100];
    char healthConditions[100];
    float waterIntake;
};


float calculateBMI(float weight, float height) {
    return weight / (height * height);
}


void recommendDiet(float bmi, struct User user) {

    printf("Diet recommendations for user %s based on BMI %.2f and preferences:\n", user.username, bmi);
    printf("1. Daily calorie recommendation: %.2f calories\n", user.weightGoal);
    printf("2. Meal suggestions: Include %s\n", user.dietaryPreferences);
    printf("3. Water intake tracking: Aim for %.2f liters per day\n", user.waterIntake);
}


void recommendExercise(struct User user) {

    printf("Exercise recommendations for user %s based on preferences:\n", user.username);
    printf("1. Include %s in your exercise routine\n", user.activityLevel >= 1.5 ? "high-intensity exercises" : "moderate-intensity exercises");
}

void trackProgress(struct User user) {

    printf("Tracking progress for user %s...\n", user.username);
}


bool userinfochecking(const char *temp_username1, const char *temp_password1, const char *temp_username2, const char *temp_password2) {
    return (strcmp(temp_username1, temp_username2) == 0 && strcmp(temp_password1, temp_password2) == 0);
}

int main() {
    struct User currentUser;

    
    printf("Registration:\n");
    printf("Enter your username: ");
    scanf("%49s", currentUser.username); 
    printf("Enter your password: ");
    scanf("%19s", currentUser.password); 
    printf("Registration Completed Successfully.\n");

    
    char temp_username2[50];
    char temp_password2[20];
    printf("Login:\n");
    printf("Enter your username: ");
    scanf("%49s", temp_username2);
    printf("Enter your password: ");
    scanf("%19s", temp_password2);

    if (userinfochecking(currentUser.username, currentUser.password, temp_username2, temp_password2)) {
        printf("Logged in as %s\n", currentUser.username);


        printf("Enter your weight (in kilograms): ");
        scanf("%f", &currentUser.weight);
        printf("Enter your height (in meters): ");
        scanf("%f", &currentUser.height);
        printf("Select your activity level (1 = Sedentary, 1.5 = Lightly active, 2 = Moderately active, 2.5 = Very active, 3 = Super active): ");
        scanf("%f", &currentUser.activityLevel);
        printf("Enter your weight goal (in kilograms): ");
        scanf("%f", &currentUser.weightGoal);
        printf("Enter your dietary preferences: ");
        scanf("%99s", currentUser.dietaryPreferences);
        printf("Enter your food allergies/intolerances: ");
        scanf("%99s", currentUser.allergies);
        printf("Enter your health conditions: ");
        scanf("%99s", currentUser.healthConditions);
        printf("Enter your target daily water intake (in liters): ");
        scanf("%f", &currentUser.waterIntake);


        float bmi = calculateBMI(currentUser.weight, currentUser.height);
        printf("Your BMI is %.2f.\n", bmi);


        recommendDiet(bmi, currentUser);


        recommendExercise(currentUser);


        trackProgress(currentUser);


        printf("Logged out.\n");
    } else {
        printf("Username or Password Wrong.\n");
    }

    return 0;
}

