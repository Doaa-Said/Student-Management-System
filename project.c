/*
 ============================================================================
 Name        :project.c
 Author      : Doaa Said
 Date        : 9/8/2024
 Description : Student Management System
 ============================================================================
 */
# include<stdio.h>
# include<stdlib.h>
# include<string.h>

struct student {
	int id;
	char name[50];
	int age;
	float gpa;

};
struct node {
	struct student data;
	struct node *next;

};
struct node *head = NULL;

void addStudent(const struct student *const ptr);
// Prompts the user for new student details and adds them to the system.

void displayStudents(void);
// Shows a list of all stored student records.

void searchStudentByID(int id);
// Allows the user to find a specific student using their unique ID.

void updateStudent(int id);
//facilitates the updating of details for an existing student identified by their ID.

void deleteStudent(int id);
//Removes a student's record based on their ID.

float calculateAverageGPA(void);
//Computes and displays the average GPA of all students.

void searchHighestGPA(void);
//Identifies and displays the student with the highest GPA.

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int choice;
	while (1) {
		printf("------------------------------------\n");
		printf("1. Add student\n");
		printf("2. Display Students\n");
		printf("3. Search  Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student:\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter choice:");

		scanf("%d", &choice);
		printf("------------------------------------\n");
		switch (choice) {
		case 1: {
			struct student s1;
			printf("Enter student ID:");
			scanf("%d", &s1.id);
			printf("Enter name:");
			scanf("%s", s1.name);
			printf("Enter age:");
			scanf("%d", &s1.age);
			printf("Enter GPA:");
			scanf("%f", &s1.gpa);
			addStudent(&s1);
			break;
		}
		case 2: {
			displayStudents();
			break;
		}
		case 3: {
			int id;
			printf("Enter student ID to search:");
			scanf("%d", &id);
			searchStudentByID(id);
			break;
		}
		case 4: {
			int id;
			printf("Enter student ID to update its information:");
			scanf("%d", &id);
			updateStudent(id);
			break;
		}
		case 5: {
			int id;
			printf("Enter student ID to delete its Data:");
			scanf("%d", &id);
			deleteStudent(id);
			break;

		}
		case 6: {
			printf("average GPA = %f \n", calculateAverageGPA());
			break;

		}
		case 7: {

			searchHighestGPA();
			break;

		}
		case 8: {
			printf("Exiting.......\n");
			return 0;
		}

		}

	}
}

void addStudent(const struct student *const ptr) {
	struct node *current = head;
	if (head != NULL) {
		while (current != NULL) {
			if (ptr->id == current->data.id) {
				printf("------------------------------------\n");
				printf("this ID is already reserved\n");
				return;

			}
			current = current->next;

		}
	}
	//create a new node
	struct node *newnode = (struct node*) (malloc(sizeof(struct node)));
	if (newnode == NULL) {
		//
		printf("memory is full");
		return;
	} else {
		//store data of student in newnode
		newnode->data.age = ptr->age;
		newnode->data.gpa = ptr->gpa;
		newnode->data.id = ptr->id;
		int i = 0;
		for (i = 0; i < strlen(ptr->name); i++) {
			newnode->data.name[i] = ptr->name[i];
		}
		newnode->data.name[i] = '\0';
		newnode->next = NULL;
		current = head;
		if (head == NULL) {
			//insert newnode at the beginning of the list
			head = newnode;
			return;
		}
		while (current->next != NULL) {
			current = current->next;

		}
		current->next = newnode;

	}

}

void displayStudents(void) {
	struct node *current = head;
	if (head == NULL) {

		printf(" no students are present\n");
		return;
	}
	//start looping from the head until the last node
	while (current != NULL) {
		printf("[ID: %d, Name:%s, Age: %d, GPA: %f ]\n", current->data.id,
				current->data.name, current->data.age, current->data.gpa);

		current = current->next;
	}

}
void searchStudentByID(int id) {
	if (head == NULL) {
		printf(" no students are present\n");
		return;

	}
	struct node *current = head;

	while (current != NULL) {
		if (current->data.id == id) {
			printf("------------------------------------\n");
			printf("student found:\n");
			printf("ID: %d, Name:%s, Age:%d, GPA:%f \n ", current->data.id,
					current->data.name, current->data.age, current->data.gpa);
			return;
		}
		current = current->next;
	}

	printf("student with ID %d not found\n", id);

}

void updateStudent(int id) {
	if (head == NULL) {
		printf(" no students are present\n");
		return;
	}
	struct node *current = head;

	while (current != NULL) {

		if (current->data.id == id) {
			printf("------------------------------------\n");
			printf("Enter new details for the student with ID %d:\n", id);
			printf("Enter new name:");
			scanf("%s", current->data.name);
			printf("Enter new age:");
			scanf("%d", &current->data.age);
			printf("Enter new GPA:");
			scanf("%f", &current->data.gpa);
			printf("students details updated successfully.\n");
			return;
		}

		current = current->next;
	}

	printf("student with ID %d not found\n", id);

}
float calculateAverageGPA(void) {
	if (head == NULL) {
		return 0.0;
	}
	float sum = 0;
	int count = 0;
	struct node *current = head;
	while (current != NULL) {
		sum += current->data.gpa;
		count++;
		current = current->next;
	}

	return sum / count;

}
void searchHighestGPA(void) {
	if (head == NULL) {
		printf(" no students are present\n");
		return;
	}
	float max = head->data.gpa;
	struct student hieghestStudent = head->data;
	struct node *current = head->next;
	while (current != NULL) {
		if (current->data.gpa > max) {
			max = current->data.gpa;
			hieghestStudent = current->data;

		}
		current = current->next;
	}

	printf("Student with the highest GPA:\n ");
	printf("[ID: %d, Name:%s, Age: %d, GPA: %f ]\n", hieghestStudent.id,
			hieghestStudent.name, hieghestStudent.age, hieghestStudent.gpa);

}
void deleteStudent(int id) {
	if (head == NULL) {
		printf(" no students are present\n");
		return;

	}

	struct node *current = head->next;
	struct node *previous = head;

	// pointer to point the node that will be deleted
	struct node *deletenode = NULL;
	if (head->data.id == id) {
		//check the first student in the linked list
		deletenode = head;
		head = head->next;
		free(deletenode);
		printf("student with ID %d deleted successfully.\n", id);
		return;
	}
	while (current != NULL) {
		//check the rest of students in the linked list
		if (current->data.id == id) {
			//student found
			deletenode = current;
			previous->next = current->next;
			free(deletenode);
			printf("student with ID %d deleted successfully.\n", id);
			return;
		}
		previous = previous->next;
		current = current->next;
	}
	printf("------------------------------------\n");
	//in case the student found in the linked list
	printf("student with ID %d not found\n", id);

}

