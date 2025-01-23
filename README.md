Gym System
Data Structure (2024-2025)

1. Gym System
Final Project Report for Data Structure
Faculty of Information Technology

Submitted By:
Mohammad Nemrini
Loay Al-Masri
Faris Hijazi
Zubaida Nassar

Under The Guidance Of:
Dr. Hashim Jarrar
2025

2. Introduction
This Gym System Project. The system helps with the following:

Member Management: Storing and managing member information (like name, ID, and membership details).
Healthy Meals: Providing healthy food options with information about price, and serving size.
To achieve this, we use data structures such as linked lists, stacks, Binary Search, Bubble Sort, Linear Search, queues, and binary search trees.
These structures help us organize and handle data more efficiently.

3. System Design
3.1 Main Modules
User Management (Add User, Delete User, Search for a user)


Healthy Meal Service

Members can view a list of healthy meals with details (price, size).
They can buy these meals directly through the system.
3.2 Data Structures Used

Stack:
Could store recent user actions or track the most recent meal purchases.


Queue:
Useful for a waiting list if a class or trainer is popular (first-come, first-served).


Linked List:
Can store member details or workout schedules, allowing easy insertion or deletion of records.


Binary Search Tree (BST):
Can store meals or members in a way that makes searching for a specific ID faster (compared to a normal list).
(Your actual code might use different names or focus on certain structures. Feel free to modify this list.)

Linear Search:
we used it to find a specific item if it is stored or not.


Binary Search:
it can search over an array in less time compared to the linear search.


4. Key Features and Operations
Add New Member

Collects information (like name, email, membership type) and saves it in a linked list or BST.
Display Members or Meals

Shows the list of members or meals with important details.
Uses data structure traversal to go through items one by one.
Search

Finds a member or meal by ID or name.
For a BST, searching can be done faster than in a normal list.
Delete or Update

Removes a member or meal from the data structure.
Updates records (like changing a member’s phone number or a meal’s price).

Could be stored in a linked list or array.
