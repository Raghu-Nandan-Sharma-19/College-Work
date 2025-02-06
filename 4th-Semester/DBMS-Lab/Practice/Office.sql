create database office;

use office;

CREATE TABLE Employees (
	EmployeeId INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(20),
    Age INT,
    DateOfBirth DATE,
    Designation VARCHAR(50),
    Email VARCHAR(50)
);

desc Employees