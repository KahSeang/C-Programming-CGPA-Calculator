#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6262)
#define AAA1003 "AAA1003"
#define AAA1014 "AAA1014"
#define ABA1003 "ABA1003"
#define ABA1014 "ABA1014"
#define ACA1003 "ABA1003"
#define ACA1014 "ABA1014"
#define CREDITHOUR3 3
#define CREDITHOUR4 4


void staffs();
void staffMenu();
void addSemester();
void student();
int studentIdValidation(char stID[]);
double score(int mark);

//the all colour function declaraction
void purpleColour();
void whiteColour();
void cyanColour();
void redColour();
void greenColour();
void whiteColour();

//function font color definition
void purpleColour() {
	printf("\033[0;35m");
}
void blackColour() {
	printf("\033[0;30m");
}
void cyanColour() {
	printf("\033[0;36m");
}
void redColour() {
	printf("\033[0;31m");
}
void greenColour() {
	printf("\033[0;32m");
}
void whiteColour() {
	printf("\033[0;37m");
}

//local variable
//studentNameArray[100][50] 100 is array size, 50 is how many character I can type, studentIDArray also same. 
char  studentNameArray[100][50], studentIDArray[100][10], cont;
//gpa is two d array, others is array
double gpa[100][3], cgpa[100], totalqualitypoint1[100], totalcredithour1[100], totalqualitypoint2[100], totalcredithour2[100], totalqualitypoint3[100], totalcredithour3[100];
int stNumOfCourseSEM1[100], stNumOfCourseSEM2[100], stNumOfCourseSEM3[100];
//then stCourseName is a two d array, [100][10] both are array size and [20] is how many character I can type. stCourseCode also same
char  stCourseName1[100][10][20], stCourseCode1[100][10][20], stCourseName2[100][10][20], stCourseCode2[100][10][20], stCourseName3[100][10][20], stCourseCode3[100][10][20]; // 
// gradePoint is two d array
double gradePoint[10], stCreditHour1[10], stCreditHour2[10], stCreditHour3[10], qualitypoint1[10], qualitypoint2[10], qualitypoint3[10];
int mark1[10], mark2[10], mark3[10], wrongformat;


void main() {
	int selection;

	do {

		selection = 0;
		cyanColour();
		printf("\n\n    ============================================================\n");
		printf("    ======== Welcome to Kolej Pasar GPA/CGPA calculator ========\n");
		printf("    ============================================================\n\n");
		whiteColour();
		printf("The number to select Student or Staff....\n[1].Student\n[2].Staff\n[3].Exit\n");
		printf("Please enter the number to select Student or Staff: ");
		greenColour();
		scanf("%d", &selection);
		while (selection != 1 && selection != 2 && selection != 3)
		{

			redColour();
			printf("Invalid number,Please Enter Again\n");
			cyanColour();
			printf("\n\n    ============================================================\n");
			printf("    ======== Welcome to Kolej Pasar GPA/CGPA calculator ========\n");
			printf("    ============================================================\n\n");
			whiteColour();
			printf("The number to select Student or Staff....\n[1].Student\n[2].Staff\n[3].Exit\n");
			printf("Please enter the number to select Student or Staff: ");
			greenColour();
			rewind(stdin);
			scanf("%d", &selection);
			whiteColour();
		}
		switch (selection) {
		case 1:
			system("cls");
			student();
			break;
		case 2:
			system("cls");
			staffMenu();
			break;
		case 3:
			printf("Thank for using this system! Hava a nice day !!\n");
			break;
		default:
			break;
		}

	} while (selection == 1 || selection == 2);
}

void staffMenu() {

	int option;

	do {
		cyanColour();
		printf("        ===========================================================\n");
		printf("	========Welcome to Kolej Pasar GPA/CGPA calculator ========\n");
		printf("	===========================================================\n\n");
		whiteColour();
		printf("[1].Add A Student\n[2].Add SEMESTER To A Student\n[3].Exit\n");
		printf("Please enter the number : ");
		greenColour();
		scanf("%d", &option);
		while (option != 1 && option != 2 && option != 3)
		{
			redColour();
			printf("Invalid number,Please Enter Again\n");
			whiteColour();
			printf("[1].Add A Student\n[2].Add SEMESTER To A Student\n[3].Exit\n");
			printf("Please enter the number : ");
			greenColour();
			rewind(stdin);
			scanf("%d", &option);
		}
		switch (option) {
		case 1:
			system("cls");
			staffs();
			break;
		case 2:
			system("cls");
			addSemester();
			break;
		case 3:
			system("cls");
			break;
		default:
			break;
		}

	} while (option == 1 || option == 2);
}

void staffs() {

	int  i = 0, result1, result2, choose, code;
	cyanColour();

	printf("\t=============================================================\n");
	printf("	============== Kolej Pasar staff administrator ==============\n");
	printf("	=============================================================\n");

	do {
		whiteColour();
		printf("\nPlease enter the student details\n");
		printf("================================\n");
		printf("Enter the student name : ");
		greenColour();
		rewind(stdin);
		whiteColour();
		scanf("%[^\n]", &studentNameArray[i]);
		printf("Student Name: %s\n\n", studentNameArray[i]);

		do {
			printf("Enter the student id (ID format is fixed, e.g. KPKL12345) : ");
			greenColour();
			rewind(stdin);
			scanf("%s", &studentIDArray[i]);
			whiteColour();
			wrongformat = studentIdValidation(studentIDArray[i]);

			if (wrongformat == 0) {
				printf("The student ID: %s is Invalid.\n\n", studentIDArray[i]);
			}
			else {
				printf("The student ID: %s is valid.\n\n", studentIDArray[i]);
			}


		} while (wrongformat != 1);

		//Enter number of course in SEMESTER 1
		//validate the number of the course
		do {
			printf("Enter the number of the course SEMESTER 1 : ");
			rewind(stdin);
			result1 = scanf("%d", &stNumOfCourseSEM1[i]);

			if (result1 != 1) {
				printf("Invalid. Please enter a number!\n");
			}

		} while (result1 != 1);

		while (stNumOfCourseSEM1[i] < 0 || stNumOfCourseSEM1[i]>10) {
			printf("enter agian\n");
			printf("Enter the number of the course in SEMESTER 1 : ");
			rewind(stdin);
			scanf("%d", &stNumOfCourseSEM1[i]);
		}


		//Enter course details
		for (int x = 0; x < stNumOfCourseSEM1[i]; x++)
		{
			printf("\n==================== Course Details ========================\n");
			printf("Enter the course name : ");
			rewind(stdin);
			scanf("%[^\n]", &stCourseName1[i][x]);

			printf("Do you want to choose the course code or enter the course code yourself?\n");
			printf("[1]. Choose the course code\n");
			printf("[2]. Enter the course code\n");
			scanf("%d", &choose);
			switch (choose)
			{
			case 1:
				printf("Choose the course code\n");
				printf("\n[1]. AAA1003");
				printf("\n[2]. AAA1014\n");
				scanf("\n%d", &code);
				if (code == 1) {
					strcmp(stCourseCode1[i][x], AAA1003);
					stCreditHour1[x] = CREDITHOUR3;
				}
				else if (code == 2) {
					strcmp(stCourseCode1[i][x], AAA1014);
					stCreditHour1[x] = CREDITHOUR4;
				}
				break;
			case 2:
				printf("Enter the course code : ");
				rewind(stdin);
				scanf("%s", &stCourseCode1[i][x]);
				//validate the credit hours
				do {
					printf("Enter the credit hours : ");
					rewind(stdin);
					result2 = scanf("%lf", &stCreditHour1[x]);

					if (result2 != 1) {
						printf("Invalid. Please enter a number!\n");
					}

				} while (result2 != 1);
			default:
				break;
			}

			printf("Enter the mark :");
			rewind(stdin);
			scanf("%d", &mark1[x]);
			gradePoint[x] = score(mark1[x]);
			printf("==============================================================\n\n");

			qualitypoint1[x] = stCreditHour1[x] * gradePoint[x];
			totalqualitypoint1[i] = totalqualitypoint1[i] + qualitypoint1[x];
			totalcredithour1[i] = totalcredithour1[i] + stCreditHour1[x];

		}
		gpa[i][0] = totalqualitypoint1[i] / totalcredithour1[i];


		printf("\n\nDo you want to continue to next SEMESTER? (Y/N) : ");
		rewind(stdin);
		scanf("%c", &cont);

		while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n') {
			printf("You only can type (Y/N) only\n");
			printf("Please try again !\n\n");
			printf("Do you want to next SEMESTER? (Y/N) : ");
			rewind(stdin);
			scanf("%c", &cont);
		}


		//if yes go to SEMESTER 2
		if (cont == 'Y' || cont == 'y') {

			//Enter number of course in SEMESTER 2
			//validate the number of the course
			do {
				printf("Enter the number of the course SEMESTER 2 : ");
				rewind(stdin);
				result1 = scanf("%d", &stNumOfCourseSEM2[i]);

				if (result1 != 1) {
					printf("Invalid. Please enter a number!\n");
				}

			} while (result1 != 1);

			while (stNumOfCourseSEM2[i] < 0 || stNumOfCourseSEM2[i]>10) {
				printf("enter agian\n");
				printf("Enter the number of the course in SEMESTER 2 : ");
				rewind(stdin);
				scanf("%d", &stNumOfCourseSEM2[i]);
			}

			//Enter course details
			for (int x = 0; x < stNumOfCourseSEM2[i]; x++)
			{
				printf("\n==================== Course Details ==========================\n");
				printf("Enter the course name : ");
				rewind(stdin);
				scanf("%[^\n]", &stCourseName2[i][x]);

				printf("Do you want to choose the course code or enter the course code yourself?\n");
				printf("[1]. Choose the course code\n");
				printf("[2]. Enter the course code");
				scanf("\n%d", &choose);
				switch (choose)
				{
				case 1:
					printf("Choose the course code\n");
					printf("\n[1]. ABA1003");
					printf("\n[2]. ABA1014");
					scanf("%d", &code);
					if (code == 1) {
						strcmp(stCourseCode2[i][x], ABA1003);
						stCreditHour2[x] == CREDITHOUR3;
					}
					else if (code == 2) {
						strcmp(stCourseCode2[i][x], ABA1014);
						stCreditHour2[x] == CREDITHOUR4;
					}
					break;
				case 2:
					printf("Enter the course code : ");
					rewind(stdin);
					scanf("%s", &stCourseCode2[i][x]);
					//validate the credit hours
					do {
						printf("Enter the credit hours : ");
						rewind(stdin);
						result2 = scanf("%lf", &stCreditHour2[x]);

						if (result2 != 1) {
							printf("Invalid. Please enter a number!\n");
						}

					} while (result2 != 1);
				default:
					break;
				}


				printf("Enter the mark : ");
				rewind(stdin);
				scanf("%d", &mark2[x]);
				gradePoint[x] = score(mark2[x]);
				printf("==============================================================\n\n");

				qualitypoint2[x] = stCreditHour2[x] * gradePoint[x];
				totalqualitypoint2[i] = totalqualitypoint2[i] + qualitypoint2[x];
				totalcredithour2[i] = totalcredithour2[i] + stCreditHour2[x];

			}
			gpa[i][1] = totalqualitypoint2[i] / totalcredithour2[i];


			printf("Do you want to continue to next SEMESTER? (Y/N) : ");
			rewind(stdin);
			scanf("%c", &cont);

			while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n') {
				printf("You only can type (Y/N) only\n");
				printf("Please try again !\n\n");
				printf("Do you want to next SEMESTER? (Y/N) : ");
				rewind(stdin);
				scanf("%c", &cont);
			}


			// if yes go to SEMESTER 3
			if (cont == 'Y' || cont == 'y') {

				//Enter number of course in SEMESTER 3
				//validate the number of the course
				do {
					printf("Enter the number of the course SEMESTER 3 : ");
					rewind(stdin);
					result1 = scanf("%d", &stNumOfCourseSEM3[i]);

					if (result1 != 1) {
						printf("Invalid. Please enter a number!\n");
					}

				} while (result1 != 1);

				while (stNumOfCourseSEM3[i] < 0 || stNumOfCourseSEM3[i]>10) {
					printf("enter agian\n");
					printf("Enter the number of the course in SEMESTER 3 : ");
					rewind(stdin);
					scanf("%d", &stNumOfCourseSEM3[i]);
				}

				//Enter course details
				for (int x = 0; x < stNumOfCourseSEM3[i]; x++)
				{
					printf("\n==================== Course Details ==========================\n");
					printf("Enter the course name : ");
					rewind(stdin);
					scanf("%[^\n]", &stCourseName3[i][x]);

					printf("Do you want to choose the course code or enter the course code yourself?\n");
					printf("[1]. Choose the course code\n");
					printf("[2]. Enter the course code");
					scanf("\n%d", &choose);
					switch (choose)
					{
					case 1:
						printf("Choose the course code\n");
						printf("\n[1]. AAA1003");
						printf("\n[2]. AAA1014");
						scanf("%d", &code);
						if (code == 1) {
							strcmp(stCourseCode3[i][x], ACA1003);
							stCreditHour3[x] == CREDITHOUR3;
						}
						else if (code == 2) {
							strcmp(stCourseCode3[i][x], ACA1014);
							stCreditHour3[x] == CREDITHOUR4;
						}
						break;
					case 2:
						printf("Enter the course code : ");
						rewind(stdin);
						scanf("%s", &stCourseCode3[i][x]);
						//validate the credit hours
						do {
							printf("Enter the credit hours : ");
							rewind(stdin);
							result2 = scanf("%lf", &stCreditHour3[x]);

							if (result2 != 1) {
								printf("Invalid. Please enter a number!\n");
							}

						} while (result2 != 1);
					default:
						break;
					}

					printf("Enter the mark : ");
					rewind(stdin);
					scanf("%d", &mark3[x]);
					gradePoint[x] = score(mark3[x]);
					printf("==============================================================\n\n");

					qualitypoint3[x] = stCreditHour3[x] * gradePoint[x];
					totalqualitypoint3[i] = totalqualitypoint3[i] + qualitypoint3[x];
					totalcredithour3[i] = totalcredithour3[i] + stCreditHour3[x];

				}
				gpa[i][2] = totalqualitypoint3[i] / totalcredithour3[i];
				cgpa[i] = (totalqualitypoint1[i] + totalqualitypoint2[i] + totalqualitypoint3[i]) / (totalcredithour1[i] + totalcredithour2[i] + totalcredithour3[i]);

			}
			else {
				system("cls");
				// assign an empty string to all the course details for SEM3;
				stNumOfCourseSEM3[i] = 0;
				stCourseName3[i][0][0] = "";
				stCourseCode3[i][0][0] = "";
				stCreditHour3[0] = 0.0;
				mark3[0] = 0;
				cgpa[i] = (totalqualitypoint1[i] + totalqualitypoint2[i]) / (totalcredithour1[i] + totalcredithour2[i]);
			}

		}
		else {
			system("cls");
			// assign an empty string to all the course details for SEM2 and SEM3;
			stNumOfCourseSEM2[i] = 0;
			stCourseName2[i][0][0] = "";
			stCourseCode2[i][0][0] = "";
			stCreditHour2[0] = 0.0;
			mark2[0] = 0;
			stNumOfCourseSEM3[i] = 0;
			stCourseName3[i][0][0] = "";
			stCourseCode3[i][0][0] = "";
			stCreditHour3[0] = 0.0;
			mark3[0] = 0;
			cgpa[i] = (totalqualitypoint1[i]) / (totalcredithour1[i]);
		}


		printf("\n\n========================================================================\n");
		printf("======================== Student Information ===========================\n");
		printf("========================================================================\n");
		printf("Student Name: %s\n", studentNameArray[i]);
		printf("Student ID: %s\n", studentIDArray[i]);

		printf("========================================================================\n");
		printf("================== Course Information In SEMESTER 1 ====================\n");
		printf("========================================================================\n");

		for (int x = 0; x < stNumOfCourseSEM1[i]; x++) {
			printf("Course %d:\n", x + 1);
			printf("Course Name: %s\n", stCourseName1[i][x]);
			printf("Course Code: %s\n", stCourseCode1[i][x]);
			printf("Credit Hours: %.2f\n", stCreditHour1[x]);
			printf("Mark: %d\n", mark1[x]);
			printf("Quality Point: %.2lf\n", qualitypoint1[x]);
			printf("========================================================================\n\n");
		}

		if (stNumOfCourseSEM2[i] != 0) {

			printf("========================================================================\n");
			printf("================== Course Information In SEMESTER 2 ====================\n");
			printf("========================================================================\n");

			for (int x = 0; x < stNumOfCourseSEM2[i]; x++) {
				printf("Course %d:\n", x + 1);
				printf("Course Name: %s\n", stCourseName2[i][x]);
				printf("Course Code: %s\n", stCourseCode2[i][x]);
				printf("Credit Hours: %.2f\n", stCreditHour2[x]);
				printf("Mark: %d\n", mark2[x]);
				printf("Quality Point: %.2lf\n", qualitypoint2[x]);
				printf("========================================================================\n\n");
			}
		}

		if (stNumOfCourseSEM3[i] != 0) {

			printf("========================================================================\n");
			printf("================== Course Information In SEMESTER 3 ====================\n");
			printf("========================================================================\n");


			for (int x = 0; x < stNumOfCourseSEM3[i]; x++) {
				printf("Course %d:\n", x + 1);
				printf("Course Name: %s\n", stCourseName3[i][x]);
				printf("Course Code: %s\n", stCourseCode3[i][x]);
				printf("Credit Hours: %.2f\n", stCreditHour3[x]);
				printf("Mark: %d\n", mark3[x]);
				printf("Quality Point: %.2lf\n", qualitypoint3[x]);
				printf("========================================================================\n\n");
			}
		}

		printf("========================================================================\n");
		printf("=========================== GPA and CGPA ===============================\n");
		printf("========================================================================\n");
		printf("GPA for Semester 1: %.2lf\n", gpa[i][0]);
		if (stNumOfCourseSEM2[i] != 0)
			printf("GPA for Semester 2: %.2lf\n", gpa[i][1]);
		if (stNumOfCourseSEM3[i] != 0)
			printf("GPA for Semester 3: %.2lf\n", gpa[i][2]);
		printf("CGPA: %.2lf\n\n", cgpa[i]);




		printf("Do you want to continue to the next student? (Y/N) : ");
		rewind(stdin);
		scanf("%c", &cont);

		while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n') {
			printf("You only can type (Y/N) only\n");
			printf("Please try again !\n\n");
			printf("Do you want to continue? (Y/N) : ");
			rewind(stdin);
			scanf("%c", &cont);
		}

		//to the next student
		if (cont == 'Y' || cont == 'y') {
			i++;
			system("cls");
		}
		else {
			system("cls");
		}

	} while (cont == 'y' || cont == 'Y');


}

void student()
{
	char studentID[10];
	int find = 0;
	cyanColour();

	do {
		printf("        ===========================================================\n");
		printf("	====================Kolej Pasar student====================\n");
		printf("	===========================================================\n");
		whiteColour();
		printf("\nPlease enter your STUDENT ID to log in\n(ID format is fixed, e.g. KPKL12345): ");
		greenColour();
		scanf("%9s", &studentID);
		whiteColour();
		printf("Entered Student ID :");
		greenColour();
		printf(" % s\n", studentID);
		whiteColour();

		for (int i = 0; i < 100; i++)
		{
			// using strcmp to compare the studentID and studentIDArray, if both values are same, then will display the student gpa and cgpa
			if (strcmp(studentID, studentIDArray[i]) == 0)
			{
				whiteColour();
				printf("Student ID: %s\n", studentIDArray[i]);
				printf("Student Name: %s\n\n", studentNameArray[i]);
				cyanColour();
				printf("===========================================================\n");
				printf("============== GPA and CGPA ===============================\n");
				printf("===========================================================\n");
				whiteColour();
				printf("GPA for Semester 1: %.2lf\n", gpa[i][0]);
				if (stNumOfCourseSEM2[i] != 0) {
					printf("GPA for Semester 2: %.2lf\n", gpa[i][1]);
				}
				if (stNumOfCourseSEM3[i] != 0) {
					printf("GPA for Semester 3: %.2lf\n", gpa[i][2]);
				}

				printf("CGPA: %.2lf\n", cgpa[i]);
				if (cgpa[i] >= 3.5 && cgpa[i] <= 4.0) {
					printf("Excellent work! Your CGPA is outstanding. Keep up the great effort!\n");
				}
				else if (cgpa[i] >= 2.5 && cgpa[i] < 3.5) {
					printf("Good job! You're doing well, but there's room for improvement. Keep striving for excellence!\n");
				}
				else {
					printf("Don't get discouraged! Everyone has room to grow, and you're no exception. Consider seeking additional resources or help to improve your grades.\n");
				}
				find = 1;

			}
		}

		if (find != 1) {
			redColour();
			printf("The student ID is not match!\n\n");
			whiteColour();
			printf("Do you want to continue enter student ID? (Y/N) : ");
			greenColour();
			rewind(stdin);
			scanf("%c", &cont);
			whiteColour();
			while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n') {
				redColour();
				printf("You only can type (Y/N) only\n");
				printf("Please try again !!!\n\n");
				whiteColour();
				printf("Do you want to continue enter student ID? ? (Y/N) : ");
				rewind(stdin);
				scanf("%c", &cont);
			}

			if (cont == 'N' || cont == 'n') {
				system("cls");
			}
		}


	} while (cont == 'y' || cont == 'Y');

}

void addSemester() {
	char studentID[10], confirm;
	int result1, result2, find = 0, choose, code;
	whiteColour();

	do {
		printf("\t=============================================================\n");
		printf("	================= Add SEMESTER to a Student =================\n");
		printf("	=============================================================\n");
		printf("Please enter your STUDENT ID (ID format is fixed, e.g. KPKL12345) : \n");
		scanf("%9s", &studentID);
		printf("Entered Student ID: %s\n", studentID);


		for (int i = 0; i < 100; i++)
		{
			// using strcmp to compare the studentID and studentIDArray, if both values are same, then will display the student gpa and cgpa
			if (strcmp(studentID, studentIDArray[i]) == 0)
			{
				cyanColour();
				printf("\n\n========================================================================\n");
				printf("======================== Student Information ===========================\n");
				printf("========================================================================\n");
				whiteColour();
				printf("Student ID: %s\n", studentIDArray[i]);
				printf("Student Name: %s\n\n", studentNameArray[i]);
				cyanColour();
				printf("========================================================================\n");
				printf("================== Course Information In SEMESTER 1 ====================\n");
				printf("========================================================================\n");
				whiteColour();
				for (int x = 0; x < stNumOfCourseSEM1[i]; x++) {
					printf("Course %d:\n", x + 1);
					printf("Course Name: %s\n", stCourseName1[i][x]);
					printf("Course Code: %s\n", stCourseCode1[i][x]);
					printf("Credit Hours: %.2f\n", stCreditHour1[x]);
					printf("Mark: %d\n", mark1[x]);
					printf("Quality Point: %.2lf\n", qualitypoint1[x]);
					printf("========================================================================\n\n");
				}

				if (stNumOfCourseSEM2[i] != 0) {
					cyanColour();
					printf("========================================================================\n");
					printf("================== Course Information In SEMESTER 2 ====================\n");
					printf("========================================================================\n");
					whiteColour();
					for (int x = 0; x < stNumOfCourseSEM2[i]; x++) {
						printf("Course %d:\n", x + 1);
						printf("Course Name: %s\n", stCourseName2[i][x]);
						printf("Course Code: %s\n", stCourseCode2[i][x]);
						printf("Credit Hours: %.2f\n", stCreditHour2[x]);
						printf("Mark: %d\n", mark2[x]);
						printf("Quality Point: %.2lf\n", qualitypoint2[x]);
						printf("========================================================================\n\n");
					}
				}

				if (stNumOfCourseSEM3[i] != 0) {
					cyanColour();
					printf("========================================================================\n");
					printf("================== Course Information In SEMESTER 3 ====================\n");
					printf("========================================================================\n");

					whiteColour();
					for (int x = 0; x < stNumOfCourseSEM3[i]; x++) {
						printf("Course %d:\n", x + 1);
						printf("Course Name: %s\n", stCourseName3[i][x]);
						printf("Course Code: %s\n", stCourseCode3[i][x]);
						printf("Credit Hours: %.2f\n", stCreditHour3[x]);
						printf("Mark: %d\n", mark3[x]);
						printf("Quality Point: %.2lf\n", qualitypoint3[x]);
						printf("========================================================================\n\n");
					}
				}
				cyanColour();
				printf("========================================================================\n");
				printf("=========================== GPA and CGPA ===============================\n");
				printf("========================================================================\n");
				whiteColour();
				printf("GPA for Semester 1: %.2lf\n", gpa[i][0]);
				if (stNumOfCourseSEM2[i] != 0) {
					printf("GPA for Semester 2: %.2lf\n", gpa[i][1]);
				}
				if (stNumOfCourseSEM3[i] != 0) {
					printf("GPA for Semester 3: %.2lf\n", gpa[i][2]);
				}
				printf("CGPA: %.2lf\n\n", cgpa[i]);

				if (stNumOfCourseSEM2[i] == 0) {
					printf("Add SEMESTER 2 (Y/N)? : ");
					rewind(stdin);
					scanf("%c", &confirm);

					while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
						redColour();
						printf("You only can type (Y/N) only !!!\n");
						greenColour();
						printf("Please try again !\n\n");
						printf("Add SEMESTER 2 (Y/N) : ");
						greenColour();
						rewind(stdin);
						scanf("%c", &confirm);
						whiteColour();
					}

					if (confirm == 'Y' || confirm == 'y') {
						//Enter number of course in SEMESTER 2
						//validate the number of the course
						do {
							whiteColour();
							printf("Enter the number of the course SEMESTER 2 : ");
							rewind(stdin);
							greenColour();
							result1 = scanf("%d", &stNumOfCourseSEM2[i]);

							if (result1 != 1) {
								printf("Invalid. Please enter a number!\n");
							}

						} while (result1 != 1);

						while (stNumOfCourseSEM2[i] < 0 || stNumOfCourseSEM2[i]>10) {
							redColour();
							printf("Please enter agian !!!\n");
							whiteColour();
							printf("Enter the number of the course in SEMESTER 2 : ");
							greenColour();
							rewind(stdin);
							scanf("%d", &stNumOfCourseSEM2[i]);
						}

						//Enter course details
						for (int x = 0; x < stNumOfCourseSEM2[i]; x++)
						{
							whiteColour();
							printf("\n==================== Course Details ==========================\n");
							printf("Enter the course name : ");
							greenColour();
							rewind(stdin);
							scanf("%[^\n]", &stCourseName2[i][x]);
							whiteColour();
							printf("\nDo you want to choose the course code or enter the course code yourself?\n");
							printf("[1]. Choose the course code\n");
							printf("[2]. Enter the course code\n");
							scanf("\n%d", &choose);
							switch (choose)
							{
							case 1:
								printf("Choose the course code\n");
								printf("\n[1]. AAA1003");
								printf("\n[2]. AAA1014\n");
								scanf("%d", &code);
								if (code == 1) {
									strcmp(stCourseCode2[i][x], ABA1003);
									stCreditHour2[x] = CREDITHOUR3;
								}
								else if (code == 2) {
									strcmp(stCourseCode2[i][x], ABA1014);
									stCreditHour2[x] = CREDITHOUR4;
								}
								break;
							case 2:
								printf("Enter the course code : ");
								rewind(stdin);
								scanf("%s", &stCourseCode2[i][x]);
								//validate the credit hours
								do {
									printf("Enter the credit hours : ");
									rewind(stdin);
									result2 = scanf("%lf", &stCreditHour2[x]);

									if (result2 != 1) {
										printf("Invalid. Please enter a number!\n");
									}

								} while (result2 != 1);
							default:
								break;
							}

							whiteColour();
							printf("Enter the mark : ");
							greenColour();
							rewind(stdin);
							scanf("%d", &mark2[x]);
							gradePoint[x] = score(mark2[x]);
							whiteColour();
							printf("==============================================================\n\n");

							qualitypoint2[x] = stCreditHour2[x] * gradePoint[x];
							totalqualitypoint2[i] = totalqualitypoint2[i] + qualitypoint2[x];
							totalcredithour2[i] = totalcredithour2[i] + stCreditHour2[x];

						}
						gpa[i][1] = totalqualitypoint1[i] / totalcredithour1[i];
						cgpa[i] = (totalqualitypoint1[i] + totalqualitypoint2[i]) / (totalcredithour1[i] + totalcredithour2[i]);
						system("cls");
						printf("\n               Added Sucessful!!\n");
					}

				}
				else if (stNumOfCourseSEM3[i] == 0) {
					whiteColour();
					printf("Add SEMESTER 3 (Y/N)? : ");
					greenColour();
					rewind(stdin);
					scanf("%c", &confirm);

					while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
						redColour();
						printf("You only can type (Y/N) only !!!");
						printf("Please try again !\n\n");
						whiteColour();
						printf("Add SEMESTER 3? (Y/N) : ");
						rewind(stdin);
						scanf("%c", &confirm);
						whiteColour();
					}

					if (confirm == 'Y' || confirm == 'y') {
						//Enter number of course in SEMESTER 3
						//validate the credit hours

						do {
							whiteColour();
							printf("Enter the number of the course SEMESTER 3 : ");
							greenColour();
							rewind(stdin);
							result1 = scanf("%d", &stNumOfCourseSEM3[i]);
							whiteColour();
							if (result1 != 1) {
								redColour();
								printf("Invalid. Please enter a number!\n");
							}

						} while (result1 != 1);

						while (stNumOfCourseSEM3[i] < 0 || stNumOfCourseSEM3[i]>10) {
							whiteColour();
							printf("Please enter agian\n");
							printf("Enter the number of the course in SEMESTER 3 : ");
							greenColour();
							rewind(stdin);
							scanf("%d", &stNumOfCourseSEM3[i]);
						}

						//Enter course details
						for (int x = 0; x < stNumOfCourseSEM3[i]; x++)
						{
							whiteColour();
							printf("\n==================== Course Details ==========================\n");
							printf("Enter the course name : ");
							greenColour();
							rewind(stdin);
							scanf("%[^\n]", &stCourseName3[i][x]);
							whiteColour();
							printf("\nDo you want to choose the course code or enter the course code yourself?\n");
							printf("[1]. Choose the course code\n");
							printf("[2]. Enter the course code\n");
							scanf("\n%d", &choose);
							switch (choose)
							{
							case 1:
								printf("Choose the course code\n");
								printf("\n[1]. AAA1003");
								printf("\n[2]. AAA1014\n");
								scanf("\n%d", &code);
								if (code == 1) {
									strcmp(stCourseCode3[i][x], ABA1003);
									stCreditHour3[x] = CREDITHOUR3;
								}
								else if (code == 2) {
									strcmp(stCourseCode3[i][x], ABA1014);
									stCreditHour3[x] = CREDITHOUR4;
								}
								break;
							case 2:
								printf("Enter the course code : ");
								rewind(stdin);
								scanf("%s", &stCourseCode3[i][x]);
								//validate the credit hours
								do {
									printf("Enter the credit hours : ");
									rewind(stdin);
									result2 = scanf("%lf", &stCreditHour3[x]);

									if (result2 != 1) {
										printf("Invalid. Please enter a number!\n");
									}

								} while (result2 != 1);
							default:
								break;
							}
							whiteColour();
							printf("Enter the mark : ");
							greenColour();
							rewind(stdin);
							scanf("%d", &mark3[x]);
							whiteColour();
							gradePoint[x] = score(mark3[x]);
							printf("==============================================================\n\n");

							qualitypoint3[x] = stCreditHour3[x] * gradePoint[x];
							totalqualitypoint3[i] = totalqualitypoint3[i] + qualitypoint3[x];
							totalcredithour3[i] = totalcredithour3[i] + stCreditHour3[x];

						}
						gpa[i][2] = totalqualitypoint3[i] / totalcredithour3[i];
						cgpa[i] = (totalqualitypoint1[i] + totalqualitypoint2[i] + totalqualitypoint3[i]) / (totalcredithour1[i] + totalcredithour2[i] + totalcredithour3[i]);
						system("cls");
						printf("\n               Added Sucessful!!\n");


					}
				}
				else {
					whiteColour();
					printf("\nThis student has done his study!!\n");
				}

				find = 1;
			}
		}

		if (find != 1) {
			redColour();
			printf("The student ID is not match!\n\n");
			whiteColour();
			printf("Do you want to continue enter student ID? (Y/N) : ");
			greenColour();
			rewind(stdin);
			scanf("%c", &cont);
			whiteColour();
			while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n') {
				redColour();
				printf("You only can type (Y/N) only\n");
				printf("Please try again !!!\n\n");
				whiteColour();
				printf("Do you want to continue enter student ID? ? (Y/N) : ");
				rewind(stdin);
				scanf("%c", &cont);
			}

			if (cont == 'N' || cont == 'n') {
				system("cls");
			}
		}

	} while (cont == 'y' || cont == 'Y');
}

double score(int mark)
{

	double gradepoint;

	if (mark >= 80 && mark <= 100)
	{
		gradepoint = 4.00;
	}
	else if (mark >= 75 && mark <= 79)
	{
		gradepoint = 3.75;
	}
	else if (mark >= 70 && mark <= 74)
	{
		gradepoint = 3.50;
	}
	else if (mark >= 65 && mark <= 69)
	{
		gradepoint = 3.00;
	}
	else if (mark >= 60 && mark <= 64)
	{
		gradepoint = 2.75;
	}
	else if (mark >= 55 && mark <= 59)
	{
		gradepoint = 2.50;
	}
	else if (mark >= 50 && mark <= 54)
	{
		gradepoint = 2.00;
	}
	else if (mark >= 45 && mark <= 49)
	{
		gradepoint = 1.75;
	}
	else if (mark >= 40 && mark <= 44)
	{
		gradepoint = 1.00;
	}
	else
	{
		gradepoint = 0.00;
	}
	return gradepoint;

}

int studentIdValidation(char stID[]) {
	// Check length

	if (strlen(stID) != 9) {
		return 0;
	}
	// Check if first three characters are alphabets
	for (int i = 0; i < 3; i++) {

		if (!isalpha(stID[i])) {
			return 0;
		}
	}
	// Check if the remaining characters are digits
	for (int i = 4; i < 9; i++) {
		if (!isdigit(stID[i])) {
			return 0;
		}
	}
	return 1;
}

// based on your grade point to decide the grade 
char grade(double gpa) {
	char grade;
	if (gpa == 4.00) {
		grade = 'A';
	}
	else if (gpa == 3.75) {
		grade = 'A-';
	}
	else if (gpa == 3.5) {
		grade = 'B+';
	}
	else if (gpa == 3.0) {
		grade = 'B';
	}
	else if (gpa == 2.75) {
		grade = 'B-';
	}
	else if (gpa == 2.5) {
		grade = 'C+';
	}
	else if (gpa == 2.0) {
		grade = 'C+';
	}
	else {
		grade = 'F';
	}

}