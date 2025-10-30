# OOP-Assignment2-Amna-Rehan-241-5581
This is my assignment that covers the concept of que,stacks and singly and double linked list  and recursive function.

Question 1: Recursion
a) ChangeLocation Function:
•	Implemented a recursive function ChangeLocation(char *Array, int b1, int b2) that swaps elements between indices b1 and b2.
•	Base case: when b1 >= b2, recursion stops.
•	Recursive step: swap Array[b1] and Array[b2], then call ChangeLocation(Array, b1+1, b2-1).
•	Example worked correctly: 'COMPUTER' → 'COEPUTMR'.
b) PrintPattern Function:
•	Implemented recursive function PrintPattern(int &n) to print a number pattern.
•	Recursively reduce n, print the corresponding row pattern based on the current value.
•	Produces the desired output for n = 4.

Question 2: Singly Linked List (Geospatial Features)
•	Defined a base class Feature with a virtual analyze() method.
•	Derived LandFeature and WaterFeature classes with specific implementations of analyze().
•	Created SinglyLinkedList class with:
o	insertAtEnd(int featureID, Feature* f)
o	deleteByID(int featureID)
o	displayAll()
o	reverseList() (iterative)
•	In main(), added mixed features, displayed them, deleted one, and reversed the list.
•	Memory management handled via constructors/destructors.

Question 3: Doubly Linked List (Library System)
•	Implemented BookNode with BookID, Title, Author, next, prev.
•	Functions implemented:
o	Add book at beginning, end, or specific position.
o	Delete book by ID.
o	Display list forward and backward.

Question 4: Queue (Ticket Booking System)
•	Implemented Customer node with CustomerID, Name, Tickets.
•	Queue operations implemented:
o	enqueue to add customer at the back.
o	dequeue to remove the front customer after issuing tickets.
o	Display the queue to show FIFO order.

Question 5: Stack & Algorithm Analysis
•	Implemented two stack types:
o	Linked List Stack: dynamic memory, pointer-based operations.
o	Array Stack: dynamic array, resizing as needed.
•	Used both stacks to solve Question 1 recursively, now iteratively.
•	Algorithm Analysis:
o	Linked list stack: O(1) insertion/deletion, memory overhead per node.
o	Array stack: O(1) amortized insertion/deletion, contiguous memory, resizing cost occasionally.
o	Comparison shows linked list is more memory-flexible, array stack faster for contiguous access.

Summary:
My work  demonstrates mastery of recursion, linked lists (single & double), stacks, queues, and algorithm analysis, with bonus features like operator overloading and STL-compatible iterators enhancing your implementation.
