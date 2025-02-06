create database school;

use school;

CREATE TABLE Students (
	StudentID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName CHAR(20),
	Age INT,
    DateOfBirth DATE,
	Marks FLOAT,
	Email VARCHAR(100)
);

desc Students