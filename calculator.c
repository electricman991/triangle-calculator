#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M_PI 3.14159265358979323846

struct triangle {
    int number;
    float opposite;
    float adjacent;
    float hypotenuse;
    float angle;
    struct triangle *next;
};

struct triangle *head = NULL;

void add_triangle(float opposite, float adjacent, float hypotenuse, float angle, int number) {
  struct triangle *new_triangle = malloc(sizeof(struct triangle));

  new_triangle->number = number;
  new_triangle->opposite = opposite;
  new_triangle->adjacent = adjacent;
  new_triangle->hypotenuse = hypotenuse;
  new_triangle->angle = angle;
  new_triangle->next = NULL;
  if (head == NULL) {
        head = new_triangle;
    } else {
        struct triangle *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_triangle;
    }
}

void trigonometry(int choice, struct triangle *triangle, int number) {
    float result; // store the result of the trigonometric function
    int trigChoice; // store the choice of trigonometric function
    float opposite; // store the length of the opposite side
    float adjacent; // store the length of the adjacent side
    float hypotenuse; // store the hypotenuse
    float angle; // store the angle in degrees
    
    switch (choice) {
        case 1:
            printf("Which trigonometric function do you want to use? \n");
            printf("Enter 1 for sine. \n");
            printf("Enter 2 for cosine. \n");
            printf("Enter 3 for tangent. \n");
            printf("Enter 1, 2, or 3: ");
            scanf("%d",&trigChoice);

            printf("Please enter the length of the two sides: \n");
            
            if(trigChoice == 1){
                printf("Enter opposite first then hypotenuse. \n");
                printf("Enter two sides separated by a space: ");
                scanf("%f %f", &opposite, &hypotenuse);
                result = asin(opposite/hypotenuse) * (180 / M_PI);
                if (isnan(result)) {
                  printf("The hypotenuse must be larger than the opposite. \n");
                }
                else
                  printf("The angle is %.2f degrees \n",result);
                  angle = result;
                  add_triangle(opposite, 0, hypotenuse, angle, number);
            }
            else if(trigChoice == 2){
                printf("Enter adjacent first then hypotenuse. \n");
                printf("Enter two sides separated by a space: ");
                scanf("%f %f", &adjacent, &hypotenuse);
                result = acos(adjacent/hypotenuse) * (180 / M_PI);
                if (isnan(result)) {
                  printf("The hypotenuse must be larger than the adjacent. \n");
                }
                else
                  printf("The angle is %.2f degrees \n",result);
                  angle = result;
                  add_triangle(0, adjacent, hypotenuse, angle, number);
            }
            else if(trigChoice == 3){
                printf("Enter opposite first then adjacent. \n");
                printf("Enter two sides separated by a space: ");
                scanf("%f %f", &opposite, &adjacent);
                result = atan(opposite/adjacent) * (180 / M_PI);
                if (isnan(result)) {
                  printf("Please enter the correct choice. \n");
                }
                else
                  printf("The angle is %.2f degrees \n",result);
                  angle = result;
                  add_triangle(opposite, adjacent, 0, result, number);
            }
            else
              printf("Please choose a number between 1 and 3. \n");
            break;
        case 2:
            char sideChoice[10];
            float side;
            float angle;
            printf("Please enter an angle less than 90 degrees: ");
            scanf("%f",&angle);
            double radians = angle * (M_PI / 180.0);
            printf("Which trigonometric function do you want to use? \n");
            printf("Choose sine if you know the hypotenuse or opposite side \n");
            printf("Choose cosine if you know the hypotenuse or adjacent side \n");
            printf("Choose tangent if you know the opposite or adjacent side \n");
            printf("Enter 1 for sine. \n");
            printf("Enter 2 for cosine. \n");
            printf("Enter 3 for tangent. \n");
            printf("Enter 1, 2, or 3: ");
            scanf("%d",&trigChoice);
            
            printf("Please enter the length of the one known side: ");
            scanf("%f",&side);

            if(trigChoice == 1){
                printf("Which side did you enter? (opposite(O), hypotenuse(H)) \n");
                printf("Enter O for opposite or H for hypotenuse: ");
                scanf("%s", sideChoice);
                if (strcmp(sideChoice, "O") == 0) {
                  opposite = side;
                  result = opposite / sin(radians);
                  printf("The hypotenuse is %.2f \n", result);
                  hypotenuse = result;
                  add_triangle(opposite, 0, hypotenuse, angle, number);
                }
                else if (strcmp(sideChoice, "H") == 0) {
                  hypotenuse = side;
                  result = hypotenuse * sin(radians);
                  printf("The opposite side is %.2f \n", result);
                  opposite = result;
                  add_triangle(opposite, 0, hypotenuse, angle, number);
                }
                else
                  printf("Please enter the correct choice. \n");
                
            }
            else if(trigChoice == 2){
                printf("Which side did you enter? (adjacent(A), hypotenuse(H)) \n");
                printf("Enter A for adjacent or H for hypotenuse: ");
                scanf("%s", sideChoice);
                if (strcmp(sideChoice,"A") == 0) {
                  adjacent = side;
                  result = adjacent / cos(radians);
                  printf("The hyptonuse is %.2f \n", result);
                  hypotenuse = result;
                  add_triangle(0, adjacent, result, angle, number);
                }
                else if (strcmp(sideChoice,"H") == 0) {
                  hypotenuse = side;
                  result = hypotenuse * cos(radians);
                  printf("The adjacent side is %.2f \n", result);
                  adjacent = result;
                  add_triangle(0, adjacent, hypotenuse, angle, number);
                }
                else
                  printf("Please enter the correct choice. \n");
            }
            else if(trigChoice == 3){
                printf("Which side did you enter? (opposite(O), adjacent(A)) \n");
                printf("Enter O for opposite or A for adjacent: ");
                scanf("%s", sideChoice);
                if (strcmp(sideChoice,"O") == 0) {
                  opposite = side;
                  result = opposite / tan(radians);
                  printf("The adjacent side is %.2f \n", result);
                  adjacent = result;
                  add_triangle(opposite, result, 0, angle, number);
                }
                else if (strcmp(sideChoice,"A") == 0) {
                  adjacent = side;
                  result = adjacent * tan(radians);
                  printf("The opposite side is %.2f \n", result);
                  opposite = result;
                  add_triangle(result, adjacent, 0, angle, number);
                }
                else
                  printf("Please enter the correct choice. \n");
            }
            else
              printf("Please enter a number between 1 and 3. \n");
            break;
        
        default:
            printf("Please enter the correct choice. \n");
            break;
    }
}

void display_triangles(struct triangle *first) {
  struct triangle *current = first;
  if (current == NULL) {
    printf("Error: No triangle data.\n");
    return;
}
  while (current != NULL) {
    printf("    Triangle %d \n", current -> number);
    printf("    Opposite: %.2f \n", current -> opposite);
    printf("    Adjacent: %.2f \n", current -> adjacent);
    printf("    Hypotenuse: %.2f \n", current -> hypotenuse);
    printf("    Angle: %.2f \n\n", current -> angle);
    current = current -> next;
  }
}

int main() {
  int choice; // 1 or 2
  int continueChoice = 1; // 0 or 1
  int number = 0; // number of triangles
  char category; // S, A, D, or Q
  
  printf("Welcome to the Trigonometry Calculator \n");
  struct triangle *triangle = (struct triangle *)malloc(sizeof(struct triangle));
  while (continueChoice) {
    
    printf("\nPlease enter the calculation that you would like to do: \n");
    printf("Find side(S), Find angle(A), Display all Triangles(D), Quit(Q) \n");
    printf("Please enter S, A, D or Q: ");
    scanf(" %c",&category);

    switch (category) {

        case 'A':
            printf("\nWelcome to Angle Finder! \n");
            choice = 1;
            number += 1;
            trigonometry(choice, triangle, number);
            break;

          case 'S':
            printf("\nWelcome to Side Finder! \n");
            choice = 2;
            number += 1;
            trigonometry(choice, triangle, number);
            break;

          case 'D':
            printf("Displaying all triangles: \n");
            display_triangles(head);
            break;
          
          case 'Q':
            printf("Goodbye! \n");
            continueChoice = 0;
            break;
        
        default:
            printf("Please enter the letter A or S. \n");
            break;
    }
  }

  struct triangle *current = head;
    while (current != NULL) {
        struct triangle *next = current->next;
        free(current);
        current = next;
    }
  
  return 0;
}