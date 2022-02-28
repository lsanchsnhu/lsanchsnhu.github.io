## Luc Sanchez ePortfolio
### Code Review
[link to mp4 in repo](https://github.com/lsanchsnhu/lsanchsnhu.github.io/blob/main/Code%20Review/Code%20Review.mp4)
### Artifacts

### Software Design and Engineering
#### Original source code
***
```
#include <iostream>
using namespace std;

int main() {
	int choice, i = 1;
	int first, second;

	while (i > 0) {
		cout << "----------------" << endl;
		cout << "- 1)Add -" << endl;
		cout << "- 2)Subtract -" << endl;
		cout << "- 3)Multiply -" << endl;
		cout << "- 4)Exit -" << endl;
		cout << "----------------" << endl;
		cin >> choice;

		switch (choice) {
		case 1: 
			cin >> first >> second;
			// Vulnerability #1: This line subtracts the value even though this option is for addition. This will be fixed
			// by changing the operator from '-' to '+'

			// Vulnerability #2: This line also outputs the - sign even thhough the option is for addition.This will be fixed
			// by changing the output from '-' to '+'
			cout << first << " + " << second << " = " << first + second << endl;
			break;
		case 2:
			cin >> first >> second;
			// Vulnerability #3: This line adds the value even though this option is for subtraction. This will be fixed
			// by changing the operator from '+' to '-'
			cout << first << " - " << second << " = " << first - second << endl;
			break;
		case 3:
			cin >> first >> second;
			// Vulnerability #4: This line divides the value even though this option is for multiplication. This will be fixed
			// by changing the operator from '/' to '*'

			// Vulnerability #2: This line also outputs the - sign even thhough the option is for multiplication.This will be fixed
			// by changing the output from '-' to '*'
			cout << first << " * " << second << " = " << first * second << endl;
			break;
		// Vulnerability #6: This line is used to exit the program even though the option text says that 4 is supposed to be
		// the option for exiting the program. This will  be fixed  by changing the case from 5 to 4
		case 4:
			i = 0;
			break;
		default:
			// Vulnerability  #5: This line is used to handle any other integers other than 1-4, but it doesn't actually tell the
			// user what is happening. This will be fixed by outputting an error message telling the user the proper options.
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			break;
		}
	}
}
```
#### Enhanced Source Code
***
```
#include <iostream>
using namespace std;

int main() {
	int choice, i = 1;
	int first, second;

	while (i > 0) {
		cout << "----------------" << endl;
		cout << "- 1)Add -" << endl;
		cout << "- 2)Subtract -" << endl;
		cout << "- 3)Multiply -" << endl;
		cout << "- 4)Exit -" << endl;
		cout << "----------------" << endl;
		cin >> choice;

		switch (choice) {
		case 1: 
			cout << "- Add -" << endl;
			cout << "- Enter 2 digits to be added -" << endl;
			cin >> first >> second;
			cout << first << " + " << second << " = " << first + second << endl;
			break;
		case 2:
			cout << "- Subtract -" << endl;
			cout << "- Enter 2 digits to be subtracted -" << endl;
			cin >> first >> second;
			cout << first << " - " << second << " = " << first - second << endl;
			break;
		case 3:
			cout << "- Multiply -" << endl;
			cout << "- Enter 2 digits to be multiplied -" << endl;
			cin >> first >> second;
			cout << first << " * " << second << " = " << first * second << endl;
			break;
		case 4:
			i = 0;
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			break;
		}
	}
}
```
### Algorithms and Data Structures
#### Original Source Code
***
```
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
string clientData[2][5] = { {"Bob Jones","Sarah Davis","Amy Friendly","Johnny Smith","Carol Spears"},{"1","2","1","1","2"} };


void CheckUserPermissionAccess() {
    cout << "Enter your username : " << endl;
    string user;
    cin >> user;
    cout << "Enter your password : " << endl;
    int pass;
    cin >> pass;
    // this just compares the user input to a hardcoded value that can be found by disassembling the source code
    while (pass != 123) {
        cout << "Invalid Password. Please try again" << endl;
        cin >> pass;
    }
}

void DisplayInfo() {
    cout << "You chose 1\n" << "Client's Name Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    for (int i = 0; i < 5; i++) {
        cout << clientData[0][i] << " selected option " << clientData[1][i] << endl;
    }
}

void ChangeCustomerChoice() {
    cout << "You chose 2" << endl;
    cout << "Enter the number of client you wish to chang" << endl;
    int client;
    cin >> client;
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
    cin >> clientData[1][client - 1];
}

int main() {
    cout << "Hello! Welcome to our Investment Company" << endl;
    cout << "Created by: Luc Sanchez" << endl;
    
    CheckUserPermissionAccess();

    while (1) {
        cout << "What would you like to do?\n" << "DISPLAY the client list(enter 1)\n" << "CHANGE a client's choice(enter 2)\n" << "Exit the program(enter 3)" << endl;
        int option;
        cin >> option;
        switch (option) {
        case 1:
            DisplayInfo();
            break;
        case 2:
            ChangeCustomerChoice();
            break;
        case 3:
            exit(0);
        // this just re-displayed the options if something other than 1, 2, or 3 were picked. Now it explicitly tells you
        // that those are the only options and to try again
        default:
            cout << "Invalid Selection, please choose from 1-3:" << endl;
            break;
        }
    }
    return 0;
}
```
#### Enhanced source code
***
```
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using std::vector;

// define a structure to hold bid information
struct Bid {
    string name; 
    string type;
};

string clientNames[5] = { "Bob Jones","Sarah Davis","Amy Friendly","Johnny Smith","Carol Spears" };
string clientTypes[5] = { "1","2","1","1","2" };

vector<Bid> clientData(5);

void createClientData() {
    clientData.push_back(Bid());
    for (int i = 0; i < 5; i++) {
        clientData[i].name = clientNames[i];
        clientData[i].type = clientTypes[i];
    }
}


void CheckUserPermissionAccess() {
    cout << "Enter your username : " << endl;
    string user;
    cin >> user;
    cout << "Enter your password : " << endl;
    int pass;
    cin >> pass;
    // this just compares the user input to a hardcoded value that can be found by disassembling the source code
    while (pass != 123) {
        cout << "Invalid Password. Please try again" << endl;
        cin >> pass;
    }
}

void DisplayInfo() {
    cout << "You chose 1\n" << "Client's Name Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    for (int i = 0; i < 5; i++) {
        cout << clientData[i].name << " selected option " << clientData[i].type << endl;
    }
}

void ChangeCustomerChoice() {
    cout << "You chose 2" << endl;
    cout << "Enter the number of client you wish to change" << endl;
    int client;
    cin >> client;
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
    cin >> clientData[client - 1].type;
}

int main() {
    cout << "Hello! Welcome to our Investment Company" << endl;
    cout << "Created by: Luc Sanchez" << endl;
    
    CheckUserPermissionAccess();
    createClientData();

    while (1) {
        cout << "What would you like to do?\n" << "DISPLAY the client list(enter 1)\n" << "CHANGE a client's choice(enter 2)\n" << "Exit the program(enter 3)" << endl;
        int option;
        cin >> option;
        switch (option) {
        case 1:
            DisplayInfo();
            break;
        case 2:
            ChangeCustomerChoice();
            break;
        case 3:
            exit(0);
        // this just re-displayed the options if something other than 1, 2, or 3 were picked. Now it explicitly tells you
        // that those are the only options and to try again
        default:
            cout << "Invalid Selection, please choose from 1-3:" << endl;
            break;
        }
    }
    return 0;
}
```
### Databases
#### Original source code
***
```
INSERT INTO hr.person (first_name, last_name, gender, age)
	VALUES ('Jack', 'Smith', 'M', 45);
	
INSERT INTO hr.department (dept_name, building)
	VALUES ('Engineering', 'Building 5');
	
INSERT INTO hr.person_department (person_id, dept_id)
	VALUES ((SELECT person_id FROM hr.person WHERE UPPER(first_name) = 'JACK' AND UPPER(last_name) = 'SMITH'),
			(SELECT dept_id FROM hr.department WHERE UPPER(dept_name) = 'ENGINEERING'));			
			
INSERT INTO hr.person (first_name, last_name, gender, age, favorite_book)
	VALUES ('Luc', 'Sanchez', 'M', 26, 'The Dark Tower');
	
INSERT INTO hr.department (dept_name, building)
	VALUES ('Computer Science', 'Mudd');
	
INSERT INTO hr.person_department (person_id, dept_id)
	VALUES ((SELECT person_id FROM hr.person WHERE UPPER(first_name) = 'LUC' AND UPPER(last_name) = 'SANCHEZ'),
			(SELECT dept_id FROM hr.department WHERE UPPER(dept_name) = 'COMPUTER SCIENCE'));
```
#### Enhanced Source Code
***
```
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/hr";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("hr");

  var firstPerson = { firstName: "Jack", lastName: "Smith", gender: "M", age: 45};
  dbo.collection("person").insertOne(firstPerson, function(err, res) {
    if (err) throw err;
  });

  var firstDepartment = { deptName: "Engineering", building: "Building 5"};
  dbo.collection("department").insertOne(firstDepartment, function(err, res) {
    if (err) throw err;
  });

  var firstPersonQuery = {$and:[{"firstName":"Luc"},{"lastName": "Sanchez"}]};
  let firstPersonResult;
  dbo.collection("person").find(firstPersonQuery, { projection: { _id: 1 } }).toArray(function(err, result) {
    if (err) throw err;
    firstPersonResult = result;
  });

  var firstDepartmentQuery = {$and:[{"deptName":"Computer Science"},{"building": "Mudd"}]};
  let firstDepartmentResult;
  dbo.collection("department").find(firstDepartmentQuery, { projection: { _id: {"$toString": "$_id"} } }).toArray(function(err, result) {
    if (err) throw err;
    firstDepartmentResult = result;    
  });

  var firstPersonDepartment = { personId: firstPersonResult, departmentId: firstDepartmentResult}
  dbo.collection("personDepartment").insertOne(firstPersonDepartment, function(err, res) {
    if (err) throw err;
  });

  var secondPerson = { firstName: "Luc", lastName: "Sanchez", gender: "M", age: 30, favBook: "The Dark Tower"};
  dbo.collection("person").insertOne(secondPerson, function(err, res) {
    if (err) throw err;
  });

  var secondDepartment = { deptName: "Computer Science", building: "Mudd"};
  dbo.collection("department").insertOne(secondDepartment, function(err, res) {
    if (err) throw err;
  });

  var secondPersonQuery = {$and:[{"firstName":"Luc"},{"lastName": "Sanchez"}]};
  let secondPersonResult;
  dbo.collection("person").find(secondPersonQuery, { projection: { _id: 1 } }).toArray(function(err, result) {
    if (err) throw err;
    secondPersonResult = result;
  });

  var secondDepartmentQuery = {$and:[{"deptName":"Computer Science"},{"building": "Mudd"}]};
  let secondDepartmentResult;
  dbo.collection("department").find(secondDepartmentQuery, { projection: { _id: {"$toString": "$_id"} } }).toArray(function(err, result) {
    if (err) throw err;
    secondDepartmentResult = result;    
  });

  var secondPersonDepartment = { personId: secondPersonResult, departmentId: secondDepartmentResult}
  dbo.collection("personDepartment").insertOne(secondPersonDepartment, function(err, res) {
    if (err) throw err;
    db.close();
  });

});
```

### Narratives
### Software Design and Engineering
**A. Briefly describe the artifact. What is it? When was it created?**

This artifact is from CS 405: Secure Coding. It is a C++ program that presents you with a menu of arithmetic operations, which can then be chosen. After choosing your operation, you enter 2 numbers. The results of that operation are then printed on the screen. It was created in October of 2021.

**B. Justify the inclusion of the artifact in your ePortfolio. Why did you select this item? What specific components of the artifact showcase your skills and abilities in software development? How was the artifact improved?**

I think this belongs in the ePortfolio because it provides insight into my process as a software engineer. I looked at how it worked before, and I found the process of not seeing the operation you enter actually appear somewhat frustrating. A good UX improvement is simply showing the operation as you enter it, which lets you know if you potentially entered an operation you didn’t mean to. I also included instructions indicating that you need to enter 2 numbers, as opposed to just a blank newline.

**C. Did you meet the course objectives you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?**

I think this enhancement does a good job of meeting my course outcome plans on improving the “softer” aspect of software engineering, that being the user experience as you go through an app or program. Often I feel like we concentrate so much on the harder skills that we forgot that most of the time another person is going to be the one using the product.

**D. Reflect on the process of enhancing and/or modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?**

This definitely wasn’t my most difficult enhancement, considering all I had to do was add strings to the correct switch cases and make the language added up. Regardless, there were things to consider, such as the language being used (striking the balance between minimalist but still friendly), or the formatting used in the string messages, which can affect user perception of professionalism. 

### Algorithms and Data Structures
**A. Briefly describe the artifact. What is it? When was it created?**

This artifact is from CS 405: Secure Coding. The main data is a 2-dimensional array of strings, with one set being the names of clients and the other being a number representing the clients service. There is a simple interface that first asks for credentials, and once you are in you have options to display or modify the data. It was created in October of 2021.

**B. Justify the inclusion of the artifact in your ePortfolio. Why did you select this item? What specific components of the artifact showcase your skills and abilities in algorithms and data structure? How was the artifact improved?**

This artifact seemed like a good candidate based on the crudeness of its data structures. It uses just a 2D array, not even a vector, and it seemed like we could do better than a C++ primitive. I think my decision to make and implement a customized C++ struct demonstrates my ability to made software more modular and friendly for future development. Thanks to my enhancements, further changes in the future to the client list and service list will be easier, as you can just push new ones to the vector of Client structs, rather than modify an internal 2D array to make changes.
  
**C. Did you meet the course objectives you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?**

I’m happy with the changes I made to this program. Since working in software I have strived to make the development process as developer friendly as possible, both for myself and future people who might end up working on the same code as me. Part of that process means creating data structures that are intuitive, easy to understand, and easy to modify.
  
**D. Reflect on the process of enhancing and/or modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?**

The easy part of the process was simply taking the two string values that were previously part of the 2D array and creating a new struct that has 2 strings as fields. The somewhat tricker aspect was efficiently filling a vector of that struct with default construction and overallocation, which I had to refamiliarize myself with.

### Databases
**A. Briefly describe the artifact. What is it? When was it created?**

This artifact is from DAD 220 Introduction to SQL. It is a small script that inserts a stranger’s information into a table, queries that new information to get its IDs, and then adds those IDs as keys into a new table. It then repeats the process with my own information, as well as adding a new field to my information.
  
**B. Justify the inclusion of the artifact in your ePortfolio. Why did you select this item? What specific components of the artifact showcase your skills and abilities in software development? How was the artifact improved?**

I thought this was a good inclusion to my ePortfolio thanks to its initial simplicity. Because the initial course was introductory, it used plain old SQL. By recreating the script in MongoDB, I was able to take the concepts and principles I learned and apply them to a technology I am much likelier to use in my professional life. 

**C. Did you meet the course objectives you planned to meet with this enhancement in Module One? Do you have any updates to your outcome-coverage plans?**

I would say I even surpassed my original objectives. Thanks to these changes, the script is now much more readable and adaptable if future developers are looking at it.
  
**D. Reflect on the process of enhancing and/or modifying the artifact. What did you learn as you were creating it and improving it? What challenges did you face?**

This was definitely the trickiest artifact to enhance. Even picking the initial artifact was difficult, as my choices of coursework were much more limited. Furthermore, I had no prior experience to MongoDB, so I had to do a lot of learning on the fly just to even convert my initial SQL commands to their MongoDB variants. Not to mention a lot of the boilerplate and setup necessary to install and run a local MongoDB instance on your local machine.
### Professional Self-Assessment

**A. Discuss how completing your coursework throughout the program and developing the ePortfolio has helped showcased your strengths and shape your professional goals and values and prepared you to either enter or become more employable in the computer science field. Use specific examples from your program and include examples outside of the artifacts included in your ePortfolio. Please address following topics: collaborating in a team environment, communicating to stakeholders, data structures and algorithms, software engineering and database, and security. Note: This should function as an overall introduction to your skills and you will become more specific relative to the included artifacts in the next section.**

More important than showcasing my strengths, I am grateful for the opportunity to **develop** these strengths via my coursework. Before enrolling, despite a career in multiple sub-fields of software engineering, I had zero to little experience with subjects such as data mining, mobile architecture, or cybersecurity. Now I’m able to apply a lot of these skills to my current workplace and increase both my professional worth and my productivity. 
  
I’ve actually already been able to do this in practice. I’m at a somewhat young startup, enough that we didn’t really have much of a testing suite in place, and one of the concepts that stuck out as interesting from my QA course was “move from simple to complex”. Keeping this in mind as we built up our test suite both made later test adoption simpler and let us focus more on product development.
  
I’ve also learned a lot about putting together ideas in a thoughtful way and responding respectfully to my peers via all of the discussion posts, creating future proof objects that future developers will understand in my data structures classes, and keeping my products and users safe with secure coding practices. 

**B. Summarize/introduce how your artifacts fit together and inform the portfolio as a whole; this will help demonstrate the full range of your computer science talents and abilities? This section should introduce your audience to the technical artifacts that will follow the professional self-assessment.**

My improvement in software engineering for example was the reason I included the first artifact in the ePortfolio. I often now find myself looking from the perspective of the user, and trying to see behaviors and designs not away from the implementation side.
  
Documentation, modularity and future-proofing are the reasons I chose my second artifact. By making and implementing a customized C++ struct, I showcased my ability to made software more modular and friendly for future development.
  
My last enhancement was a good indicator of my research and problem-solving skills. The translation of a nontrivial SQL script to a MongoDB one is not something that can be ran through a translator or looked up online, and I think the successful transformation of that script demonstrates that I can quickly grapple and apply new technologies and concepts.
