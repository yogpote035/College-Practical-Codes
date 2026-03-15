// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Employee {

    uint public empId;
    string public name;
    string public department;
    uint public salary;

    // Store employee details
    function setEmployee(
        uint _empId,
        string memory _name,
        string memory _department,
        uint _salary
    ) public {
        empId = _empId;
        name = _name;
        department = _department;
        salary = _salary;
    }
}