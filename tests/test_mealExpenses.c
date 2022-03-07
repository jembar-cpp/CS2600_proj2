#include "../unity/src/unity.h"
#include "../mealExpenses.h"

void setUp() {}

void tearDown() {}

/**
 * This is a modified version of calculateMealCosts, to avoid user inputs,
 * since the function requires multiple user inputs originally.
 * The modified version hardcodes the inputs. The results are the same as if the user entered those inputs.
 */
void modifiedCalculateMealCosts(int numDays, int departureTime, int arrivalTime, float *totalMealCost, float *allowableMealCost) {
    float total = 0, allowable = 0, cost;

    for(int day = 1; day <= numDays; day++) { // loop through each day
        if(numDays == 1) { // special case: 1-day trip
            if(departureTime < 700 && arrivalTime > 800) { // breakfast is allowed
                cost = 10.50; // MODIFIED
                total += cost;
                allowable += 9;
            }
            if (departureTime < 1200 && arrivalTime > 1300) { // lunch is allowed
                cost = 12.25; // MODIFIED
                total += cost;
                allowable += 12;
            }
            if(departureTime < 1800 && arrivalTime > 1900) { // dinner is allowed
                cost = 7.50; // MODIFIED
                total += cost;
                allowable += 16;
            }
        }
        else if(day == 1) { // check the first day
            if(departureTime < 700) { // breakfast is allowed
                cost = 10.50; // MODIFIED
                total += cost;
                allowable += 9;
            }
            if(departureTime < 1200) { // lunch is allowed
                cost = 12.25; // MODIFIED
                total += cost;
                allowable += 12;
            }
            if (departureTime < 1800) { // dinner is allowed
                cost = 7.50; // MODIFIED
                total += cost;
                allowable += 16;
            }
        }
        else if(day != numDays) { // normal day, check all meals
            cost = 7.50; // MODIFIED
            total += cost;
            allowable += 9;
            cost = 12.25; // MODIFIED
            total += cost;
            allowable += 12;
            cost = 30; // MODIFIED
            total += cost;
            allowable += 16;;
        }
        else { // check the last day
            if(arrivalTime > 800) { // breakfast is allowed
                cost = 8; // MODIFIED
            total += cost;
                allowable += 9;
            }
            if(arrivalTime > 1300) { // lunch is allowed
                cost = 9; // MODIFIED
                total += cost;
                allowable += 12;
            }
            if (arrivalTime > 1900) { // dinner is allowed
                cost = 12; // MODIFIED
                total += cost;
                allowable += 16;
            }
        }
    }

    // Update pointers
    *totalMealCost = total;
    *allowableMealCost = allowable;
}

// Tests two versions: one with dollar sign added, one without dollar sign.
void testPromptCost() {
    freopen("test_mealExpenses_input/cost.txt", "r", stdin); // change standard input method
    float cost = promptCost();
    TEST_ASSERT_EQUAL(cost, 7.50);
    freopen("test_mealExpenses_input/cost2.txt", "r", stdin);
    cost = promptCost();
    TEST_ASSERT_EQUAL(cost, 12);
}

void testCalculateMealCosts() {
    freopen("test_mealExpenses_input/cost.txt", "r", stdin);
    float totalMealCost = 0;
    float allowedMealCost = 0;
    modifiedCalculateMealCosts(3,900,1200,&totalMealCost,&allowedMealCost);
    printf("%f, %f", totalMealCost, allowedMealCost);
    TEST_ASSERT_EQUAL(totalMealCost, 77.5);
    TEST_ASSERT_EQUAL(allowedMealCost, 74);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(testPromptCost);
    RUN_TEST(testCalculateMealCosts);
    return UNITY_END();
}