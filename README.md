# Data Structures I

The purpose of this repository is to practice skills related to Data Structures. The algorithms created are intended to work on Linear Lists, such as Arrays and Linked Lists of structured types. The idea for the DataStructuresI repository came from a course I'm taking in college by the same name. As I progress on the subject, more implementations and applications will be developed and inserted into this repository.

### Note to readers

This being a practical application of the contents studied by me, the algorithms are going to stick to the basics, seeking memory optimization and capacity to import to other languages, etc. This is an attempt to both use this as a project for this subject and also future applications in other areas/fields.

# Index

1. [Shared Characteristics](#shared-characteristics)
    1. [Enumerated Type](#enumerated-type)
    2. [ReportConclusion function](#reportconclusion-function)
    3. [Menu](#menu)
2. [Unsorted and sorted arrays](#1-unsorted-and-sorted-arrays)
3. [Linked List (Sorted)](#2-linked-list-sorted)
4. [Stack](#3-stack)
5. [Queue](#4-queue)

# Shared characteristics

The following items are present in all five algorithms

### Includes

The standard libraries for I/O and a conditional to allow users to be able to use the sleep() function.

### Enumerated Type

        enum OpConclusions{...}

### ReportConclusion function

        string ReportConclusion(OpConclusions Conclusion){...}
        
Returns a string that indicates the state of conclusion of the functions in the algorithms.

### Menu

        bool Menu(){...}

#### Procedure

1. Lists all possible options
2. Asks for user input on options
3. Calls function according to user's input

#### Return

- Returns false if user chooses any of the accepted crudl operations or a value beyond the scope of the operations
- Returns true if user chooses to abandon program

# 1. Unsorted and Sorted Arrays

## Global Variables

- A structured type array

        struct Dados Lista[7];

- An integer to control the amount of items in the list

        int n;

- An integer to indicate the last possible element of the list

        int m;
        
## Functions and Procedures

### Crudl

#### 1. Read

        int Read (int Key){...}

##### Parameters

- An integer `Key`

##### Procedure

It cycles through the data structure accordingly looking for the key.

##### Return

- Returns the position of the array element if and where Key was found.
- Returns `0` if Key was not found or if list is empty

#### 2. Create 

        OpConclusions Create(int Key, int Input){...}

##### Parameters

- An integer `Key`
- An integer to represent the data to be inserted in the array element `Input`

##### Procedure

1. It checks if the list is full
2. It calls the `Read` function to check if there is already a Key with the same value
3. Inserts the element accordingly.

##### Return

Always returns an enum `OpConclusions` depending on the outcome
- Returns `ListaCheia` if the list is full
- Returns `RegistroJaExiste` if there is already a Key with the same value
- Returns `Success` if the insertion was completed

#### 3. Update 

        OpConclusions Update(int Key, int Input){...}

##### Parameters

- An integer `Key`
- An integer to represent the data to be updated in the array element `Input`

##### Procedure

1. It checks if the list is empty
2. It calls the `Read` function to check if there is a Key with the same value
3. Updates the element accordingly

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `NotFound` if there isn't a Key with the same value
- Returns `Success` if the update was completed

#### 4. Delete 

        OpConclusions Delete(int Key){...}

##### Parameters

- An integer `Key`

##### Procedure

1. It checks if the list is empty
2. It calls the `Read` function to check if there is a Key with the same value
3. Deletes the element accordingly

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `NotFound` if there isn't a Key with the same value
- Returns `Success` if the deletion was completed

#### 5. List

        OpConclusions Listagem(){...}

##### Procedure

1. It checks if the list is empty
2. It prints on console the Keys and Data in the list
3. Puts the console to sleep for an `n` amount of seconds so that users can read the list

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `Success` if the listing was completed

# 2. Linked List (Sorted)

## Global Variables

- A pointer to the head of the list of structured types

        struct Dados *HeadPointer;
        
- A pointer to hold the position of the previous element in the `Read` function

        struct Dados *Previous Pointer;

- A pointer to hold the position of the Result of the `Read` function

        struct Dados *ResultPointer

## Functions and procedures

### Crudl in linked lists

#### 1. Read

        OpConclusions Read (int Key){...}

##### Parameters

- An integer `Key`

##### Procedure

It cycles through the data structure accordingly looking for the key.

##### Return

- Returns `Success` if key was found
- Returns `NotFound` if Key was not found 
- Returns `ListaVazia` if list is empty

#### 2. Create 

        OpConclusions Create(int Key, int Input){...}

##### Parameters

- An integer `Key`
- An integer to represent the data to be inserted in the array element `Input`

##### Procedure

1. It calls the `Read` function to check if there is already a Key with the same value
2. Inserts the element accordingly.

##### Return

Always returns an enum `OpConclusions` depending on the outcome
- Returns `RegistroJaExiste` if there is already a Key with the same value
- Returns `Success` if the insertion was completed

#### 3. Update 

        OpConclusions Update(int Key, int Input){...}

##### Parameters

- An integer `Key`
- An integer to represent the data to be updated in the array element `Input`

##### Procedure

1. It checks if the list is empty
2. It calls the `Read` function to check if there is a Key with the same value
3. Updates the element accordingly

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `NotFound` if there isn't a Key with the same value
- Returns `Success` if the update was completed

#### 4. Delete 

        OpConclusions Delete(int Key){...}

##### Parameters

- An integer `Key`

##### Procedure

1. It checks if the list is empty
2. It calls the `Read` function to check if there is a Key with the same value
3. Deletes the element accordingly

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `NotFound` if there isn't a Key with the same value
- Returns `Success` if the deletion was completed

#### 5. List

        OpConclusions Listagem(){...}

##### Procedure

1. It checks if the list is empty
2. It prints on console the Keys and Data in the list
3. Puts the console to sleep for a `second` amount of seconds so that users can read the list

##### Return

- Returns `ListaVazia` if the list is empty
- Returns `Success` if the listing was completed

# 3. Stack

## Global Variables

- A pointer to the top of the stack

        struct Dados *Top = NULL;

- A variable to limit the amount of items in the stack

        int StackLimit = 10;

- A variable to count the items in the stack

        int StackCounter = 0;

## Functions and procedures

#### 1. PopLast

        void PopLast(){...}

##### Procedure

1. Cycles through the stack until the last item is found
2. Removes the last item from the stack

#### 2. Push

        OpConclusions Push(int Input){...}

##### Parameters

- An integer `Input`

##### Procedure

- Checks if Stack Limit has been met
  - If so, calls `PopLast()` to remove the item at the bottom of the stack
- Inserts the new item at the top of the stack

##### Return

- Always returns `Success`

#### 3. Pop

        OpConclusions Pop(){...}

##### Procedure

- Checks if stack is empty
- Removes the item at the top of the list

##### Returns

- `Pilha Vazia` if the stack is empty
- `Success` if the procedure was done

#### 4. List

##### Procedure

- Checks if stack is empty
- Cycles through all the items in the stack, printing them on console

# 4. Queue

## Global Variables

- A pointer to the first item of the queue

        struct Dados *First = NULL;
        
- A pointer to the last item of the queue

        struct Dados *Last = NULL;

## Functions and procedures

#### 1. Enqueue

##### Parameters

- An integer `Input` to be inserted in the queue

##### Procedure

- Checks if queue is empty
- Inserts the item at the end of the queue

##### Return

- Always returns `Success`

#### 2. Dequeue

##### Procedure

- Checks if the queue is empty
- Removes the first item in queue

##### Returns

- Returns `EmptyQueue` if queue is empty
- Returns `Sucess` if item is removed

#### 4. List

##### Procedure

- Checks if stack is empty
- Cycles through all the items in the queue, printing them on console
