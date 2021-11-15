# DataStructuresI

The purpose of this repository is to practice skills related to Data Structures. The algorithms created are intended to work on Linear Lists, such as Arrays and Linked Lists of structured types. The idea for the DataStructuresI repository came from a course I'm taking in college by the same name. As I progress on the subject, more implementations and applications will be developed and inserted into this repository.

### Note to readers

This being a practical application of the contents studied by me, the algorithms are going to stick to the basics, seeking memory optimization and capacity to import to other languages, etc. This is an attempt to both use this as a project for this subject and also future applications in other areas/fields.

## Index

1. [Code Definitions](#code-definitions)
    1. [Includes](#includes)
    2. [Global Variables](#global-variables)
2. [Functions and Procedures](#functions-and-procedures)
    1. [Crudl](#crudl)
        1. [Read](#1-read)
        2. [Create](#2-create)
        3. [Update](#3-update)
        4. [Delete](#4-delete)
        5. [List](#5-list)
    2. [Menu](#menu)

## Code definitions

### Includes

The standard libraries for I/O and a conditional to allow users to be able to use the sleep() function.

### Global Variables

#### Array

- A structured type array

        struct Dados Lista[7];

- An integer to control the amount of items in the list

        int n;

- An integer to indicate the last possible element of the list

        int m;

- An enumerated type to report the conclusion of the functions (OpConclusions)

        enum OpConclusions {NotFound, RegistroJaExiste, ListaCheia, ListaVazia, Success};

#### Linked List

- A pointer to a structured type
- An integer to control the amount of items in the list (n)
- An integer to indicate the last possible element of the list (m)
- An enumerated type to report the conclusion of the functions (OpConclusions)

## Functions and Procedures

### Crudl

#### 1. Read

`int Read (int Key){...}`  

##### Parameters

- An integer `Key`

##### Procedure

It cycles through the data structures accordingly looking for the key.

##### Return

- Returns the position of the array element if and where Key was found.
- Returns `0` if Key was not found or if list is empty

#### 2. Create 

`OpConclusions Create(int Key, int Input){...}`

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

`OpConclusions Update(int Key, int Input){...}`

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

`OpConclusions Delete(int Key){...}`

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

`OpConclusions Listagem()`

##### Parameters

None

##### Procedure

1. It checks if the list is empty
2. It prints on console the Keys and Data in the list
3. Puts the console to sleep for an `n` amount of seconds so that users can read the list

##### Return

Always returns an enum OpConclusions depending on the outcome
- Returns `ListaVazia` if the list is empty
- Returns `Success` if the listing was completed

### Menu

`bool Menu(){...}`

##### Parameters

None

##### Procedure

1. Lists all possible options
2. Asks for user input on options
3. Calls function corresponding the input

##### Return

- Returns false if user chooses any of the accepted crudl operations or a value beyond the scope of the operations
- Returns true if user chooses to abandon program
