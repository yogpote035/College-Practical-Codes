// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentStorage {

    struct Student {
        uint id;
        string name;
        uint age;
        string course;
    }

    Student public student;

    // Store student information
    function setStudent(
        uint _id,
        string memory _name,
        uint _age,
        string memory _course
    ) public {
        student = Student(_id, _name, _age, _course);
    }

    // Retrieve student information
    function getStudent() public view returns(uint, string memory, uint, string memory) {
        return (student.id, student.name, student.age, student.course);
    }
}